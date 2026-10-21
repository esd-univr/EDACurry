# @author: Christian Checchetti (chris22checchetti@gmail.com)
# This module analyses all retrieved and produced data to generate the final defect coverage report required by the standard

import json
import re
import textwrap
from typing import List
from .models import DefectModel, DefectType


class CoverageReportBuilder:
    _manifest : json
    _defect_universe : List[DefectModel]

    # Standard 65-char width for optimal A4 PDF printing
    PAGE_WIDTH = 65

    def __init__(self, manifest, universe):
        if not manifest:
            raise ValueError("[CoverageReportBuilder] Initialization error: no manifest file has been provided")
        self._manifest = manifest
        if not universe:
            raise ValueError("[CoverageReportBuilder] Initialization error: no defect universe has been provided")
        self._defect_universe = universe


    def _format_banner(self, title: str) -> str:
        """Creates a full-width top/bottom document banner."""
        border = "=" * self.PAGE_WIDTH
        centered_title = title.center(self.PAGE_WIDTH)
        return f"{border}\n{centered_title}\n{border}\n\n"


    def _format_section_header(self, title: str) -> str:
        """Creates a full-width section header with an underline."""
        underline = "-" * self.PAGE_WIDTH
        return f"{title}\n{underline}\n"


    def _format_kv(self, key: str, value: str, indent: int = 3, key_width: int = 24) -> str:
        """Formats a key-value pair with aligned columns and automatic wrapping on the right margin."""
        prefix = " " * indent + f"- {key:<{key_width}} : "
        subsequent = " " * len(prefix)
        return textwrap.fill(
            str(value),
            width=self.PAGE_WIDTH,
            initial_indent=prefix,
            subsequent_indent=subsequent
        ) + "\n"


    def _format_paragraph(self, text: str, initial_indent: str = "   ", subsequent_indent: str = "   ") -> str:
        """Wraps a long text paragraph cleanly within PAGE_WIDTH."""
        return textwrap.fill(
            text,
            width=self.PAGE_WIDTH,
            initial_indent=initial_indent,
            subsequent_indent=subsequent_indent
        ) + "\n"


    def _compute_metrics(self, defect_list: list) -> dict:
        """
        Computes all IEEE Std 2427-2025 coverage metrics for a given list of DefectModel objects:
        - Defect Coverage (Rule 3.3a)
        - Unknown Percentage (Rule 3.3b)
        - Undetected Percentage (Rule 3.3d)
        - Detectable Defect Coverage (Rules 3.4a & 3.4c)
        """
        total_weight = 0.0
        detected_weight = 0.0
        unknown_weight = 0.0
        undetected_weight = 0.0

        detectable_total_weight = 0.0
        detectable_detected_weight = 0.0

        count_total = 0
        count_detected = 0

        for defect in defect_list:
            record = defect.get_record()
            info = record.get_info()

            weight = float(info.get("weight") or 0.0)
            # Ignore collapsed or excluded defects with weight 0
            if weight <= 0.0:
                continue

            status = str(info.get("detection_status") or "unsimulated").lower()
            undet_reason = str(info.get("undetectability_reason") or "").lower()

            count_total += 1
            total_weight += weight

            # 1. Standard Defect Coverage accumulation (Rules 3.3a, 3.3b, 3.3d)
            if status == "detected":
                detected_weight += weight
                count_detected += 1
            elif status == "unknown":
                unknown_weight += weight
            else:
                # Includes 'undetected' and 'unsimulated' (Permission 3.3n)
                undetected_weight += weight

            # 2. Detectable Defect Coverage accumulation (Rule 3.4c)
            # Excludes structurally_undetectable and potentially_undetectable from denominator
            if undet_reason not in ("structurally_undetectable", "potentially_undetectable"):
                detectable_total_weight += weight
                if status == "detected":
                    detectable_detected_weight += weight

        def calc_pct(num: float, den: float) -> float:
            return (num / den) * 100.0 if den > 0.0 else 0.0

        return {
            "count_total": count_total,
            "count_detected": count_detected,
            "total_weight": total_weight,
            "detectable_weight": detectable_total_weight,
            "defect_coverage": calc_pct(detected_weight, total_weight),
            "detectable_coverage": calc_pct(detectable_detected_weight, detectable_total_weight),
            "unknown_pct": calc_pct(unknown_weight, total_weight),
            "undetected_pct": calc_pct(undetected_weight, total_weight)
        }


    def build_coverage_report(self):
        print("[CoverageReportBuilder::build_coverage_report] Generating coverage report...")
        coverage_report = self._format_banner("IEEE Std 2427™-2025 DEFECT COVERAGE SUMMARY")

        # =====================================================================
        # 1. GENERAL INFORMATION
        # =====================================================================
        coverage_report += self._format_section_header("1. GENERAL INFORMATION")
        dut_name = self._manifest.get("dut", "Unknown")
        coverage_report += self._format_kv("Circuit Netlist", dut_name)
        coverage_report += self._format_kv("Testbench Name", f"tb_{dut_name}")

        # Test description details (Recommendation 3.7d)
        cmp_vars = self._manifest.get("cmp_vars", [])
        cmp_vars_str = ", ".join(cmp_vars) if cmp_vars else "None specified"
        tolerance = self._manifest.get("tolerance_limit", "N/A")
        coverage_report += self._format_kv("Tested Variables", cmp_vars_str)
        coverage_report += self._format_kv("Tolerance Limit", f"±{tolerance}%")

        process_model_info = self._manifest.get("process_model", {})
        if not process_model_info:
            coverage_report += self._format_kv("Process Model", "Unknown")
        else:
            pdk_name = process_model_info.get("pdk_name")
            corner = process_model_info.get("corner")
            coverage_report += self._format_kv("Process Model", f"{pdk_name} (Corner: {corner})")

            for key, value in process_model_info.items():
                if key in ["pdk_name", "corner"]:
                    continue

                formatted_key = key.replace("_", " ").title()
                if isinstance(value, list):
                    value_str = ", ".join(str(v) for v in value)
                else:
                    value_str = str(value)

                coverage_report += self._format_kv(formatted_key, value_str)
        coverage_report += "\n\n\n"

        # =====================================================================
        # 2. CIRCUITRY PARTITION AND EXCLUSIONS
        # =====================================================================
        coverage_report += self._format_section_header("2. CIRCUITRY PARTITION AND EXCLUSIONS")
        coverage_report += self._format_kv("Application Circuitry", dut_name)

        excluded_target = self._manifest.get("excluded_target", {})
        if excluded_target:
            categories = [
                ("contents", "Component Masters"),
                ("components", "Components"),
                ("parameters", "Parameters")
            ]

            target_lines = ""
            for key, label in categories:
                items = excluded_target.get(key, [])
                # Filter out invalid, empty, or None entries
                valid_items = [
                    item for item in items
                    if isinstance(item, dict) and item.get("name")
                ]

                if valid_items:
                    target_lines += f"      - {label}:\n"
                    for item in valid_items:
                        name = item.get("name")
                        reason = item.get("exclusion_reason") or "No reason specified"
                        target_lines += self._format_kv(name, reason, indent=9, key_width=18)

            # Print header only if at least one valid excluded target exists
            if target_lines:
                coverage_report += "   - Excluded Target:\n" + target_lines
        coverage_report += "\n\n\n"

        # =====================================================================
        # 3. WEIGHTING AND SAMPLING METHODOLOGY
        # =====================================================================
        coverage_report += self._format_section_header("3. WEIGHTING AND SAMPLING METHODOLOGY")
        coverage_report += self._format_kv("Weighting Method", "Based on circuit element type and or model name")
        coverage_report += self._format_kv("Parametric Weight", "Uniform weight = 1.0")
        coverage_report += self._format_kv("Sampling Method", "Complete universe simulation (No sampling applied)")
        coverage_report += "\n\n\n"

        # =====================================================================
        # 4. DEFECT MODELS AND PARAMETERS
        # =====================================================================
        coverage_report += self._format_section_header("4. DEFECT MODELS AND PARAMETERS")
        coverage_report += self._format_kv("Short Model", "R = 100 Ohm")
        coverage_report += self._format_kv("Open Model", "R = 1 GOhm")
        coverage_report += self._format_kv("Open Gate Model", "3-terminal resistive divider (K = 0.5)")
        coverage_report += self._format_kv("Parametric Model", "DF_PDK = 2.0")
        coverage_report += "\n\n\n"

        # =====================================================================
        # 5. COVERAGE RESULTS
        # =====================================================================
        coverage_report += self._format_section_header("5. COVERAGE RESULTS")
        corner_label = self._manifest.get("process_model", {}).get("corner", "Typical")
        coverage_report += self._format_kv("Process Corner Evaluated", corner_label)
        coverage_report += "\n"

        shorts = []
        opens = []
        parametric = []
        for defect in self._defect_universe:
            d_type = defect.get_record().get_info().get("type")
            if d_type == DefectType.OPEN:
                opens.append(defect)
            elif d_type == DefectType.SHORT:
                shorts.append(defect)
            elif d_type == DefectType.PARAMETRIC:
                parametric.append(defect)

        combined_hard = shorts + opens

        # Compute metrics for each category
        m_shorts = self._compute_metrics(shorts)
        m_opens = self._compute_metrics(opens)
        m_hard = self._compute_metrics(combined_hard)
        m_param = self._compute_metrics(parametric)

        # Pre-format counts to avoid nested f-string syntax errors
        shorts_counts = f"{m_shorts['count_detected']}/{m_shorts['count_total']}"
        opens_counts = f"{m_opens['count_detected']}/{m_opens['count_total']}"
        hard_counts = f"{m_hard['count_detected']}/{m_hard['count_total']}"
        param_counts = f"{m_param['count_detected']}/{m_param['count_total']}"

        # Full-width (65 chars) Summary Table: 1+22+1+9+1+9+1+10+1+9+1 = 65
        table_sep = "+" + "-" * 22 + "+" + "-" * 9 + "+" + "-" * 9 + "+" + "-" * 10 + "+" + "-" * 9 + "+\n"
        coverage_report += table_sep
        coverage_report += f"| {'Metric':<20} | {'Shorts':>7} | {'Opens':>7} | {'CombHard':>8} | {'Param.':>7} |\n"
        coverage_report += table_sep
        coverage_report += (
            f"| {'Defect Coverage':<20} | "
            f"{m_shorts['defect_coverage']:6.2f}% | "
            f"{m_opens['defect_coverage']:6.2f}% | "
            f"{m_hard['defect_coverage']:7.2f}% | "
            f"{m_param['defect_coverage']:6.2f}% |\n"
        )
        coverage_report += (
            f"| {'Detectable Coverage':<20} | "
            f"{m_shorts['detectable_coverage']:6.2f}% | "
            f"{m_opens['detectable_coverage']:6.2f}% | "
            f"{m_hard['detectable_coverage']:7.2f}% | "
            f"{m_param['detectable_coverage']:6.2f}% |\n"
        )
        coverage_report += (
            f"| {'Unknown Status':<20} | "
            f"{m_shorts['unknown_pct']:6.2f}% | "
            f"{m_opens['unknown_pct']:6.2f}% | "
            f"{m_hard['unknown_pct']:7.2f}% | "
            f"{m_param['unknown_pct']:6.2f}% |\n"
        )
        coverage_report += (
            f"| {'Undetected Status':<20} | "
            f"{m_shorts['undetected_pct']:6.2f}% | "
            f"{m_opens['undetected_pct']:6.2f}% | "
            f"{m_hard['undetected_pct']:7.2f}% | "
            f"{m_param['undetected_pct']:6.2f}% |\n"
        )
        coverage_report += table_sep
        coverage_report += (
            f"| {'Active (Det/Tot)':<20} | "
            f"{shorts_counts:>7} | "
            f"{opens_counts:>7} | "
            f"{hard_counts:>8} | "
            f"{param_counts:>7} |\n"
        )
        coverage_report += (
            f"| {'Total Weight':<20} | "
            f"{m_shorts['total_weight']:7.2f} | "
            f"{m_opens['total_weight']:7.2f} | "
            f"{m_hard['total_weight']:8.2f} | "
            f"{m_param['total_weight']:7.2f} |\n"
        )
        coverage_report += (
            f"| {'Detectable Weight':<20} | "
            f"{m_shorts['detectable_weight']:7.2f} | "
            f"{m_opens['detectable_weight']:7.2f} | "
            f"{m_hard['detectable_weight']:8.2f} | "
            f"{m_param['detectable_weight']:7.2f} |\n"
        )
        coverage_report += table_sep + "\n"

        note_text = (
            "NOTE: Individual justifications for zero-weight defects (Rule 3.1m) and potentially/structurally "
            "undetectable defects (Rules 3.4d & 3.4e) are documented per-defect in defect_coverage_details.json "
            "(referenced in Section 7 pursuant to Rule 3.3f)."
        )
        coverage_report += self._format_paragraph(note_text, initial_indent="   ", subsequent_indent="         ") + "\n\n\n"

        # =====================================================================
        # 6. COMPLIANCE DECLARATION
        # =====================================================================
        coverage_report += self._format_section_header("6. COMPLIANCE DECLARATION")
        coverage_report += self._format_kv("Standard", "IEEE Std 2427™-2025 (Standard for Analog Defect Modeling and Coverage)")
        coverage_report += "\n"

        optimization_info = self._manifest.get("perform_optimization", {})
        merge_enabled = optimization_info.get("merge", False)
        collapse_enabled = optimization_info.get("collapse", False)
        include_bulk_opens = self._manifest.get("include_bulk_opens", True)

        # Clauses structurally not exercised by the tool (layout/critical-area, series, multi-corner, custom defects)
        not_exercised_clauses = [
            "3.1o)", "3.1p)", "3.1q)", "3.1r)", "3.1u)", "3.1v)", "3.1w)", "3.1y)", "3.1aa)",
            "3.2p)", "3.2s)", "3.2t)", "3.2u)", "3.2v)", "3.2w)", "3.2x)", "3.2y)",
            "3.3j)", "3.3k)",
            "3.5d)", "3.5e)", "3.5f)"
        ]

        if not collapse_enabled:
            not_exercised_clauses.append("3.1t)")
        if not merge_enabled:
            not_exercised_clauses.append("3.1x)")
        if include_bulk_opens:
            not_exercised_clauses.append("3.1z)")

        def sort_key(clause_str):
            parts = clause_str.rstrip(")").split(".")
            sec = int(parts[0])
            m = re.match(r"(\d+)([a-z]+)", parts[1])
            subsec = int(m.group(1))
            letter = m.group(2)
            return (sec, subsec, len(letter), letter)

        sorted_clauses = sorted(set(not_exercised_clauses), key=sort_key)
        not_exercised_str = ", ".join(sorted_clauses)

        coverage_report += self._format_paragraph(
            "- IEEE Std 2427™-2025 recommendations and permissions not exercised for this Summary:",
            initial_indent="   ",
            subsequent_indent="     "
        )
        coverage_report += self._format_paragraph(not_exercised_str, initial_indent="     ", subsequent_indent="     ") + "\n"

        # Structured Annex K items for clean text wrapping (Rule 3.7c)
        annex_k_sections = [
            ("3.1 Defect universe", [
                ("n)", "Each circuit element should be site of potential parametric defect models, having a high and a low element performance."),
                ("o)", "Passive elements having resistance, capacitance, or inductance below specified threshold values should be assumed parasitic."),
                ("p)", "If space between nodes in application circuitry and unused circuitry is small but contains intervening power/ground rail, then only a short to ground."),
                ("q)", "If space between nodes in application circuitry and unused circuitry is small enough, with no intervening power/ground rail, then a short between the nodes."),
                ("r)", "Process/characterization monitors that are sufficiently far, should be classified as unused circuitry."),
                ("s)", "Defect Universe Details should indicate for each defect: potentially or structurally undetectable."),
                ("t)", "Opens injected in each terminal of a two-terminal element should be collapsed to a single open."),
                ("u)", "Open in each same terminal of N identical elements in parallel should be collapsed to a single open."),
                ("v)", "Short across 1 of N identical circuit elements in series should be collapsed to a single short."),
                ("w)", "If trimming will cause any circuit elements to become unused circuitry, may exclude all but one set of circuit elements."),
                ("x)", "Parallel design-intent circuit elements may be merged."),
                ("y)", "For parametric defect coverage, series identical design-intent circuit elements may be merged."),
                ("z)", "If the bulk node of a transistor is connected to a shared substrate, an open defect in this terminal may be omitted."),
                ("aa)", "A user-defined defect may be included.")
            ]),
            ("3.2 Defect models and defect injection", [
                ("m)", "Short defect should have a resistance of 100 Ohm or more."),
                ("n)", "Open defect should have a resistance of 1 GOhm or less, and a second model should have an infinite resistance."),
                ("o)", "Model or subcircuit specified by open_gate_model should have infinite resistance or apply Vg=(Vd+Vs)/2."),
                ("p)", "Defect[s] that result in the same CUT topology should be collapsed into a single defect for simulations."),
                ("q)", "Value for DF_PDK should be 2.0."),
                ("r)", "Parametric defects in each circuit element should have a positive and a negative number of standard deviations."),
                ("s)", "If N identical elements are in parallel, open defects may be in one of them and in the merged node."),
                ("t)", "If N identical R, L, C, or D elements are in series, a short defect may be injected in only one of them."),
                ("u)", "Any two defects that produce the same behavior may be collapsed into a single defect."),
                ("v)", "Elements connected in parallel, and open in one indistinguishable from variation in all, may be denoted potentially undet."),
                ("w)", "R,L,C in series, and short in one indistinguishable from variation in all, may be denoted potentially undet."),
                ("x)", "MOS in series, short defect in one indistinguishable from variation in all, may be denoted potentially undet."),
                ("y)", "Complete open and resistive open in gate of N MOS transistors in parallel may be collapsed to complete open.")
            ]),
            ("3.3 Defect coverage", [
                ("i)", "A coverage should be reported that combines coverage for shorts and opens."),
                ("j)", "In addition to 'typical' process, defect coverage should be stated at one or more representative process corners."),
                ("k)", "If Defect Coverage Summary reports coverage at corners, it should describe each and report the union coverage."),
                ("l)", "Simulator accuracy should be approximately equal to the accuracy used during design verification."),
                ("m)", "If a defect's status is listed as 'unknown,' the reason should be stated as due to the simulator, computer, or test."),
                ("n)", "Potentially and structurally undetectable defects may be counted as undetected without simulating them.")
            ]),
            ("3.5 Defect weighting", [
                ("c)", "Weight for a defect should be proportional to the defect's likelihood of occurrence."),
                ("d)", "Weight for short across critical-area gap should be proportional to gap's length and inversely to distance across gap."),
                ("e)", "Weight for open in a critical-area polygon should be proportional to polygon's length and inversely to its width."),
                ("f)", "Weight for open in a via should be inversely related to via's area."),
                ("g)", "All parametric defects should be assigned the same weight.")
            ]),
            ("3.6 Redundancy and defect tolerance", [
                ("a)", "Defect in element added for redundancy to improve yield may be potentially or structurally undetectable.")
            ]),
            ("3.7 Defect Coverage Summary", [
                ("d)", "The Defect Coverage Summary should include a description of the tests.")
            ])
        ]

        coverage_report += self._format_paragraph(
            "- List of IEEE Std 2427™-2025 recommendations and permissions, paraphrased (Annex K):",
            initial_indent="   ",
            subsequent_indent="     "
        ) + "\n"
        for sec_title, clauses in annex_k_sections:
            coverage_report += f"     [{sec_title}]\n"
            for letter, desc in clauses:
                init_ind = f"       {letter:<4}"
                sub_ind = "           "
                coverage_report += self._format_paragraph(desc, initial_indent=init_ind, subsequent_indent=sub_ind)
            coverage_report += "\n\n\n"

        # =====================================================================
        # 7. DETAILED LOG ATTACHMENTS
        # =====================================================================
        coverage_report += self._format_section_header("7. DETAILED LOG ATTACHMENTS")
        coverage_report += self._format_kv("Per-defect Status Log", "See defect_coverage_details.json file")

        print("[CoverageReportBuilder::build_coverage_report] Report successfully generated")
        return coverage_report

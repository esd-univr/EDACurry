# Bandgap DUT

A bandgap voltage reference used as a device under test (DUT) by the
`edacurry2427` defect-injection and fault-simulation tool.

## Provenance

These sources are **not original work of the EDACurry project**. They are
derived from the [adsbenchmark](https://github.com/Infineon/adsbenchmark)
project by Infineon Technologies AG, a collection of benchmark circuits for
analog defect simulation and IEEE P2427 standard validation.

| | |
|---|---|
| Upstream repository | <https://github.com/Infineon/adsbenchmark> |
| Upstream path | `BANDGAP/src/` |
| Upstream commit | `ce4f658ff890a136d0f826391abffbfeb24bd8dc` (2022-05-24) |
| Upstream license | MIT (see [LICENSE](LICENSE)) |

The MIT License permits redistribution and modification; the required
copyright and permission notice is reproduced in [LICENSE](LICENSE). The
original Infineon disclaimer headers have been preserved verbatim in every
source file.

Upstream also ships `BANDGAP/doc/` (circuit documentation) and `BANDGAP/ref/`
(reference open- and short-defect lists). Those are not redistributed here;
refer to the upstream repository for them.

## Local modifications

The circuits were adapted to run under ngspice, which does not support the
Spectre `simulator lang` directive nor Verilog-A compiled models. All changes
are listed below; nothing else differs from upstream.

| File | Change | Reason |
|---|---|---|
| `model/bip_nom.scs` | `simulator lang = spice` commented out | Spectre-only directive, rejected by ngspice |
| `model/mosfets.scs` | `simulator lang = spice` commented out | Spectre-only directive, rejected by ngspice |
| `top.hsp` | `.hdl "checker/bg_checker.va"` commented out | ngspice cannot load Verilog-A modules |
| `top.hsp` | `.measure tran max_fail max v(fail)` commented out | `fail` is driven by the disabled Verilog-A checker |
| `top.hsp` | added `.measure tran v_bg_val AVG v(bg) from=50m to=100m` | replacement observation point: average bandgap output once settled |
| `tb_bandgap.hsp` | `'vsup'` → `'{vsup}'` in the `V3` pulse source | ngspice parameter-substitution syntax |
| `tb_bandgap.hsp` | checker instance `XI89 bg fail testnr bg_chk` commented out | instantiates the disabled Verilog-A checker |

`checker/bg_checker.va` and `model/readme.txt` are unmodified. The Verilog-A
checker is kept in the tree for reference and for future use with a simulator
that supports it.

To diff against upstream:

```sh
git clone https://github.com/Infineon/adsbenchmark.git
diff -r adsbenchmark/BANDGAP/src .
```

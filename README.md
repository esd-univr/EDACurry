# EDACurry: A Multi-Language Framework to Create, Translate, and Manipulate Transistor-Level Netlists

The Simulation Program with Integrated Circuit
Emphasis (SPICE), introduced in 1973, laid the foundation for
transistor-level netlist representation. Over the decades, numer-
ous SPICE dialects emerged, each tailored to specific needs but
sharing core semantics. This article presents EDACurry, an inno-
vative, open-source framework designed to simplify and automate
the creation, translation, and manipulation of transistor-level
netlists across SPICE-based languages such as Eldo and Spectre.

By leveraging a unified internal Abstract Syntax Tree (AST),
EDACurry bridges syntactical differences while maintaining
semantic consistency, enabling efficient manipulation workflows.
The framework supports custom operations, including design
space exploration, defect model injection, and subcircuit wrap-
ping, all accessible through Python. Demonstrated applications
highlight its versatility in analog design workflows, offering
integration with commercial and open-source simulators. With
EDACurry, analog designers gain a powerful tool to support
netlist manipulation tasks, improving productivity and fostering
innovation in circuit design.

## Project Structure and Files

    .
    ├── grammar/                # Spectre and Eldo grammar.
    ├── sources/                # Netlist manipulator (includes C++ parser).
    ├── LICENSE                       
    └── README.md

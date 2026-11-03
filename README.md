# jellyfish

<center><b><i>"The reasonable man adapts himself to the world: the unreasonable one persists in trying to adapt the world to himself. Therefore all progress depends on the unreasonable man."</i></b></center> <a href="https://de.wikipedia.org/wiki/George_Bernard_Shaw">-George Bernard Shaw</a>

<p align="center">

![Built with](https://img.shields.io/badge/Built%20with-C%2B%2B20-informational?style=flat-square&logo=cplusplus)
![macOS · Windows · Linux](https://img.shields.io/badge/macOS%20%C2%B7%20Windows%20%C2%B7%20Linux-support-blue?style=flat-square)
![License](https://img.shields.io/badge/License-MIT-inactive?style=flat-square)

<br>

![Standard](https://img.shields.io/badge/Standard-j26-inactive?style=flat-square)
![Version](https://img.shields.io/badge/Version-0.1.0-informational?style=flat-square)
</p>

Jellyfish is a lightweight, runtime-based programming language designed for simple distribution and execution. Programs are packaged directly into a standalone runtime executable, eliminating the need to distribute source files and runtime environments separately. Write once, pack once, and distribute as a single executable — no additional installation required.

### The Pitch
Jellyfish is an open-source scipting language designed to produce lightweight, self-contained, and easily distributable executable files. Instead of compiling source code directly into native machine instructions, Jellyfish transforms it into an optimized intermediate payload that is executed by a compact, embedded runtime.

The generated payload can be compressed and encrypted before being embedded into the runtime executable. This allows the entire program, including everything required for execution, to be distributed as a single standalone file without requiring users to install a separate runtime or additional dependencies.

Jellyfish is designed to simplify software distribution, minimize executable size, and provide a fast and lightweight execution environment. By separating the program's compiled payload from its execution runtime, Jellyfish offers an alternative to traditional native compilation while maintaining a straightforward development and deployment workflow.

* Self-contained executables: Package the program and its runtime into a single distributable file.
* Lightweight runtime: Keep the execution environment compact and minimize unnecessary overhead.
* Optimized payload generation: Transform source code into a structured, execution-ready payload.
* Compression: Reduce payload size before embedding it into the final executable.
* Encryption: Optionally protect the generated payload through encryption.
* No external runtime installation: Programs carry their own execution environment.
* Light-weight cli interface: build the entire project directly from the terminal.

### Getting started

### Demo

### How it works

### The Goal

### Releases & Changelogs

### Documentation

### Statistics

### Support & FAQ

### Gallery
*coming soon*

### Credits
Developed by Kian Schmalzl.

### License
The jellyfish project including the language frontend, compressor and runtime are licensed under the MIT License. See [LICENSE.txt](./LICENSE.txt) for more information.

# jellyfish

<center><b><i>"The reasonable man adapts himself to the world: the unreasonable one persists in trying to adapt the world to himself. Therefore all progress depends on the unreasonable man."</i></b></center> <a href="https://de.wikipedia.org/wiki/George_Bernard_Shaw">-George Bernard Shaw</a>

<br>

![Built with](https://img.shields.io/badge/Built%20with-C%2B%2B20-informational?style=flat-square&logo=cplusplus)
![macOS · Windows · Linux](https://img.shields.io/badge/macOS%20%C2%B7%20Windows%20%C2%B7%20Linux-support-blue?style=flat-square)
![License](https://img.shields.io/badge/License-MIT-inactive?style=flat-square)
![status](https://img.shields.io/badge/status-early%20alpha-yellow?style=flat-square)
<br>
![Standard](https://img.shields.io/badge/Standard-j26-inactive?style=flat-square)
![Version](https://img.shields.io/badge/Version-0.1.0-informational?style=flat-square)

**Runtime-based programming language; an open-source language built around a compressor-driven, self-contained execution model.**
Programs are compressed into optimized payloads and embedded directly into a lightweight runtime executable. No separate runtime installation, no external dependencies. Pack once, distribute anywhere.

| [The Pitch](#the-pitch) - [Getting Started](#getting-started) - [How it works](#how-it-works) - [Releases & Changelogs](#releases--changelogs) - [Demo](#demo) - [Getting Started](#getting-started) |
:----------------------------------------------------------: |
| [The Goal](#the-goal) - [Support, FAQ](#support--FAQ) -[Statistics](#statistics) - [Gallery](#gallery) - [Credits](#credits) - [License](#license) |



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
*coming soon*

### Demo
*coming soon*

### How it works
*coming soon*

### The Goal
Also see [todo.txt](./docs/todo.txt) for extra details on WIP features coming in further releases.

### Releases & Changelogs
See [Releases](https://github.com/schmalzl/jellyfish/releases) page (decorated) or [changelogs.txt](./docs/CHANGELOGS.txt) for changelogs. Reading the changelogs is a good way to keep up to date with the things the current compiler has to offer, and maybe will give you ideas of some features that you've been ignoring until now!

### Documentation
The official documentation and syntax guide are available in [docs.md](./docs/docs.md)

### Statistics
*detailed and decorated statistics coming soon*
Also see [statistics.txt](./docs/statistics.txt) for more details and recent test results.

### Support & FAQ
For any questions, bug reports or suggestions on improving jellyfish, open a new issue [here](https://github.com/schmalzl/jellyfish/issues).

### Gallery
*coming soon*

### Credits
Developed by Kian Schmalzl.

### License
The jellyfish project including language frontend, compressor and runtime are licensed under the MIT License. See [LICENSE.txt](./LICENSE.txt) for more information.

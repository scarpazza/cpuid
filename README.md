Yet another CPUID tool
===========================================

<img src="https://raw.githubusercontent.com/scarpazza/cpuid/refs/heads/master/silly-image.jpg" width="500">

This is a semi-toy implementation of a cpuid tool, written to
demonstrate C++26 reflection.



## Main goal of the project

Specifically, the point of this project is to write a reasonably cpuid
implementation in which the layout and labels of fields are given **in
a declarative fashion and in one place only**, then use rely on C++
reflection and the compiler to generate code that extract and
pretty-print the corresponding data.

In other words, reflection allows the creation of self-documenting
bitfield structs that can, at the same time, describe data layout and
be examined programmatically.

The result is, hopefully: shorter, cleaner, more readable code.

Older solutions to this problem have instead relied on the C
preprocessor and its stringification operator.


The two key point where this mechanism is at play is:
- here [for the reflection](https://github.com/scarpazza/cpuid/blob/master/include/cpuid.hpp#L64), and
- here [for the splicing](https://github.com/scarpazza/cpuid/blob/master/include/cpuid.hpp#L88).



## Compiler support

As of July 2025, compiler support for C++26 Reflection is limited to the
  [clang-p2996](https://github.com/bloomberg/clang-p2996/tree/p2996) by Blooomberg.

- To compile this project, you have to roll your own clang-p2996 build locally.
- `Makefile` contains a hacky set of `CXX` and `CXXFLAGS` that work on my installation.
- **MAKE SURE YOU ADAPT** `CXX` and `CXXFLAGS` to your local clang installation details.



## On the quality of this tool

This is not a comprehensive cpuid tool.  If you desire a
full-featured, extensively tested, supported cpuid tool, use [Todd Allen's](https://www.etallen.com/cpuid.html).



## References

- The latest paper on C++ Reflection at the time this project was started is:
  [P2996R12](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2025/p2996r12.html)

- CPUID return value interpretation is based on the
  [CPUID Wikipedia page](https://en.wikipedia.org/wiki/CPUID).

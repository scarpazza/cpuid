- Latest Reflection paper at the time this project is done: [P2996R12](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2025/p2996r12.html)

- Compiler support: as of July 2024, neither GCC nor clang have support for C++26 reflection yet.
  This project uses Bloomberg's clang-p2996 branch for testing.


- Test command lines for clang-p2996
  ```
   /usr/local/bin/clang++ --gcc-toolchain='~/repos/clang-p2996/build-llvm/lib/clang/21'  -isystem /usr/local/include/c++/v1 -isystem '/usr/local/include/x86_64-unknown-linux-gnu/c++/v1'  -freflection-latest --std=c++26 cpuid.cpp -o cpuid
  ```


- refl1
  basic example

- refl2
  static assertion on `is_bit_field`

## Digression on use of AI in this project

I attempted to generate the `cpuid::leaf...` structs with the help of ChatGPT,
and verified the results by hand against [wikipedia](https://en.wikipedia.org/wiki/CPUID).

The accuracy of ChatGPT's results has proven to be very variable.

For example, when asked to generated `cpuid::leaf7_subleaf0::ecx_features` via prompt

> Generate a C bitfield struct definition describing the results left in the ECX
> register by a CPUID invocation of leaf 7 subleaf 0, i.e., an invocation of CPUID
> with EAX equal to 7 and ECX equal to 0.

The results were mostly correct, but had inaccuracies.
- Field `mawau` was erroneously reported by ChatGPT as 6 bits wide (it's 5).
- A spurious reserved field was generated between `kl` and `bus_lock_detect`.
- Fields `fzm` and `pks` were forgotten.

When asked to generate the same for EDX, ChatGPT produced wrong results, producing the following:
```c
typedef union {
    uint32_t raw;
    struct {
        uint32_t reserved0       : 10; /* bits 0–9: reserved */
        uint32_t md_clear        : 1;  /* bit 10: md_clear supported */
        uint32_t reserved1       : 15; /* bits 11–25: reserved */
        uint32_t ibrs_ibpb       : 1;  /* bit 26: ibrs and ibpb supported */
        uint32_t stibp           : 1;  /* bit 27: stibp supported */
        uint32_t l1d_flush       : 1;  /* bit 28: l1d_flush supported */
        uint32_t arch_cap        : 1;  /* bit 29: ia32_arch_capabilities supported */
        uint32_t reserved2       : 1;  /* bit 30: reserved */
        uint32_t ssbd            : 1;  /* bit 31: ssbd supported */
    } bits;
} cpuid_7_0_edx_t;

```

which is quite different from correct.


The following prompt, which was an attempt to generate `cpuid::leaf7_sublead1`

> Go read the wikipedia page on CPUID leaf 7, subleaf 1, i.e., the meaning of the extended features left in registers
> after you invoke the CPUID instruction with EAX = 7 and ECX = 1. Then generate a C language struct definition with
> bitfields corresponding to each field. Generate lower case identifiers. For each field, populate the comment in the
> same way as the wikipedia CPUID page describes the same field. Do not make mistakes.

... also produced a struct definition matching a majority of fields, but with several inaccuracies.

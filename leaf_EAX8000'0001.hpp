// Descriptions of the feature bits and fields returned by CPUID
//
//
// https://en.wikipedia.org/wiki/CPUID#EAX=8000'0001h:_Extended_Processor_Info_and_Feature_Bits

# pragma once

#include <sys/types.h>
namespace cpuid {

  namespace leaf80000001 {
    struct ecx_features {
      uint32_t lahf_lm           : 1;  //  0: load/store ah from/to eflags in long mode
      uint32_t cmp_legacy        : 1;  //  1: Hyperthreading not valid (core-complex id legacy encoding, disables HT detect)
      uint32_t svm               : 1;  //  2: secure virtual machine, AMD-V
      uint32_t extapic           : 1;  //  3: extended APIC space
      uint32_t cr8_legacy        : 1;  //  4: CR8 works in 32‑bit mode
      uint32_t abm               : 1;  //  5: Advanced bit manipulation (LZCNT and POPCNT)
      uint32_t sse4a             : 1;  //  6: SSE4A instruction support)
      uint32_t misalignsse       : 1;  //  7: Misaligned sse mode
      uint32_t has_3dnow_prefetch: 1;  //  8: PREFETCHW instruction
      uint32_t osvw              : 1;  //  9: os visible workaround support
      uint32_t ibs               : 1;  // 10: instruction based sampling
      uint32_t xop               : 1;  // 11: XOP instruction set
      uint32_t skinit            : 1;  // 12: SKINIT and STGI support
      uint32_t wdt               : 1;  // 13: watchdog timer support
      uint32_t reserved_14       : 1;
      uint32_t lwp               : 1;  // 15: lightweight profiling support
      uint32_t fma4              : 1;  // 16: 4-operand fused multiply add
      uint32_t tce               : 1;  // 17: translation cache extension
      uint32_t reserved_18       : 1;
      uint32_t nodeid_msr        : 1;  // 19: nodeid_msr
      uint32_t reserved_20       : 1;
      uint32_t tbm               : 1;  // 21: trailing bit manipulation
      uint32_t topoext           : 1;  // 22: topology extensionstopoext
      uint32_t perfctr_core      : 1;  // 23: Core performance counter extensions
      uint32_t perfctr_nb        : 1;  // 24: Northbridge performance counter extensions
      uint32_t streamperfmon     : 1;  // 25: Streaming performance monitor architecture
      uint32_t dbx               : 1;  // 26: Data breakpoint extensions
      uint32_t perftsc           : 1;  // 27: Performance timestamp counter PTSC
      uint32_t pcx_l2i           : 1;  // 28: L2I perf counter extensions
      uint32_t monitorx          : 1;  // 29: MONITORX and MWAITX instructions
      uint32_t addr_mask_ext     : 1;  // 30: Address mask extension to 32 bits for instruction breakpoint
      uint32_t reserved_31       : 1;
    };
    static_assert( sizeof(ecx_features) == sizeof(uint32_t) );

    struct edx_features {
      // On AMD machines, fields marked with a star are the same as EDX as returned from leaf 1 (EAX=1)
      uint32_t fpu_amd           : 1;  // * 0 Onboard x87 FPU
      uint32_t vme_amd           : 1;  // * 1 Virtual 8086 mode extensions (such as VIF, VIP, PVI)
      uint32_t de_amd            : 1;  // * 2 Debugging extensions (CR4 bit 3)
      uint32_t pse_amd           : 1;  // * 3 Page Size Extension (4 MB pages)
      uint32_t tsc_amd           : 1;  // * 4 Time Stamp Counter and RDTSC instruction
      uint32_t msr_amd           : 1;  // * 5 Model-specific registers and RDMSR/WRMSR instructions
      uint32_t pae_amd           : 1;  // * 6 Physical Address Extension
      uint32_t mce_amd           : 1;  // * 7 Machine Check Exception
      uint32_t cx8_amd           : 1;  // * 8 CMPXCHG8B (compare-and-swap) instruction
      uint32_t apic_amd          : 1;  // * 9 Onboard Advanced Programmable Interrupt Controller
      uint32_t syscall_k6        : 1;  //  10 SYSCALL/SYSRET, K6 only
      uint32_t syscall           : 1;  // *11 SYSCALL and SYSRET instructions
      uint32_t mtrr_amd          : 1;  // *12 Memory Type Range Registers
      uint32_t pge_amd           : 1;  // *13 Page Global Enable bit in CR4
      uint32_t mca_amd           : 1;  // *14 Machine check architecture
      uint32_t cmov_amd          : 1;  // *15 Conditional move: CMOV, FCMOV and FCOMI instructions
      uint32_t pat_amd           : 1;  // *16 Page Attribute Table
      uint32_t pse36_amd         : 1;  // *17 36-bit page size extension
      uint32_t reserved_18       : 1;
      uint32_t exx               : 1;  //  19: Athlon MP, Sempron CPU brand identification
      uint32_t nx                : 1;  //  20 No-execute (NX) bit
      uint32_t reserved_21       : 1;
      uint32_t mmx_ext           : 1;  //  22 Extended MMX instructions
      uint32_t mmx_amd           : 1;  // *23 MMX instructions (64-bit SIMD)
      uint32_t fxsr_amd          : 1;  // *24 FXSAVE, FXRSTOR instructions, CR4 bit 9
      uint32_t fxsr_opt          : 1;  //  25 FXSAVE, FXRSTOR optimizations
      uint32_t pdpe1gb           : 1;  //  26 Gigabyte pages
      uint32_t rdtscp            : 1;  //  27 RDTSCP instruction
      uint32_t reserved_28       : 1;
      uint32_t lm                : 1;  //  29 Long mode
      uint32_t has_3dnow_ext     : 1;  //  30 Extended 3DNow! instructions
      uint32_t has_3dnow         : 1;  //  31 3DNow! instructions
    };
    static_assert( sizeof(edx_features) == sizeof(uint32_t) );
  } // namespace leaf80000001
}; // namespace cpuid

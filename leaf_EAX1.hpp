// Descriptions of the feature bits and fields returned by CPUID
//
//

# pragma once


#include <sys/types.h>
namespace cpuid {

  struct leaf1 {
    struct eax_features {
      uint32_t stepping        : 4;
      uint32_t model           : 4;
      uint32_t family          : 4;
      uint32_t proc_type       : 2;
      uint32_t reserved_14_15  : 2;
      uint32_t extended_model  : 4;
      uint32_t extended_family : 8;
      uint32_t reserved_28_31  : 4;
    };
    static_assert( sizeof(eax_features) == sizeof(uint32_t) );
    // keep using uint32_t for extended_family; if you declare a uint8 bitfield that happens to have size 8 (bits),
    // it will be aligned and the struct won't be packed

    struct ebx_features {
      uint8_t brand_index      ;
      uint8_t clflush_line     ; // (Value * 8 = cache line size in bytes) -- if CLFLUSH feature flag is set;
      uint8_t max_logical_id   ; // maximum number of addressable IDs for logical processors in this physical package - if htt is set
      uint8_t apic_id          ; // local apic id
    };
    static_assert( sizeof(ebx_features) == sizeof(uint32_t) );

    struct ecx_features {
      uint32_t sse3          : 1;  //  0
      uint32_t pclmulqdq     : 1;  //  1
      uint32_t dtes64        : 1;  //  2
      uint32_t monitor       : 1;  //  3 -- MONITOR and MWAIT instructions (PNI)
      uint32_t ds_cpl        : 1;  //  4
      uint32_t vmx           : 1;  //  5 -- Virtual Machine Extensions
      uint32_t smx           : 1;  //  6 -- Safer Mode Extensions GETSEC instruction
      uint32_t est           : 1;  //  7 -- Enhanced SpeedStep
      uint32_t tm2           : 1;  //  8 -- Thermal Monitor 2
      uint32_t ssse3         : 1;  //  9 -- Supplemental SSE3
      uint32_t cnxt_id       : 1;  // 10 -- L1 Context ID
      uint32_t sdbg          : 1;  // 11 -- Silicon Debug Interface
      uint32_t fma           : 1;  // 12
      uint32_t cmpxchg16b    : 1;  // 13 -- CMPXCHG16B instruction
      uint32_t xtpr          : 1;  // 14 -- able to disable sending task priority messages
      uint32_t pdcm          : 1;  // 15 -- perfmon and debug
      uint32_t reserved_1    : 1;  // 16
      uint32_t pcid          : 1;  // 17
      uint32_t dca           : 1;  // 18
      uint32_t sse4_1        : 1;  // 19
      uint32_t sse4_2        : 1;  // 20
      uint32_t x2apic        : 1;  // 21
      uint32_t movbe         : 1;  // 22
      uint32_t popcnt        : 1;  // 23
      uint32_t tsc_deadline  : 1;  // 24
      uint32_t aes_ni        : 1;  // 25
      uint32_t xsave         : 1;  // 26 -- XSAVE, XRSTOR, XSETBV, XGETBV instructions
      uint32_t osxsave       : 1;  // 27 -- XSAVE enabled by the OS
      uint32_t avx           : 1;  // 28 -- AVX 256-bit SIMD instructions
      uint32_t f16c          : 1;  // 29
      uint32_t rdrnd         : 1;  // 30
      uint32_t hypervisor    : 1;  // 31 -- hypervisor present - always zero on physical CPUs
    };
    static_assert( sizeof(ecx_features) == sizeof(uint32_t) );

    struct edx_features {
      uint32_t fpu           : 1;  //  0 Onboard x87 FPU
      uint32_t vme           : 1;  //  1 Virtual 8086 mode extensions (such as VIF, VIP, PVI)
      uint32_t de            : 1;  //  2 Debugging extensions (CR4 bit 3)
      uint32_t pse           : 1;  //  3 Page Size Extension (4 MB pages)
      uint32_t tsc           : 1;  //  4 Time Stamp Counter and RDTSC instruction
      uint32_t msr           : 1;  //  5 Model-specific registers and RDMSR/WRMSR instructions
      uint32_t pae           : 1;  //  6 Physical Address Extension
      uint32_t mce           : 1;  //  7 Machine Check Exception
      uint32_t cx8           : 1;  //  8 CMPXCHG8B (compare-and-swap) instruction
      uint32_t apic          : 1;  //  9 Onboard Advanced Programmable Interrupt Controller
      uint32_t mtrr_reserved : 1;  // 10 (mtrr)
      uint32_t sep           : 1;  // 11 SYSENTER and SYSEXIT fast system call instructions
      uint32_t mtrr          : 1;  // 12 Memory Type Range Registers[f]
      uint32_t pge           : 1;  // 13 Page Global Enable bit in CR4
      uint32_t mca           : 1;  // 14 Machine check architecture
      uint32_t cmov          : 1;  // 15 Conditional move: CMOV, FCMOV and FCOMI instructions
      uint32_t pat           : 1;  // 16 Page Attribute Table
      uint32_t pse36         : 1;  // 17 36-bit page size extension
      uint32_t psn           : 1;  // 18 Processor Serial Number supported and enabled
      uint32_t clfsh         : 1;  // 19 CLFLUSH cache line flush instruction (SSE2)
      uint32_t nx            : 1;  // 20 No-execute (NX) bit (Itanium only, reserved on other CPUs)
      uint32_t ds            : 1;  // 21 Debug store: save trace of executed jumps
      uint32_t acpi          : 1;  // 22 Onboard thermal control MSRs for ACPI
      uint32_t mmx           : 1;  // 23 MMX instructions (64-bit SIMD)
      uint32_t fxsr          : 1;  // 24 FXSAVE, FXRSTOR instructions, CR4 bit 9
      uint32_t sse           : 1;  // 25 Streaming SIMD Extensions (SSE) instructions
      uint32_t sse2          : 1;  // 26 SSE2 instructions
      uint32_t ss            : 1;  // 27 CPU cache implements self-snoop
      uint32_t htt           : 1;  // 28 Max APIC IDs reserved field is Valid[l]
      uint32_t tm            : 1;  // 29 Thermal monitor automatically limits temperature
      uint32_t ia64          : 1;  // 30 IA64 processor emulating x86[66]
      uint32_t pbe           : 1;  // 31 Pending Break Enable (PBE# pin) wakeup capability
    };
    static_assert( sizeof(edx_features) == sizeof(uint32_t) );
  }; // struct leaf1
}; // namespace cpuid

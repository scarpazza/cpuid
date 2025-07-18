// Descriptions of the feature bits and fields returned by CPUID
//
//

#pragma once

#include <sys/types.h>
namespace cpuid {

  namespace leaf7_subleaf0 {
    struct eax_features {
      u_int32_t max_subleaf;
    };
    struct ebx_features {
      uint32_t fsgsbase            :1; // Access to base of %fs and %gs
      uint32_t ia32_tsc_adjust_msr :1; // IA32_TSC_ADJUST MSR
      uint32_t sgx                 :1; // Software Guard Extensions
      uint32_t bmi1                :1; // Bit Manipulation Instruction Set 1
      uint32_t hle                 :1; // TSX Hardware Lock Elision
      uint32_t avx2                :1; // Advanced Vector Extensions 2
      uint32_t fdp_excptn_only     :1; // x87 FPU data pointer register updated on exceptions only
      uint32_t smep                :1; // Supervisor Mode Execution Prevention
      uint32_t bmi2                :1; // Bit Manipulation Instruction Set 2
      uint32_t erms                :1; // Enhanced REP MOVSB/STOSB
      uint32_t invpcid             :1; // INVPCID instruction
      uint32_t rtm                 :1; // TSX Restricted Transactional Memory
      uint32_t rdtm_pqm            :1; // Intel Resource Director (RDT) Monitoring or AMD Platform QOS Monitoring
      uint32_t x87_fpu_cs_ds_depr  :1; // x87 FPU CS and DS deprecated
      uint32_t mpx                 :1; // Intel MPX (Memory Protection Extensions)
      uint32_t rdta_pqe            :1; // Intel Resource Director (RDT) Allocation or AMD Platform QOS Enforcement
      uint32_t avx512_f            :1; // AVX-512 Foundation
      uint32_t avx512_dq           :1; // AVX-512 Doubleword and Quadword Instructions
      uint32_t rdseed              :1; // RDSEED instruction
      uint32_t adx                 :1; // Intel ADX (Multi-Precision Add-Carry Instruction Extensions)
      uint32_t smap                :1; // Supervisor Mode Access Prevention
      uint32_t avx512_ifma         :1; // AVX-512 Integer Fused Multiply-Add Instructions
      uint32_t pcommit             :1; // (PCOMMIT instruction, deprecated)
      uint32_t clflushopt          :1; // CLFLUSHOPT instruction
      uint32_t clwb                :1; // CLWB (Cache line writeback) instruction
      uint32_t pt                  :1; // Intel Processor Trace
      uint32_t avx512_pf           :1; // AVX-512 Prefetch Instructions (mprr)[a]
      uint32_t avx512_er           :1; // AVX-512 Exponential and Reciprocal Instructions
      uint32_t avx512_cd           :1; // AVX-512 Conflict Detection Instructions
      uint32_t sha                 :1; // SHA-1 and SHA-256 extensions
      uint32_t avx512_bw           :1; // AVX-512 Byte and Word Instructions
      uint32_t avx512_vl           :1; // AVX-512 Vector Length Extensions

    };

    struct ecx_features {
      uint32_t prefetchwt1       : 1;  // bit 0: supports prefetchwt1 instruction
      uint32_t avx512_vbmi       : 1;  // bit 1: avx-512 vector bit manipulation instructions
      uint32_t umip              : 1;  // bit 2: user-mode instruction prevention
      uint32_t pku               : 1;  // bit 3: protection keys for user-mode pages
      uint32_t ospke             : 1;  // bit 4: os has set cr4.pke to enable pku
      uint32_t waitpkg           : 1;  // bit 5: timed pause and user-level monitor/wait
      uint32_t avx512_vbmi2      : 1;  // bit 6: avx-512 vbmi2
      uint32_t cetss_shstk       : 1;  // bit 7: cet supervisor shadow stack
      uint32_t gfni              : 1;  // bit 8: galois field new instructions
      uint32_t vaes              : 1;  // bit 9: vector aes
      uint32_t vpclmulqdq        : 1;  // bit 10: vector carry-less multiply
      uint32_t avx512_vnni       : 1;  // bit 11: avx-512 vector neural network instructions
      uint32_t avx512_bitalg     : 1;  // bit 12: avx-512 bitalg instructions
      uint32_t tme_en            : 1;  // bit 13: total memory encryption
      uint32_t avx512_vpopcntdq  : 1;  // bit 14: avx-512 vector popcnt for d/q
      uint32_t fzm               : 1;  // bit 15: listed only in Intel TDX documentation and not set in any known processor.
      uint32_t la57              : 1;  // bit 16: 5-level paging
      uint32_t mawau             : 5;  // bits 17–21: The value of userspace MPX Address-Width Adjust used by the BNDLDX and BNDSTX Intel MPX instructions in 64-bit mode
      uint32_t rdpid             : 1;  // bit 22: read processor id (rdpid) instruction
      uint32_t kl                : 1;  // bit 23: key locker
      uint32_t bus_lock_detect   : 1;  // bit 24: bus lock detection
      uint32_t cldemote          : 1;  // bit 25: cache line demote
      uint32_t mprr_reserved     : 1;  // bit 26: listed only in Intel TDX documentation and not set in any known processor.
      uint32_t movdiri           : 1;  // bit 27: MOVDIRI move direct instruction
      uint32_t movdir64b         : 1;  // bit 28: move 64 bytes direct instruction
      uint32_t enqcmd            : 1;  // bit 29: enqueue stores and EMQCMD/EMQCMDS instructions
      uint32_t sgx_lc            : 1;  // bit 30: sgx launch configuration
      uint32_t pks               : 1;  // bit 31: protection keys for supervisor-mode pages

    };

    struct edx_features {
      uint32_t sgx_tem                    : 1; // bit  0: sgx-tem (sgx transactional memory)
      uint32_t sgx_keys                   : 1; // bit  1: sgx-keys (sgx attestation key IDs)
      uint32_t avx512_4vnniw              : 1; // bit  2: avx512-4vnniw (AVX‑512 4-register neural net instr.)
      uint32_t avx512_4fmaps              : 1; // bit  3: avx512-4fmaps (AVX‑512 4‑register multiply-accum SP)
      uint32_t fsrm                       : 1; // bit  4: fast short REP MOVSB
      uint32_t uintr                      : 1; // bit  5: user Inter-processor interrupts
      uint32_t reserved_6_7               : 2; // bits 6-7: reserved
      uint32_t md_clear                   : 1; // bit 10: VERW instruction clears CPU buffers
      uint32_t rtm_always_abort           : 1; // bit 11: All TSX transactions are aborted
      uint32_t reserved_12                : 1; // bit 12: reserved
      uint32_t rtm_force_abort            : 1; // bit 13: TSX_FORCE_ABORT (MSR 0x10f) is available
      uint32_t serialize                  : 1; // bit 14: SERIALIZE instruction
      uint32_t hybrid                     : 1; // bit 15: Mixture of CPU types in processor topology (e.g. Alder Lake)
      uint32_t tsxldtrk                   : 1; // bit 16: TSX load address tracking suspend/resume instructions (TSUSLDTRK and TRESLDTRK)
      uint32_t reserved_17                : 1; // bit 17: reserved
      uint32_t pconfig                    : 1; // bit 18: Platform configuration (Memory Encryption Technologies Instructions)
      uint32_t lbr                        : 1; // bit 19: Architectural Last Branch Records
      uint32_t cet_ibt                    : 1; // bit 20: Control flow enforcement (CET): indirect branch tracking
      uint32_t reserved_21                : 1; // bit 21: reserved
      uint32_t amx_bf16                   : 1; // bit 22: AMX tile computation on bfloat16 numbers
      uint32_t avx512_fp16                : 1; // bit 23: AVX-512 half-precision floating-point arithmetic instructions[110]
      uint32_t amx_tile                   : 1; // bit 24: AMX tile load/store instructions
      uint32_t amx_int8                   : 1; // bit 25: AMX tile computation on 8-bit integers
      uint32_t ibrs_spec_ctrl             : 1; // bit 26: Speculation Control, part of Indirect Branch Control (IBC)
      uint32_t stibp                      : 1; // bit 27: Single Thread Indirect Branch Predictor, part of IBC
      uint32_t l1d_flush                  : 1; // bit 28: IA32_FLUSH_CMD MSR
      uint32_t ia32_arch_capabilities_msr : 1; // bit 29: IA32_ARCH_CAPABILITIES MSR (lists speculative side channel mitigations)
      uint32_t ia32_core_capabilities_msr : 1; // bit 30: IA32_CORE_CAPABILITIES MSR (lists model-specific core capabilities)
      uint32_t ssbd                       : 1; // bit 31: speculative store bypass Disable, as mitigation for Speculative Store Bypass (IA32_SPEC_CTRL)

    };
  } // namespace leaf1
}; // namespace cpuid

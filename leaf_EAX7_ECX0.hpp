// Descriptions of the feature bits and fields returned by CPUID
//
//

#include <sys/types.h>
namespace cpuid {

  namespace leaf7_subleaf0 {
    struct ebx_features {
      uint8_t fsgsbase            :1; // Access to base of %fs and %gs
      uint8_t ia32_tsc_adjust_msr :1; // IA32_TSC_ADJUST MSR
      uint8_t sgx	          :1; // Software Guard Extensions
      uint8_t bmi1	          :1; // Bit Manipulation Instruction Set 1
      uint8_t hle	          :1; // TSX Hardware Lock Elision
      uint8_t avx2	          :1; // Advanced Vector Extensions 2
      uint8_t fdp_excptn_only	  :1; // x87 FPU data pointer register updated on exceptions only
      uint8_t smep	          :1; // Supervisor Mode Execution Prevention
      uint8_t bmi2	          :1; // Bit Manipulation Instruction Set 2
      uint8_t erms	          :1; // Enhanced REP MOVSB/STOSB
      uint8_t invpcid	          :1; // INVPCID instruction
      uint8_t rtm	          :1; // TSX Restricted Transactional Memory
      uint8_t rdtm_pqm	          :1; // Intel Resource Director (RDT) Monitoring or AMD Platform QOS Monitoring
      uint8_t x87_fpu_cs_ds_depr  :1; // x87 FPU CS and DS deprecated
      uint8_t mpx	          :1; // Intel MPX (Memory Protection Extensions)
      uint8_t rdta_pqe	          :1; // Intel Resource Director (RDT) Allocation or AMD Platform QOS Enforcement
      uint8_t avx512_f	          :1; // AVX-512 Foundation
      uint8_t avx512_dq	          :1; // AVX-512 Doubleword and Quadword Instructions
      uint8_t rdseed	          :1; // RDSEED instruction
      uint8_t adx	          :1; // Intel ADX (Multi-Precision Add-Carry Instruction Extensions)
      uint8_t smap	          :1; // Supervisor Mode Access Prevention
      uint8_t avx512_ifma	  :1; // AVX-512 Integer Fused Multiply-Add Instructions
      uint8_t pcommit             :1; // (PCOMMIT instruction, deprecated)
      uint8_t clflushopt	  :1; // CLFLUSHOPT instruction
      uint8_t clwb                :1; // CLWB (Cache line writeback) instruction
      uint8_t pt	          :1; // Intel Processor Trace
      uint8_t avx512_pf	          :1; // AVX-512 Prefetch Instructions	(mprr)[a]
      uint8_t avx512_er	          :1; // AVX-512 Exponential and Reciprocal Instructions
      uint8_t avx512_cd	          :1; // AVX-512 Conflict Detection Instructions
      uint8_t sha	          :1; // SHA-1 and SHA-256 extensions
      uint8_t avx512_bw	          :1; // AVX-512 Byte and Word Instructions
      uint8_t avx512_vl           :1; // AVX-512 Vector Length Extensions

    };

    struct ecx_features {
      uint8_t prefetchwt1       : 1;  // bit 0: supports prefetchwt1 instruction
      uint8_t avx512_vbmi       : 1;  // bit 1: avx-512 vector bit manipulation instructions
      uint8_t umip              : 1;  // bit 2: user-mode instruction prevention
      uint8_t pku               : 1;  // bit 3: protection keys for user-mode pages
      uint8_t ospke             : 1;  // bit 4: os has set cr4.pke to enable pku
      uint8_t waitpkg           : 1;  // bit 5: timed pause and user-level monitor/wait
      uint8_t avx512_vbmi2      : 1;  // bit 6: avx-512 vbmi2
      uint8_t cetss_shstk       : 1;  // bit 7: cet supervisor shadow stack
      uint8_t gfni              : 1;  // bit 8: galois field new instructions
      uint8_t vaes              : 1;  // bit 9: vector aes
      uint8_t vpclmulqdq        : 1;  // bit 10: vector carry-less multiply
      uint8_t avx512_vnni       : 1;  // bit 11: avx-512 vector neural network instructions
      uint8_t avx512_bitalg     : 1;  // bit 12: avx-512 bitalg instructions
      uint8_t tme_en            : 1;  // bit 13: total memory encryption
      uint8_t avx512_vpopcntdq  : 1;  // bit 14: avx-512 vector popcnt for d/q
      uint8_t fzm               : 1;  // bit 15: listed only in Intel TDX documentation and not set in any known processor.
      uint8_t la57              : 1;  // bit 16: 5-level paging
      uint8_t mawau             : 5;  // bits 17–21: The value of userspace MPX Address-Width Adjust used by the BNDLDX and BNDSTX Intel MPX instructions in 64-bit mode
      uint8_t rdpid             : 1;  // bit 22: read processor id (rdpid) instruction
      uint8_t kl                : 1;  // bit 23: key locker
      uint8_t bus_lock_detect   : 1;  // bit 24: bus lock detection
      uint8_t cldemote          : 1;  // bit 25: cache line demote
      uint8_t mprr_reserved     : 1;  // bit 26: listed only in Intel TDX documentation and not set in any known processor.
      uint8_t movdiri           : 1;  // bit 27: MOVDIRI move direct instruction
      uint8_t movdir64b         : 1;  // bit 28: move 64 bytes direct instruction
      uint8_t enqcmd            : 1;  // bit 29: enqueue stores and EMQCMD/EMQCMDS instructions
      uint8_t sgx_lc            : 1;  // bit 30: sgx launch configuration
      uint8_t pks               : 1;  // bit 31: protection keys for supervisor-mode pages

    };

    struct edx_features {
      uint8_t sgx_tem       : 1;  // bit 0: sgx-tem (sgx transactional memory)
      uint8_t sgx_keys      : 1;  // bit 1: sgx-keys (sgx attestation key IDs)
      uint8_t avx512_4vnniw : 1;  // bit 2: avx512-4vnniw (AVX‑512 4-register neural net instr.)
      uint8_t avx512_4fmaps : 1;  // bit 3: avx512-4fmaps (AVX‑512 4‑register multiply-accum SP)
      uint8_t fsrm          : 1;  // bit 4: fast short REP MOVSB
      uint8_t uintr         : 1;  // bit 5: user Inter-processor interrupts
      uint8_t reserved_6_7  : 2;  // bits 6-7: reserved
      uint8_t md_clear                   : 1; // 10 VERW instruction clears CPU buffers
      uint8_t rtm_always_abort           : 1; // 11 All TSX transactions are aborted
      uint8_t reserved_12                : 1; // 12 reserved
      uint8_t rtm_force_abort            : 1; // 13 TSX_FORCE_ABORT (MSR 0x10f) is available
      uint8_t serialize	                 : 1; // 14 SERIALIZE instruction
      uint8_t hybrid	                 : 1; // 15 Mixture of CPU types in processor topology (e.g. Alder Lake)
      uint8_t tsxldtrk	                 : 1; // 16 TSX load address tracking suspend/resume instructions (TSUSLDTRK and TRESLDTRK)

      uint8_t reserved_17                : 1; // 17 reserved
      uint8_t pconfig	                 : 1; // 18 Platform configuration (Memory Encryption Technologies Instructions)
      uint8_t lbr	                 : 1; // 19 Architectural Last Branch Records
      uint8_t cet_ibt	                 : 1; // 20 Control flow enforcement (CET): indirect branch tracking
      uint8_t reserved_21                : 1; // 21 reserved
      uint8_t amx_bf16	                 : 1; // 22 AMX tile computation on bfloat16 numbers
      uint8_t avx512_fp16                : 1; // 23 AVX-512 half-precision floating-point arithmetic instructions[110]
      uint8_t amx_tile	                 : 1; // 24 AMX tile load/store instructions
      uint8_t amx_int8	                 : 1; // 25 AMX tile computation on 8-bit integers
      uint8_t ibrs_spec_ctrl             : 1; // 26 Speculation Control, part of Indirect Branch Control (IBC)
      uint8_t stibp	                 : 1; // 27 Single Thread Indirect Branch Predictor, part of IBC
      uint8_t l1d_flush                  : 1; // 28 IA32_FLUSH_CMD MSR
      uint8_t ia32_arch_capabilities_msr : 1; // 29: IA32_ARCH_CAPABILITIES MSR (lists speculative side channel mitigations)
      uint8_t ia32_core_capabilities_msr : 1; // 30: IA32_CORE_CAPABILITIES MSR (lists model-specific core capabilities)
      uint8_t ssbd                       : 1; // 31: speculative store bypass Disable, as mitigation for Speculative Store Bypass (IA32_SPEC_CTRL)

    };
  } // namespace leaf1
}; // namespace cpuid


/*

0	fsgsbase Access to base of %fs and %gs	prefetchwt1	PREFETCHWT1 instruction	(sgx-tem)[a]	?	0
1	ia32_tsc_adjust_msr 	 IA32_TSC_ADJUST MSR	avx512-vbmi	AVX-512 Vector Bit Manipulation Instructions	sgx-keys	Attestation Services for Intel SGX	1
2	sgx	 Software Guard Extensions	umip	User-mode Instruction Prevention	avx512-4vnniw	AVX-512 4-register Neural Network Instructions	2
3	bmi1	 Bit Manipulation Instruction Set 1	pku	Memory Protection Keys for User-mode pages	avx512-4fmaps	AVX-512 4-register Multiply Accumulation Single precision	3
4	hle	 TSX Hardware Lock Elision	ospke	PKU enabled by OS	fsrm	Fast Short REP MOVSB	4
5	avx2	 Advanced Vector Extensions 2	waitpkg	Timed pause and user-level monitor/wait instructions (TPAUSE, UMONITOR, UMWAIT)	uintr	User Inter-processor Interrupts	5
6	fdp-excptn-only	x87 FPU data pointer register updated on exceptions only	avx512-vbmi2	AVX-512 Vector Bit Manipulation Instructions 2	(reserved)	6
7	smep	Supervisor Mode Execution Prevention	cet_ss/shstk	Control flow enforcement (CET): shadow stack (SHSTK alternative name)	(reserved)	7
8	bmi2	Bit Manipulation Instruction Set 2	gfni	Galois Field instructions	avx512-vp2intersect	AVX-512 vector intersection instructions on 32/64-bit integers	8
9	erms	Enhanced REP MOVSB/STOSB	vaes	Vector AES instruction set (VEX-256/EVEX)	srbds-ctrl	Special Register Buffer Data Sampling Mitigations	9
10	invpcid	INVPCID instruction	vpclmulqdq	CLMUL instruction set (VEX-256/EVEX)
11	rtm	TSX Restricted Transactional Memory	avx512-vnni	AVX-512 Vector Neural Network Instructions
12	rdt-m/pqm	Intel Resource Director (RDT) Monitoring or AMD Platform QOS Monitoring	avx512-bitalg	AVX-512 BITALG instructions	(reserved)	12
13	x87 FPU_CS_DS_deprecated 	x87 FPU CS and DS deprecated	tme_en	Total Memory Encryption MSRs available
14	mpx	Intel MPX (Memory Protection Extensions)	avx512-vpopcntdq	AVX-512 Vector Population Count Double and Quad-word
15	rdt-a/pqe	Intel Resource Director (RDT) Allocation or AMD Platform QOS Enforcement	(fzm)[a]	?
16	avx512-f	AVX-512 Foundation	la57	5-level paging (57 address bits)
31	avx512-vl	AVX-512 Vector Length Extensions	pks	Protection keys for supervisor-mode pages
*/

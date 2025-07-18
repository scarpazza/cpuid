// Descriptions of the feature bits and fields returned by CPUID
//

# pragma once

#include <sys/types.h>
namespace cpuid {

  struct leaf7_subleaf1 {
    struct eax_features {
      uint32_t sha512                        : 1;  // bit 0: sha‑512 extensions
      uint32_t sm3                           : 1;  // bit 1: sm3 hash extensions
      uint32_t sm4                           : 1;  // bit 2: sm4 cipher extensions
      uint32_t rao_int                       : 1;  // bit 3: rao‑int (remote atomic on integers)
      uint32_t avx_vnni                      : 1;  // bit 4: avx‑vnni
      uint32_t avx512_bf16                   : 1;  // bit 5: avx‑512‑bf16
      uint32_t lass                          : 1;  // bit 6: lass (linear address space separation)
      uint32_t cmpccxadd                     : 1;  // bit 7: cmpccxadd instructions
      uint32_t archperf_monext               : 1;  // bit 8: archperfmonext (architectural performance monitor ext)
      uint32_t dedup                         : 1;  // bit 9: dedup - the DEDUP bit is listed only in Intel TDX documentation and is not set in any known processor.
      uint32_t fzrm                          : 1;  // bit 10: fast zero‑length REP MOVSB
      uint32_t fsrs                          : 1;  // bit 11: fast short REP CMPSB and REP SCASB
      uint32_t rsrcs                         : 1;  // bit 12: Fast short REP CMPSB and REP SCASB
      uint32_t reserved_13_16                : 4;  // bit 13-16: reserved
      uint32_t fred                          : 1;  // bit 17: fred (flexible return/event delivery)
      uint32_t lkgs                          : 1;  // bit 18: lkgs (LKGS instruction)
      uint32_t wrmsrns                       : 1;  // bit 19: wrmsrns (WRMSRNS instruction)
      uint32_t nmi_src                       : 1;  // bit 20: nmi_src (NMI source reporting)
      uint32_t amx_fp16                      : 1;  // bit 21: amx‑fp16 (AMX FP16 instructions)
      uint32_t hreset                        : 1;  // bit 22: hreset (HRESET instruction)
      uint32_t avx_ifma                      : 1;  // bit 23: avx‑ifma (AVX IFMA instructions)
      uint32_t reserved_24_25                : 2;  // bits 24-25
      uint32_t lam                           : 1;  // bit 26: linear address masking
      uint32_t msrlist                       : 1;  // bit 27: RDMSRLIST/WRMSRLIST instructions
      uint32_t reserved_28_29                : 2;  // bits 28-29
      uint32_t invd_disable_post_bios_done   : 1;  // bit 30: invd_disable_post_bios_done
      uint32_t movrs                         : 1;  // bit 31: MOVRS (MOVRS/PREFETCHRST2 instructions)
    };
    struct ebx_features {
      uint32_t placeholder;
    };

    struct ecx_features {
      uint32_t placeholder;
    };

    struct edx_features {
      uint32_t placeholder;
    };

    static_assert( sizeof(eax_features) == sizeof(uint32_t) );
    static_assert( sizeof(ebx_features) == sizeof(uint32_t) );
    static_assert( sizeof(ecx_features) == sizeof(uint32_t) );
    static_assert( sizeof(edx_features) == sizeof(uint32_t) );

  }; // struct leaf7_subleaf1
}; // namespace cpuid

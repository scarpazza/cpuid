// Descriptions of the feature bits and fields returned by CPUID
//
// https:// en.wikipedia.org/wiki/CPUID#EAX=8000'0005h:_L1_Cache_and_TLB_Identifiers

#pragma once

#include <sys/types.h>
namespace cpuid {

  struct leaf80000005 {

    struct eax_features {
      uint8_t L1_huge_TLB_instr_entries;
      uint8_t L1_huge_TLB_associativity;
      uint8_t L1_huge_TLB_data_entries;
      uint8_t L1_huge_TLB_data_associativity;
    };
    static_assert( sizeof(eax_features) == sizeof(uint32_t) );

    struct ebx_features {
      uint8_t L1_small_TLB_instr_entries;
      uint8_t L1_small_TLB_associativity;
      uint8_t L1_small_TLB_data_entries;
      uint8_t L1_small_TLB_data_associativity;
    };
    static_assert( sizeof(ebx_features) == sizeof(uint32_t) );

    struct ecx_features {
      uint8_t L1D_line_size_bytes;
      uint8_t L1D_lines_per_tag;
      uint8_t L1D_associativity;
      uint8_t L1D_cache_size_kb;
    };
    static_assert( sizeof(ecx_features) == sizeof(uint32_t) );

    struct edx_features {
      uint8_t L1I_line_size_bytes;
      uint8_t L1I_lines_per_tag;
      uint8_t L1I_associativity;
      uint8_t L1I_cache_size_kb;
    };
    static_assert( sizeof(edx_features) == sizeof(uint32_t) );

  }; // struct leaf80000005
}; // namespace cpuid

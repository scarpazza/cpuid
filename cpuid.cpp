// Daniele Scarpazza - 2025
//
// Free code
//
// Code written outside of any affiliation with any employer or organization.
//


#include <experimental/meta> // compile-time reflection metafunctions, like members_of()
#include <iostream>
#include <iomanip>
#include <tuple>
#include <sys/types.h>

#include "leaf_EAX1.hpp"
#include "leaf_EAX7_ECX0.hpp"
#include "cpuid.hpp"



template <typename RS>
union SchizoReg32 {
  uint32_t  as_int;
  RS        as_struct;
  static_assert (sizeof(RS) == sizeof(uint32_t), "Size of RS should match 32-bit register size (==4 bytes)");
};


const auto query_leaf(const uint32_t leaf,
		      const uint32_t subleaf=0) {
  uint32_t eax = leaf,
    ebx,
    ecx = subleaf,
    edx;
  __asm__ volatile("cpuid"
		   : "+a"(eax), "=b"(ebx), "+c"(ecx), "=d"(edx)  // out
		     // the "a","b","c","d", modifiers come from x86 family-config/i386/constraints.md
		   : // input - nothing more than eax. already listed
		   : // clobbers - nothing more than those already listed
		   );
  return std::make_tuple( eax, ebx, ecx, edx );
}




int main() {

  std::cout << "Leaf 1:" << std::endl;
  {
    const auto [eax, ebx, ecx, edx]  = query_leaf(1);

    const SchizoReg32< cpuid::leaf1::eax_features > r_eax{eax};
    const SchizoReg32< cpuid::leaf1::ebx_features > r_ebx{ebx};
    const SchizoReg32< cpuid::leaf1::ecx_features > r_ecx{ecx};
    const SchizoReg32< cpuid::leaf1::edx_features > r_edx{edx};

    cpuid::enumerate_fields( r_eax.as_struct );
    cpuid::enumerate_fields( r_ebx.as_struct );
    cpuid::enumerate_fields( r_ecx.as_struct );
    cpuid::enumerate_fields( r_edx.as_struct );
  }


  std::cout << "Leaf 7, subleaf 0:" << std::endl;
  {
    const auto [eax, ebx, ecx, edx]  = query_leaf(7,0);

    const SchizoReg32< cpuid::leaf7_subleaf0::ebx_features > r_ebx{ebx};
    const SchizoReg32< cpuid::leaf7_subleaf0::ecx_features > r_ecx{ecx};
    const SchizoReg32< cpuid::leaf7_subleaf0::edx_features > r_edx{edx};

    cpuid::enumerate_fields( r_ebx.as_struct );
    cpuid::enumerate_fields( r_ecx.as_struct );
    cpuid::enumerate_fields( r_edx.as_struct );
  }
  
  return 0;
}

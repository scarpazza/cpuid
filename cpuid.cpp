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
#include "cpuid.hpp"



template <typename RS>
union SchizoReg32 {
  uint32_t  as_int;
  RS        as_struct;
  // static assert or constrain so that size is the same
};


const auto query_leaf(const uint32_t leaf) {
  uint32_t eax = leaf, ebx, ecx, edx;
  __asm__ volatile("cpuid"
		   : "+a"(eax), "=b"(ebx), "=c"(ecx), "=d"(edx)  // out
		     // the "a","b","c","d", modifiers come from x86 family-config/i386/constraints.md
		   : // input - nothing more than eax. already listed
		   : // clobbers - nothing more than those already listed
		   );
  return std::make_tuple( eax, ebx, ecx, edx );
}




int main() {

  //std::cout << "Max eax=" << eax << std::endl;

  std::cout << "Leaf 1:" << std::endl;
  {
    const auto [eax, ebx, ecx, edx]  = query_leaf(1);

    const SchizoReg32< cpuid::leaf1::ecx_features > r_ecx{ecx};
    const SchizoReg32< cpuid::leaf1::edx_features > r_edx{edx};

    cpuid::enumerate_fields( r_ecx.as_struct );
    cpuid::enumerate_fields( r_edx.as_struct );
  }

  return 0;
}

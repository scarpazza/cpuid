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
#include <optional>
#include <string>
#include <sys/types.h>

#include "leaf_EAX1.hpp"
#include "leaf_EAX8000'0001.hpp"
#include "leaf_EAX7_ECX0.hpp"
#include "leaf_EAX7_ECX1.hpp"

#include "cpuid.hpp"




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
  using namespace cpuid;

  // declaring optional as a guarantee I won't use these values before they are initialized
  std::optional<uint32_t> max_leaf;
  std::optional<uint32_t> max_ext_leaf;
  std::optional<uint32_t> max_leaf7_subleaf;

  std::cout << "Leaf 0:" << std::endl;
  {
    const auto [eax, ebx, ecx, edx]  = query_leaf(0);

    max_leaf = eax;
    std::cout << "Max EAX leaf: " << max_leaf.value() << std::endl;

    const SchizoReg32< void > r_ebx{ebx};
    const SchizoReg32< void > r_ecx{ecx};
    const SchizoReg32< void > r_edx{edx};

    std::string manufacturer =
      std::string( r_ebx.as_str4, 4) +
      std::string( r_edx.as_str4, 4) +
      std::string( r_ecx.as_str4, 4); // yes, it's EBX, EDX and then ECX

    std::cout << "Manufacturer: '" << manufacturer << "'" << std::endl;
  }

  std::cout << "Extended leaf 0 (EAX = 0x8000'0000):" << std::endl;
  {
    const auto [eax, ebx, ecx, edx]  = query_leaf(0x8000'0000);

    max_ext_leaf = eax;
    std::cout << "Max EAX extended leaf: 0x" << std::hex << max_ext_leaf.value()
	      << std::dec
	      << std::endl;
  }


  std::cout << "Hypervisor Leaf 0 (0x4000'0000):" << std::endl;
  {
    const auto [eax, ebx, ecx, edx]  = query_leaf(0x4000'0000);

    if ( eax != 0x4000'0000 )
      {
        const SchizoReg32< void > r_ebx{ebx};
	const SchizoReg32< void > r_ecx{ecx};
	const SchizoReg32< void > r_edx{edx};

	std::string hypervisor =
	  std::string( r_ebx.as_str4, 4) +
	  std::string( r_ecx.as_str4, 4) +
	  std::string( r_edx.as_str4, 4);

	std::cout << "\tHypervisor vendor: '" << hypervisor << "'" << std::endl;
      }
    else
      {
	std::cout << "\tNo hypervisor detected." << std::endl;
      }

  }


  if ( 1 <= max_leaf.value() )
  {
    std::cout << "Leaf 1:" << std::endl;
    const auto [eax, ebx, ecx, edx]  = query_leaf(1);

    interpret_fields32<leaf1::eax_features>(eax);
    interpret_fields32<leaf1::ebx_features>(ebx);
    interpret_fields32<leaf1::ecx_features>(ecx);
    interpret_fields32<leaf1::edx_features>(edx);
  }

  std::cout << "Extended leaf 1 (EAX = 0x8000'0001):" << std::endl;
  if ( 0x8000'0001 <= max_ext_leaf.value() )
  {
    const auto [eax, ebx, ecx, edx]  = query_leaf(0x8000'0001);

    interpret_fields32<leaf80000001::edx_features>(edx);
    interpret_fields32<leaf80000001::ecx_features>(ecx);
  } else
    std::cout << "\t N/A.\n";


  if ( 7 <= max_leaf.value() )
  {
    {
      std::cout << "Leaf 7, subleaf 0:" << std::endl;
      const auto [eax, ebx, ecx, edx]  = query_leaf(7,0);
      max_leaf7_subleaf = eax;
      std::cout << "\tMax leaf-7 ECX sub-leaf: " << max_leaf7_subleaf.value() << std::endl;;

      interpret_fields32<leaf7_subleaf0::eax_features>(eax);
      interpret_fields32<leaf7_subleaf0::ebx_features>(ebx);
      interpret_fields32<leaf7_subleaf0::ecx_features>(ecx);
      interpret_fields32<leaf7_subleaf0::edx_features>(edx);
    }

    if ( 1 <= max_leaf7_subleaf) {
      std::cout << "Leaf 7, subleaf 1:" << std::endl;
      const auto [eax, ebx, ecx, edx]  = query_leaf(7,1);

      interpret_fields32< leaf7_subleaf1::ebx_features >( eax );
      interpret_fields32< leaf7_subleaf1::ebx_features >( ebx );
      interpret_fields32< leaf7_subleaf1::ecx_features >( ecx );
      interpret_fields32< leaf7_subleaf1::edx_features >( edx );
    }

  }

  return 0;
}

/*
   Copyright © 2025, Daniele Paolo Scarpazza
   BSD-3 license.
   Redistribution and use in source and binary forms, with or without modification, are permitted provided
   that the following conditions are met:
   1. Redistributions of source code must retain the above copyright notice, this list of conditions and
      the following disclaimer.
   2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions
      and the following disclaimer in the documentation and/or other materials provided with the distribution.
   3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse
      or promote products derived from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS “AS IS” AND ANY EXPRESS OR
   IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
   FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
   DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY
   WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

   NDA and non-compete compliance statement:
   The author of this code explicitly affirms that this code was written outside of any professional
   affiliation with any employer or organization, and in full compliance with any non-disclosure and
   non-compete agreement that he has entered.
*/


#include <experimental/meta> // compile-time reflection metafunctions, like members_of()
#include <iostream>
#include <iomanip>
#include <tuple>
#include <optional>
#include <string>
#include <sys/types.h>

#include "cpuid.hpp"
#include "leaves.hpp"
#include "codenames.hpp"

const auto query_leaf(const uint32_t leaf,
		      const uint32_t subleaf=0) {
  uint32_t eax = leaf, ebx, ecx = subleaf, edx;
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
    const auto manufacturer = regs_to_string( ebx, edx, ecx );
    // yes, it's EBX, EDX and then ECX

    std::cout << "Manufacturer: '" << manufacturer << "'" << std::endl;
  }

  if ( 1 <= max_leaf.value() )
  {
    std::cout << "Leaf 1:" << std::endl;
    const auto [eax, ebx, ecx, edx]  = query_leaf(1);

    interpret_fields32_abcd< leaf1 >( eax, ebx, ecx, edx );

    const auto e = find_codename( eax );
    if (e.has_value())
      std::cout << "\t Microarch codename : " << e->microarch
		<< "\n\t Introduced         : " << e->year
		<< "\n\t Core codename      : " << e->core << "\n";
    else
      std::cout << "\t Microarch codename : NOT IN THE DATABASE\n";

  }
  
  std::cout << "Extended leaf 0 (EAX = 0x8000'0000):" << std::endl;
  {
    const auto [eax, ebx, ecx, edx]  = query_leaf(0x8000'0000);
    max_ext_leaf = eax;
    std::cout << "Max EAX extended leaf: 0x" << std::hex << max_ext_leaf.value()
	      << std::dec << std::endl;
  }

  std::cout << "Hypervisor Leaf 0 (EAX = 0x4000'0000):" << std::endl;
  {
    const auto [eax, ebx, ecx, edx]  = query_leaf(0x4000'0000);

    if ( eax != 0 ) {
      const auto hypervisor = regs_to_string( ebx, ecx, edx );
      std::cout << "\t Hypervisor vendor: '" << hypervisor << "'" << std::endl;
    }
    else
      std::cout << "\t No hypervisor." << std::endl;
  }

  std::cout << "Extended leaf 1 (EAX = 0x8000'0001):" << std::endl;
  if ( 0x8000'0001 <= max_ext_leaf.value() )
  {
    const auto [eax, ebx, ecx, edx]  = query_leaf(0x8000'0001);

    interpret_fields32<leaf80000001::ecx_features>(ecx);
    interpret_fields32<leaf80000001::edx_features>(edx);
  } else
    std::cout << "\t N/A.\n";


  std::cout << "Extended leaves 2,3,4 (EAX = 0x8000'0002...4):" << std::endl;
  if (0x8000'0004 <= max_ext_leaf)
  {
    const auto [eax2, ebx2, ecx2, edx2]  = query_leaf(0x8000'0002);
    const auto [eax3, ebx3, ecx3, edx3]  = query_leaf(0x8000'0003);
    const auto [eax4, ebx4, ecx4, edx4]  = query_leaf(0x8000'0004);

    std::string brand_string = regs_to_string( eax2, ebx2, ecx2, edx2,
					       eax3, ebx3, ecx3, edx3,
					       eax4, ebx4, ecx4, edx4 );

    // "The string is specified in Intel/AMD documentation to be null-terminated,
    // however this is not always the case [...] and software should not rely on it."
    // - https://en.wikipedia.org/wiki/CPUID#EAX=8000'0001h:_Extended_Processor_Info_and_Feature_Bits
    const auto nul_idx = brand_string.find( char{0} );
    if ( nul_idx != std::string::npos)
      brand_string.resize(nul_idx);

    std::cout << "\tProcessor Brand string: '" << brand_string << "'" << std::endl;
  } else
    std::cout << "\t N/A.\n";

  std::cout << "Extended leaf 5 (EAX = 0x8000'0005): L1 cache and TLB identifiers:" << std::endl;
  if (0x8000'0005 <= max_ext_leaf)
  {
    const auto [eax, ebx, ecx, edx]  = query_leaf(0x8000'0005);
    interpret_fields32_abcd< leaf80000005 >( eax, ebx, ecx, edx );
  } else
    std::cout << "\t N/A.\n";


  std::cout << "Leaf 7:\n";
  if ( 7 <= max_leaf.value() )
  {
    {
      std::cout << "Leaf 7, subleaf 0:" << std::endl;
      const auto [eax, ebx, ecx, edx]  = query_leaf(7,0);
      max_leaf7_subleaf = eax;
      std::cout << "\tMax leaf-7 ECX sub-leaf: " << max_leaf7_subleaf.value() << std::endl;;

      interpret_fields32_abcd< leaf7_subleaf0 >( eax, ebx, ecx, edx );
    }

    std::cout << "Leaf 7, subleaf 1:" << std::endl;
    if ( 1 <= max_leaf7_subleaf) {
      const auto [eax, ebx, ecx, edx]  = query_leaf(7,1);

      interpret_fields32_abcd< leaf7_subleaf1 >( eax, ebx, ecx, edx );
    }else
      std::cout << "\t N/A.\n";

    std::cout << "Leaf 7, subleaf 2:" << std::endl;
    if ( 2 <= max_leaf7_subleaf) {
      const auto [eax, ebx, ecx, edx]  = query_leaf(7,2);
      interpret_fields32<cpuid::leaf7_subleaf2::edx_features>(edx);
    } else
      std::cout << "\t N/A.\n";
  }
  else
    std::cout << "\t N/A.\n";

  {
    std::cout << "Xeon Phi Function (Leaf 0x2000'0000):\n";
    const auto [eax, ebx, ecx, edx]  = query_leaf(0x2000'0000);
    if ( eax == 0 )
      std::cout << "\t N/A.\n";
    else
      std::cout << "Max Xeon Phi Function: " << eax << "\n";
  }


  return 0;
}

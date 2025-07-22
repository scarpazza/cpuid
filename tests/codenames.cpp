#include <iostream>

#include <iomanip>

#include "include/codenames.hpp"
#include "include/leaf_EAX1.hpp"

#include <optional>

 template <typename RS>
  union SchizoReg32 {
    uint32_t  as_int;
    RS        as_struct;
    char      as_str4 [4];
    static_assert (sizeof(RS) == sizeof(uint32_t), "Size of RS should match 32-bit register size (==4 bytes)");
  };


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

std::optional<CodenameEntry> find_codename ( const uint32_t eax )
{
  const SchizoReg32< cpuid::leaf1::eax_features > dual_eax{eax};

  const auto sig = dual_eax.as_struct;


  std::cout << "Needle: "
	    << std::hex
	    << +sig.extended_family << ","
    	    << +sig.family << ","
	    << +sig.extended_model << ","
	    << +sig.model
 	    << "\n";


  for (const auto entry: codenames)
    if (sig.model == entry.model &&
	sig.family == entry.family &&
	sig.extended_model == entry.extended_model &&
	sig.extended_family == entry.extended_family &&
	( entry.steppings.empty() or
	  entry.steppings.contains( sig.stepping )
	  )
	)
      return std::optional<CodenameEntry>{entry};

  return std::optional<CodenameEntry>{};
}



int main()
{
  const uint32_t skylake_eax1 = 0x0406e3;
    //and 0506e3

  const auto e = find_codename( skylake_eax1 );

  if (e.has_value())
    std::cout << e->microarch << std::dec
	      << " (" << e->year << ") "
	      << e->core << "\n";

  {
    const auto [eax, ebx, ecx, edx] = query_leaf(1);
    const auto e = find_codename( eax );

    if (e.has_value())
      std::cout << e->microarch << std::dec
	      << " (" << e->year << ") "
	      << e->core << "\n";

  }

  return 0;
}

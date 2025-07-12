// demonstrates bit_size_of


#include <experimental/meta> // compile-time reflection metafunctions, like members_of()
#include <algorithm>
#include <iostream>
#include <iomanip>
#include "leaf_EAX1.hpp"

template<typename S>
struct field_info {
  std::string_view name;
  int    seq;
  size_t bit_size;
};

template<typename S>
consteval auto get_fields() {
  constexpr auto ctx    = std::meta::access_context::unchecked();
  constexpr auto N = std::meta::nonstatic_data_members_of( ^^S, ctx ).size(); // OK
  std::array< field_info<S>, N > result;

  int k = 0;

  for ( auto f: std::meta::nonstatic_data_members_of( ^^S, ctx ) )  {
    result[k++] = field_info<S>{ std::meta::identifier_of( f ),
				 k,
				 std::meta::bit_size_of(f) };
  }

  return result;
}

template <typename S>
void enumerate_fields( const S & s)
{
  constexpr auto fs = get_fields<S>();

  for ( int i=0; i< fs.size(); i++)
    std::cout << std::setw(2) << fs[i].seq
	      << ": " << fs[i].name
	      << "(" << fs[i].bit_size <<")" 
	      << std::endl;

}

template <typename RegStruct>
union SchizoReg32 {
  uint32_t  as_int;
  RegStruct as_struct;
};

int main() {
  uint32_t eax, ebx;
  eax = 1;

  SchizoReg32<CPUID_ecx_features> ecx;
  SchizoReg32<CPUID_edx_features> edx;

  __asm__ volatile("cpuid"
		   : "+a"(eax), "=b"(ebx), "=c"(ecx.as_int), "=d"(edx)  // out
		     // the "a","b","c","d", modifiers come from x86 family-config/i386/constraints.md
		   : // input - nothing more than eax. already listed
		   : // clobbers - nothing more than those already listed
		   );

  enumerate_fields( ecx.as_struct );
  enumerate_fields( edx.as_struct );

  return 0;
}

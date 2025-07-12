#include <experimental/meta> // compile-time reflection metafunctions, like members_of()
#include <algorithm>
#include <cassert>
#include <iostream>
#include <iomanip>
#include "leaf_EAX1.hpp"

template<typename S>
struct field_info {
  int              seq;
  std::string_view name;
  std::string_view type_name;
  bool             bit_field;
  size_t           bit_size;
  std::meta::member_offset ofs;
};

template<typename S>
consteval auto get_fields( const S & )
// anonymous argument, only used for type deduction!
{
  constexpr auto ctx    = std::meta::access_context::unchecked();
  constexpr auto N = std::meta::nonstatic_data_members_of( ^^S, ctx ).size(); // OK
  std::array< field_info<S>, N > result;

  int k = 0;
  // this can be both a regular for and a template for - they are both guaranteed to executed at compile time
  template for ( constexpr auto f: std::define_static_array(std::meta::nonstatic_data_members_of( ^^S, ctx )) )  {
    assert( std::meta::is_bit_field(f) ); // YES this assertion WILL be checked at compile time!
    result[k++] = field_info<S>{ k,
				 std::meta::identifier_of( f ),
				 std::meta::display_string_of(std::meta::type_of( f )),
				 std::meta::is_bit_field(f),
				 std::meta::bit_size_of(f),
				 std::meta::offset_of(f)
    };
  }
  return result;
};

template <typename S>
auto get_values(const S &s)
{
  constexpr auto ctx    = std::meta::access_context::unchecked();
  constexpr auto N = std::meta::nonstatic_data_members_of( ^^S, ctx ).size(); // OK
  std::array< int, N > result;
  int k = 0;

  template for ( constexpr auto f: std::define_static_array(std::meta::nonstatic_data_members_of( ^^S, ctx )) )
    // this is where we systematically apply splicing
    result[k++] = s. [: f :];

  return result;
}


template <typename S>
void enumerate_fields( const S & s)
{
  constexpr const auto fs = get_fields(s);
  auto values = get_values(s);

  assert(values.size() == fs.size() );

  for ( int i=0; i< fs.size(); i++)
    std::cout << std::setw(2) << fs[i].seq
	      << " " << std::setw(15) << fs[i].name
	      << "\t" << fs[i].type_name
      	      << "\t" << (fs[i].bit_field? "bf" : "  ")
	      << " (" << fs[i].bit_size <<" bits)"
      	      << " @" << fs[i].ofs.bytes * 8 + fs[i].ofs.bits
      	      << " =" << values[i]
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

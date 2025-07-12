// demonstrates splicing


#include <experimental/meta> // compile-time reflection metafunctions, like members_of()
#include <algorithm>
#include <cassert>
#include <iostream>
#include <iomanip>
#include "leaf_EAX1.hpp"



/*
  int k = 0;
  for ( auto f: std::meta::nonstatic_data_members_of( ^^S, ctx ) )  {
    assert( std::meta::is_bit_field(f) ); // YES this assertion WILL be checked at compile time!
    result[k++] = field_info<S>{ k,
				 std::meta::identifier_of( f ),
				 std::meta::display_string_of(std::meta::type_of( f )),
				 std::meta::is_bit_field(f),
				 std::meta::bit_size_of(f),
				 std::meta::offset_of(f),
				 f
*/

constexpr auto ctx    = std::meta::access_context::unchecked();

struct MyStruct {
  int a;
  int b;
};

// returns the reflection of the i-th member
//
template <typename S>
consteval auto member_number(const S &, int i) {
  return std::meta::nonstatic_data_members_of( ^^S, ctx )[i];
}

// returns the C++ pointer-to-member (e.g., the &S::x thing)
// corresponding to the i-th member
/*
template <typename S>
consteval auto pointer_to_member(const S &, int i) {
  return & ( S :: [: std::meta::nonstatic_data_members_of( ^^S, ctx )[i] :]);
  }*/



int main()
{
  MyStruct s {1,2};

  std::cout << "first member  = " << s.[: member_number(s,0) :] << std::endl;
  std::cout << "second member = " << s.[: member_number(s,1) :] << std::endl;

  const auto ptr_mem_0 = & MyStruct:: [: member_number(s,0) :] ;

  
  //  const auto ptr_mem_0 = pointer_to_member(s,0);
  //  const auto ptr_mem_1 = pointer_to_member(s,1);

  /*
  for (int i=0; i<3; i++)
    std::cout << "member = " << s.[: member_number(s,i) :] << std::endl;
    }*/

  return 0;
}



/*
template <typename S>
consteval auto ptr_to_member_table(const S &)
{
  constexpr auto ctx    = std::meta::access_context::unchecked();
  std::array< std::meta::info,
	      std::meta::nonstatic_data_members_of( ^^S, ctx ).size()> result;
  int k = 0;
  for ( auto f: std::meta::nonstatic_data_members_of( ^^S, ctx ) )
    {
      result[k++] = & S :: [: f :];

    }

  return results;
}
*/

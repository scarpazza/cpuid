#pragma once


#include <cassert>

namespace cpuid {


  template <typename RS>
  union SchizoReg32 {
    uint32_t  as_int;
    RS        as_struct;
    char      as_str4 [4];
    static_assert (sizeof(RS) == sizeof(uint32_t), "Size of RS should match 32-bit register size (==4 bytes)");
  };

  template <>
  union SchizoReg32<void> {
    uint32_t  as_int;
    char      as_str4 [4];
  };



  struct field_info {
    std::string_view name;
    std::string_view type_name;
    bool bit_field;
    size_t bit_size;
    std::meta::member_offset ofs;
  };

  /* takes a struct or a class and populates an array of
     field_info describing its fields
   */

  template <typename S>
  consteval auto get_fields(const S &)
  // anonymous argument is used only for type deduction
  {
    constexpr auto ctx = std::meta::access_context::unchecked();
    constexpr auto N =
      std::meta::nonstatic_data_members_of(^^S, ctx).size(); // OK
    std::array<field_info, N> result;

    int k = 0;
    // this can be both a regular for and a template for - they are both
    // guaranteed to executed at compile time
    template for (constexpr auto f :
		    std::define_static_array( std::meta::nonstatic_data_members_of(^^S, ctx)))
      {
	//assert(std::meta::is_bit_field( f )); // this assertion WILL be checked at compile time
	result[k++] =
	  field_info{ std::meta::identifier_of(f),
		      std::meta::display_string_of(std::meta::type_of(f)),
		      std::meta::is_bit_field(f),
		      std::meta::bit_size_of(f),
		      std::meta::offset_of(f) };
      }
    return result;
  };

  template <typename S>
  auto get_values(const S &s)
  {
    constexpr auto ctx = std::meta::access_context::unchecked();
    constexpr auto N =
      std::meta::nonstatic_data_members_of(^^S, ctx).size(); // OK
    std::array<int, N> result;
    int k = 0;

    template for (constexpr auto f : std::define_static_array( std::meta::nonstatic_data_members_of(^^S, ctx)) )
      // this is where we systematically apply splicing
      result[k++] = s.[:f:];

    return result;
  }

  template <typename S>
  void enumerate_fields( const S & s)
  {
    constexpr auto fs           = get_fields(s);
    constexpr auto struct_name  = std::meta::display_string_of(^^S);
    const     auto values       = get_values(s);

    assert(values.size() == fs.size() );

    std::cout << "\t" << std::setfill('-') << std::setw(60) << std::left
	      << struct_name
	      << std::setw(0) << std::setfill(' ') << "\n";

    for ( int i=0; i< fs.size(); i++)
      std::cout << "\t\t"
		<< std::setw(25) << fs[i].name
		<< "\t" << fs[i].type_name
		<< "\t" << (fs[i].bit_field? "bf" : "  ")
		<< " (" << fs[i].bit_size <<" bit"
		<< (fs[i].bit_size==1 ? " ":"s")
		<< ") @" << fs[i].ofs.bytes * 8 + fs[i].ofs.bits
		<< "\t ="   << values[i]
		<< "\t =0x" << std::hex << values[i] << std::dec
		<< std::endl;
  }


  template <typename ExplanationStruct>
  void interpret_fields32( const uint32_t reg_value)
  {
    const SchizoReg32< ExplanationStruct > dual_personality{reg_value};
    static_assert (sizeof(dual_personality) == sizeof(reg_value),
		   "Size of ExplanationStruct should match 32-bit register");
    enumerate_fields( dual_personality.as_struct );
  }



}; // namespace cpuid

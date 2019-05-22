/**
 *  @file
 *  @copyright defined in eos/LICENSE
 */
#include <hawknwklib/hawknwk.hpp>

#include "test_api.hpp"

void test_types::types_size() {

   hawknwk_assert( sizeof(int64_t)   ==  8, "int64_t size != 8"   );
   hawknwk_assert( sizeof(uint64_t)  ==  8, "uint64_t size != 8"  );
   hawknwk_assert( sizeof(uint32_t)  ==  4, "uint32_t size != 4"  );
   hawknwk_assert( sizeof(int32_t)   ==  4, "int32_t size != 4"   );
   hawknwk_assert( sizeof(uint128_t) == 16, "uint128_t size != 16");
   hawknwk_assert( sizeof(int128_t)  == 16, "int128_t size != 16" );
   hawknwk_assert( sizeof(uint8_t)   ==  1, "uint8_t size != 1"   );

   hawknwk_assert( sizeof(hawknwk::name) ==  8, "name size !=  8");
}

void test_types::char_to_symbol() {

   hawknwk_assert( hawknwk::name::char_to_value('1') ==  1, "hawknwk::char_to_symbol('1') !=  1" );
   hawknwk_assert( hawknwk::name::char_to_value('2') ==  2, "hawknwk::char_to_symbol('2') !=  2" );
   hawknwk_assert( hawknwk::name::char_to_value('3') ==  3, "hawknwk::char_to_symbol('3') !=  3" );
   hawknwk_assert( hawknwk::name::char_to_value('4') ==  4, "hawknwk::char_to_symbol('4') !=  4" );
   hawknwk_assert( hawknwk::name::char_to_value('5') ==  5, "hawknwk::char_to_symbol('5') !=  5" );
   hawknwk_assert( hawknwk::name::char_to_value('a') ==  6, "hawknwk::char_to_symbol('a') !=  6" );
   hawknwk_assert( hawknwk::name::char_to_value('b') ==  7, "hawknwk::char_to_symbol('b') !=  7" );
   hawknwk_assert( hawknwk::name::char_to_value('c') ==  8, "hawknwk::char_to_symbol('c') !=  8" );
   hawknwk_assert( hawknwk::name::char_to_value('d') ==  9, "hawknwk::char_to_symbol('d') !=  9" );
   hawknwk_assert( hawknwk::name::char_to_value('e') == 10, "hawknwk::char_to_symbol('e') != 10" );
   hawknwk_assert( hawknwk::name::char_to_value('f') == 11, "hawknwk::char_to_symbol('f') != 11" );
   hawknwk_assert( hawknwk::name::char_to_value('g') == 12, "hawknwk::char_to_symbol('g') != 12" );
   hawknwk_assert( hawknwk::name::char_to_value('h') == 13, "hawknwk::char_to_symbol('h') != 13" );
   hawknwk_assert( hawknwk::name::char_to_value('i') == 14, "hawknwk::char_to_symbol('i') != 14" );
   hawknwk_assert( hawknwk::name::char_to_value('j') == 15, "hawknwk::char_to_symbol('j') != 15" );
   hawknwk_assert( hawknwk::name::char_to_value('k') == 16, "hawknwk::char_to_symbol('k') != 16" );
   hawknwk_assert( hawknwk::name::char_to_value('l') == 17, "hawknwk::char_to_symbol('l') != 17" );
   hawknwk_assert( hawknwk::name::char_to_value('m') == 18, "hawknwk::char_to_symbol('m') != 18" );
   hawknwk_assert( hawknwk::name::char_to_value('n') == 19, "hawknwk::char_to_symbol('n') != 19" );
   hawknwk_assert( hawknwk::name::char_to_value('o') == 20, "hawknwk::char_to_symbol('o') != 20" );
   hawknwk_assert( hawknwk::name::char_to_value('p') == 21, "hawknwk::char_to_symbol('p') != 21" );
   hawknwk_assert( hawknwk::name::char_to_value('q') == 22, "hawknwk::char_to_symbol('q') != 22" );
   hawknwk_assert( hawknwk::name::char_to_value('r') == 23, "hawknwk::char_to_symbol('r') != 23" );
   hawknwk_assert( hawknwk::name::char_to_value('s') == 24, "hawknwk::char_to_symbol('s') != 24" );
   hawknwk_assert( hawknwk::name::char_to_value('t') == 25, "hawknwk::char_to_symbol('t') != 25" );
   hawknwk_assert( hawknwk::name::char_to_value('u') == 26, "hawknwk::char_to_symbol('u') != 26" );
   hawknwk_assert( hawknwk::name::char_to_value('v') == 27, "hawknwk::char_to_symbol('v') != 27" );
   hawknwk_assert( hawknwk::name::char_to_value('w') == 28, "hawknwk::char_to_symbol('w') != 28" );
   hawknwk_assert( hawknwk::name::char_to_value('x') == 29, "hawknwk::char_to_symbol('x') != 29" );
   hawknwk_assert( hawknwk::name::char_to_value('y') == 30, "hawknwk::char_to_symbol('y') != 30" );
   hawknwk_assert( hawknwk::name::char_to_value('z') == 31, "hawknwk::char_to_symbol('z') != 31" );

   for(unsigned char i = 0; i<255; i++) {
      if( (i >= 'a' && i <= 'z') || (i >= '1' || i <= '5') ) continue;
      hawknwk_assert( hawknwk::name::char_to_value((char)i) == 0, "hawknwk::char_to_symbol() != 0" );
   }
}

void test_types::string_to_name() {
   return;
   hawknwk_assert( hawknwk::name("a") == "a"_n, "hawknwk::string_to_name(a)" );
   hawknwk_assert( hawknwk::name("ba") == "ba"_n, "hawknwk::string_to_name(ba)" );
   hawknwk_assert( hawknwk::name("cba") == "cba"_n, "hawknwk::string_to_name(cba)" );
   hawknwk_assert( hawknwk::name("dcba") == "dcba"_n, "hawknwk::string_to_name(dcba)" );
   hawknwk_assert( hawknwk::name("edcba") == "edcba"_n, "hawknwk::string_to_name(edcba)" );
   hawknwk_assert( hawknwk::name("fedcba") == "fedcba"_n, "hawknwk::string_to_name(fedcba)" );
   hawknwk_assert( hawknwk::name("gfedcba") == "gfedcba"_n, "hawknwk::string_to_name(gfedcba)" );
   hawknwk_assert( hawknwk::name("hgfedcba") == "hgfedcba"_n, "hawknwk::string_to_name(hgfedcba)" );
   hawknwk_assert( hawknwk::name("ihgfedcba") == "ihgfedcba"_n, "hawknwk::string_to_name(ihgfedcba)" );
   hawknwk_assert( hawknwk::name("jihgfedcba") == "jihgfedcba"_n, "hawknwk::string_to_name(jihgfedcba)" );
   hawknwk_assert( hawknwk::name("kjihgfedcba") == "kjihgfedcba"_n, "hawknwk::string_to_name(kjihgfedcba)" );
   hawknwk_assert( hawknwk::name("lkjihgfedcba") == "lkjihgfedcba"_n, "hawknwk::string_to_name(lkjihgfedcba)" );
   hawknwk_assert( hawknwk::name("mlkjihgfedcba") == "mlkjihgfedcba"_n, "hawknwk::string_to_name(mlkjihgfedcba)" );
}

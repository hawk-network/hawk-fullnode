/**
 *  @file
 *  @copyright defined in eos/LICENSE
 */
#pragma once

#include <hawknwk/hawknwk.hpp>

class [[hawknwk::contract]] test_api_db : public hawknwk::contract {
public:
   using hawknwk::contract::contract;

   [[hawknwk::action("pg")]]
   void primary_i64_general();

   [[hawknwk::action("pl")]]
   void primary_i64_lowerbound();

   [[hawknwk::action("pu")]]
   void primary_i64_upperbound();

   [[hawknwk::action("s1g")]]
   void idx64_general();

   [[hawknwk::action("s1l")]]
   void idx64_lowerbound();

   [[hawknwk::action("s1u")]]
   void idx64_upperbound();

   [[hawknwk::action("tia")]]
   void test_invalid_access( hawknwk::name code, uint64_t val, uint32_t index, bool store );

   [[hawknwk::action("sdnancreate")]]
   void idx_double_nan_create_fail();

   [[hawknwk::action("sdnanmodify")]]
   void idx_double_nan_modify_fail();

   [[hawknwk::action("sdnanlookup")]]
   void idx_double_nan_lookup_fail( uint32_t lookup_type );

   [[hawknwk::action("sk32align")]]
   void misaligned_secondary_key256_tests();

};

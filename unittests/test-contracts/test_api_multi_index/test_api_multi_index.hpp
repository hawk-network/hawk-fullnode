/**
 *  @file
 *  @copyright defined in eos/LICENSE
 */
#pragma once

#include <hawknwk/hawknwk.hpp>

class [[hawknwk::contract]] test_api_multi_index : public hawknwk::contract {
public:
   using hawknwk::contract::contract;

   [[hawknwk::action("s1g")]]
   void idx64_general();

   [[hawknwk::action("s1store")]]
   void idx64_store_only();

   [[hawknwk::action("s1check")]]
   void idx64_check_without_storing();

   [[hawknwk::action("s1findfail1")]]
   void idx64_require_find_fail();

   [[hawknwk::action("s1findfail2")]]
   void idx64_require_find_fail_with_msg();

   [[hawknwk::action("s1findfail3")]]
   void idx64_require_find_sk_fail();

   [[hawknwk::action("s1findfail4")]]
   void idx64_require_find_sk_fail_with_msg();

   [[hawknwk::action("s1pkend")]]
   void idx64_pk_iterator_exceed_end();

   [[hawknwk::action("s1skend")]]
   void idx64_sk_iterator_exceed_end();

   [[hawknwk::action("s1pkbegin")]]
   void idx64_pk_iterator_exceed_begin();

   [[hawknwk::action("s1skbegin")]]
   void idx64_sk_iterator_exceed_begin();

   [[hawknwk::action("s1pkref")]]
   void idx64_pass_pk_ref_to_other_table();

   [[hawknwk::action("s1skref")]]
   void idx64_pass_sk_ref_to_other_table();

   [[hawknwk::action("s1pkitrto")]]
   void idx64_pass_pk_end_itr_to_iterator_to();

   [[hawknwk::action("s1pkmodify")]]
   void idx64_pass_pk_end_itr_to_modify();

   [[hawknwk::action("s1pkerase")]]
   void idx64_pass_pk_end_itr_to_erase();

   [[hawknwk::action("s1skitrto")]]
   void idx64_pass_sk_end_itr_to_iterator_to();

   [[hawknwk::action("s1skmodify")]]
   void idx64_pass_sk_end_itr_to_modify();

   [[hawknwk::action("s1skerase")]]
   void idx64_pass_sk_end_itr_to_erase();

   [[hawknwk::action("s1modpk")]]
   void idx64_modify_primary_key();

   [[hawknwk::action("s1exhaustpk")]]
   void idx64_run_out_of_avl_pk();

   [[hawknwk::action("s1skcache")]]
   void idx64_sk_cache_pk_lookup();

   [[hawknwk::action("s1pkcache")]]
   void idx64_pk_cache_sk_lookup();

   [[hawknwk::action("s2g")]]
   void idx128_general();

   [[hawknwk::action("s2store")]]
   void idx128_store_only();

   [[hawknwk::action("s2check")]]
   void idx128_check_without_storing();

   [[hawknwk::action("s2autoinc")]]
   void idx128_autoincrement_test();

   [[hawknwk::action("s2autoinc1")]]
   void idx128_autoincrement_test_part1();

   [[hawknwk::action("s2autoinc2")]]
   void idx128_autoincrement_test_part2();

   [[hawknwk::action("s3g")]]
   void idx256_general();

   [[hawknwk::action("sdg")]]
   void idx_double_general();

   [[hawknwk::action("sldg")]]
   void idx_long_double_general();

};

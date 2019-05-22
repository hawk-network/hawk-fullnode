/**
 *  @file
 *  @copyright defined in eos/LICENSE
 */
#pragma once

#include <hawknwk/hawknwk.hpp>
#include <vector>

class [[hawknwk::contract]] deferred_test : public hawknwk::contract {
public:
   using hawknwk::contract::contract;

   [[hawknwk::action]]
   void defercall( hawknwk::name payer, uint64_t sender_id, hawknwk::name contract, uint64_t payload );

   [[hawknwk::action]]
   void deferfunc( uint64_t payload );
   using deferfunc_action = hawknwk::action_wrapper<"deferfunc"_n, &deferred_test::deferfunc>;

   [[hawknwk::action]]
   void inlinecall( hawknwk::name contract, hawknwk::name authorizer, uint64_t payload );

   [[hawknwk::on_notify("hawknwk::onerror")]]
   void on_error( uint128_t sender_id, hawknwk::ignore<std::vector<char>> sent_trx );
};

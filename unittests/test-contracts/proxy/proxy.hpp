/**
 *  @file
 *  @copyright defined in eos/LICENSE
 */
#pragma once

#include <hawknwk/hawknwk.hpp>
#include <hawknwk/singleton.hpp>
#include <hawknwk/asset.hpp>

// Extacted from hawknwk.token contract:
namespace hawknwk {
   class [[hawknwk::contract("hawknwk.token")]] token : public hawknwk::contract {
   public:
      using hawknwk::contract::contract;

      [[hawknwk::action]]
      void transfer( hawknwk::name        from,
                     hawknwk::name        to,
                     hawknwk::asset       quantity,
                     const std::string& memo );
      using transfer_action = hawknwk::action_wrapper<"transfer"_n, &token::transfer>;
   };
}

// This contract:
class [[hawknwk::contract]] proxy : public hawknwk::contract {
public:
   proxy( hawknwk::name self, hawknwk::name first_receiver, hawknwk::datastream<const char*> ds );

   [[hawknwk::action]]
   void setowner( hawknwk::name owner, uint32_t delay );

   [[hawknwk::on_notify("hawknwk.token::transfer")]]
   void on_transfer( hawknwk::name        from,
                     hawknwk::name        to,
                     hawknwk::asset       quantity,
                     const std::string& memo );

   [[hawknwk::on_notify("hawknwk::onerror")]]
   void on_error( uint128_t sender_id, hawknwk::ignore<std::vector<char>> sent_trx );

   struct [[hawknwk::table]] config {
      hawknwk::name owner;
      uint32_t    delay   = 0;
      uint32_t    next_id = 0;

      EOSLIB_SERIALIZE( config, (owner)(delay)(next_id) )
   };

   using config_singleton = hawknwk::singleton< "config"_n,  config >;

protected:
   config_singleton _config;
};

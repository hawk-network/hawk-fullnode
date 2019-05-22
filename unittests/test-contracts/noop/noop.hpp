/**
 *  @file
 *  @copyright defined in eos/LICENSE
 */
#pragma once

#include <hawknwk/hawknwk.hpp>

class [[hawknwk::contract]] noop : public hawknwk::contract {
public:
   using hawknwk::contract::contract;

   [[hawknwk::action]]
   void anyaction( hawknwk::name                       from,
                   const hawknwk::ignore<std::string>& type,
                   const hawknwk::ignore<std::string>& data );
};

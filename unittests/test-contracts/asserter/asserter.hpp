/**
 *  @file
 *  @copyright defined in eos/LICENSE
 */
#pragma once

#include <hawknwk/hawknwk.hpp>

class [[hawknwk::contract]] asserter : public hawknwk::contract {
public:
   using hawknwk::contract::contract;

   [[hawknwk::action]]
   void procassert( int8_t condition, std::string message );

   [[hawknwk::action]]
   void provereset();
};

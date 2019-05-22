/**
 *  @file
 *  @copyright defined in eos/LICENSE
 */
#pragma once

#include <hawknwk/hawknwk.hpp>

class [[hawknwk::contract]] payloadless : public hawknwk::contract {
public:
   using hawknwk::contract::contract;

   [[hawknwk::action]]
   void doit();
};

/**
 *  @file
 *  @copyright defined in eos/LICENSE
 */
#pragma once

#include <hawknwk/chain/types.hpp>
#include <hawknwk/chain/contract_types.hpp>

namespace hawknwk { namespace chain {

   class apply_context;

   /**
    * @defgroup native_action_handlers Native Action Handlers
    */
   ///@{
   void apply_hawknwk_newaccount(apply_context&);
   void apply_hawknwk_updateauth(apply_context&);
   void apply_hawknwk_deleteauth(apply_context&);
   void apply_hawknwk_linkauth(apply_context&);
   void apply_hawknwk_unlinkauth(apply_context&);

   /*
   void apply_hawknwk_postrecovery(apply_context&);
   void apply_hawknwk_passrecovery(apply_context&);
   void apply_hawknwk_vetorecovery(apply_context&);
   */

   void apply_hawknwk_setcode(apply_context&);
   void apply_hawknwk_setabi(apply_context&);

   void apply_hawknwk_canceldelay(apply_context&);
   ///@}  end action handlers

} } /// namespace hawknwk::chain

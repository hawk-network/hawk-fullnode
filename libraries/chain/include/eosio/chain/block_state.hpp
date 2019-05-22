/**
 *  @file
 *  @copyright defined in eos/LICENSE
 */
#pragma once

#include <hawknwk/chain/block_header_state.hpp>
#include <hawknwk/chain/block.hpp>
#include <hawknwk/chain/transaction_metadata.hpp>
#include <hawknwk/chain/action_receipt.hpp>

namespace hawknwk { namespace chain {

   struct block_state : public block_header_state {
      explicit block_state( const block_header_state& cur ):block_header_state(cur){}
      block_state( const block_header_state& prev, signed_block_ptr b, bool skip_validate_signee );
      block_state( const block_header_state& prev, block_timestamp_type when );
      block_state() = default;

      /// weak_ptr prev_block_state....
      signed_block_ptr                                    block;
      bool                                                validated = false;
      bool                                                in_current_chain = false;

      /// this data is redundant with the data stored in block, but facilitates
      /// recapturing transactions when we pop a block
      vector<transaction_metadata_ptr>                    trxs;
   };

   using block_state_ptr = std::shared_ptr<block_state>;

} } /// namespace hawknwk::chain

FC_REFLECT_DERIVED( hawknwk::chain::block_state, (hawknwk::chain::block_header_state), (block)(validated)(in_current_chain) )

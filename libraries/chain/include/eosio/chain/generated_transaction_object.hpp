/**
 *  @file
 *  @copyright defined in eos/LICENSE
 */
#pragma once
#include <hawknwk/chain/config.hpp>
#include <hawknwk/chain/database_utils.hpp>

#include <hawknwk/chain/transaction.hpp>
#include <fc/uint128.hpp>

#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/mem_fun.hpp>

#include "multi_index_includes.hpp"

namespace hawknwk { namespace chain {
   using boost::multi_index_container;
   using namespace boost::multi_index;
   /**
    * The purpose of this object is to store transactions generated by processing the
    * transactions included in the chain.  These transactions should be treated like
    * authentic/valid SignedTransactions for the purposes of scheduling transactions
    * in to new blocks
    */
   class generated_transaction_object : public chainbase::object<generated_transaction_object_type, generated_transaction_object>
   {
         OBJECT_CTOR(generated_transaction_object, (packed_trx) )

         id_type                       id;
         transaction_id_type           trx_id;
         account_name                  sender;
         uint128_t                     sender_id = 0; /// ID given this transaction by the sender
         account_name                  payer;
         time_point                    delay_until; /// this generated transaction will not be applied until the specified time
         time_point                    expiration; /// this generated transaction will not be applied after this time
         time_point                    published;
         shared_blob                   packed_trx;

         uint32_t set( const transaction& trx ) {
            auto trxsize = fc::raw::pack_size( trx );
            packed_trx.resize( trxsize );
            fc::datastream<char*> ds( packed_trx.data(), trxsize );
            fc::raw::pack( ds, trx );
            return trxsize;
         }
   };

   struct by_trx_id;
   struct by_expiration;
   struct by_delay;
   struct by_status;
   struct by_sender_id;

   using generated_transaction_multi_index = chainbase::shared_multi_index_container<
      generated_transaction_object,
      indexed_by<
         ordered_unique< tag<by_id>, BOOST_MULTI_INDEX_MEMBER(generated_transaction_object, generated_transaction_object::id_type, id)>,
         ordered_unique< tag<by_trx_id>, BOOST_MULTI_INDEX_MEMBER( generated_transaction_object, transaction_id_type, trx_id)>,
         ordered_unique< tag<by_expiration>,
            composite_key< generated_transaction_object,
               BOOST_MULTI_INDEX_MEMBER( generated_transaction_object, time_point, expiration),
               BOOST_MULTI_INDEX_MEMBER( generated_transaction_object, generated_transaction_object::id_type, id)
            >
         >,
         ordered_unique< tag<by_delay>,
            composite_key< generated_transaction_object,
               BOOST_MULTI_INDEX_MEMBER( generated_transaction_object, time_point, delay_until),
               BOOST_MULTI_INDEX_MEMBER( generated_transaction_object, generated_transaction_object::id_type, id)
            >
         >,
         ordered_unique< tag<by_sender_id>,
            composite_key< generated_transaction_object,
               BOOST_MULTI_INDEX_MEMBER( generated_transaction_object, account_name, sender),
               BOOST_MULTI_INDEX_MEMBER( generated_transaction_object, uint128_t, sender_id)
            >
         >
      >
   >;

   class generated_transaction
   {
      public:
         generated_transaction(const generated_transaction_object& gto)
         :trx_id(gto.trx_id)
         ,sender(gto.sender)
         ,sender_id(gto.sender_id)
         ,payer(gto.payer)
         ,delay_until(gto.delay_until)
         ,expiration(gto.expiration)
         ,published(gto.published)
         ,packed_trx(gto.packed_trx.begin(), gto.packed_trx.end())
         {}

         generated_transaction(const generated_transaction& gt) = default;
         generated_transaction(generated_transaction&& gt) = default;

         transaction_id_type           trx_id;
         account_name                  sender;
         uint128_t                     sender_id;
         account_name                  payer;
         time_point                    delay_until; /// this generated transaction will not be applied until the specified time
         time_point                    expiration; /// this generated transaction will not be applied after this time
         time_point                    published;
         vector<char>                  packed_trx;

   };

   namespace config {
      template<>
      struct billable_size<generated_transaction_object> {
         static const uint64_t overhead = overhead_per_row_per_index_ram_bytes * 5;  ///< overhead for 5x indices internal-key, txid, expiration, delay, sender_id
         static const uint64_t value = 96 + 4 + overhead; ///< 96 bytes for our constant size fields, 4 bytes for a varint for packed_trx size and 96 bytes of implementation overhead
      };
   }
} } // hawknwk::chain

CHAINBASE_SET_INDEX_TYPE(hawknwk::chain::generated_transaction_object, hawknwk::chain::generated_transaction_multi_index)

FC_REFLECT(hawknwk::chain::generated_transaction_object, (trx_id)(sender)(sender_id)(payer)(delay_until)(expiration)(published)(packed_trx))

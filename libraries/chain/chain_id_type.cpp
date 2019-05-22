/**
 *  @file
 *  @copyright defined in eos/LICENSE
 */

#include <hawknwk/chain/chain_id_type.hpp>
#include <hawknwk/chain/exceptions.hpp>

namespace hawknwk { namespace chain {

   void chain_id_type::reflector_init()const {
      EOS_ASSERT( *reinterpret_cast<const fc::sha256*>(this) != fc::sha256(), chain_id_type_exception, "chain_id_type cannot be zero" );
   }

} }  // namespace hawknwk::chain

namespace fc {

   void to_variant(const hawknwk::chain::chain_id_type& cid, fc::variant& v) {
      to_variant( static_cast<const fc::sha256&>(cid), v);
   }

   void from_variant(const fc::variant& v, hawknwk::chain::chain_id_type& cid) {
      from_variant( v, static_cast<fc::sha256&>(cid) );
   }

} // fc

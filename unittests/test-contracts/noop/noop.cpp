/**
 *  @file
 *  @copyright defined in eos/LICENSE
 */
#include "noop.hpp"

using namespace hawknwk;

void noop::anyaction( name                       from,
                      const ignore<std::string>& type,
                      const ignore<std::string>& data )
{
   require_auth( from );
}

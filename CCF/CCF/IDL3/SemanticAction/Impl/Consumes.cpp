// file      : CCF/IDL3/SemanticAction/Impl/Consumes.cpp
// author    : Boris Kolpackov <boris@dre.vanderbilt.edu>
// cvs-id    : $Id$

#include "CCF/IDL3/SemanticGraph/Component.hpp"
#include "CCF/IDL3/SemanticAction/Impl/Consumes.hpp"

#include <iostream>

using std::cerr;
using std::endl;

namespace CCF
{
  namespace IDL3
  {
    namespace SemanticAction
    {
      namespace Impl
      {
        using namespace SemanticGraph;

        Consumes::
        ~Consumes () throw ()
        {
        }

        Consumes::
        Consumes (Context& c)
            : Base (c)
        {
        }

        void Consumes::
        type (IdentifierPtr const& id)
        {
          if (ctx.trace ()) cerr << "consumes " << id;

          type_ = 0;

          Name name (id->lexeme ());
          ScopedName from (ctx.scope ().scoped_name ());

          try
          {
            try
            {
              type_ = &resolve<EventType> (from, name);
            }
            catch (Resolve const&)
            {
              cerr << "error: invalid consumes declaration" << endl;
              throw;
            }
          }
          catch (NotFound const&)
          {
            cerr << "no eventtype with name \'" << name
                 << "\' visible from scope \'" << from << "\'" << endl;
          }
          catch (WrongType const&)
          {
            cerr << "declaration with name \'" << name
                 << "\' visible from scope \'" << from
                 << "\' is not an eventtype declaration" << endl;
            cerr << "using non-eventtype in consumes declaration is illegal"
                 << endl;
          }
        }

        void Consumes::
        name (SimpleIdentifierPtr const& id)
        {
          if (ctx.trace ()) cerr << " " << id << endl;

          if (type_)
          {
            Consumer& c (ctx.tu ().new_node<Consumer> ());

            ctx.tu ().new_edge<Belongs> (c, *type_);
            ctx.tu ().new_edge<Defines> (ctx.scope (), c, id->lexeme ());
          }
        }
      }
    }
  }
}

// file      : CCF/IDL3/SemanticAction/Impl/Emits.cpp
// author    : Boris Kolpackov <boris@dre.vanderbilt.edu>
// cvs-id    : $Id$

#include "CCF/IDL3/SemanticGraph/Component.hpp"
#include "CCF/IDL3/SemanticAction/Impl/Emits.hpp"

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

        Emits::
        ~Emits () throw ()
        {
        }

        Emits::
        Emits (Context& c)
            : Base (c)
        {
        }

        void Emits::
        type (IdentifierPtr const& id)
        {
          if (ctx.trace ()) cerr << "emits " << id;

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
              cerr << "error: invalid emits declaration" << endl;
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
            cerr << "using non-eventtype in emits declaration is illegal"
                 << endl;
          }
        }

        void Emits::
        name (SimpleIdentifierPtr const& id)
        {
          if (ctx.trace ()) cerr << " " << id << endl;

          if (type_)
          {
            Emitter& e (ctx.tu ().new_node<Emitter> ());
            
            ctx.tu ().new_edge<Belongs> (e, *type_);
            ctx.tu ().new_edge<Defines> (ctx.scope (), e, id->lexeme ());
          }
        }
      }
    }
  }
}

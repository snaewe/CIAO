// file      : CCF/IDL3/SemanticAction/Impl/Include.hpp
// author    : Boris Kolpackov <boris@dre.vanderbilt.edu>
// cvs-id    : $Id$

#ifndef CCF_IDL3_SEMANTIC_ACTION_IMPL_INCLUDE_HPP
#define CCF_IDL3_SEMANTIC_ACTION_IMPL_INCLUDE_HPP

#include <stack>
#include <set>

#include "CCF/CompilerElements/Context.hpp"
#include "CCF/CompilerElements/Diagnostic.hpp"

#include "CCF/IDL2/SemanticGraph/Translation.hpp"
#include "CCF/IDL3/SemanticGraph/Elements.hpp"

#include "CCF/IDL2/SemanticAction/Include.hpp"
#include "CCF/IDL3/SemanticAction/Elements.hpp"
#include "CCF/IDL3/SemanticAction/Impl/Elements.hpp"

#include "CCF/IDL3/SemanticAction/Factory.hpp"

namespace CCF
{
  namespace IDL3
  {
    namespace SemanticAction
    {
      namespace Impl
      {
        // Note: overriding IDL2 include to allow inclusion of IDL3 files
        //
        //
        class Include : public virtual IDL2::SemanticAction::Include
        {
        public:
          virtual
          ~Include () throw ();

          Include (Context& c,
                   CompilerElements::Context& context,
                   Diagnostic::Stream& dout,
                   SemanticAction::Factory& action_factory);

          virtual void
          quote (StringLiteralPtr const& sl);

          virtual void
          bracket (StringLiteralPtr const& sl);

          virtual void
          end ();

        private:
          enum Type_
          {
            quote_,
            bracket_
          };

          virtual void
          impl (StringLiteralPtr const& sl, Type_ type);

          bool
          handle_already_included (fs::path const& path,
                                   StringLiteralPtr const& sl);
        private:
          Context& ctx;

          CompilerElements::Context& context_;
          Diagnostic::Stream& dout_;
          SemanticAction::Factory& action_factory_;

          std::stack<SemanticGraph::TranslationRegion*> stack_;
          std::stack<fs::path> abs_path_stack_, rel_path_stack_;

          struct FilePathComparator
          {
            bool operator () (fs::path const& x, fs::path const& y) const
            {
              return x.string () < y.string ();
            }
          };

          std::set<fs::path, FilePathComparator> include_file_set_;
        };
      }
    }
  }
}

#endif  // CCF_IDL3_SEMANTIC_ACTION_IMPL_INCLUDE_HPP

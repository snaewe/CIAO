// file      : CCF/IDL2/SemanticGraph/Operation.hpp
// author    : Boris Kolpackov <boris@dre.vanderbilt.edu>
// cvs-id    : $Id$

#ifndef CCF_IDL2_SEMANTIC_GRAPH_OPERATION_HPP
#define CCF_IDL2_SEMANTIC_GRAPH_OPERATION_HPP

#include <string>

#include "CCF/IDL2/SemanticGraph/Elements.hpp"
#include "CCF/IDL2/SemanticGraph/Exception.hpp"
namespace CCF
{
  namespace IDL2
  {
    namespace SemanticGraph
    {
      class Operation;
      class Parameter;

      // Operation receives parameter
      //
      //
      class Receives : public virtual Edge
      {
      public:
        Operation&
        operation ()
        {
          return *operation_;
        }

        Parameter&
        parameter ()
        {
          return *parameter_;
        }

        static Introspection::TypeInfo const&
        static_type_info ();

      protected:
        friend class Graph<Node, Edge>;

        Receives ()
        {
          type_info (static_type_info ());
        }

        void
        set_left_node (Operation& n)
        {
          operation_ = &n;
        }

        void
        set_right_node (Parameter& n)
        {
          parameter_ = &n;
        }

      private:
        Operation* operation_;
        Parameter* parameter_;
      };


      // Operation returns
      //
      //
      class Returns : public virtual Belongs
      {
      public:
        static Introspection::TypeInfo const&
        static_type_info ();

      protected:
        friend class Graph<Node, Edge>;

        Returns ()
        {
          type_info (static_type_info ());
        }
      };


      // Raises
      //
      //
      class Raises : public virtual Edge
      {
      public:
        Operation&
        operation ()
        {
          return *operation_;
        }

        Exception&
        exception ()
        {
          return *exception_;
        }

        static Introspection::TypeInfo const&
        static_type_info ();

      protected:
        friend class Graph<Node, Edge>;

        Raises ()
        {
          type_info (static_type_info ());
        }

        void
        set_left_node (Operation& n)
        {
          operation_ = &n;
        }

        void
        set_right_node (Exception& n)
        {
          exception_ = &n;
        }

      private:
        Operation* operation_;
        Exception* exception_;
      };


      //
      //
      //
      class Parameter : public virtual Instance
      {
      public:
        std::string
        name () const
        {
          return name_;
        }

        static Introspection::TypeInfo const&
        static_type_info ();

      protected:
        friend class Graph<Node, Edge>;

        Parameter (std::string const& name)
            : name_ (name)
        {
          type_info (static_type_info ());
        }

        void
        add_edge_right (Receives& e)
        {
        }

      private:
        std::string name_;
      };


      class InParameter : public virtual Parameter
      {
      public:
        static Introspection::TypeInfo const&
        static_type_info ();

      protected:
        friend class Graph<Node, Edge>;

        InParameter (std::string const& name)
            : Parameter (name)
        {
          type_info (static_type_info ());
        }
      };

      class OutParameter : public virtual Parameter
      {
      public:
        static Introspection::TypeInfo const&
        static_type_info ();

      protected:
        friend class Graph<Node, Edge>;

        OutParameter (std::string const& name)
            : Parameter (name)
        {
          type_info (static_type_info ());
        }
      };

      class InOutParameter : public virtual Parameter
      {
      public:
        static Introspection::TypeInfo const&
        static_type_info ();

      protected:
        friend class Graph<Node, Edge>;

        InOutParameter (std::string const& name)
            : Parameter (name)
        {
          type_info (static_type_info ());
        }
      };


      // @@ How am I going to make Instance & Returns work together?
      //
      //
      class Operation : public virtual Nameable, public virtual Instance
      {
        typedef
        std::vector<Receives*>
        Receives_;

        typedef
        std::vector<Raises*>
        Raises_;

      public:
        typedef
        Receives_::const_iterator
        ReceivesIterator;

        ReceivesIterator
        receives_begin () const
        {
          return receives_.begin ();
        }

        ReceivesIterator
        receives_end () const
        {
          return receives_.end ();
        }

        typedef
        Raises_::const_iterator
        RaisesIterator;

        RaisesIterator
        raises_begin () const
        {
          return raises_.begin ();
        }

        RaisesIterator
        raises_end () const
        {
          return raises_.end ();
        }

        Returns&
        returns ()
        {
          return dynamic_cast<Returns&> (belongs ());
        }

        static Introspection::TypeInfo const&
        static_type_info ();

      protected:
        friend class Graph<Node, Edge>;

        Operation ()
        {
          type_info (static_type_info ());
        }

        void
        add_edge_left (Receives& e)
        {
          receives_.push_back (&e);
        }

        void
        add_edge_left (Raises& e)
        {
          raises_.push_back (&e);
        }

        void
        add_edge_left (Returns& e)
        {
          Instance::add_edge_left (e);
        }

      private:
        Receives_ receives_;
        Raises_ raises_;
      };


      //
      //
      //
      class OneWayOperation : public virtual Operation
      {
      public:
        static Introspection::TypeInfo const&
        static_type_info ();

      protected:
        friend class Graph<Node, Edge>;

        OneWayOperation ()
        {
          type_info (static_type_info ());
        }
      };


      //
      //
      //
      class TwoWayOperation : public virtual Operation
      {
      public:
        static Introspection::TypeInfo const&
        static_type_info ();

      protected:
        friend class Graph<Node, Edge>;

        TwoWayOperation ()
        {
          type_info (static_type_info ());
        }
      };
    }
  }
}

#endif  // CCF_IDL2_SEMANTIC_GRAPH_OPERATION_HPP

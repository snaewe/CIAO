// $Id$
//
// ****              Code generated by the                 ****
// ****  Component Integrated ACE ORB (CIAO) CIDL Compiler ****
// CIAO has been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// CIDL Compiler has been developed by:
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about CIAO is available at:
//    http://www.cs.wustl.edu/~nanbor/projects/CIAO-src/docs/index.html

#ifndef CIAO_GLUE_SESSION_RECEIVER_SVNT_H
#define CIAO_GLUE_SESSION_RECEIVER_SVNT_H

#include /**/ "ace/pre.h"

#include "ReceiverEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ciao/Container_Base.h"
#include "ciao/Servant_Impl_T.h"
#include "tao/LocalObject.h"
#include "tao/PortableServer/Key_Adapters.h"
#include "ace/Active_Map_Manager_T.h"

#include "ReceiverS.h"

namespace ReceiverImpl
{
  namespace CIAO_GLUE_Protocols
  {
    template <typename T>
    class test_Servant_T
    : public virtual POA_Protocols::test,
    public virtual PortableServer::RefCountServantBase
    {
      public:
      test_Servant_T (
      ::Protocols::CCM_test_ptr executor,
      ::Components::CCMContext_ptr ctx);

      virtual ~test_Servant_T (void);

      virtual void
      start_test (
      ::CORBA::Long session_id,
      const char * protocol,
      ::CORBA::ULong invocation_rate,
      ::CORBA::ULong message_size,
      ::CORBA::ULong iterations
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      virtual void
      end_test (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      virtual void
      oneway_sync (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      virtual void
      twoway_sync (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      virtual void
      oneway_method (
      ::CORBA::Long session_id,
      ::CORBA::ULong iteration,
      const ::Protocols::test::octets & payload
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      virtual void
      twoway_method (
      ::CORBA::Long & session_id,
      ::CORBA::ULong & iteration,
      ::Protocols::test::octets & payload
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      // Get component implementation.
      virtual CORBA::Object_ptr
      _get_component (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      protected:
      // Facet executor.
      ::Protocols::CCM_test_var executor_;

      // Context object.
      ::Components::CCMContext_var ctx_;
    };

    typedef RECEIVER_SVNT_Export test_Servant_T<int> test_Servant;
  }

  namespace CIAO_GLUE_Protocols
  {
    class RECEIVER_SVNT_Export Receiver_Context
    : public virtual ::Protocols::CCM_Receiver_Context,
    public virtual TAO_Local_RefCounted_Object
    {
      public:
      // We will allow the servant glue code we generate to access our state.
      friend class Receiver_Servant;

      Receiver_Context (
      ::Components::CCMHome_ptr home,
      ::CIAO::Session_Container *c,
      Receiver_Servant *sv);

      virtual ~Receiver_Context (void);

      // Operations from ::Components::CCMContext.

      virtual ::Components::Principal_ptr
      get_caller_principal (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      virtual ::Components::CCMHome_ptr
      get_CCM_home (
      ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC ((CORBA::SystemException));

      virtual CORBA::Boolean
      get_rollback_only (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::IllegalState));

      virtual ::Components::Transaction::UserTransaction_ptr
      get_user_transaction (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::IllegalState));

      virtual CORBA::Boolean
      is_caller_in_role (
      const char *role
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      virtual void
      set_rollback_only (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::IllegalState));

      // Operations from ::Components::SessionContext interface.

      virtual CORBA::Object_ptr
      get_CCM_object (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::IllegalState));

      // Operations for Receiver receptacles and event sources,
      // defined in ::Protocols::CCM_Receiver_Context.

      // CIAO-specific.

      ::CIAO::Session_Container *
      _ciao_the_Container (void) const;

      static Receiver_Context *
      _narrow (
      ::Components::SessionContext_ptr p
      ACE_ENV_ARG_DECL_WITH_DEFAULTS);

      protected:
      // Methods that manage this component's connections and consumers.

      protected:
      ::Components::CCMHome_var home_;

      ::CIAO::Session_Container *container_;

      Receiver_Servant *servant_;

      ::Protocols::Receiver_var component_;
    };
  }

  namespace CIAO_GLUE_Protocols
  {
    class RECEIVER_SVNT_Export Receiver_Servant
      : public virtual CIAO::Servant_Impl<
          POA_Protocols::Receiver,
          ::Protocols::CCM_Receiver,
          ::Protocols::CCM_Receiver_var,
          Receiver_Context
        >,
        public virtual PortableServer::RefCountServantBase
    {
      public:
      /// Hack for VC6 the most sucky compiler
      typedef CIAO::Servant_Impl<
      POA_Protocols::Receiver,
            ::Protocols::CCM_Receiver,
            ::Protocols::CCM_Receiver_var,
            Receiver_Context
          > our_base;

      Receiver_Servant (
      ::Protocols::CCM_Receiver_ptr executor,
      ::Components::CCMHome_ptr home,
      ::CIAO::Session_Container *c);

      virtual ~Receiver_Servant (void);

      // Supported operations.

      virtual void
      shutdown (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));
      // Public port operations.

      virtual ::Protocols::test_ptr
      provide_writer (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      // Component attribute operations.


      // Operations for Navigation interface.

      virtual CORBA::Object_ptr
      provide_facet (
      const char *name
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::InvalidName));

      virtual ::Components::FacetDescriptions *
      get_named_facets (
      const ::Components::NameList & /* names */
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::InvalidName));

      virtual CORBA::Boolean
      same_component (
      CORBA::Object_ptr object_ref
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      // Operations for Receptacles interface.

      virtual ::Components::Cookie *
      connect (
      const char *name,
      CORBA::Object_ptr connection
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::InvalidName,
      ::Components::InvalidConnection,
      ::Components::AlreadyConnected,
      ::Components::ExceededConnectionLimit));

      virtual CORBA::Object_ptr
      disconnect (
      const char *name,
      ::Components::Cookie *ck
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::InvalidName,
      ::Components::InvalidConnection,
      ::Components::CookieRequired,
      ::Components::NoConnection));

      virtual ::Components::ConnectionDescriptions *
      get_connections (
      const char *name
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::InvalidName));

      virtual ::Components::ReceptacleDescriptions *
      get_all_receptacles (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      virtual ::Components::ReceptacleDescriptions *
      get_named_receptacles (
      const ::Components::NameList & /* names */
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::InvalidName));

      // Operations for Events interface.

      virtual ::Components::EventConsumerBase_ptr
      get_consumer (
      const char *sink_name
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::InvalidName));

      virtual ::Components::Cookie *
      subscribe (
      const char *publisher_name,
      ::Components::EventConsumerBase_ptr subscriber
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::InvalidName,
      ::Components::InvalidConnection,
      ::Components::ExceededConnectionLimit));

      virtual ::Components::EventConsumerBase_ptr
      unsubscribe (
      const char *publisher_name,
      ::Components::Cookie *ck
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::InvalidName,
      ::Components::InvalidConnection));

      virtual void
      connect_consumer (
      const char *emitter_name,
      ::Components::EventConsumerBase_ptr consumer
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::InvalidName,
      ::Components::AlreadyConnected,
      ::Components::InvalidConnection));

      virtual ::Components::EventConsumerBase_ptr
      disconnect_consumer (
      const char *source_name
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::InvalidName,
      ::Components::NoConnection));

      virtual ::Components::ConsumerDescriptions *
      get_named_consumers (
      const ::Components::NameList & /* names */
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::InvalidName));

      virtual ::Components::EmitterDescriptions *
      get_all_emitters (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      virtual ::Components::EmitterDescriptions *
      get_named_emitters(
      const ::Components::NameList & /* names */
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::InvalidName));

      virtual ::Components::PublisherDescriptions *
      get_all_publishers (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      virtual ::Components::PublisherDescriptions *
      get_named_publishers(
      const ::Components::NameList & /* names */
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::InvalidName));

      // Operations for CCMObject interface.

      virtual CORBA::IRObject_ptr
      get_component_def (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      virtual ::Components::CCMHome_ptr
      get_ccm_home (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      virtual ::Components::PrimaryKeyBase *
      get_primary_key (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::NoKeyAvailable));

      virtual void
      configuration_complete (
      ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::InvalidConfiguration));

      virtual void
      remove (
      ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::RemoveFailure));

      virtual ::Components::ComponentPortDescription *
      get_all_ports(
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      // Get component implementation.
      virtual CORBA::Object_ptr
      _get_component (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      // CIAO-specific operations.

      void
      ciao_preactivate (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      void
      ciao_activate (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      void
      ciao_postactivate (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      /// @@NOTE: The busted operation.
      void
      _ciao_passivate (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      ::Protocols::test_var
      provide_writer_;

      private:

      void populate_port_tables (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));
    };
  }

  namespace CIAO_GLUE_Protocols
  {
    class RECEIVER_SVNT_Export ReceiverHome_Servant
    : public virtual POA_Protocols::ReceiverHome,
    public virtual PortableServer::RefCountServantBase
    {
      public:
      ReceiverHome_Servant (
      ::Protocols::CCM_ReceiverHome_ptr exe,
      ::CIAO::Session_Container *c);

      virtual ~ReceiverHome_Servant (void);

      // Home operations.

      // Home factory operations.

      // Attribute operations.

      // Operations for keyless home interface.

      virtual ::Components::CCMObject_ptr
      create_component (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::CreateFailure));

      // Operations for implicit home interface.

      virtual ::Protocols::Receiver_ptr
      create (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::CreateFailure));

      // Operations for CCMHome interface.

      virtual ::CORBA::IRObject_ptr
      get_component_def (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      virtual ::CORBA::IRObject_ptr
      get_home_def (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      virtual void
      remove_component (
      ::Components::CCMObject_ptr comp
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::RemoveFailure));

      // Supported operations.

      protected:
      // CIAO-specific operations.

      ::Protocols::Receiver_ptr
      _ciao_activate_component (
      ::Protocols::CCM_Receiver_ptr exe
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      void
      _ciao_passivate_component (
      ::Protocols::Receiver_ptr comp
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      protected:
      ::Protocols::CCM_ReceiverHome_var
      executor_;

      ::CIAO::Session_Container *
      container_;

      ACE_Hash_Map_Manager_Ex<
      PortableServer::ObjectId,
      Receiver_Servant *,
      TAO_ObjectId_Hash,
      ACE_Equal_To<PortableServer::ObjectId>,
      ACE_SYNCH_MUTEX>
      component_map_;
    };

    extern "C" RECEIVER_SVNT_Export ::PortableServer::Servant
    createReceiverHome_Servant (
    ::Components::HomeExecutorBase_ptr p,
    CIAO::Session_Container *c
    ACE_ENV_ARG_DECL_WITH_DEFAULTS);
  }
}

#include /**/ "ace/post.h"

#endif /* CIAO_GLUE_SESSION_RECEIVER_SVNT_H */


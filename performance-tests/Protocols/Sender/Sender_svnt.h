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

#ifndef CIAO_GLUE_SESSION_SENDER_SVNT_H
#define CIAO_GLUE_SESSION_SENDER_SVNT_H

#include /**/ "ace/pre.h"

#include "SenderEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ciao/Container_Base.h"
#include "ciao/Servant_Impl_T.h"
#include "tao/LocalObject.h"
#include "tao/PortableServer/Key_Adapters.h"
#include "ace/Active_Map_Manager_T.h"

#include "SenderS.h"

namespace SenderImpl
{
  namespace CIAO_GLUE_Protocols
  {
    class SENDER_SVNT_Export Sender_Context
    : public virtual ::Protocols::CCM_Sender_Context,
    public virtual TAO_Local_RefCounted_Object
    {
      public:
      // We will allow the servant glue code we generate to access our state.
      friend class Sender_Servant;

      Sender_Context (
      ::Components::CCMHome_ptr home,
      ::CIAO::Session_Container *c,
      Sender_Servant *sv);

      virtual ~Sender_Context (void);

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

      // Operations for Sender receptacles and event sources,
      // defined in ::Protocols::CCM_Sender_Context.

      virtual ::Protocols::test_ptr
      get_connection_reader (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      // CIAO-specific.

      ::CIAO::Session_Container *
      _ciao_the_Container (void) const;

      static Sender_Context *
      _narrow (
      ::Components::SessionContext_ptr p
      ACE_ENV_ARG_DECL_WITH_DEFAULTS);

      protected:
      // Methods that manage this component's connections and consumers.

      virtual void
      connect_reader (
      ::Protocols::test_ptr
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::AlreadyConnected,
      ::Components::InvalidConnection));

      virtual ::Protocols::test_ptr
      disconnect_reader (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::NoConnection));

      protected:
      // Simplex reader connection.
      ::Protocols::test_var
      ciao_uses_reader_;

      ::Components::CCMHome_var home_;

      ::CIAO::Session_Container *container_;

      Sender_Servant *servant_;

      ::Protocols::Sender_var component_;
    };
  }

  namespace CIAO_GLUE_Protocols
  {
    class SENDER_SVNT_Export Sender_Servant
      : public virtual CIAO::Servant_Impl<
          POA_Protocols::Sender,
          ::Protocols::CCM_Sender,
          ::Protocols::CCM_Sender_var,
          Sender_Context
        >,
        public virtual PortableServer::RefCountServantBase
    {
      public:
      /// Hack for VC6 the most sucky compiler
      typedef CIAO::Servant_Impl<
      POA_Protocols::Sender,
            ::Protocols::CCM_Sender,
            ::Protocols::CCM_Sender_var,
            Sender_Context
          > our_base;

      Sender_Servant (
      ::Protocols::CCM_Sender_ptr executor,
      ::Components::CCMHome_ptr home,
      ::CIAO::Session_Container *c);

      virtual ~Sender_Servant (void);

      // Supported operations.

      virtual void
      start (
      ::CORBA::ULong iterations,
      ::CORBA::ULong invocation_rate,
      ::CORBA::Boolean count_missed_end_deadlines,
      ::CORBA::Boolean do_dump_history,
      ::CORBA::Boolean print_missed_invocations,
      ::CORBA::ULong message_size,
      ::CORBA::ULong test_protocol_tag,
      ::CORBA::Boolean print_statistics,
      ::CORBA::ULong number_of_connection_attempts,
      ::CORBA::Boolean enable_diffserv_code_points,
      ::CORBA::Short priority,
      ::Protocols::Sender_Controller::Test_Type test_type
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));
      virtual void
      shutdown (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));
      // Public port operations.

      virtual void
      connect_reader (
      ::Protocols::test_ptr c
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::AlreadyConnected,
      ::Components::InvalidConnection));

      virtual ::Protocols::test_ptr
      disconnect_reader (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::NoConnection));

      virtual ::Protocols::test_ptr
      get_connection_reader (
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

      private:

      void populate_port_tables (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));
    };
  }

  namespace CIAO_GLUE_Protocols
  {
    class SENDER_SVNT_Export SenderHome_Servant
    : public virtual POA_Protocols::SenderHome,
    public virtual PortableServer::RefCountServantBase
    {
      public:
      SenderHome_Servant (
      ::Protocols::CCM_SenderHome_ptr exe,
      ::CIAO::Session_Container *c);

      virtual ~SenderHome_Servant (void);

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

      virtual ::Protocols::Sender_ptr
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

      ::Protocols::Sender_ptr
      _ciao_activate_component (
      ::Protocols::CCM_Sender_ptr exe
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      void
      _ciao_passivate_component (
      ::Protocols::Sender_ptr comp
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      protected:
      ::Protocols::CCM_SenderHome_var
      executor_;

      ::CIAO::Session_Container *
      container_;

      ACE_Hash_Map_Manager_Ex<
      PortableServer::ObjectId,
      Sender_Servant *,
      TAO_ObjectId_Hash,
      ACE_Equal_To<PortableServer::ObjectId>,
      ACE_SYNCH_MUTEX>
      component_map_;
    };

    extern "C" SENDER_SVNT_Export ::PortableServer::Servant
    createSenderHome_Servant (
    ::Components::HomeExecutorBase_ptr p,
    CIAO::Session_Container *c
    ACE_ENV_ARG_DECL_WITH_DEFAULTS);
  }
}

#include /**/ "ace/post.h"

#endif /* CIAO_GLUE_SESSION_SENDER_SVNT_H */


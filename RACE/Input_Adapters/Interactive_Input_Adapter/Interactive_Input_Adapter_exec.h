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
//    http://www.dre.vanderbilt.edu/CIAO

#ifndef CIAO_INTERACTIVE_INPUT_ADAPTER_EXEC_H
#define CIAO_INTERACTIVE_INPUT_ADAPTER_EXEC_H

#include /**/ "ace/pre.h"

#include "Interactive_Input_Adapter_svnt.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "Interactive_Input_Adapter_exec_export.h"
#include "tao/LocalObject.h"

namespace CIAO
{
  namespace RACE
  {
    namespace CIDL_Interactive_Input_Adapter_Impl
    {
      class INTERACTIVE_INPUT_ADAPTER_EXEC_Export Interactive_Input_Adapter_exec_i
      : public virtual Interactive_Input_Adapter_Exec,
      public virtual TAO_Local_RefCounted_Object
      {
        public:
        Interactive_Input_Adapter_exec_i (void);
        virtual ~Interactive_Input_Adapter_exec_i (void);

        // Supported or inherited operations.

        // Attribute operations.

        // Port operations.

        // Operations from Components::SessionComponent

        virtual void
        set_session_context (
        ::Components::SessionContext_ptr ctx)
        ACE_THROW_SPEC ((
        ::CORBA::SystemException,
        ::Components::CCMException));

        virtual void
        ciao_preactivate ()
        ACE_THROW_SPEC ((
        ::CORBA::SystemException,
        ::Components::CCMException));

        virtual void
        ciao_postactivate ()
        ACE_THROW_SPEC ((
        ::CORBA::SystemException,
        ::Components::CCMException));

        virtual void
        ccm_activate ()
        ACE_THROW_SPEC ((
        ::CORBA::SystemException,
        ::Components::CCMException));

        virtual void
        ccm_passivate ()
        ACE_THROW_SPEC ((
        ::CORBA::SystemException,
        ::Components::CCMException));

        virtual void
        ccm_remove ()
        ACE_THROW_SPEC ((
        ::CORBA::SystemException,
        ::Components::CCMException));

        protected:
        Interactive_Input_Adapter_Context *context_;
      };

      class INTERACTIVE_INPUT_ADAPTER_EXEC_Export Interactive_Input_Adapter_Home_exec_i
      : public virtual Interactive_Input_Adapter_Home_Exec,
      public virtual TAO_Local_RefCounted_Object
      {
        public:
        Interactive_Input_Adapter_Home_exec_i (void);
        virtual ~Interactive_Input_Adapter_Home_exec_i (void);

        // Supported or inherited operations.

        // Home operations.

        // Factory and finder operations.

        // Attribute operations.

        // Implicit operations.

        virtual ::Components::EnterpriseComponent_ptr
        create ()
        ACE_THROW_SPEC ((
        ::CORBA::SystemException,
        ::Components::CCMException));
      };

      extern "C" INTERACTIVE_INPUT_ADAPTER_EXEC_Export ::Components::HomeExecutorBase_ptr
      createInteractive_Input_Adapter_Home_Impl (void);
    }
  }
}

#include /**/ "ace/post.h"

#endif /* CIAO_INTERACTIVE_INPUT_ADAPTER_EXEC_H */


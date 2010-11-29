// -*- C++ -*-
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v1.8.3
 * TAO and the TAO IDL Compiler have been developed by:
 *       Center for Distributed Object Computing
 *       Washington University
 *       St. Louis, MO
 *       USA
 *       http://www.cs.wustl.edu/~schmidt/doc-center.html
 * and
 *       Distributed Object Computing Laboratory
 *       University of California at Irvine
 *       Irvine, CA
 *       USA
 * and
 *       Institute for Software Integrated Systems
 *       Vanderbilt University
 *       Nashville, TN
 *       USA
 *       http://www.isis.vanderbilt.edu/
 *
 * Information about TAO is available at:
 *     http://www.cs.wustl.edu/~schmidt/TAO.html
 **/

#include "InterReturnT_Sender_exec.h"
#include "InterReturnTA_conn_i.h"
#include "ace/OS_NS_unistd.h"

namespace CIAO_InterReturnT_Sender_Impl
{
  //============================================================
  // Worker thread for asynchronous invocations for MyFoo
  //============================================================
  asynch_foo_generator::asynch_foo_generator (
    ::InterReturnT::CCM_Sender_Context_ptr context,
     Atomic_UShort  &nr_of_received)
   : context_(::InterReturnT::CCM_Sender_Context::_duplicate (context)),
     nr_of_received_(nr_of_received)
  {
  }

  int asynch_foo_generator::svc ()
  {
    ACE_OS::sleep (3);
    ::InterReturnT::AMI4CCM_MyFoo_var my_foo_ami_  =
        context_->get_connection_sendc_run_my_foo();

    if (CORBA::is_nil (my_foo_ami_))
      {
        ACE_ERROR ((LM_ERROR, "ERROR Sender (ASYNCH) :\tfoo_ami is NIL !\n"));
        return 1;
      }
    else
      {
        ::InterReturnT::AMI4CCM_MyFooReplyHandler_var cb =
            new CIAO_InterReturnT_Sender_Impl::AMI4CCM_MyFooReplyHandler_i (
            this->nr_of_received_);

        //Invoke Asynchronous calls to test
        my_foo_ami_->sendc_ret_void (cb.in (), "Send me a void." );
        my_foo_ami_->sendc_ret_long (cb.in (),"Send me a long.");
        my_foo_ami_->sendc_ret_double (cb.in (),"Send me a double.");
        my_foo_ami_->sendc_ret_struct (cb.in (), "Send me a struct.");
        my_foo_ami_->sendc_ret_array (cb.in (),"Send me an array.");
        my_foo_ami_->sendc_ret_seq (cb.in (),"Send me a sequence.");
        my_foo_ami_->sendc_ret_union (cb.in (),"Send me a union.");
        my_foo_ami_->sendc_ret_enum (cb.in (),"Send me a enum value.");

      }
    return 0;
  }

  //============================================================
  // Worker thread for synchronous invocations for MyFoo
  //============================================================
  synch_foo_generator::synch_foo_generator (
    ::InterReturnT::CCM_Sender_Context_ptr context,
     Atomic_UShort  &nr_of_received)
   : context_(::InterReturnT::CCM_Sender_Context::_duplicate (context)),
     nr_of_received_(nr_of_received)
  {
  }

  int synch_foo_generator::svc ()
  {
    ACE_OS::sleep (3);
    ::InterReturnT::MyFoo_var my_foo_ami_ =
          context_->get_connection_run_my_foo ();

    //run some synch calls
    InterReturnT::TestStruct_var test_topic = 0;
    InterReturnT::TestArray_var topic_arr = 0;
    CORBA::Long l_cmd = 0;
    CORBA::String_var out_str;
    try
      {
        CORBA::Double ret =
           my_foo_ami_->ret_double ("Send me synch double",out_str, l_cmd);
        if ( (ret == 3.14 ) && (l_cmd == 3))
          {
            ++this->nr_of_received_;
          }
      }
    catch (const InterReturnT::InternalError&)
      {
        ACE_ERROR ((LM_ERROR, "ERROR: synch_foo_generator::ret_double: "
                               "Unexpected exception.\n"));
      }
    try
      {
        InterReturnT::TestArray_slice *arr =
           my_foo_ami_->ret_array ("Send me synch array",out_str, l_cmd);
        if ((l_cmd != 5) || (arr[1].x_array[2] != 102))
          {
            ACE_ERROR ((LM_ERROR, "ERROR MyFoo synchronous ret_array: "
                               "received the wrong long or array, expected 5 "
                               "and 102, received %u and %u\n",
                               l_cmd, arr[1].x_array[2]));
          }
        else
          {
            ++this->nr_of_received_;
          }
        if (arr)
          {
            InterReturnT::TestArray_free(arr);
            arr = 0;
          }
      }

    catch (const InterReturnT::InternalError&)
      {
        ACE_ERROR ((LM_ERROR, "ERROR: synch_foo_generator::ret_array: "
                               "Unexpected exception.\n"));
      }
    return 0;
  }
  /**
   * Component Executor Implementation Class: Sender_exec_i
   */

  Sender_exec_i::Sender_exec_i (void)
  : nr_of_received_(0)
  {
  }

  Sender_exec_i::~Sender_exec_i (void)
  {
  }

  // Supported operations and attributes.

  // Component attributes and port operations.

  // Operations from Components::SessionComponent.

  void
  Sender_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    this->ciao_context_ =
      ::InterReturnT::CCM_Sender_Context::_narrow (ctx);

    if ( ::CORBA::is_nil (this->ciao_context_.in ()))
      {
        throw ::CORBA::INTERNAL ();
      }
  }

  void
  Sender_exec_i::configuration_complete (void)
  {
    /* Your code here. */
  }

  void
  Sender_exec_i::ccm_activate (void)
  {
    this->asynch_foo_gen =
       new asynch_foo_generator (this->ciao_context_.in (),
                                  this->nr_of_received_);
    this->asynch_foo_gen->activate (THR_NEW_LWP | THR_JOINABLE, 1);

    this->synch_foo_gen =
        new synch_foo_generator (this->ciao_context_.in(),
                                 this->nr_of_received_);
    this->synch_foo_gen->activate (THR_NEW_LWP | THR_JOINABLE, 1);
  }

  void
  Sender_exec_i::ccm_passivate (void)
  {
    /* Your code here. */
  }

  void
  Sender_exec_i::ccm_remove (void)
  {
    if (this->nr_of_received_.value() == 10)
      {
        ACE_DEBUG ((LM_DEBUG, "OK: Sender received all expected return data"
                              " for syn- and asynchronous calls\n"));
      }
    else
      {
        ACE_ERROR ((LM_ERROR, "ERROR: Sender didn't receive all expected"
                              " return data for syn- and asynchronous"
                              " calls\n"));
      }
    delete this->asynch_foo_gen;
    this->asynch_foo_gen = 0;
    delete this->synch_foo_gen;
    this->synch_foo_gen = 0;
  }

  extern "C" INTERRETURN_T_SENDER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_InterReturnT_Sender_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_NORETURN (
      retval,
      Sender_exec_i);

    return retval;
  }
}

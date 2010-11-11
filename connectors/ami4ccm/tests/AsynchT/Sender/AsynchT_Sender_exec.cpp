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

#include "AsynchT_Sender_exec.h"
#include "AsynchTA_conn_i.h"
#include "ace/OS_NS_unistd.h"

namespace CIAO_AsynchT_Sender_Impl
{
   CORBA::Boolean asynch = false;

  //============================================================
   // Worker thread for asynchronous invocations for MyFoo
   //============================================================
   asynch_foo_generator::asynch_foo_generator (
               ::AsynchT::CCM_Sender_Context_ptr context,
               Atomic_UShort  &nr_of_sent,
               Atomic_UShort  &nr_of_rec)
   : context_(::AsynchT::CCM_Sender_Context::_duplicate (context)),
     nr_of_sent_(nr_of_sent),
     nr_of_rec_(nr_of_rec)
   {
   }

   int asynch_foo_generator::svc ()
   {
     ::AsynchT::AMI4CCM_MyFoo_var my_foo_ami_  =
        context_->get_connection_sendc_run_my_foo();

     ACE_OS::sleep(2);

     ::AsynchT::AMI4CCM_MyFooReplyHandler_var cb =
       new CIAO_AsynchT_Sender_Impl::AMI4CCM_MyFooReplyHandler_i (
                                                 this->nr_of_sent_,
                                                 this->nr_of_rec_);

     if (CORBA::is_nil (my_foo_ami_))
       {
          ACE_ERROR ((LM_ERROR, "ERROR Sender (ASYNCH) :"
                              "\tfoo_ami is NIL !\n"));
          return 1;
       }
     //Invoke Asynchronous calls to test
     ++this->nr_of_sent_;
     my_foo_ami_->sendc_foo ( cb.in(),"Hi ", 1);
     ACE_DEBUG ((LM_DEBUG, "OK: SEND ASYNCHRONOUS CALL foo.\n"));

     ++this->nr_of_sent_;
     my_foo_ami_->sendc_bar ( cb.in(), 1);
     ACE_DEBUG ((LM_DEBUG, "OK: SEND ASYNCHRONOUS CALL bar.\n"));

     ++this->nr_of_sent_;
     my_foo_ami_->sendc_get_rw_attrib( cb.in());
     ACE_DEBUG ((LM_DEBUG, "OK: SEND ASYNCHRONOUS CALL get_rw_attrib.\n"));

     ++this->nr_of_sent_;
     my_foo_ami_->sendc_set_rw_attrib( cb.in(),2);
     ACE_DEBUG ((LM_DEBUG, "OK: SEND ASYNCHRONOUS CALL set_rw_attrib.\n"));

     ++this->nr_of_sent_;
     ACE_DEBUG ((LM_DEBUG, "OK: SEND ASYNCHRONOUS CALL get_ro_attrib.\n"));
     my_foo_ami_->sendc_get_ro_attrib( cb.in());

     //there is more than 1 message sent, without receiving callbacks,
     //so it is asynchronous
     if (this->nr_of_sent_.value() > 1)
       {
         asynch = true;
       }
     return 0;
   }
   //============================================================
   // Worker thread for synchronous invocations for MyFoo
   //============================================================
   synch_foo_generator::synch_foo_generator (
    ::AsynchT::CCM_Sender_Context_ptr context)
   : context_(::AsynchT::CCM_Sender_Context::_duplicate (context))
   {
   }

   int synch_foo_generator::svc ()
   {
     ::AsynchT::MyFoo_var my_foo_ami_ =
          context_->get_connection_run_my_foo ();

     ACE_OS::sleep(1);
     CORBA::Boolean wait = false;
     for (int i = 0; i < 3; ++i)
       {
         // Run some synch calls, answer has to come before the next step.
          CORBA::String_var answer;
          try
            {
              if( wait==true)
                {
                  ACE_ERROR ((LM_ERROR,
                              "ERROR: NOT RECEIVED SYNCHRONOUS answer.\n"));
                }
              wait = true;
              ACE_DEBUG ((LM_DEBUG, "OK: SEND SYNCHRONOUS CALL foo.\n"));
              CORBA::Long result = my_foo_ami_->foo ("Do something synchronous",
                                                      2 ,
                                                      answer.out ());
              if ( result == 2)
                {
                  ACE_DEBUG ((LM_DEBUG, "OK: RECEIVED SYNCHRONOUS answer <%C>\n",
                                        answer.in ()));
                  wait = false;
                }
              if ( wait==true)
                {
                  ACE_ERROR ((LM_ERROR,
                              "ERROR: NOT RECEIVED SYNCHRONOUS answer.\n"));
                }
              wait = true;
              CORBA::Long l_cmd = 0;
              ACE_DEBUG ((LM_DEBUG, "OK: SEND SYNCHRONOUS CALL bar.\n"));
              my_foo_ami_->bar (2,l_cmd);
              if ( l_cmd == 2)
                {
                  ACE_DEBUG ((LM_DEBUG, "OK: RECEIVED SYNCHRONOUS answer <%C>\n",
                                        answer.in ()));
                  wait = false;
                }
             }
           catch (const AsynchT::InternalError&)
             {
               ACE_ERROR ((LM_ERROR, "ERROR: synch_foo_generator::foo: "
                                     "Unexpected exception.\n"));
             }
        }
     return 0;
   }
  /**
   * Component Executor Implementation Class: Sender_exec_i
   */

  Sender_exec_i::Sender_exec_i (void)
   : nr_of_sent_ (0),
     nr_of_rec_ (0)
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
      ::AsynchT::CCM_Sender_Context::_narrow (ctx);

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
                                this->nr_of_sent_,
                                this->nr_of_rec_);
    this->asynch_foo_gen->activate (THR_NEW_LWP | THR_JOINABLE, 1);

    this->synch_foo_gen =
        new synch_foo_generator (this->ciao_context_.in());
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
    if ((asynch == false) || (this->nr_of_rec_.value() != 5))
      {
        ACE_ERROR ((LM_ERROR,
                    "ERROR: Test not asynchronous or not received back"
                    " all requests ( %u/5)!\n",
                    this->nr_of_rec_.value() ));
      }
    else
      {
        ACE_DEBUG ((LM_DEBUG, "OK: Test asynchronous, received back %u.\n",
                      this->nr_of_rec_.value()));
      }
    if (this->asynch_foo_gen)
      {
        delete this->asynch_foo_gen;
        this->asynch_foo_gen = 0;
      }
    if (this->synch_foo_gen)
      {
        delete this->synch_foo_gen;
        this->synch_foo_gen = 0;
      }
  }

  extern "C" ASYNCHT_SENDER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_AsynchT_Sender_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_NORETURN (
      retval,
      Sender_exec_i);

    return retval;
  }
}

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

// TAO_IDL - Generated from
// be/be_codegen.cpp:1661

#include "InterInOutTA_conn_i.h"

namespace CIAO_InterInOutT_AMI4CCM_MyFoo_Connector_AMI4CCM_Connector_Impl
{
  CORBA::UShort update_val = InterInOutT::update_val;
  CORBA::UShort cmd_synch_ok = InterInOutT::cmd_synch_ok;
  CORBA::UShort cmd_synch_nok = InterInOutT::cmd_synch_nok;
  CORBA::UShort cmd_asynch_ok = InterInOutT::cmd_asynch_ok;
  CORBA::UShort cmd_asynch_nok = InterInOutT::cmd_asynch_nok;

  AMI4CCM_MyFooReplyHandler_i::AMI4CCM_MyFooReplyHandler_i (
       Atomic_UShort &nr_of_received)
   : nr_of_received_(nr_of_received)
  {
  }

  AMI4CCM_MyFooReplyHandler_i::~AMI4CCM_MyFooReplyHandler_i (void)
  {
  }

  void
  AMI4CCM_MyFooReplyHandler_i::foo (    ::CORBA::Long ami_return_val,
      ::CORBA::Long l_cmd,
      const char * answer)
    {
      if (( ami_return_val == ( cmd_asynch_ok + update_val )) &&
          ( l_cmd == ami_return_val) &&
          ( ACE_OS::strcmp (answer, "Hi from receiver") == 0))
       {
         ++this->nr_of_received_;
       }
  }

  void
  AMI4CCM_MyFooReplyHandler_i::foo_excep (     ::CCM_AMI::ExceptionHolder * excep_holder)
  {
    try
      {
        excep_holder->raise_exception ();
      }
    catch (const InterInOutT::InternalError& ex)
      {
        CIAO_InterInOutT_Sender_Impl::HandleException (ex.id, (cmd_asynch_nok + update_val),
                         ex.error_string.in(), "asynch foo");
      }
    catch (const CORBA::Exception& ex)
      {
        ex._tao_print_exception ("ERROR: Caught unexpected exception:");
      }
  }
  void
  AMI4CCM_MyFooReplyHandler_i::var_ins (const char * /* answer */,
  ::CORBA::Double cmd )
  {
    if (cmd == 3.2)
    {
        ++this->nr_of_received_;
    }
  }

  void
  AMI4CCM_MyFooReplyHandler_i::var_ins_excep (
      ::CCM_AMI::ExceptionHolder_ptr  excep_holder)
  {
    excep_holder->raise_exception ();
  }

  void
  AMI4CCM_MyFooReplyHandler_i::var_div_ins (
      const InterInOutT::TestTopic &test_topic,
      const InterInOutT::TopicString &topic_str,
      const InterInOutT::TestArray topic_arr,
      const char * /*answer*/)
  {
    CORBA::Boolean error = false;
    if ((ACE_OS::strcmp (test_topic.key, "111") != 0) || (test_topic.x != 111))
      {
        ACE_ERROR ((LM_ERROR, "MyFoo_exec_i::var_div_ins: "
                             "received the wrong struct, "
                             "expected key '111', x = 111,"
                             " received key '%C' , x = %u\n",
                             test_topic.key.in(),test_topic.x));
        error = true;
      }

    if ((ACE_OS::strcmp (topic_str.key, "222") != 0) ||
    (ACE_OS::strcmp (topic_str.x_str, "333") != 0))
      {
        ACE_ERROR ((LM_ERROR, "MyFoo_exec_i::var_div_ins: "
                             "received the wrong struct, "
                             "expected key '222', x = '333',"
                             " received key '%C' , x = %C\n",
                             topic_str.key.in() ,topic_str.x_str.in()));
        error = true;
      }

    if ((ACE_OS::strcmp (topic_arr[0].key, "444") != 0) ||
    (topic_arr[1].x_array[2] != 444))
      {
        ACE_ERROR ((LM_ERROR, "MyFoo_exec_i::var_div_ins: "
                             "received the wrong struct, "
                             "expected key '444', elem 444"
                             " received key '%C', elem %u\n",
                             topic_arr[0].key.in(),topic_arr[1].x_array[2] ));
        error = true;
      }

    if(error == false)
      {
          ++this->nr_of_received_;
      }
  }

  void
  AMI4CCM_MyFooReplyHandler_i::var_div_ins_excep (
      ::CCM_AMI::ExceptionHolder_ptr  excep_holder)
  {
    excep_holder->raise_exception ();
  }

  void
  AMI4CCM_MyFooReplyHandler_i::var_div2_ins (const InterInOutT::X_Union &x_uni,
      const InterInOutT::test_seq &seq,
      const char * /*answer*/)
  {
    CORBA::Boolean error = false;
    if (x_uni.x_long() != 555)
      {
        ACE_ERROR ((LM_ERROR, "MyFoo_exec_i::var_div2_ins: "
        "received the wrong union, "
        "expected x = 555,"
        " received x = %u\n",
        x_uni.x_long()));
        error = true;
      }
    if ((ACE_OS::strcmp (seq[0].x_teststr, "666") != 0)||
    (seq[0].x_test != 666))
      {
        ACE_ERROR ((LM_ERROR, "MyFoo_exec_i::var_div2_ins: "
        "received the wrong struct, "
        "expected key '666', x = 666,"
        " received key '%C' , x = %u\n",
        seq[0].x_teststr.in(),seq[0].x_test));
        error = true;
      }
    if(error == false)
      {
        ++this->nr_of_received_;
      }
  }

  void
  AMI4CCM_MyFooReplyHandler_i::var_div2_ins_excep (
      ::CCM_AMI::ExceptionHolder_ptr  excep_holder )
  {
    excep_holder->raise_exception ();
  }

  void
  AMI4CCM_MyFooReplyHandler_i::enum_in (const char * /*answer*/,
      InterInOutT::test_enum test_enum)
  {
  if ( test_enum != InterInOutT::TWO)
    {
      ACE_ERROR ((LM_ERROR, "MyFoo_exec_i::enum_in: "
      "received the wrong enum value, expected TWO,"
      " received %u\n",
      test_enum));
    }
  else
    {
       ++this->nr_of_received_;
    }
  }

  void
  AMI4CCM_MyFooReplyHandler_i::enum_in_excep (
      ::CCM_AMI::ExceptionHolder_ptr excep_holder)
  {
    excep_holder->raise_exception ();
  }
}

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

#include "UsesMultiA_conn_i.h"

namespace CIAO_UsesMulti_Sender_Impl
{
  AMI4CCM_OneReplyHandler_i::AMI4CCM_OneReplyHandler_i (
      Atomic_UShort  &nr_of_received,
      Atomic_UShort  &nr_of_sent)
  : nr_of_received_(nr_of_received),
    nr_of_sent_(nr_of_sent)
  {
  }

  AMI4CCM_OneReplyHandler_i::~AMI4CCM_OneReplyHandler_i (void)
  {
  }

  void
  AMI4CCM_OneReplyHandler_i::foo (::CORBA::Long /* ami_return_val */,
  const char * answer)
  {
    ACE_DEBUG ((LM_DEBUG, "Sender: Get asynchronous callback from foo,"
                            " answer = <%C>\n",
                            answer));
    ++this->nr_of_received_;
    --this->nr_of_sent_;
  }

  void
  AMI4CCM_OneReplyHandler_i::foo_excep (
      ::CCM_AMI::ExceptionHolder_ptr excep_holder)
  {
    excep_holder->raise_exception ();
  }
}

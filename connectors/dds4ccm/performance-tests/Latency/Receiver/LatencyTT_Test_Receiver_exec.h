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
#ifndef CIAO_LATENCYTT_TEST_RECEIVER_EXEC_SYGLHE_H_
#define CIAO_LATENCYTT_TEST_RECEIVER_EXEC_SYGLHE_H_

#include /**/ "ace/pre.h"

#include "LatencyTT_Test_ReceiverEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include /**/ "Receiver_exec_export.h"
#include "tao/LocalObject.h"

namespace CIAO_LatencyTT_Test_Receiver_Impl
{
  class Receiver_exec_i;

  /**
   * Provider Executor Implementation Class: info_listen_data_listener_exec_i
   */

  class info_listen_data_listener_exec_i
    : public virtual ::LatencyTT_Test::LatencyTTTestConn::CCM_Listener,
      public virtual ::CORBA::LocalObject
  {
  public:
    info_listen_data_listener_exec_i (
      ::LatencyTT_Test::CCM_Receiver_Context_ptr ctx,
      Receiver_exec_i &callback);
    virtual ~info_listen_data_listener_exec_i (void);

    //@{
    /** Operations and attributes from LatencyTT_Test::LatencyTTTestConn::Listener. */

    virtual
    void on_one_data (const ::LatencyTTTest & datum,
    const ::CCM_DDS::ReadInfo & info);

    virtual
    void on_many_data (const ::LatencyTTTestSeq & data,
    const ::CCM_DDS::ReadInfoSeq & infos);
    //@}

  private:
    ::LatencyTT_Test::CCM_Receiver_Context_var ciao_context_;
    Receiver_exec_i &callback_;
  };

  /**
   * Component Executor Implementation Class: Receiver_exec_i
   */

  class Receiver_exec_i
    : public virtual Receiver_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    Receiver_exec_i (void);
    virtual ~Receiver_exec_i (void);

    //@{
    /** Supported operations and attributes. */

    //@}

    //@{
    /** Component attributes and port operations. */

    virtual ::LatencyTT_Test::LatencyTTTestConn::CCM_Listener_ptr
    get_info_listen_data_listener (void);

    virtual ::CCM_DDS::CCM_PortStatusListener_ptr
    get_info_listen_status (void);
    //@}

    //@{
    /** Operations from Components::SessionComponent. */
    virtual void set_session_context (::Components::SessionContext_ptr ctx);
    virtual void configuration_complete (void);
    virtual void ccm_activate (void);
    virtual void ccm_passivate (void);
    virtual void ccm_remove (void);
    //@}

    //@{
    /** User defined public operations. */
    void write_one (const LatencyTTTest & an_instance);

    //@}

  private:
    ::LatencyTT_Test::CCM_Receiver_Context_var ciao_context_;

    //@{
    /** Component attributes. */
    ::LatencyTT_Test::LatencyTTTestConn::CCM_Listener_var ciao_info_listen_data_listener_;
    //@}

    //@{
    /** User defined members. */
    CORBA::ULong count_;
    ::LatencyTT_Test::LatencyTTTestConn::Writer_var writer_;

    //@}

    //@{
    /** User defined private operations. */
    void start (void);

    //@}
  };

  extern "C" RECEIVER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_LatencyTT_Test_Receiver_Impl (void);
}

#include /**/ "ace/post.h"

#endif /* ifndef */

// -*- C++ -*-
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v1.8.2
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

#include "Shapes_Receiver_comp_exec.h"

namespace CIAO_Shapes_Receiver_comp_Impl
{
  //============================================================
  // Facet Executor Implementation Class: info_out_data_listener_exec_i
  //============================================================

  info_out_data_listener_exec_i::info_out_data_listener_exec_i (
        ::Shapes::CCM_Receiver_comp_Context_ptr ctx)
    : ciao_context_ (
        ::Shapes::CCM_Receiver_comp_Context::_duplicate (ctx))
  {
  }

  info_out_data_listener_exec_i::~info_out_data_listener_exec_i (void)
  {
  }

  // Operations from ::Shapes::ShapeType_conn::Listener

  void
  info_out_data_listener_exec_i::on_one_data (
    const ::ShapeType & /* datum */,
    const ::CCM_DDS::ReadInfo & /* info */)
  {
    /* Your code here. */
  }

  void
  info_out_data_listener_exec_i::on_many_data (
    const ::Shapes::ShapeTypeSeq & /* data */,
    const ::CCM_DDS::ReadInfoSeq & /* infos */)
  {
    /* Your code here. */
  }
  //============================================================
  // Facet Executor Implementation Class: info_out_status_exec_i
  //============================================================

  info_out_status_exec_i::info_out_status_exec_i (
        ::Shapes::CCM_Receiver_comp_Context_ptr ctx)
    : ciao_context_ (
        ::Shapes::CCM_Receiver_comp_Context::_duplicate (ctx))
  {
  }

  info_out_status_exec_i::~info_out_status_exec_i (void)
  {
  }

  // Operations from ::CCM_DDS::PortStatusListener

  void
  info_out_status_exec_i::on_requested_deadline_missed (
    ::DDS::DataReader_ptr /* the_reader */,
    const ::DDS::RequestedDeadlineMissedStatus & /* status */)
  {
    /* Your code here. */
  }

  void
  info_out_status_exec_i::on_sample_lost (
    ::DDS::DataReader_ptr /* the_reader */,
    const ::DDS::SampleLostStatus & /* status */)
  {
    /* Your code here. */
  }
  //============================================================
  // Component Executor Implementation Class: Receiver_comp_exec_i
  //============================================================

  Receiver_comp_exec_i::Receiver_comp_exec_i (void)
  {
  }

  Receiver_comp_exec_i::~Receiver_comp_exec_i (void)
  {
  }

  // Supported operations and attributes.

  // Component attributes and port operations.

  ::Shapes::ShapeType_conn::CCM_Listener_ptr
  Receiver_comp_exec_i::get_info_out_data_listener (void)
  {
    if ( ::CORBA::is_nil (this->ciao_info_out_data_listener_.in ()))
      {
        info_out_data_listener_exec_i *tmp = 0;
        ACE_NEW_RETURN (
          tmp,
          info_out_data_listener_exec_i (
            this->ciao_context_.in ()),
          ::Shapes::ShapeType_conn::CCM_Listener::_nil ());

        this->ciao_info_out_data_listener_ = tmp;
      }

    return
      ::Shapes::ShapeType_conn::CCM_Listener::_duplicate (
        this->ciao_info_out_data_listener_.in ());
  }

  ::CCM_DDS::CCM_PortStatusListener_ptr
  Receiver_comp_exec_i::get_info_out_status (void)
  {
    if ( ::CORBA::is_nil (this->ciao_info_out_status_.in ()))
      {
        info_out_status_exec_i *tmp = 0;
        ACE_NEW_RETURN (
          tmp,
          info_out_status_exec_i (
            this->ciao_context_.in ()),
          ::CCM_DDS::CCM_PortStatusListener::_nil ());

        this->ciao_info_out_status_ = tmp;
      }

    return
      ::CCM_DDS::CCM_PortStatusListener::_duplicate (
        this->ciao_info_out_status_.in ());
  }

  // Operations from Components::SessionComponent.

  void
  Receiver_comp_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    this->ciao_context_ =
      ::Shapes::CCM_Receiver_comp_Context::_narrow (ctx);

    if ( ::CORBA::is_nil (this->ciao_context_.in ()))
      {
        throw ::CORBA::INTERNAL ();
      }
  }

  void
  Receiver_comp_exec_i::configuration_complete (void)
  {
    /* Your code here. */
  }

  void
  Receiver_comp_exec_i::ccm_activate (void)
  {
    /* Your code here. */
  }

  void
  Receiver_comp_exec_i::ccm_passivate (void)
  {
    /* Your code here. */
  }

  void
  Receiver_comp_exec_i::ccm_remove (void)
  {
    /* Your code here. */
  }

  extern "C"  ::Components::EnterpriseComponent_ptr
  create_Shapes_Receiver_comp_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_NORETURN (
      retval,
      Receiver_comp_exec_i);

    return retval;
  }
}

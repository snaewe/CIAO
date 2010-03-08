// -*- C++ -*-
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v1.7.6
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
 *       http://doc.ece.uci.edu/
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
// .\be\be_codegen.cpp:1278

#include "Null_Component_exec.h"

namespace CIAO_Null_Component_Impl
{
  //============================================================
  // Facet Executor Implementation Class: Null_Interface_exec_i
  //============================================================
  
  Null_Interface_exec_i::Null_Interface_exec_i (void)
  {
  }
  
  Null_Interface_exec_i::~Null_Interface_exec_i (void)
  {
  }
  
  // Operations from ::Null_Interface
  
  void
  Null_Interface_exec_i::null_operation (void)
  {
    /* Your code here. */
  }
  
  //============================================================
  // Component Executor Implementation Class: Null_Component_exec_i
  //============================================================
  
  Null_Component_exec_i::Null_Component_exec_i (void)
  {
  }
  
  Null_Component_exec_i::~Null_Component_exec_i (void)
  {
  }
  
  // Supported operations and attributes.
  
  // Component attributes and port operations.
  
  ::CCM_Null_Interface_ptr
  Null_Component_exec_i::get_null_facet (void)
  {
    /* Your code here. */
    return ::CCM_Null_Interface::_nil ();
  }
  
  // Operations from Components::SessionComponent.
  
  void
  Null_Component_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    this->context_ =
      ::CCM_Null_Component_Context::_narrow (ctx);
    
    if ( ::CORBA::is_nil (this->context_.in ()))
      {
        throw ::CORBA::INTERNAL ();
      }
  }
  
  void
  Null_Component_exec_i::configuration_complete (void)
  {
    /* Your code here. */
  }
  
  void
  Null_Component_exec_i::ccm_activate (void)
  {
    /* Your code here. */
  }
  
  void
  Null_Component_exec_i::ccm_passivate (void)
  {
    /* Your code here. */
  }
  
  void
  Null_Component_exec_i::ccm_remove (void)
  {
    /* Your code here. */
  }
  
  extern "C" NULL_COMPONENT_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Null_Component_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();
    
    ACE_NEW_NORETURN (
      retval,
      Null_Component_exec_i);
    
    return retval;
  }
}

namespace CIAO_Null_Component_Impl
{
  //============================================================
  // Home Executor Implementation Class: Null_ComponentHome_exec_i
  //============================================================
  
  Null_ComponentHome_exec_i::Null_ComponentHome_exec_i (void)
  {
  }
  
  Null_ComponentHome_exec_i::~Null_ComponentHome_exec_i (void)
  {
  }
  
  // All operations and attributes.
  
  // Factory operations.
  
  // Finder operations.
  
  // Implicit operations.
  
  ::Components::EnterpriseComponent_ptr
  Null_ComponentHome_exec_i::create (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();
    
    ACE_NEW_THROW_EX (
      retval,
      Null_Component_exec_i,
      ::CORBA::NO_MEMORY ());
    
    return retval;
  }
  
  extern "C" NULL_COMPONENT_EXEC_Export ::Components::HomeExecutorBase_ptr
  create_Null_ComponentHome_Impl (void)
  {
    ::Components::HomeExecutorBase_ptr retval =
      ::Components::HomeExecutorBase::_nil ();
    
    ACE_NEW_NORETURN (
      retval,
      Null_ComponentHome_exec_i);
    
    return retval;
  }
}


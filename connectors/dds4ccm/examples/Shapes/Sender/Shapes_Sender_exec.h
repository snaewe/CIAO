// -*- C++ -*-
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v2.0.0
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
#ifndef CIAO_SHAPES_SENDER_EXEC_ETSDUL_H_
#define CIAO_SHAPES_SENDER_EXEC_ETSDUL_H_

#include /**/ "ace/pre.h"

#include "Shapes_SenderEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include /**/ "Sender_exec_export.h"
#include "tao/LocalObject.h"

namespace CIAO_Shapes_Sender_Impl
{
  class Sender_exec_i;

  /**
   * Write action generator
   */

  class pulse_Generator : public ACE_Event_Handler
  {
  public:
    pulse_Generator (Sender_exec_i &callback);

    virtual ~pulse_Generator ();

    virtual int handle_timeout (const ACE_Time_Value &tv,
                                const void *arg);
  private:
    Sender_exec_i &pulse_callback_;
  };

  /**
   * Component Executor Implementation Class: Sender_exec_i
   */

  class Sender_exec_i
    : public virtual Sender_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    Sender_exec_i (void);
    virtual ~Sender_exec_i (void);

    //@{
    /** Supported operations and attributes. */

    //@}

    //@{
    /** Component attributes and port operations. */

    virtual ::CORBA::ULong rate (void);

    virtual void rate (::CORBA::ULong rate);

    virtual ::CORBA::UShort max_x (void);

    virtual void max_x (::CORBA::UShort max_x);

    virtual ::CORBA::UShort max_y (void);

    virtual void max_y (::CORBA::UShort max_y);

    virtual ::CORBA::UShort max_size (void);

    virtual void max_size (::CORBA::UShort max_size);

    virtual ::CORBA::Boolean resize_shape (void);

    virtual void resize_shape (::CORBA::Boolean resize_shape);

    virtual char *color (void);

    virtual void color (const char* color);
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
    void tick (void);

    //@}

  private:
    ::Shapes::CCM_Sender_Context_var ciao_context_;

    //@{
    /** Component attributes. */

    ::CORBA::ULong rate_;

    ::CORBA::UShort max_x_;

    ::CORBA::UShort max_y_;

    ::CORBA::UShort max_size_;

    ::CORBA::Boolean resize_shape_;

    ::CORBA::String_var color_;
    //@}

    //@{
    /** User defined members. */
    void start (void);
    void stop (void);

    pulse_Generator * ticker_;

    bool x_increasing_;
    bool y_increasing_;
    bool size_increasing_;

    ShapeType* square_;

    ::DDS::InstanceHandle_t instance_handle_;

    //@}

    //@{
    /** User defined private operations. */

    //@}

    /// Get the ACE_Reactor
    ACE_Reactor* reactor (void);
  };

  extern "C" SENDER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Shapes_Sender_Impl (void);
}

#include /**/ "ace/post.h"

#endif /* ifndef */

// $Id$

#include "TopicDescription.h"
#include "DomainParticipant.h"

#include "dds4ccm/idl/dds4ccm_BaseC.h"

#include "dds4ccm/impl/logger/Log_Macros.h"

namespace CIAO
{
  namespace DDS4CCM
  {
    CCM_DDS_TopicDescription_i::CCM_DDS_TopicDescription_i (
      DDSTopicDescription * rc) : impl_ (rc)
    {
    }

    CCM_DDS_TopicDescription_i::~CCM_DDS_TopicDescription_i (void)
    {
    }

    char *
    CCM_DDS_TopicDescription_i::get_type_name (void)
    {
#if defined (CIAO_DDS4CCM_NDDS) && (CIAO_DDS4CCM_NDDS==1)
      return CORBA::string_dup (this->impl ()->get_type_name ());
#else
      return this->impl ()->get_type_name ();
#endif
    }

    char *
    CCM_DDS_TopicDescription_i::get_name (void)
    {
#if defined (CIAO_DDS4CCM_NDDS) && (CIAO_DDS4CCM_NDDS==1)
      return CORBA::string_dup (this->impl ()->get_name ());
#else
      return this->impl ()->get_name ();
#endif
    }

    ::DDS::DomainParticipant_ptr
    CCM_DDS_TopicDescription_i::get_participant (void)
    {
      ::DDS::DomainParticipant_var retval = ::DDS::DomainParticipant::_nil ();
#if defined (CIAO_DDS4CCM_NDDS) && (CIAO_DDS4CCM_NDDS==1)
      ACE_NEW_THROW_EX (retval,
                        ::CIAO::DDS4CCM::RTI::RTI_DomainParticipant_i (),
                        CORBA::NO_MEMORY ());
      DDSDomainParticipant* p = this->impl ()->get_participant ();
      ::CIAO::DDS4CCM::RTI::RTI_DomainParticipant_i *rti_dp = dynamic_cast < ::CIAO::DDS4CCM::RTI::RTI_DomainParticipant_i *> (retval.in ());
      rti_dp->set_impl (p);
#else
      ::DDS::DomainParticipant_var p = this->impl ()->get_participant ();
      ACE_NEW_THROW_EX (retval,
                        RTI_DomainParticipant_i (p.in ()),
                        CORBA::NO_MEMORY ());
#endif
      return retval._retn ();
    }

    DDSTopicDescription *
    CCM_DDS_TopicDescription_i::get_impl (void)
    {
      return this->impl_;
    }

    void
    CCM_DDS_TopicDescription_i::set_impl (DDSTopicDescription * rc)
    {
      this->impl_ = rc;
    }

    DDSTopicDescription *
    CCM_DDS_TopicDescription_i::impl (void)
    {
      if (!this->impl_)
        {
          throw ::CORBA::BAD_INV_ORDER ();
        }
      return this->impl_;
    }
  }
}


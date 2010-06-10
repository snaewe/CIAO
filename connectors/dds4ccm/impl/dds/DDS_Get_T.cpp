// -*- C++ -*-
// $Id$

#include "dds4ccm/impl/dds/Log_Macros.h"

template <typename DDS_TYPE, typename CCM_TYPE, bool FIXED>
DDS_Get_T<DDS_TYPE, CCM_TYPE, FIXED>::DDS_Get_T (void)
{
}

template <typename DDS_TYPE, typename CCM_TYPE, bool FIXED>
DDS_Get_T<DDS_TYPE, CCM_TYPE, FIXED>::~DDS_Get_T (void)
{
}

template <typename DDS_TYPE, typename CCM_TYPE, bool FIXED>
bool
DDS_Get_T<DDS_TYPE, CCM_TYPE, FIXED>::configuration_complete (
  typename CCM_TYPE::base_type::_ptr_type component,
  ::DDS::Topic_ptr topic,
  ::DDS::Subscriber_ptr subscriber,
  const char* library_name,
  const char* profile_name)
{
  DDS4CCM_TRACE ("DDS_Get_T<DDS_TYPE, CCM_TYPE, FIXED>::configuration_complete");
  if (DDSSubscriberBase::configuration_complete(component,
                                                topic,
                                                subscriber,
                                                library_name,
                                                profile_name))
    {
      this->dds_get_.set_impl (&this->data_reader_);
      this->dds_get_._set_component (component);
    }
  return true;
}

template <typename DDS_TYPE, typename CCM_TYPE, bool FIXED>
typename CCM_TYPE::getter_type::_ptr_type
DDS_Get_T<DDS_TYPE, CCM_TYPE, FIXED>::get_fresh_data (void)
{
  DDS4CCM_TRACE ("DDS_Get_T<DDS_TYPE, CCM_TYPE, FIXED>::get_fresh_data");

  return &this->dds_get_;
}

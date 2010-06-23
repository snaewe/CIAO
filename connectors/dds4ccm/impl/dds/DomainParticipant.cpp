// $Id$

#include "Subscriber.h"
#include "Publisher.h"
#include "ContentFilteredTopic.h"
#include "TopicDescription.h"
#include "Utils.h"
#include "StatusCondition.h"
#include "PublisherListener.h"
#include "SubscriberListener.h"
#include "Topic.h"
#include "TopicListener.h"
#include "DomainParticipantListener.h"

#include "ndds/PublisherQos.h"
#include "ndds/SubscriberQos.h"
#include "ndds/TopicQos.h"
#include "ndds/DomainParticipantQos.h"
#include "ndds/InstanceHandle_t.h"
#include "ndds/Duration_t.h"
#include "ndds/Time_t.h"
#include "ndds/InstanceHandleSeq.h"
#include "ndds/TopicBuiltinTopicData.h"
#include "ndds/ParticipantBuiltinTopicData.h"

#include "dds4ccm/idl/dds4ccm_BaseC.h"

#include "dds4ccm/impl/dds/Log_Macros.h"

#include "ace/CORBA_macros.h"

namespace CIAO
{
  namespace DDS4CCM
  {
    template <typename DDS_TYPE, typename CCM_TYPE>
    CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::CCM_DDS_DomainParticipant_i (
      DDSDomainParticipant * dp) : impl_ (dp)
    {
      DDS4CCM_TRACE ("CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::CCM_DDS_DomainParticipant_i");
    }

    template <typename DDS_TYPE, typename CCM_TYPE>
    CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::~CCM_DDS_DomainParticipant_i (void)
    {
      DDS4CCM_TRACE ("CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::~CCM_DDS_DomainParticipant_i");
    }

#if (CIAO_DDS4CCM_NDDS==1)
    template <typename DDS_TYPE, typename CCM_TYPE>
    ::DDS::Publisher_ptr
    CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::create_publisher_with_profile (
      const char* library_name,
      const char *profile_name,
      ::DDS::PublisherListener_ptr a_listener,
      ::DDS::StatusMask mask)
    {
      DDS4CCM_TRACE ("DDS_DomainParticipant_i::create_publisher_with_profile");

      DDS4CCM_DEBUG (9, (LM_TRACE, CLINFO "CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::create_publisher_with_profile - "
                   "Creating Publisher\n"));
      CCM_DDS_PublisherListener_i<DDS_TYPE, CCM_TYPE> *ccm_dds_pl = 0;
      if (! ::CORBA::is_nil (a_listener))
        {
          ACE_NEW_THROW_EX (ccm_dds_pl,
                            PublisherListener_type (a_listener),
                            CORBA::NO_MEMORY ());
        }
      DDSPublisher * ccm_dds_pub =
        this->impl ()->create_publisher_with_profile (library_name,
                                                      profile_name,
                                                      ccm_dds_pl,
                                                      mask);

      if (!ccm_dds_pub)
        {
          DDS4CCM_ERROR (1, (LM_ERROR, CLINFO "CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::create_publisher_with_profile - "
                       "Error: Unable to create Publisher\n"));
          delete ccm_dds_pl;
          throw CCM_DDS::InternalError (::DDS::RETCODE_ERROR, 0);
        }

      ::DDS::Publisher_var retval = ::DDS::Publisher::_nil ();
      ACE_NEW_THROW_EX (retval,
                        Publisher_type (ccm_dds_pub),
                        CORBA::NO_MEMORY ());


      DDS4CCM_DEBUG (6, (LM_INFO, CLINFO "CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::create_publisher_with_profile - "
                   "Successfully created a DDSPublisher\n"));

      ccm_dds_pub->enable ();
      return retval._retn ();
    }
#endif

    template <typename DDS_TYPE, typename CCM_TYPE>
    ::DDS::Publisher_ptr
    CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::create_publisher (
      const ::DDS::PublisherQos & qos,
      ::DDS::PublisherListener_ptr a_listener,
      ::DDS::StatusMask mask)
    {
      DDS4CCM_TRACE ("DDS_DomainParticipant_i::create_publisher");
#if (CIAO_DDS4CCM_NDDS==1)
      ACE_UNUSED_ARG (qos);
      DDS4CCM_DEBUG (9, (LM_TRACE, CLINFO "CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::create_publisher - "
                   "Creating Publisher\n"));

      DDS_PublisherQos ccm_dds_qos = DDS_PUBLISHER_QOS_DEFAULT;

      CCM_DDS_PublisherListener_i<DDS_TYPE, CCM_TYPE> *ccm_dds_pl = 0;
      if (! ::CORBA::is_nil (a_listener))
        {
          ccm_dds_pl = new CCM_DDS_PublisherListener_i<DDS_TYPE, CCM_TYPE> (a_listener);
//           ACE_NEW_THROW_EX (ccm_dds_pl,
//                             CCM_DDS_PublisherListener_i (a_listener),
//                             CORBA::NO_MEMORY ());
        }

      DDSPublisher * ccm_dds_pub =
        this->impl ()->create_publisher (ccm_dds_qos,
                                         ccm_dds_pl,
                                         mask);

      if (!ccm_dds_pub)
        {
          DDS4CCM_ERROR (1, (LM_ERROR, CLINFO "CCM_DDS_DomainParticipant_i"
                       "<DDS_TYPE, CCM_TYPE>::create_publisher - "
                       "Error: Unable to create Publisher\n"));
          throw CCM_DDS::InternalError (::DDS::RETCODE_ERROR, 0);
        }

      ::DDS::Publisher_var retval = ::DDS::Publisher::_nil ();
      ACE_NEW_THROW_EX (retval,
                        Publisher_type (ccm_dds_pub),
                        CORBA::NO_MEMORY ());

      DDS4CCM_DEBUG (6, (LM_INFO, CLINFO "CCM_DDS_DomainParticipant_i"
                   "<DDS_TYPE, CCM_TYPE>::create_publisher - "
                   "Successfully created a DDSPublisher\n"));

      ccm_dds_pub->enable ();
      return retval._retn ();
#else
      return this->impl ()->create_publisher (qos, a_listener, mask);
#endif
    }

    template <typename DDS_TYPE, typename CCM_TYPE>
    ::DDS::ReturnCode_t
    CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::delete_publisher (::DDS::Publisher_ptr p)
    {
      Publisher_type *ccm_dds_pub =
        dynamic_cast < Publisher_type * > (p);

      if (!ccm_dds_pub)
        {
          DDS4CCM_ERROR (1, (LM_ERROR, CLINFO "CCM_DDS_DomainParticipant_i"
                       "<DDS_TYPE, CCM_TYPE>::delete_publisher - "
                       "Unable to cast provided object reference to servant pointer.\n"));
          return ::DDS::RETCODE_ERROR;
        }

      DDS4CCM_DEBUG (9, (LM_TRACE, CLINFO "CCM_DDS_DomainParticipant_i"
                   "<DDS_TYPE, CCM_TYPE>::delete_publisher - "
                   "Successfully casted provided object reference to "
                   "CCM_DDS_Publisher_i\n"));

      DDS_ReturnCode_t const retval = this->impl ()->delete_publisher (ccm_dds_pub->get_impl ());

      if (retval != DDS_RETCODE_OK)
        {
          DDS4CCM_ERROR (1, (LM_ERROR, CLINFO "CCM_DDS_DomainParticipant_i"
                       "<DDS_TYPE, CCM_TYPE>::delete_publisher - "
                       "Error: RTI delete_publisher returned non-ok error code %C\n",
                       translate_retcode (retval)));
        }
      else
        {
          DDS4CCM_DEBUG (6, (LM_INFO, CLINFO "CCM_DDS_DomainParticipant_i"
                        "<DDS_TYPE, CCM_TYPE>::delete_publisher - "
                        "Provided publisher successfully deleted\n"));
        }

      return retval;
    }

#if (CIAO_DDS4CCM_NDDS==1)
    template <typename DDS_TYPE, typename CCM_TYPE>
    ::DDS::Subscriber_ptr
    CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::create_subscriber_with_profile (
      const char* library_name,
      const char *profile_name,
      ::DDS::SubscriberListener_ptr a_listener,
      ::DDS::StatusMask mask)
    {
      DDS4CCM_TRACE ("DDS_DomainParticipant_i::create_subscriber_with_profile");

      DDS4CCM_DEBUG (9, (LM_TRACE, CLINFO "CCM_DDS_DomainParticipant_i"
                   "<DDS_TYPE, CCM_TYPE>::create_subscriber_with_profile - "
                   "Creating Subscriber\n"));

      SubscriberListener_type *ccm_dds_sl = 0;
      if (! ::CORBA::is_nil (a_listener))
        {
          ACE_NEW_THROW_EX (ccm_dds_sl,
                            SubscriberListener_type (a_listener),
                            CORBA::NO_MEMORY ());
        }
      DDSSubscriber * ccm_dds_sub =
        this->impl ()->create_subscriber_with_profile (
          library_name,
          profile_name,
          ccm_dds_sl,
          mask);

      if (!ccm_dds_sub)
        {
          DDS4CCM_ERROR (1, (LM_ERROR, CLINFO "CCM_DDS_DomainParticipant_i"
                        "<DDS_TYPE, CCM_TYPE>::create_subscriber_with_profile - "
                       "Error: Unable to create Subscriber\n"));
          delete ccm_dds_sl;
          throw CCM_DDS::InternalError (::DDS::RETCODE_ERROR, 0);
        }

      ::DDS::Subscriber_var retval = ::DDS::Subscriber::_nil ();
      ACE_NEW_THROW_EX (retval,
                        Subscriber_type (ccm_dds_sub),
                        CORBA::NO_MEMORY ());

      DDS4CCM_DEBUG (6, (LM_INFO, CLINFO "CCM_DDS_DomainParticipant_i"
                    "<DDS_TYPE, CCM_TYPE>::create_subscriber_with_profile - "
                    "Successfully created a DDSSubscriber\n"));

      ccm_dds_sub->enable ();
      return retval._retn ();
    }
#endif

    template <typename DDS_TYPE, typename CCM_TYPE>
    ::DDS::Subscriber_ptr
    CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::create_subscriber (const ::DDS::SubscriberQos & qos,
                                                ::DDS::SubscriberListener_ptr a_listener,
                                                ::DDS::StatusMask mask)
    {
      DDS4CCM_TRACE ("DDS_DomainParticipant_i::create_subscriber");

#if (CIAO_DDS4CCM_NDDS==1)
      ACE_UNUSED_ARG (qos);

      DDS4CCM_DEBUG (9, (LM_TRACE, CLINFO "CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::create_subscriber - "
                   "Creating Subscriber\n"));

      SubscriberListener_type *ccm_dds_sl = 0;
      if (! ::CORBA::is_nil (a_listener))
        {
          ACE_NEW_THROW_EX (ccm_dds_sl,
                            SubscriberListener_type (a_listener),
                            CORBA::NO_MEMORY ());
        }

      DDS_SubscriberQos ccm_dds_qos = DDS_SUBSCRIBER_QOS_DEFAULT;
      DDSSubscriber * ccm_dds_sub =
      this->impl ()->create_subscriber (ccm_dds_qos,
                                        ccm_dds_sl,
                                        mask);

      if (!ccm_dds_sub)
        {
          DDS4CCM_ERROR (1, (LM_ERROR, CLINFO "CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::create_subscriber - "
                       "Error: Unable to create Subscriber\n"));
          delete ccm_dds_sl;
          throw CCM_DDS::InternalError (::DDS::RETCODE_ERROR, 0);
        }

      ::DDS::Subscriber_var retval = ::DDS::Subscriber::_nil ();
      ACE_NEW_THROW_EX (retval,
                        Subscriber_type (ccm_dds_sub),
                        CORBA::NO_MEMORY ());

      DDS4CCM_DEBUG (6, (LM_INFO, CLINFO "CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::create_subscriber - "
                   "Successfully created a DDSSubscriber\n"));

      ccm_dds_sub->enable ();
      return retval._retn ();
#else
      return this->impl ()->create_subscriber (qos, a_listener, mask);
#endif
    }

    template <typename DDS_TYPE, typename CCM_TYPE>
    ::DDS::ReturnCode_t
    CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::delete_subscriber (::DDS::Subscriber_ptr s)
    {
#if (CIAO_DDS4CCM_NDDS==1)
      Subscriber_type *ccm_dds_sub = dynamic_cast < Subscriber_type * > (s);

      if (!ccm_dds_sub)
        {
          DDS4CCM_ERROR (1, (LM_ERROR, CLINFO "CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::delete_subscriber - "
                       "Unable to cast provided object reference to servant pointer.\n"));
          return ::DDS::RETCODE_ERROR;
        }

      DDS4CCM_DEBUG (9, (LM_TRACE, CLINFO "CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::delete_subscriber - "
                   "Successfully casted provided object reference to Subscriber_type\n"));

      DDS_ReturnCode_t const retval = this->impl ()->delete_subscriber (ccm_dds_sub->get_impl ());

      if (retval != DDS_RETCODE_OK)
        {
          DDS4CCM_ERROR (1, (LM_ERROR, CLINFO "CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::delete_subscriber - "
                       "Error: RTI delete_subscriber returned non-ok error code %C\n",
                       translate_retcode (retval)));
        }
      else
        {
          DDS4CCM_DEBUG (6, (LM_INFO, CLINFO "CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::delete_subscriber - "
                        "Provided subscriber successfully deleted\n"));
        }

      return retval;
#else
      return this->impl ()->delete_subscriber (s);
#endif
    }

    template <typename DDS_TYPE, typename CCM_TYPE>
    ::DDS::Subscriber_ptr
    CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::get_builtin_subscriber (void)
    {
      ::DDS::Subscriber_var retval = ::DDS::Subscriber::_nil ();
#if (CIAO_DDS4CCM_NDDS==1)
      DDSSubscriber* sub = this->impl ()->get_builtin_subscriber ();
      if (sub)
        {
          ACE_NEW_THROW_EX (retval,
                            Subscriber_type (sub),
                            CORBA::NO_MEMORY ());
        }
#else
      ::DDS::Subscriber_var sub = this->impl ()->get_builtin_subscriber ();
      if (! ::CORBA::is_nil (sub.in ()))
        {
          ACE_NEW_THROW_EX (retval,
                            Subscriber_type (sub.in ()),
                            CORBA::NO_MEMORY ());
        }
#endif
      return retval._retn ();
    }

    template <typename DDS_TYPE, typename CCM_TYPE>
    ::DDS::Topic_ptr
    CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::create_topic (const char * impl_name,
                                           const char * type_name,
                                           const ::DDS::TopicQos & qos,
                                           ::DDS::TopicListener_ptr a_listener,
                                           ::DDS::StatusMask mask)
    {
      DDS4CCM_TRACE ("DDS_DomainParticipant_i::create_topic");

#if (CIAO_DDS4CCM_NDDS==1)
      ACE_UNUSED_ARG (qos);

      if (impl_name == 0)
        {
          DDS4CCM_ERROR (1, (LM_ERROR, CLINFO "DDS_DomainParticipant_i::create_topic - "
                       "Error: provided nil topic name\n"));
          throw CCM_DDS::InternalError (::DDS::RETCODE_BAD_PARAMETER,
                                        0);
        }

      if (type_name == 0)
        {
          DDS4CCM_ERROR (1, (LM_ERROR, CLINFO "DDS_DomainParticipant_i::create_topic - "
                       "Error: provided nil type name\n"));
          throw CCM_DDS::InternalError (::DDS::RETCODE_BAD_PARAMETER,
                                        0);
        }

      DDS4CCM_DEBUG (6, (LM_DEBUG, CLINFO "DDS_DomainParticipant_i::create_topic - "
                   "Attempting to create topic with name %C and type %C\n",
                   impl_name, type_name));

      TopicListener_type *ccm_dds_tl = 0;
      if (! ::CORBA::is_nil (a_listener))
        {
          ACE_NEW_THROW_EX (ccm_dds_tl,
                            TopicListener_type (a_listener),
                            CORBA::NO_MEMORY ());
        }

      DDS_TopicQos ccm_dds_qos = DDS_TOPIC_QOS_DEFAULT;

      ACE_GUARD_THROW_EX (TAO_SYNCH_MUTEX, _guard,
                      this->tps_mutex_, CORBA::INTERNAL ());
      {
        Topic_type *ccm_dds_tp = this->tps_[impl_name];

        if (!ccm_dds_tp)
          {
            DDSTopic *dds_topic = this->impl ()->create_topic (impl_name,
                                                            type_name,
                                                            ccm_dds_qos,
                                                            ccm_dds_tl,
                                                            mask);

            if (dds_topic == 0)
              {
                DDS4CCM_ERROR (1, (LM_ERROR, CLINFO "DDS_DomainParticipant_i::create_topic - "
                            "Error: RTI DDS returned a nil topic\n"));
                delete ccm_dds_tl;
                throw CCM_DDS::InternalError (::DDS::RETCODE_ERROR, 0);
              }

            ::DDS::Topic_var retval = ::DDS::Topic::_nil ();
            ACE_NEW_THROW_EX (retval,
                              Topic_type (dds_topic),
                              CORBA::NO_MEMORY ());

            DDS4CCM_DEBUG (6, (LM_INFO, CLINFO "DDS_DomainParticipant_i::create_topic - "
                        "Successfully created topic with name %C and type %C\n",
                        impl_name, type_name));

            ccm_dds_tp = dynamic_cast < Topic_type *> (retval.in ());
            ccm_dds_tp->set_impl (dds_topic);

            this->tps_[impl_name] = ccm_dds_tp;

            return retval._retn ();
          }
        else
          {
            DDS4CCM_DEBUG (6, (LM_DEBUG, CLINFO "DDS_DomainParticipant_i::create_topic_with_profile - "
                        "Re-using topic with name %C and type %C.\n",
                        impl_name, type_name));

            return ::DDS::Topic::_duplicate (ccm_dds_tp);
          }
      }
#else
      return this->impl ()->create_topic (impl_name,
                                                      type_name,
                                                      qos,
                                                      a_listener,
                                                      mask);
#endif
    }

#if (CIAO_DDS4CCM_NDDS==1)
    template <typename DDS_TYPE, typename CCM_TYPE>
    ::DDS::Topic_ptr
    CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::create_topic_with_profile (
        const char *impl_name,
        const char *type_name,
        const char *library_name,
        const char *profile_name,
        ::DDS::TopicListener_ptr a_listener,
        ::DDS::StatusMask mask)
    {
      DDS4CCM_TRACE ("DDS_DomainParticipant_i::create_topic_with_profile");

      if (impl_name == 0)
        {
          DDS4CCM_ERROR (1, (LM_ERROR, CLINFO "DDS_DomainParticipant_i::create_topic_with_profile - "
                       "Error: provided nil topic name\n"));
          throw CCM_DDS::InternalError (::DDS::RETCODE_BAD_PARAMETER, 0);
        }

      if (type_name == 0)
        {
          DDS4CCM_ERROR (1, (LM_ERROR, CLINFO "DDS_DomainParticipant_i::create_topic_with_profile - "
                       "Error: provided nil type name\n"));
          throw CCM_DDS::InternalError (::DDS::RETCODE_BAD_PARAMETER, 0);
        }

      DDS4CCM_DEBUG (6, (LM_DEBUG, CLINFO "DDS_DomainParticipant_i::create_topic_with_profile - "
                   "Attempting to create topic with name %C and type %C\n",
                   impl_name, type_name));

      TopicListener_type *ccm_dds_tl = 0;
      if (! ::CORBA::is_nil (a_listener))
        {
          ACE_NEW_THROW_EX (ccm_dds_tl,
                            TopicListener_type (a_listener),
                            CORBA::NO_MEMORY ());
        }

      ACE_GUARD_THROW_EX (TAO_SYNCH_MUTEX, _guard,
                      this->tps_mutex_, CORBA::INTERNAL ());
      {
        Topic_type *ccm_dds_tp = this->tps_[impl_name];

        if (!ccm_dds_tp)
          {
            DDSTopic *dds_topic = this->impl ()->create_topic_with_profile (
                                                          impl_name,
                                                          type_name,
                                                          library_name,
                                                          profile_name,
                                                          ccm_dds_tl,
                                                          mask);

            if (dds_topic == 0)
              {
                DDS4CCM_ERROR (1, (LM_ERROR, CLINFO "DDS_DomainParticipant_i::create_topic_with_profile - "
                          "Error: RTI DDS returned a nil topic\n"));
                delete ccm_dds_tl;
                throw CCM_DDS::InternalError (::DDS::RETCODE_ERROR, 0);
              }

            ::DDS::Topic_var retval = ::DDS::Topic::_nil ();
            ACE_NEW_THROW_EX (retval,
                              Topic_type (dds_topic),
                              CORBA::NO_MEMORY ());

            DDS4CCM_DEBUG (6, (LM_INFO, CLINFO "DDS_DomainParticipant_i::create_topic_with_profile - "
                        "Successfully created topic with name %C and type %C\n",
                        impl_name, type_name));

            ccm_dds_tp = dynamic_cast < Topic_type *> (retval.in ());
            ccm_dds_tp->set_impl (dds_topic);

            this->tps_[impl_name] = ccm_dds_tp;

            return retval._retn ();
          }
        else
          {
            DDS4CCM_DEBUG (6, (LM_DEBUG, CLINFO "DDS_DomainParticipant_i::create_topic_with_profile - "
                        "Re-using topic with name %C and type %C.\n",
                        impl_name, type_name));
            return ::DDS::Topic::_duplicate (ccm_dds_tp);
          }
      }
    }
#endif

    template <typename DDS_TYPE, typename CCM_TYPE>
    bool
    CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::remove_topic (Topic_type * topic)
    {
      DDS4CCM_TRACE ("CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::remove_topic");

      ACE_GUARD_THROW_EX (TAO_SYNCH_MUTEX, _guard,
                      this->tps_mutex_, CORBA::INTERNAL ());

      if (topic->_refcount_value () == 1)
        {
          for (Topics_iterator pos = this->tps_.begin(); pos != this->tps_.end(); ++pos)
            {
              if (pos->second == topic)
                {
                  DDS4CCM_DEBUG (9, (LM_TRACE, CLINFO "CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::remove_topic - "
                            "Removing topic for %C from list.\n",
                            pos->first.c_str ()));
                  this->tps_.erase (pos->first);
                  break;
                }
            }
        }
      else
        {
          DDS4CCM_DEBUG (9, (LM_TRACE, CLINFO "CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::remove_topic - "
                    "Don't delete topic %C since it's still used - ref_count <%d>\n",
                    topic->get_name (),
                    topic->_refcount_value ()));
          return false;
        }
      return true;
    }

    template <typename DDS_TYPE, typename CCM_TYPE>
    ::DDS::ReturnCode_t
    CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::delete_topic (::DDS::Topic_ptr a_topic)
    {
      DDS4CCM_TRACE ("DDS_DomainParticipant_i::delete_topic");
      const char * topic_name = a_topic->get_name ();
      Topic_type *top = this->tps_[topic_name];

      if (!top)
        {
          DDS4CCM_ERROR (1, (LM_ERROR, CLINFO "CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::delete_topic <%C> - "
                       "Unable to cast provided object reference to servant.\n",
                       topic_name));
          return ::DDS::RETCODE_BAD_PARAMETER;
        }

      DDS4CCM_DEBUG (9, (LM_TRACE, CLINFO "CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::delete_topic <%C> - "
                   "Successfully casted provided object reference to servant.\n",
                   topic_name));

      ::DDS::ReturnCode_t retval = DDS::RETCODE_OK;
      if (this->remove_topic (top))
        {
          retval = this->impl ()->delete_topic (top->get_impl ());

          if (retval != DDS_RETCODE_OK)
            {
              DDS4CCM_ERROR (1, (LM_ERROR, CLINFO "CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::delete_topic <%C> - "
                          "Error: RTI delete_topic returned non-ok error code %C\n",
                          topic_name,
                          translate_retcode (retval)));
            }
          else
            {
              DDS4CCM_DEBUG (6, (LM_INFO, CLINFO "CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::delete_topic <%C> - "
                            "Provided topic successfully deleted\n",
                            topic_name));
            }
        }
      return retval;
    }

    template <typename DDS_TYPE, typename CCM_TYPE>
    ::DDS::Topic_ptr
    CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::find_topic (const char * impl_name,
                                         const ::DDS::Duration_t & timeout)
    {
      ::DDS::Topic_var retval = ::DDS::Topic::_nil ();
#if (CIAO_DDS4CCM_NDDS==1)
      ::DDS_Duration_t ddstimeout;
      ddstimeout <<= timeout;
      ::DDSTopic* topic = this->impl ()->find_topic (impl_name, ddstimeout);
      if (topic)
        {
          ACE_NEW_RETURN (retval,
                          Topic_type (topic),
                          ::DDS::Topic::_nil ());
        }
#else
      ::DDS::Topic_var topic = this->impl ()->find_topic (impl_name, timeout);
      if (! ::CORBA::is_nil (topic.in ())
        {
          ACE_NEW_RETURN (retval,
                          ‘Topic_type (topic.in ()),
                          ::DDS::Topic::_nil ());
        }
#endif
      return retval._retn ();
    }

    template <typename DDS_TYPE, typename CCM_TYPE>
    ::DDS::TopicDescription_ptr
    CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::lookup_topicdescription (const char * name)
    {
      DDS4CCM_TRACE ("CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::lookup_topicdescription");

      DDS4CCM_DEBUG (7, (LM_DEBUG, CLINFO "Looking up topic: name <%C>\n",
                                   name));

      ::DDS::TopicDescription_var retval = ::DDS::TopicDescription::_nil ();
#if (CIAO_DDS4CCM_NDDS==1)
      ::DDSTopicDescription* topic = this->impl ()->lookup_topicdescription (name);
      if (topic)
        {
          // Check the entity: is it a Topic or a ContentFilteredTopic
          ::DDSTopic * tp = dynamic_cast < ::DDSTopic *> (topic);
          if (tp)
            {
              ACE_NEW_THROW_EX (retval,
                                Topic_type (tp),
                                CORBA::NO_MEMORY ());
            }
          else
            {
              ::DDSContentFilteredTopic * cftp =
                dynamic_cast < ::DDSContentFilteredTopic *>(topic);
              if (cftp)
                {
                  ACE_NEW_THROW_EX (retval,
                                    ContentFilteredTopic_type (cftp),
                                    CORBA::NO_MEMORY ());
                }
            }
        }
#else
      ::DDSTopicDescription_var topic = this->impl ()->lookup_topicdescription (name);
      if (!CORBA::is_ni (topic.in ()))
        {
          ACE_NEW_THROW_EX (retval,
                            CCM_DDS_TopicDescription_i (topic.in ()),
                            CORBA::NO_MEMORY ());
        }
#endif
      return retval._retn ();
    }

    template <typename DDS_TYPE, typename CCM_TYPE>
    ::DDS::ContentFilteredTopic_ptr
    CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::create_contentfilteredtopic (const char * name,
                                                          ::DDS::Topic_ptr related_topic,
                                                          const char * filter_expression,
                                                          const ::DDS::StringSeq & expression_parameters)
    {
      DDS4CCM_TRACE ("DDS_DomainParticipant_i::create_contentfilteredtopic");

#if (CIAO_DDS4CCM_NDDS==1)
      Topic_type *top = dynamic_cast< Topic_type *> (related_topic);
      if (!top)
        {
          DDS4CCM_ERROR (1, (LM_ERROR, CLINFO "CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::create_contentfilteredtopic - "
                       "Unable to cast provided topic.\n"));
          throw CCM_DDS::InternalError (::DDS::RETCODE_ERROR, 0);
        }

      const char** parameterlist = 0;
      ACE_NEW_THROW_EX (parameterlist,
                        const char*[expression_parameters.length ()],
                        CORBA::NO_MEMORY ());

      for (CORBA::ULong i = 0; i < expression_parameters.length (); ++i)
        {
          parameterlist[i] = expression_parameters[i].in ();
        }
      DDS_StringSeq parameters (expression_parameters.length ());
      parameters.from_array (parameterlist, expression_parameters.length ());

      DDSContentFilteredTopic * ccm_dds_cft = this->impl ()->create_contentfilteredtopic (
                                                                  name,
                                                                  top->get_impl (),
                                                                  filter_expression,
                                                                  parameters);
      delete [] parameterlist;
      if (!ccm_dds_cft)
        {
          DDS4CCM_ERROR (1, (LM_ERROR, CLINFO "CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::create_contentfilteredtopic - "
                       "RTI DDS returned a nil ContentFilteredTopic for name <%C> and filter "
                       "expression <%C>.\n",
                       name, filter_expression));
          throw CCM_DDS::InternalError (::DDS::RETCODE_ERROR, 0);
        }

      ::DDS::ContentFilteredTopic_var retval = ::DDS::ContentFilteredTopic::_nil ();
      ACE_NEW_THROW_EX (retval,
                        ContentFilteredTopic_type (ccm_dds_cft),
                        CORBA::NO_MEMORY ());

      DDS4CCM_DEBUG (6, (LM_INFO, CLINFO "DDS_DomainParticipant_i::create_contentfilteredtopic - "
                   "Successfully created contentfilteredtopic with name <%C> and "
                   "filter expression <%C>\n",
                   name, filter_expression));

      return retval._retn ();
#else
      return this->impl ()->create_contentfilteredtopic (
                                                                  name,
                                                                  related_topic,
                                                                  filter_expression,
                                                                  expression_parameters);
#endif
    }

    template <typename DDS_TYPE, typename CCM_TYPE>
    ::DDS::ReturnCode_t
    CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::delete_contentfilteredtopic (::DDS::ContentFilteredTopic_ptr a_contentfilteredtopic)
    {
      DDS4CCM_TRACE ("DDS_DomainParticipant_i::delete_contentfilteredtopic");
#if (CIAO_DDS4CCM_NDDS==1)
      ContentFilteredTopic_type *ccm_dds_cft =
          dynamic_cast < ContentFilteredTopic_type *> (a_contentfilteredtopic);
      if (!ccm_dds_cft)
        {
          DDS4CCM_ERROR (1, (LM_ERROR, CLINFO "CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::delete_contentfilteredtopic - "
                       "Unable to cast provided ContentFilteredTopic.\n"));
          return ::DDS::RETCODE_BAD_PARAMETER;
        }
      return this->impl ()->delete_contentfilteredtopic (ccm_dds_cft->get_impl ());
#else
      return this->impl ()->delete_contentfilteredtopic (a_contentfilteredtopic);
#endif
    }

    template <typename DDS_TYPE, typename CCM_TYPE>
    ::DDS::MultiTopic_ptr
    CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::create_multitopic (
      const char * name,
      const char * type_name,
      const char * subscription_expression,
      const ::DDS::StringSeq & expression_parameters)
    {
      DDS4CCM_TRACE ("DDS_DomainParticipant_i::create_multitopic");
#if (CIAO_DDS4CCM_NDDS==1)
      ACE_UNUSED_ARG (name);
      ACE_UNUSED_ARG (type_name);
      ACE_UNUSED_ARG (subscription_expression);
      ACE_UNUSED_ARG (expression_parameters);
      //Not implemented in version ndds.4.5b.rev01 of RTI DDS.
      throw CORBA::NO_IMPLEMENT ();
#else
      return this->impl ()->create_multitopic (name,
                                               type_name,
                                               subscription_expression,
                                               expression_parameters);
#endif
    }

    template <typename DDS_TYPE, typename CCM_TYPE>
    ::DDS::ReturnCode_t
    CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::delete_multitopic (::DDS::MultiTopic_ptr a_multitopic)
    {
      DDS4CCM_TRACE ("DDS_DomainParticipant_i::delete_multitopic");
#if (CIAO_DDS4CCM_NDDS==1)
      ACE_UNUSED_ARG (a_multitopic);
      //Not implemented in version ndds.4.5b.rev01 of RTI DDS.
      throw CORBA::NO_IMPLEMENT ();
#else
      return this->impl ()->delete_multitopic (a_multitopic);
#endif
    }

    template <typename DDS_TYPE, typename CCM_TYPE>
    ::DDS::ReturnCode_t
    CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::delete_contained_entities (void)
    {
      return this->impl ()->delete_contained_entities ();

    }

    template <typename DDS_TYPE, typename CCM_TYPE>
    ::DDS::ReturnCode_t
    CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::set_qos (const ::DDS::DomainParticipantQos & qos)
    {
      DDS4CCM_TRACE ("DDS_DomainParticipant_i::set_qos");
#if (CIAO_DDS4CCM_NDDS==1)
      ::DDS_DomainParticipantQos ccm_dds_qos;
      ccm_dds_qos <<= qos;
      return this->impl()->set_qos (ccm_dds_qos);
#else
      return this->impl()->set_qos (qos);
#endif
    }

    template <typename DDS_TYPE, typename CCM_TYPE>
    ::DDS::ReturnCode_t
    CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::get_qos (::DDS::DomainParticipantQos & qos)
    {
      DDS4CCM_TRACE ("DDS_DomainParticipant_i::get_qos");
#if (CIAO_DDS4CCM_NDDS==1)
      ::DDS_DomainParticipantQos ccm_dds_qos;
      ::DDS::ReturnCode_t retcode = this->impl()-> get_qos (ccm_dds_qos);
      qos <<= ccm_dds_qos;
      return retcode;
#else
      return this->impl()->get_qos (qos);
#endif
    }

    template <typename DDS_TYPE, typename CCM_TYPE>
    ::DDS::ReturnCode_t
    CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::set_listener (::DDS::DomainParticipantListener_ptr a_listener,
                                           ::DDS::StatusMask mask)
    {
#if (CIAO_DDS4CCM_NDDS==1)
      CCM_DDS_DomainPublisherListener_i* ccm_dds_impl_list = 0;
      if (! ::CORBA::is_nil (a_listener))
        {
          ACE_NEW_THROW_EX (ccm_dds_impl_list,
                            CCM_DDS_DomainPublisherListener_i (a_listener),
                            CORBA::NO_MEMORY ());
        }
      return this->impl_->set_listener (ccm_dds_impl_list, mask);
#else
      return this->impl_->set_listener (a_listener, mask);
#endif
    }

    template <typename DDS_TYPE, typename CCM_TYPE>
    ::DDS::DomainParticipantListener_ptr
    CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::get_listener (void)
    {
      DDS4CCM_TRACE ("DDS_DomainParticipant_i::get_listener");

#if (CIAO_DDS4CCM_NDDS==1)
      DDSDomainParticipantListener *ccm_dds_dp_list = this->impl ()->get_listener ();
      CCM_DDS_DomainPublisherListener_i *list_proxy = dynamic_cast <CCM_DDS_DomainPublisherListener_i *> (ccm_dds_dp_list);
      if (!list_proxy)
        {
          DDS4CCM_DEBUG (6, (LM_DEBUG, "CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::get_listener - "
                                    "DDS returned a NIL listener.\n"));
          return ::DDS::DomainParticipantListener::_nil ();
        }
      return list_proxy->get_domainparticipantlistener ();
#else
      return this->impl ()->get_listener ();
#endif
    }

    template <typename DDS_TYPE, typename CCM_TYPE>
    ::DDS::ReturnCode_t
    CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::ignore_participant (DDS_INSTANCE_HANDLE_T_IN handle)
    {
#if (CIAO_DDS4CCM_NDDS==1)
      ::DDS_InstanceHandle_t ccm_dds_handle;
      ccm_dds_handle <<= handle;
      return this->impl ()->ignore_participant (ccm_dds_handle);
#else
      return this->impl ()->ignore_participant (handle);
#endif
    }

    template <typename DDS_TYPE, typename CCM_TYPE>
    ::DDS::ReturnCode_t
    CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::ignore_topic (DDS_INSTANCE_HANDLE_T_IN handle)
    {
#if (CIAO_DDS4CCM_NDDS==1)
      ::DDS_InstanceHandle_t ccm_dds_handle;
      ccm_dds_handle <<= handle;
      return this->impl ()->ignore_topic (ccm_dds_handle);
#else
      return this->impl ()->ignore_topic (handle);
#endif
    }

    template <typename DDS_TYPE, typename CCM_TYPE>
    ::DDS::ReturnCode_t
    CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::ignore_publication (DDS_INSTANCE_HANDLE_T_IN handle)
    {
#if (CIAO_DDS4CCM_NDDS==1)
      ::DDS_InstanceHandle_t ccm_dds_handle;
      ccm_dds_handle <<= handle;
      return this->impl ()->ignore_publication (ccm_dds_handle);
#else
      return this->impl ()->ignore_publication (handle);
#endif
    }

    template <typename DDS_TYPE, typename CCM_TYPE>
    ::DDS::ReturnCode_t
    CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::ignore_subscription (DDS_INSTANCE_HANDLE_T_IN handle)
    {
#if (CIAO_DDS4CCM_NDDS==1)
      ::DDS_InstanceHandle_t ccm_dds_handle;
      ccm_dds_handle <<= handle;
      return this->impl ()->ignore_subscription (ccm_dds_handle);
#else
      return this->impl ()->ignore_subscription (handle);
#endif
    }

    template <typename DDS_TYPE, typename CCM_TYPE>
    ::DDS::DomainId_t
    CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::get_domain_id (void)
    {
      return this->impl ()->get_domain_id ();
    }

    template <typename DDS_TYPE, typename CCM_TYPE>
    ::DDS::ReturnCode_t
    CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::assert_liveliness (void)
    {
      return this->impl ()->assert_liveliness ();
    }

    template <typename DDS_TYPE, typename CCM_TYPE>
    ::DDS::ReturnCode_t
    CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::set_default_publisher_qos (const ::DDS::PublisherQos & qos)
    {
      DDS4CCM_TRACE ("DDS_DomainParticipant_i::set_default_publisher_qos");
#if (CIAO_DDS4CCM_NDDS==1)
      ::DDS_PublisherQos ccm_dds_qos;
      ccm_dds_qos <<= qos;
      return this->impl()->set_default_publisher_qos (ccm_dds_qos);
#else
      return this->impl()->set_default_publisher_qos (qos);
#endif
    }

    template <typename DDS_TYPE, typename CCM_TYPE>
    ::DDS::ReturnCode_t
    CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::get_default_publisher_qos (::DDS::PublisherQos & qos)
    {
      DDS4CCM_TRACE ("DDS_DomainParticipant_i::get_default_publisher_qos");
#if (CIAO_DDS4CCM_NDDS==1)
      ::DDS_PublisherQos ccm_dds_qos;
      ::DDS::ReturnCode_t retcode = this->impl()-> get_default_publisher_qos (ccm_dds_qos);
      qos <<= ccm_dds_qos;
      return retcode;
#else
      return this->impl()->get_default_publisher_qos (qos);
#endif
    }

    template <typename DDS_TYPE, typename CCM_TYPE>
    ::DDS::ReturnCode_t
    CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::set_default_subscriber_qos (const ::DDS::SubscriberQos & qos)
    {
      DDS4CCM_TRACE ("DDS_DomainParticipant_i::set_default_subscriber_qos");
#if (CIAO_DDS4CCM_NDDS==1)
      ::DDS_SubscriberQos ccm_dds_qos;
      ccm_dds_qos <<= qos;
      return this->impl()->set_default_subscriber_qos (ccm_dds_qos);
#else
      return this->impl()->set_default_subscriber_qos (qos);
#endif
    }

    template <typename DDS_TYPE, typename CCM_TYPE>
    ::DDS::ReturnCode_t
    CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::get_default_subscriber_qos (::DDS::SubscriberQos & qos)
    {
      DDS4CCM_TRACE ("DDS_DomainParticipant_i::get_default_subscriber_qos");
#if (CIAO_DDS4CCM_NDDS==1)
      ::DDS_SubscriberQos ccm_dds_qos;
      ::DDS::ReturnCode_t retcode =
            this->impl()-> get_default_subscriber_qos (ccm_dds_qos);
      qos <<= ccm_dds_qos;
      return retcode;
#else
      return this->impl()->get_default_subscriber_qos (qos);
#endif
    }

    template <typename DDS_TYPE, typename CCM_TYPE>
    ::DDS::ReturnCode_t
    CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::set_default_topic_qos (const ::DDS::TopicQos & qos)
    {
      DDS4CCM_TRACE ("DDS_DomainParticipant_i::set_default_topic_qos");
#if (CIAO_DDS4CCM_NDDS==1)
      ::DDS_TopicQos ccm_dds_qos;
      ccm_dds_qos <<= qos;
      return this->impl()->set_default_topic_qos (ccm_dds_qos);
#else
      return this->impl()->set_default_topic_qos (qos);
#endif
    }

    template <typename DDS_TYPE, typename CCM_TYPE>
    ::DDS::ReturnCode_t
    CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::get_default_topic_qos (::DDS::TopicQos & qos)
    {
      DDS4CCM_TRACE ("DDS_DomainParticipant_i::get_default_topic_qos");
#if (CIAO_DDS4CCM_NDDS==1)
      ::DDS_TopicQos ccm_dds_qos;
      ::DDS::ReturnCode_t retcode =
            this->impl()-> get_default_topic_qos (ccm_dds_qos);
      qos <<= ccm_dds_qos;
      return retcode;
#else
      return this->impl()->get_default_topic_qos (qos);
#endif
    }

    template <typename DDS_TYPE, typename CCM_TYPE>
    ::DDS::ReturnCode_t
    CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::get_discovered_participants (::DDS::InstanceHandleSeq & impl_handles)
    {
#if (CIAO_DDS4CCM_NDDS==1)
      ::DDS_InstanceHandleSeq rtiseq;
      ::DDS::ReturnCode_t const retval = this->impl ()->get_discovered_participants (rtiseq);
      impl_handles <<= rtiseq;
      return retval;
#else
      return this->impl ()->get_discovered_participants (impl_handles);
#endif
    }

    template <typename DDS_TYPE, typename CCM_TYPE>
    ::DDS::ReturnCode_t
    CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::get_discovered_participant_data (
      ::DDS::ParticipantBuiltinTopicData & impl_data,
      DDS_INSTANCE_HANDLE_T_IN impl_handle)
    {
      DDS4CCM_TRACE ("DDS_DomainParticipant_i::get_discovered_participant_data");
#if (CIAO_DDS4CCM_NDDS==1)
      DDS_ParticipantBuiltinTopicData dds_part_data;
      dds_part_data <<= impl_data;
      ::DDS_InstanceHandle_t dds_hnd;
      dds_hnd <<= impl_handle;
      ::DDS_ReturnCode_t retcode =
        this->impl ()->get_discovered_participant_data (dds_part_data,
                                                        dds_hnd);
      impl_data <<= dds_part_data;
      return retcode;
#else
      return this->impl ()->get_discovered_topic_data (impl_data,
                                                       impl_handle);
#endif
    }

    template <typename DDS_TYPE, typename CCM_TYPE>
    ::DDS::ReturnCode_t
    CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::get_discovered_topics (::DDS::InstanceHandleSeq & impl_handles)
    {
#if (CIAO_DDS4CCM_NDDS==1)
      ::DDS_InstanceHandleSeq rtiseq;
      ::DDS::ReturnCode_t const retval = this->impl ()->get_discovered_topics (rtiseq);
      impl_handles <<= rtiseq;
      return retval;
#else
      return this->impl ()->get_discovered_topics (impl_handles);
#endif
    }

    template <typename DDS_TYPE, typename CCM_TYPE>
    ::DDS::ReturnCode_t
    CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::get_discovered_topic_data (
      ::DDS::TopicBuiltinTopicData & impl_data,
      DDS_INSTANCE_HANDLE_T_IN impl_handle)
    {
      DDS4CCM_TRACE ("DDS_DomainParticipant_i::get_discovered_topic_data");
#if (CIAO_DDS4CCM_NDDS==1)
      DDS_TopicBuiltinTopicData dds_tp_data;
      dds_tp_data <<= impl_data;
      ::DDS_InstanceHandle_t dds_hnd;
      dds_hnd <<= impl_handle;
      ::DDS_ReturnCode_t retcode =
        this->impl ()->get_discovered_topic_data (dds_tp_data,
                                                  dds_hnd);
      impl_data <<= dds_tp_data;
      return retcode;
#else
      return this->impl ()->get_discovered_topic_data (impl_data,
                                                       impl_handle);
#endif
    }

    template <typename DDS_TYPE, typename CCM_TYPE>
    ::CORBA::Boolean
    CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::contains_entity (DDS_INSTANCE_HANDLE_T_IN a_handle)
    {
#if (CIAO_DDS4CCM_NDDS==1)
      ::DDS_InstanceHandle_t ccm_dds_handle;
      ccm_dds_handle <<= a_handle;
      return this->impl ()->contains_entity (ccm_dds_handle);
#else
      return this->impl ()->contains_entity (a_handle);
#endif
    }

    template <typename DDS_TYPE, typename CCM_TYPE>
    ::DDS::ReturnCode_t
    CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::get_current_time (::DDS::Time_t & current_time)
    {
#if (CIAO_DDS4CCM_NDDS==1)
      DDS_Time_t ccm_dds_time;
      ::DDS::ReturnCode_t const retval = this->impl ()->get_current_time (ccm_dds_time);
      current_time <<= ccm_dds_time;
      return retval;
#else
      return this->impl ()->get_current_time (current_time);
#endif
    }

    template <typename DDS_TYPE, typename CCM_TYPE>
    ::DDS::ReturnCode_t
    CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::enable (void)
    {
      return this->impl ()->enable ();
    }

    template <typename DDS_TYPE, typename CCM_TYPE>
    ::DDS::StatusCondition_ptr
    CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::get_statuscondition (void)
    {
      ::DDS::StatusCondition_var retval = ::DDS::StatusCondition::_nil ();
#if (CIAO_DDS4CCM_NDDS==1)
      DDSStatusCondition* sc = this->impl ()->get_statuscondition ();
      if (sc)
        {
          ACE_NEW_THROW_EX (retval,
                            CCM_DDS_StatusCondition_i (sc),
                            CORBA::NO_MEMORY ());
        }
#else
      ::DDS::StatusCondition_var sc = this->impl ()->get_statuscondition ();
      if (! ::CORBA::is_nil (sc.in ()))
        {
          ACE_NEW_THROW_EX (retval,
                            CCM_DDS_StatusCondition_i (sc.in ()),
                            CORBA::NO_MEMORY ());
        }
#endif
      return retval._retn ();
    }

    template <typename DDS_TYPE, typename CCM_TYPE>
    ::DDS::StatusMask
    CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::get_status_changes (void)
    {
      return this->impl ()->get_status_changes ();
    }

    template <typename DDS_TYPE, typename CCM_TYPE>
    DDS_INSTANCE_HANDLE_T_RETN
    CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::get_instance_handle (void)
    {
#if (CIAO_DDS4CCM_NDDS==1)
      ::DDS_InstanceHandle_t const rtihandle = this->impl ()->get_instance_handle ();
      ::DDS::InstanceHandle_t handle;
      handle <<= rtihandle;
      return handle;
#else
      return this->impl ()->get_instance_handle ();
#endif
    }

    template <typename DDS_TYPE, typename CCM_TYPE>
    DDSDomainParticipant *
    CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::get_impl (void)
    {
      return this->impl_;
    }

    template <typename DDS_TYPE, typename CCM_TYPE>
    void
    CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::set_impl (DDSDomainParticipant * dp)
    {
      this->impl_ = dp;
    }

    template <typename DDS_TYPE, typename CCM_TYPE>
    DDSDomainParticipant *
    CCM_DDS_DomainParticipant_i<DDS_TYPE, CCM_TYPE>::impl (void)
    {
      if (!this->impl_)
        {
          throw ::CORBA::BAD_INV_ORDER ();
        }
      return this->impl_;
    }
  }
}

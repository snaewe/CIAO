/**
 * @author William R. Otte <wotte@dre.vanderbilt.edu>
 * @author Johnny Willemsen <jwillemsen@remedy.nl>
 *
 * $Id$
 *
 * Wrapper facade for NDDS.
 */

#ifndef DDS4CCM_LIVELINESSLOSTSTATUS_H
#define DDS4CCM_LIVELINESSLOSTSTATUS_H

#if defined (CIAO_DDS4CCM_OPENDDS) && (CIAO_DDS4CCM_OPENDDS==1)
typedef ::DDS::LivelinessLostStatus DDS_LivelinessLostStatus;
#endif

#if defined (CIAO_DDS4CCM_NDDS) && (CIAO_DDS4CCM_NDDS==1)
inline void
operator<<= (::DDS::LivelinessLostStatus &ddsstatus, const ::DDS_LivelinessLostStatus & status)
{
  ddsstatus.total_count = status.total_count;
  ddsstatus.total_count_change = status.total_count_change;
}

inline void
operator<<= (::DDS_LivelinessLostStatus &ddsstatus, const ::DDS::LivelinessLostStatus & status)
{
  ddsstatus.total_count = status.total_count;
  ddsstatus.total_count_change = status.total_count_change;
}

inline void
operator>>= (const ::DDS_LivelinessLostStatus &status, ::DDS::LivelinessLostStatus & ddsstatus)
{
  ddsstatus.total_count = status.total_count;
  ddsstatus.total_count_change = status.total_count_change;
}

inline void
operator>>= (const ::DDS::LivelinessLostStatus &status, ::DDS_LivelinessLostStatus & ddsstatus)
{
  ddsstatus.total_count = status.total_count;
  ddsstatus.total_count_change = status.total_count_change;
}
#endif

#endif /* DDS4CCM_LIVELINESSLOSTSTATUS_H */

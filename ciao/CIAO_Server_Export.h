
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl -s CIAO_SERVER
// ------------------------------
#ifndef CIAO_SERVER_EXPORT_H
#define CIAO_SERVER_EXPORT_H

#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (CIAO_SERVER_HAS_DLL)
#  define CIAO_SERVER_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && CIAO_SERVER_HAS_DLL */

#if !defined (CIAO_SERVER_HAS_DLL)
#  define CIAO_SERVER_HAS_DLL 1
#endif /* ! CIAO_SERVER_HAS_DLL */

#if defined (CIAO_SERVER_HAS_DLL) && (CIAO_SERVER_HAS_DLL == 1)
#  if defined (CIAO_SERVER_BUILD_DLL)
#    define CIAO_SERVER_Export ACE_Proper_Export_Flag
#    define CIAO_SERVER_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define CIAO_SERVER_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* CIAO_SERVER_BUILD_DLL */
#    define CIAO_SERVER_Export ACE_Proper_Import_Flag
#    define CIAO_SERVER_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define CIAO_SERVER_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* CIAO_SERVER_BUILD_DLL */
#else /* CIAO_SERVER_HAS_DLL == 1 */
#  define CIAO_SERVER_Export
#  define CIAO_SERVER_SINGLETON_DECLARATION(T)
#  define CIAO_SERVER_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* CIAO_SERVER_HAS_DLL == 1 */

// Set CIAO_SERVER_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (CIAO_SERVER_NTRACE)
#  if (ACE_NTRACE == 1)
#    define CIAO_SERVER_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define CIAO_SERVER_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !CIAO_SERVER_NTRACE */

#if (CIAO_SERVER_NTRACE == 1)
#  define CIAO_SERVER_TRACE(X)
#else /* (CIAO_SERVER_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define CIAO_SERVER_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (CIAO_SERVER_NTRACE == 1) */

#endif /* CIAO_SERVER_EXPORT_H */

// End of auto generated file.

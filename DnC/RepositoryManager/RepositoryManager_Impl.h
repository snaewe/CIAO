/*=======================================================================
 *
 * @file RepositoryManager_Impl.h
 *
 * $Id$
 *
 * @brief This file contains implementation for
 * Deployment::RepositoryManager interface.
 *
 * @author Jaiganesh Balasubramanian <jai@dre.vanderbilt.edu>
 *
 *======================================================================*/

#ifndef REPOSITORYMANAGER_IMPL_H
#define REPOSITORYMANAGER_IMPL_H

#include "RepositoryManagerS.h"
#include "ace/Get_Opt.h"
#include "RepositoryManager_Impl.h"
#include "ace/Auto_Ptr.h"
#include "ace/Log_Msg.h"
#include "ace/OS_main.h"
#include "tao/Exception.h"
#include "CIAO/DnC/Config_Handlers/XercesString.h"
#include <xercesc/util/XMLUniDefs.hpp>
#include "CIAO/DnC/Config_Handlers/Config_Handler_export.h"
#include "CIAO/DnC/Config_Handlers/Domain_Handler.h"
#include "CIAO/DnC/Config_Handlers/PC_Handler.h"
#include "CIAO/DnC/Config_Handlers/Plan_Handler.h"
#include "CIAO/DnC/Config_Handlers/CompImplDesc_Handler.h"
#include "CIAO/DnC/Config_Handlers/DnC_Dump.h"
#include "CIAO/DnC/Config_Handlers/Utils.h"
#include "CIAO/DnC/Config_Handlers/Config_Error_Handler.h"

using Config_Handler::XStr;
using xercesc::XMLUni;
using xercesc::XMLString;
using xercesc::XMLException;
using xercesc::DOMException;
using xercesc::DOMBuilder;
using xercesc::DOMImplementationRegistry;
using xercesc::DOMImplementationLS;
using xercesc::DOMImplementation;
using xercesc::DOMAttr;
using xercesc::DOMNamedNodeMap;
using xercesc::DOMLocator;
using xercesc::DOMError;
using xercesc::DOMNodeList;
using xercesc::DOMDocument;
using xercesc::DOMDocumentTraversal;
using xercesc::DOMNodeIterator;
using xercesc::DOMNode;
using xercesc::DOMNodeFilter;

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Synch.h"
#include "ace/Hash_Map_Manager.h"

/**
 *
 * @class ReposityManager_Impl
 *
 * @brief This class implements the RepositoryManager. RepositoryManager
 * assists the execution process after the planning stage.
 *
 */
namespace CIAO
{
  class RepositoryManager_Impl
    : public virtual POA_CIAO::RepositoryManagerDaemon,
    public virtual PortableServer::RefCountServantBase
    {

    public:

      RepositoryManager_Impl ();
      // Default constructor.
      RepositoryManager_Impl (CORBA::ORB_ptr orb,
                            PortableServer::POA_ptr poa
                            ACE_ENV_ARG_DECL);

      // Default destructor.
      ~RepositoryManager_Impl ();

      virtual void installPackage (const char* installation_name,
                                   const char* location
                                   ACE_ENV_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC ((CORBA::SystemException,
                         Deployment::NameExists,
                         Deployment::PackageError));

      virtual void createPackage (const char* installation_name,
                                  const Deployment::PackageConfiguration& pc,
                                  const char* base_location,
                                  CORBA::Boolean replace
                                  ACE_ENV_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC ((CORBA::SystemException,
                         Deployment::NameExists,
                         Deployment::PackageError));

      virtual Deployment::PackageConfiguration*
        findPackageByName (const char* name
                           ACE_ENV_ARG_DECL_WITH_DEFAULTS)
          ACE_THROW_SPEC ((CORBA::SystemException,
                           Deployment::NoSuchName));

      virtual Deployment::PackageConfiguration*
        findPackageByUUID (const char* name
                           ACE_ENV_ARG_DECL_WITH_DEFAULTS)
          ACE_THROW_SPEC ((CORBA::SystemException,
                           Deployment::NoSuchName));

      virtual CORBA::StringSeq*
        findNamesByType (const char* type
                         ACE_ENV_ARG_DECL_WITH_DEFAULTS)
          ACE_THROW_SPEC ((CORBA::SystemException));

      virtual CORBA::StringSeq*
        getAllNames (ACE_ENV_ARG_DECL_WITH_DEFAULTS)
          ACE_THROW_SPEC ((CORBA::SystemException));

      virtual CORBA::StringSeq*
        getAllTypes (ACE_ENV_ARG_DECL_WITH_DEFAULTS)
          ACE_THROW_SPEC ((CORBA::SystemException));

      virtual void
        deletePackage (const char* name
                       ACE_ENV_ARG_DECL_WITH_DEFAULTS)
          ACE_THROW_SPEC ((CORBA::SystemException,
                           Deployment::NoSuchName));

      virtual void 
        shutdown (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
          ACE_THROW_SPEC ((CORBA::SystemException));

    protected:
      // Cached ORB pointer
      CORBA::ORB_var orb_;

      // Cached POA pointer
      PortableServer::POA_var poa_;

      // Package Configuration element
      Deployment::PackageConfiguration pc_;
    };
};

#include /**/ "ace/post.h"
#endif /* REPOSITORYMANAGER_IMPL_H */

/* $Id$
 * This code was generated by the XML Schema Compiler.
 *
 * Changes made to this code will most likely be overwritten
 * when the handlers are recompiled.
 * 
 * If you find errors or feel that there are bugfixes to be made,
 * please contact the current XSC maintainer:
 *             Will Otte <wotte@dre.vanderbilt.edu>
 */


// Fixes the VC6 warning 4786.
#include "vc6-4786.h"
 
// Fix for Borland compilers, which seem to have a broken
// <string> include.
#ifdef __BORLANDC__
# include <string.h>
#endif

#include "XSC_XML_Handlers_Export.h"
#ifndef CCD_HPP
#define CCD_HPP

// Forward declarations.
//
namespace CIAO
{
  namespace Config_Handlers
  {
    class ComponentInterfaceDescription;
  }
}

#include <memory>
#include <list>
#include "XMLSchema/Types.hpp"

#include "Basic_Deployment_Data.hpp"

namespace CIAO
{
  namespace Config_Handlers
  {
    class XSC_XML_Handlers_Export ComponentInterfaceDescription : public ::XSCRT::Type
    {
      //@@ VC6 anathema
      typedef ::XSCRT::Type Base__;

      // label
      // 
      public:
      bool label_p () const;
      ::XMLSchema::string< ACE_TCHAR > const& label () const;
      void label (::XMLSchema::string< ACE_TCHAR > const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > label_;

      // UUID
      // 
      public:
      bool UUID_p () const;
      ::XMLSchema::string< ACE_TCHAR > const& UUID () const;
      void UUID (::XMLSchema::string< ACE_TCHAR > const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > UUID_;

      // specificType
      // 
      public:
      bool specificType_p () const;
      ::XMLSchema::string< ACE_TCHAR > const& specificType () const;
      void specificType (::XMLSchema::string< ACE_TCHAR > const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > specificType_;

      // supportedType
      // 
      public:
      typedef ::std::list< ::XMLSchema::string< ACE_TCHAR > >::iterator supportedType_iterator;
      typedef ::std::list< ::XMLSchema::string< ACE_TCHAR > >::const_iterator supportedType_const_iterator;
      supportedType_iterator begin_supportedType ();
      supportedType_iterator end_supportedType ();
      supportedType_const_iterator begin_supportedType () const;
      supportedType_const_iterator end_supportedType () const;
      void add_supportedType (::XMLSchema::string< ACE_TCHAR > const& );
      size_t count_supportedType (void) const;

      protected:
      ::std::list< ::XMLSchema::string< ACE_TCHAR > > supportedType_;

      // idlFile
      // 
      public:
      typedef ::std::list< ::XMLSchema::string< ACE_TCHAR > >::iterator idlFile_iterator;
      typedef ::std::list< ::XMLSchema::string< ACE_TCHAR > >::const_iterator idlFile_const_iterator;
      idlFile_iterator begin_idlFile ();
      idlFile_iterator end_idlFile ();
      idlFile_const_iterator begin_idlFile () const;
      idlFile_const_iterator end_idlFile () const;
      void add_idlFile (::XMLSchema::string< ACE_TCHAR > const& );
      size_t count_idlFile (void) const;

      protected:
      ::std::list< ::XMLSchema::string< ACE_TCHAR > > idlFile_;

      // configProperty
      // 
      public:
      typedef ::std::list< ::CIAO::Config_Handlers::Property >::iterator configProperty_iterator;
      typedef ::std::list< ::CIAO::Config_Handlers::Property >::const_iterator configProperty_const_iterator;
      configProperty_iterator begin_configProperty ();
      configProperty_iterator end_configProperty ();
      configProperty_const_iterator begin_configProperty () const;
      configProperty_const_iterator end_configProperty () const;
      void add_configProperty (::CIAO::Config_Handlers::Property const& );
      size_t count_configProperty (void) const;

      protected:
      ::std::list< ::CIAO::Config_Handlers::Property > configProperty_;

      // port
      // 
      public:
      typedef ::std::list< ::CIAO::Config_Handlers::ComponentPortDescription >::iterator port_iterator;
      typedef ::std::list< ::CIAO::Config_Handlers::ComponentPortDescription >::const_iterator port_const_iterator;
      port_iterator begin_port ();
      port_iterator end_port ();
      port_const_iterator begin_port () const;
      port_const_iterator end_port () const;
      void add_port (::CIAO::Config_Handlers::ComponentPortDescription const& );
      size_t count_port (void) const;

      protected:
      ::std::list< ::CIAO::Config_Handlers::ComponentPortDescription > port_;

      // property
      // 
      public:
      typedef ::std::list< ::CIAO::Config_Handlers::ComponentPropertyDescription >::iterator property_iterator;
      typedef ::std::list< ::CIAO::Config_Handlers::ComponentPropertyDescription >::const_iterator property_const_iterator;
      property_iterator begin_property ();
      property_iterator end_property ();
      property_const_iterator begin_property () const;
      property_const_iterator end_property () const;
      void add_property (::CIAO::Config_Handlers::ComponentPropertyDescription const& );
      size_t count_property (void) const;

      protected:
      ::std::list< ::CIAO::Config_Handlers::ComponentPropertyDescription > property_;

      // infoProperty
      // 
      public:
      typedef ::std::list< ::CIAO::Config_Handlers::Property >::iterator infoProperty_iterator;
      typedef ::std::list< ::CIAO::Config_Handlers::Property >::const_iterator infoProperty_const_iterator;
      infoProperty_iterator begin_infoProperty ();
      infoProperty_iterator end_infoProperty ();
      infoProperty_const_iterator begin_infoProperty () const;
      infoProperty_const_iterator end_infoProperty () const;
      void add_infoProperty (::CIAO::Config_Handlers::Property const& );
      size_t count_infoProperty (void) const;

      protected:
      ::std::list< ::CIAO::Config_Handlers::Property > infoProperty_;

      // contentLocation
      // 
      public:
      bool contentLocation_p () const;
      ::XMLSchema::string< ACE_TCHAR > const& contentLocation () const;
      void contentLocation (::XMLSchema::string< ACE_TCHAR > const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > contentLocation_;

      public:
      ComponentInterfaceDescription ();

      ComponentInterfaceDescription (::XSCRT::XML::Element< ACE_TCHAR > const&);
      ComponentInterfaceDescription (ComponentInterfaceDescription const& s);

      ComponentInterfaceDescription&
      operator= (ComponentInterfaceDescription const& s);

      private:
      char regulator__;
    };
  }
}

namespace CIAO
{
  namespace Config_Handlers
  {
  }
}

#include "XMLSchema/Traversal.hpp"

namespace CIAO
{
  namespace Config_Handlers
  {
    namespace Traversal
    {
      struct XSC_XML_Handlers_Export ComponentInterfaceDescription : ::XMLSchema::Traversal::Traverser< ::CIAO::Config_Handlers::ComponentInterfaceDescription >
      {
        virtual void
        traverse (Type&);

        virtual void
        traverse (Type const&);

        virtual void
        pre (Type&);

        virtual void
        pre (Type const&);

        virtual void
        label (Type&);

        virtual void
        label (Type const&);

        virtual void
        label_none (Type&);

        virtual void
        label_none (Type const&);

        virtual void
        UUID (Type&);

        virtual void
        UUID (Type const&);

        virtual void
        UUID_none (Type&);

        virtual void
        UUID_none (Type const&);

        virtual void
        specificType (Type&);

        virtual void
        specificType (Type const&);

        virtual void
        specificType_none (Type&);

        virtual void
        specificType_none (Type const&);

        virtual void
        supportedType (Type&);

        virtual void
        supportedType (Type const&);

        virtual void
        supportedType_pre (Type&);

        virtual void
        supportedType_pre (Type const&);

        virtual void
        supportedType_next (Type&);

        virtual void
        supportedType_next (Type const&);

        virtual void
        supportedType_post (Type&);

        virtual void
        supportedType_post (Type const&);

        virtual void
        supportedType_none (Type&);

        virtual void
        supportedType_none (Type const&);

        virtual void
        idlFile (Type&);

        virtual void
        idlFile (Type const&);

        virtual void
        idlFile_pre (Type&);

        virtual void
        idlFile_pre (Type const&);

        virtual void
        idlFile_next (Type&);

        virtual void
        idlFile_next (Type const&);

        virtual void
        idlFile_post (Type&);

        virtual void
        idlFile_post (Type const&);

        virtual void
        idlFile_none (Type&);

        virtual void
        idlFile_none (Type const&);

        virtual void
        configProperty (Type&);

        virtual void
        configProperty (Type const&);

        virtual void
        configProperty_pre (Type&);

        virtual void
        configProperty_pre (Type const&);

        virtual void
        configProperty_next (Type&);

        virtual void
        configProperty_next (Type const&);

        virtual void
        configProperty_post (Type&);

        virtual void
        configProperty_post (Type const&);

        virtual void
        configProperty_none (Type&);

        virtual void
        configProperty_none (Type const&);

        virtual void
        port (Type&);

        virtual void
        port (Type const&);

        virtual void
        port_pre (Type&);

        virtual void
        port_pre (Type const&);

        virtual void
        port_next (Type&);

        virtual void
        port_next (Type const&);

        virtual void
        port_post (Type&);

        virtual void
        port_post (Type const&);

        virtual void
        port_none (Type&);

        virtual void
        port_none (Type const&);

        virtual void
        property (Type&);

        virtual void
        property (Type const&);

        virtual void
        property_pre (Type&);

        virtual void
        property_pre (Type const&);

        virtual void
        property_next (Type&);

        virtual void
        property_next (Type const&);

        virtual void
        property_post (Type&);

        virtual void
        property_post (Type const&);

        virtual void
        property_none (Type&);

        virtual void
        property_none (Type const&);

        virtual void
        infoProperty (Type&);

        virtual void
        infoProperty (Type const&);

        virtual void
        infoProperty_pre (Type&);

        virtual void
        infoProperty_pre (Type const&);

        virtual void
        infoProperty_next (Type&);

        virtual void
        infoProperty_next (Type const&);

        virtual void
        infoProperty_post (Type&);

        virtual void
        infoProperty_post (Type const&);

        virtual void
        infoProperty_none (Type&);

        virtual void
        infoProperty_none (Type const&);

        virtual void
        contentLocation (Type&);

        virtual void
        contentLocation (Type const&);

        virtual void
        contentLocation_none (Type&);

        virtual void
        contentLocation_none (Type const&);

        virtual void
        post (Type&);

        virtual void
        post (Type const&);
      };
    }
  }
}

#include "XMLSchema/Writer.hpp"

namespace CIAO
{
  namespace Config_Handlers
  {
    namespace Writer
    {
      struct ComponentInterfaceDescription : Traversal::ComponentInterfaceDescription, 
      virtual ::XSCRT::Writer< ACE_TCHAR >
      {
        typedef ::CIAO::Config_Handlers::ComponentInterfaceDescription Type;
        ComponentInterfaceDescription (::XSCRT::XML::Element< ACE_TCHAR >&);

        #ifdef __BORLANDC__
        virtual void 
        traverse (Type &o)
        {

          this->traverse (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        traverse (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        label (Type &o)
        {

          this->label (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        label (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        UUID (Type &o)
        {

          this->UUID (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        UUID (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        specificType (Type &o)
        {

          this->specificType (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        specificType (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        supportedType_pre (Type &o)
        {

          this->supportedType_pre (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        supportedType_pre (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        supportedType_next (Type &o)
        {

          this->supportedType_next (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        supportedType_next (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        supportedType_post (Type &o)
        {

          this->supportedType_post (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        supportedType_post (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        idlFile_pre (Type &o)
        {

          this->idlFile_pre (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        idlFile_pre (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        idlFile_next (Type &o)
        {

          this->idlFile_next (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        idlFile_next (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        idlFile_post (Type &o)
        {

          this->idlFile_post (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        idlFile_post (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        configProperty_pre (Type &o)
        {

          this->configProperty_pre (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        configProperty_pre (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        configProperty_next (Type &o)
        {

          this->configProperty_next (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        configProperty_next (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        configProperty_post (Type &o)
        {

          this->configProperty_post (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        configProperty_post (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        port_pre (Type &o)
        {

          this->port_pre (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        port_pre (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        port_next (Type &o)
        {

          this->port_next (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        port_next (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        port_post (Type &o)
        {

          this->port_post (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        port_post (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        property_pre (Type &o)
        {

          this->property_pre (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        property_pre (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        property_next (Type &o)
        {

          this->property_next (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        property_next (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        property_post (Type &o)
        {

          this->property_post (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        property_post (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        infoProperty_pre (Type &o)
        {

          this->infoProperty_pre (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        infoProperty_pre (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        infoProperty_next (Type &o)
        {

          this->infoProperty_next (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        infoProperty_next (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        infoProperty_post (Type &o)
        {

          this->infoProperty_post (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        infoProperty_post (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        contentLocation (Type &o)
        {

          this->contentLocation (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        contentLocation (Type const&);

        protected:
        ComponentInterfaceDescription ();
      };
    }
  }
}

namespace CIAO
{
  namespace Config_Handlers
  {
  }
}

#endif // CCD_HPP

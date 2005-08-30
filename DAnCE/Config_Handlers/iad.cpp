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
 
#include "iad.hpp"

namespace CIAO
{
  namespace Config_Handlers
  {
    // NamedImplementationArtifact
    // 

    NamedImplementationArtifact::
    NamedImplementationArtifact (::XMLSchema::string< ACE_TCHAR > const& name__,
    ::CIAO::Config_Handlers::ImplementationArtifactDescription const& referencedArtifact__)
    : 
    ::XSCRT::Type (), 
    name_ (new ::XMLSchema::string< ACE_TCHAR > (name__)),
    referencedArtifact_ (new ::CIAO::Config_Handlers::ImplementationArtifactDescription (referencedArtifact__)),
    regulator__ ()
    {
      name_->container (this);
      referencedArtifact_->container (this);
    }

    NamedImplementationArtifact::
    NamedImplementationArtifact (::CIAO::Config_Handlers::NamedImplementationArtifact const& s)
    :
    ::XSCRT::Type (),
    name_ (new ::XMLSchema::string< ACE_TCHAR > (*s.name_)),
    referencedArtifact_ (new ::CIAO::Config_Handlers::ImplementationArtifactDescription (*s.referencedArtifact_)),
    regulator__ ()
    {
      name_->container (this);
      referencedArtifact_->container (this);
    }

    ::CIAO::Config_Handlers::NamedImplementationArtifact& NamedImplementationArtifact::
    operator= (::CIAO::Config_Handlers::NamedImplementationArtifact const& s)
    {
      name (s.name ());

      referencedArtifact (s.referencedArtifact ());

      return *this;
    }


    // NamedImplementationArtifact
    // 
    ::XMLSchema::string< ACE_TCHAR > const& NamedImplementationArtifact::
    name () const
    {
      return *name_;
    }

    ::XMLSchema::string< ACE_TCHAR >& NamedImplementationArtifact::
    name ()
    {
      return *name_;
    }

    void NamedImplementationArtifact::
    name (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      *name_ = e;
    }

    // NamedImplementationArtifact
    // 
    ::CIAO::Config_Handlers::ImplementationArtifactDescription const& NamedImplementationArtifact::
    referencedArtifact () const
    {
      return *referencedArtifact_;
    }

    ::CIAO::Config_Handlers::ImplementationArtifactDescription& NamedImplementationArtifact::
    referencedArtifact ()
    {
      return *referencedArtifact_;
    }

    void NamedImplementationArtifact::
    referencedArtifact (::CIAO::Config_Handlers::ImplementationArtifactDescription const& e)
    {
      *referencedArtifact_ = e;
    }


    // ImplementationArtifactDescription
    // 

    ImplementationArtifactDescription::
    ImplementationArtifactDescription ()
    : 
    ::XSCRT::Type (), 
    regulator__ ()
    {
    }

    ImplementationArtifactDescription::
    ImplementationArtifactDescription (::CIAO::Config_Handlers::ImplementationArtifactDescription const& s)
    :
    ::XSCRT::Type (),
    label_ (s.label_.get () ? new ::XMLSchema::string< ACE_TCHAR > (*s.label_) : 0),
    UUID_ (s.UUID_.get () ? new ::XMLSchema::string< ACE_TCHAR > (*s.UUID_) : 0),
    execParameter_ (s.execParameter_.get () ? new ::CIAO::Config_Handlers::Property (*s.execParameter_) : 0),
    deployRequirement_ (s.deployRequirement_.get () ? new ::CIAO::Config_Handlers::Requirement (*s.deployRequirement_) : 0),
    infoProperty_ (s.infoProperty_.get () ? new ::CIAO::Config_Handlers::Property (*s.infoProperty_) : 0),
    contentLocation_ (s.contentLocation_.get () ? new ::XMLSchema::string< ACE_TCHAR > (*s.contentLocation_) : 0),
    href_ (s.href_.get () ? new ::XMLSchema::string< ACE_TCHAR > (*s.href_) : 0),
    regulator__ ()
    {
      if (label_.get ()) label_->container (this);
      if (UUID_.get ()) UUID_->container (this);
      location_.reserve (s.location_.size ());
      {
        for (location_const_iterator i (s.location_.begin ());
        i != s.location_.end ();
        ++i) add_location (*i);
      }

      dependsOn_.reserve (s.dependsOn_.size ());
      {
        for (dependsOn_const_iterator i (s.dependsOn_.begin ());
        i != s.dependsOn_.end ();
        ++i) add_dependsOn (*i);
      }

      if (execParameter_.get ()) execParameter_->container (this);
      if (deployRequirement_.get ()) deployRequirement_->container (this);
      if (infoProperty_.get ()) infoProperty_->container (this);
      if (contentLocation_.get ()) contentLocation_->container (this);
      if (href_.get ()) href_->container (this);
    }

    ::CIAO::Config_Handlers::ImplementationArtifactDescription& ImplementationArtifactDescription::
    operator= (::CIAO::Config_Handlers::ImplementationArtifactDescription const& s)
    {
      if (s.label_.get ()) label (*(s.label_));
      else label_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (0);

      if (s.UUID_.get ()) UUID (*(s.UUID_));
      else UUID_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (0);

      location_.clear ();
      location_.reserve (s.location_.size ());
      {
        for (location_const_iterator i (s.location_.begin ());
        i != s.location_.end ();
        ++i) add_location (*i);
      }

      dependsOn_.clear ();
      dependsOn_.reserve (s.dependsOn_.size ());
      {
        for (dependsOn_const_iterator i (s.dependsOn_.begin ());
        i != s.dependsOn_.end ();
        ++i) add_dependsOn (*i);
      }

      if (s.execParameter_.get ()) execParameter (*(s.execParameter_));
      else execParameter_ = ::std::auto_ptr< ::CIAO::Config_Handlers::Property > (0);

      if (s.deployRequirement_.get ()) deployRequirement (*(s.deployRequirement_));
      else deployRequirement_ = ::std::auto_ptr< ::CIAO::Config_Handlers::Requirement > (0);

      if (s.infoProperty_.get ()) infoProperty (*(s.infoProperty_));
      else infoProperty_ = ::std::auto_ptr< ::CIAO::Config_Handlers::Property > (0);

      if (s.contentLocation_.get ()) contentLocation (*(s.contentLocation_));
      else contentLocation_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (0);

      if (s.href_.get ()) href (*(s.href_));
      else href_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (0);

      return *this;
    }


    // ImplementationArtifactDescription
    // 
    bool ImplementationArtifactDescription::
    label_p () const
    {
      return label_.get () != 0;
    }

    ::XMLSchema::string< ACE_TCHAR > const& ImplementationArtifactDescription::
    label () const
    {
      return *label_;
    }

    ::XMLSchema::string< ACE_TCHAR >& ImplementationArtifactDescription::
    label ()
    {
      return *label_;
    }

    void ImplementationArtifactDescription::
    label (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      if (label_.get ())
      {
        *label_ = e;
      }

      else
      {
        label_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (new ::XMLSchema::string< ACE_TCHAR > (e));
        label_->container (this);
      }
    }

    // ImplementationArtifactDescription
    // 
    bool ImplementationArtifactDescription::
    UUID_p () const
    {
      return UUID_.get () != 0;
    }

    ::XMLSchema::string< ACE_TCHAR > const& ImplementationArtifactDescription::
    UUID () const
    {
      return *UUID_;
    }

    ::XMLSchema::string< ACE_TCHAR >& ImplementationArtifactDescription::
    UUID ()
    {
      return *UUID_;
    }

    void ImplementationArtifactDescription::
    UUID (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      if (UUID_.get ())
      {
        *UUID_ = e;
      }

      else
      {
        UUID_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (new ::XMLSchema::string< ACE_TCHAR > (e));
        UUID_->container (this);
      }
    }

    // ImplementationArtifactDescription
    // 
    ImplementationArtifactDescription::location_iterator ImplementationArtifactDescription::
    begin_location ()
    {
      return location_.begin ();
    }

    ImplementationArtifactDescription::location_iterator ImplementationArtifactDescription::
    end_location ()
    {
      return location_.end ();
    }

    ImplementationArtifactDescription::location_const_iterator ImplementationArtifactDescription::
    begin_location () const
    {
      return location_.begin ();
    }

    ImplementationArtifactDescription::location_const_iterator ImplementationArtifactDescription::
    end_location () const
    {
      return location_.end ();
    }

    void ImplementationArtifactDescription::
    add_location (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      if (location_.capacity () < location_.size () + 1)
      {
        ::std::vector< ::XMLSchema::string< ACE_TCHAR > > v;
        v.reserve (location_.size () + 1);

        while (location_.size ())
        {
          //@@ VC6
          ::XMLSchema::string< ACE_TCHAR >& t = location_.back ();
          t.container (0);
          v.push_back (t);
          v.back ().container (this);
          location_.pop_back ();
        }

        location_.swap (v);
      }

      location_.push_back (e);
      location_.back ().container (this);
    }

    size_t ImplementationArtifactDescription::
    count_location(void) const
    {
      return location_.size ();
    }

    // ImplementationArtifactDescription
    // 
    ImplementationArtifactDescription::dependsOn_iterator ImplementationArtifactDescription::
    begin_dependsOn ()
    {
      return dependsOn_.begin ();
    }

    ImplementationArtifactDescription::dependsOn_iterator ImplementationArtifactDescription::
    end_dependsOn ()
    {
      return dependsOn_.end ();
    }

    ImplementationArtifactDescription::dependsOn_const_iterator ImplementationArtifactDescription::
    begin_dependsOn () const
    {
      return dependsOn_.begin ();
    }

    ImplementationArtifactDescription::dependsOn_const_iterator ImplementationArtifactDescription::
    end_dependsOn () const
    {
      return dependsOn_.end ();
    }

    void ImplementationArtifactDescription::
    add_dependsOn (::CIAO::Config_Handlers::NamedImplementationArtifact const& e)
    {
      if (dependsOn_.capacity () < dependsOn_.size () + 1)
      {
        ::std::vector< ::CIAO::Config_Handlers::NamedImplementationArtifact > v;
        v.reserve (dependsOn_.size () + 1);

        while (dependsOn_.size ())
        {
          //@@ VC6
          ::CIAO::Config_Handlers::NamedImplementationArtifact& t = dependsOn_.back ();
          t.container (0);
          v.push_back (t);
          v.back ().container (this);
          dependsOn_.pop_back ();
        }

        dependsOn_.swap (v);
      }

      dependsOn_.push_back (e);
      dependsOn_.back ().container (this);
    }

    size_t ImplementationArtifactDescription::
    count_dependsOn(void) const
    {
      return dependsOn_.size ();
    }

    // ImplementationArtifactDescription
    // 
    bool ImplementationArtifactDescription::
    execParameter_p () const
    {
      return execParameter_.get () != 0;
    }

    ::CIAO::Config_Handlers::Property const& ImplementationArtifactDescription::
    execParameter () const
    {
      return *execParameter_;
    }

    ::CIAO::Config_Handlers::Property& ImplementationArtifactDescription::
    execParameter ()
    {
      return *execParameter_;
    }

    void ImplementationArtifactDescription::
    execParameter (::CIAO::Config_Handlers::Property const& e)
    {
      if (execParameter_.get ())
      {
        *execParameter_ = e;
      }

      else
      {
        execParameter_ = ::std::auto_ptr< ::CIAO::Config_Handlers::Property > (new ::CIAO::Config_Handlers::Property (e));
        execParameter_->container (this);
      }
    }

    // ImplementationArtifactDescription
    // 
    bool ImplementationArtifactDescription::
    deployRequirement_p () const
    {
      return deployRequirement_.get () != 0;
    }

    ::CIAO::Config_Handlers::Requirement const& ImplementationArtifactDescription::
    deployRequirement () const
    {
      return *deployRequirement_;
    }

    ::CIAO::Config_Handlers::Requirement& ImplementationArtifactDescription::
    deployRequirement ()
    {
      return *deployRequirement_;
    }

    void ImplementationArtifactDescription::
    deployRequirement (::CIAO::Config_Handlers::Requirement const& e)
    {
      if (deployRequirement_.get ())
      {
        *deployRequirement_ = e;
      }

      else
      {
        deployRequirement_ = ::std::auto_ptr< ::CIAO::Config_Handlers::Requirement > (new ::CIAO::Config_Handlers::Requirement (e));
        deployRequirement_->container (this);
      }
    }

    // ImplementationArtifactDescription
    // 
    bool ImplementationArtifactDescription::
    infoProperty_p () const
    {
      return infoProperty_.get () != 0;
    }

    ::CIAO::Config_Handlers::Property const& ImplementationArtifactDescription::
    infoProperty () const
    {
      return *infoProperty_;
    }

    ::CIAO::Config_Handlers::Property& ImplementationArtifactDescription::
    infoProperty ()
    {
      return *infoProperty_;
    }

    void ImplementationArtifactDescription::
    infoProperty (::CIAO::Config_Handlers::Property const& e)
    {
      if (infoProperty_.get ())
      {
        *infoProperty_ = e;
      }

      else
      {
        infoProperty_ = ::std::auto_ptr< ::CIAO::Config_Handlers::Property > (new ::CIAO::Config_Handlers::Property (e));
        infoProperty_->container (this);
      }
    }

    // ImplementationArtifactDescription
    // 
    bool ImplementationArtifactDescription::
    contentLocation_p () const
    {
      return contentLocation_.get () != 0;
    }

    ::XMLSchema::string< ACE_TCHAR > const& ImplementationArtifactDescription::
    contentLocation () const
    {
      return *contentLocation_;
    }

    ::XMLSchema::string< ACE_TCHAR >& ImplementationArtifactDescription::
    contentLocation ()
    {
      return *contentLocation_;
    }

    void ImplementationArtifactDescription::
    contentLocation (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      if (contentLocation_.get ())
      {
        *contentLocation_ = e;
      }

      else
      {
        contentLocation_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (new ::XMLSchema::string< ACE_TCHAR > (e));
        contentLocation_->container (this);
      }
    }

    // ImplementationArtifactDescription
    // 
    bool ImplementationArtifactDescription::
    href_p () const
    {
      return href_.get () != 0;
    }

    ::XMLSchema::string< ACE_TCHAR > const& ImplementationArtifactDescription::
    href () const
    {
      return *href_;
    }

    ::XMLSchema::string< ACE_TCHAR >& ImplementationArtifactDescription::
    href ()
    {
      return *href_;
    }

    void ImplementationArtifactDescription::
    href (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      if (href_.get ())
      {
        *href_ = e;
      }

      else
      {
        href_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (new ::XMLSchema::string< ACE_TCHAR > (e));
        href_->container (this);
      }
    }
  }
}

namespace CIAO
{
  namespace Config_Handlers
  {
    // NamedImplementationArtifact
    //

    NamedImplementationArtifact::
    NamedImplementationArtifact (::XSCRT::XML::Element< ACE_TCHAR > const& e)
    :Base__ (e), regulator__ ()
    {

      ::XSCRT::Parser< ACE_TCHAR > p (e);

      while (p.more_elements ())
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (p.next_element ());
        ::std::basic_string< ACE_TCHAR > n (::XSCRT::XML::uq_name (e.name ()));

        if (n == "name")
        {
          name_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (new ::XMLSchema::string< ACE_TCHAR > (e));
          name_->container (this);
        }

        else if (n == "referencedArtifact")
        {
          referencedArtifact_ = ::std::auto_ptr< ::CIAO::Config_Handlers::ImplementationArtifactDescription > (new ::CIAO::Config_Handlers::ImplementationArtifactDescription (e));
          referencedArtifact_->container (this);
        }

        else 
        {
        }
      }
    }

    // ImplementationArtifactDescription
    //

    ImplementationArtifactDescription::
    ImplementationArtifactDescription (::XSCRT::XML::Element< ACE_TCHAR > const& e)
    :Base__ (e), regulator__ ()
    {

      ::XSCRT::Parser< ACE_TCHAR > p (e);

      while (p.more_elements ())
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (p.next_element ());
        ::std::basic_string< ACE_TCHAR > n (::XSCRT::XML::uq_name (e.name ()));

        if (n == "label")
        {
          ::XMLSchema::string< ACE_TCHAR > t (e);
          label (t);
        }

        else if (n == "UUID")
        {
          ::XMLSchema::string< ACE_TCHAR > t (e);
          UUID (t);
        }

        else if (n == "location")
        {
          ::XMLSchema::string< ACE_TCHAR > t (e);
          add_location (t);
        }

        else if (n == "dependsOn")
        {
          ::CIAO::Config_Handlers::NamedImplementationArtifact t (e);
          add_dependsOn (t);
        }

        else if (n == "execParameter")
        {
          ::CIAO::Config_Handlers::Property t (e);
          execParameter (t);
        }

        else if (n == "deployRequirement")
        {
          ::CIAO::Config_Handlers::Requirement t (e);
          deployRequirement (t);
        }

        else if (n == "infoProperty")
        {
          ::CIAO::Config_Handlers::Property t (e);
          infoProperty (t);
        }

        else if (n == "contentLocation")
        {
          ::XMLSchema::string< ACE_TCHAR > t (e);
          contentLocation (t);
        }

        else 
        {
        }
      }

      while (p.more_attributes ())
      {
        ::XSCRT::XML::Attribute< ACE_TCHAR > a (p.next_attribute ());
        ::std::basic_string< ACE_TCHAR > n (::XSCRT::XML::uq_name (a.name ()));
        if (n == "href")
        {
          ::XMLSchema::string< ACE_TCHAR > t (a);
          href (t);
        }

        else 
        {
        }
      }
    }
  }
}

namespace CIAO
{
  namespace Config_Handlers
  {
  }
}

#include "XMLSchema/TypeInfo.hpp"

namespace CIAO
{
  namespace Config_Handlers
  {
    namespace
    {
      ::XMLSchema::TypeInfoInitializer < ACE_TCHAR > XMLSchemaTypeInfoInitializer_ (::XSCRT::extended_type_info_map ());

      struct NamedImplementationArtifactTypeInfoInitializer
      {
        NamedImplementationArtifactTypeInfoInitializer ()
        {
          ::XSCRT::TypeId id (typeid (NamedImplementationArtifact));
          ::XSCRT::ExtendedTypeInfo nf (id);

          nf.add_base (::XSCRT::ExtendedTypeInfo::Access::public_, false, typeid (::XSCRT::Type));
          ::XSCRT::extended_type_info_map ().insert (::std::make_pair (id, nf));
        }
      };

      NamedImplementationArtifactTypeInfoInitializer NamedImplementationArtifactTypeInfoInitializer_;

      struct ImplementationArtifactDescriptionTypeInfoInitializer
      {
        ImplementationArtifactDescriptionTypeInfoInitializer ()
        {
          ::XSCRT::TypeId id (typeid (ImplementationArtifactDescription));
          ::XSCRT::ExtendedTypeInfo nf (id);

          nf.add_base (::XSCRT::ExtendedTypeInfo::Access::public_, false, typeid (::XSCRT::Type));
          ::XSCRT::extended_type_info_map ().insert (::std::make_pair (id, nf));
        }
      };

      ImplementationArtifactDescriptionTypeInfoInitializer ImplementationArtifactDescriptionTypeInfoInitializer_;
    }
  }
}

namespace CIAO
{
  namespace Config_Handlers
  {
    namespace Traversal
    {
      // NamedImplementationArtifact
      //
      //

      void NamedImplementationArtifact::
      traverse (Type& o)
      {
        pre (o);
        name (o);
        referencedArtifact (o);
        post (o);
      }

      void NamedImplementationArtifact::
      traverse (Type const& o)
      {
        pre (o);
        name (o);
        referencedArtifact (o);
        post (o);
      }

      void NamedImplementationArtifact::
      pre (Type&)
      {
      }

      void NamedImplementationArtifact::
      pre (Type const&)
      {
      }

      void NamedImplementationArtifact::
      name (Type& o)
      {
        dispatch (o.name ());
      }

      void NamedImplementationArtifact::
      name (Type const& o)
      {
        dispatch (o.name ());
      }

      void NamedImplementationArtifact::
      referencedArtifact (Type& o)
      {
        dispatch (o.referencedArtifact ());
      }

      void NamedImplementationArtifact::
      referencedArtifact (Type const& o)
      {
        dispatch (o.referencedArtifact ());
      }

      void NamedImplementationArtifact::
      post (Type&)
      {
      }

      void NamedImplementationArtifact::
      post (Type const&)
      {
      }

      // ImplementationArtifactDescription
      //
      //

      void ImplementationArtifactDescription::
      traverse (Type& o)
      {
        pre (o);
        if (o.label_p ()) label (o);
        else label_none (o);
        if (o.UUID_p ()) UUID (o);
        else UUID_none (o);
        location (o);
        dependsOn (o);
        if (o.execParameter_p ()) execParameter (o);
        else execParameter_none (o);
        if (o.deployRequirement_p ()) deployRequirement (o);
        else deployRequirement_none (o);
        if (o.infoProperty_p ()) infoProperty (o);
        else infoProperty_none (o);
        if (o.contentLocation_p ()) contentLocation (o);
        else contentLocation_none (o);
        if (o.href_p ()) href (o);
        else href_none (o);
        post (o);
      }

      void ImplementationArtifactDescription::
      traverse (Type const& o)
      {
        pre (o);
        if (o.label_p ()) label (o);
        else label_none (o);
        if (o.UUID_p ()) UUID (o);
        else UUID_none (o);
        location (o);
        dependsOn (o);
        if (o.execParameter_p ()) execParameter (o);
        else execParameter_none (o);
        if (o.deployRequirement_p ()) deployRequirement (o);
        else deployRequirement_none (o);
        if (o.infoProperty_p ()) infoProperty (o);
        else infoProperty_none (o);
        if (o.contentLocation_p ()) contentLocation (o);
        else contentLocation_none (o);
        if (o.href_p ()) href (o);
        else href_none (o);
        post (o);
      }

      void ImplementationArtifactDescription::
      pre (Type&)
      {
      }

      void ImplementationArtifactDescription::
      pre (Type const&)
      {
      }

      void ImplementationArtifactDescription::
      label (Type& o)
      {
        dispatch (o.label ());
      }

      void ImplementationArtifactDescription::
      label (Type const& o)
      {
        dispatch (o.label ());
      }

      void ImplementationArtifactDescription::
      label_none (Type&)
      {
      }

      void ImplementationArtifactDescription::
      label_none (Type const&)
      {
      }

      void ImplementationArtifactDescription::
      UUID (Type& o)
      {
        dispatch (o.UUID ());
      }

      void ImplementationArtifactDescription::
      UUID (Type const& o)
      {
        dispatch (o.UUID ());
      }

      void ImplementationArtifactDescription::
      UUID_none (Type&)
      {
      }

      void ImplementationArtifactDescription::
      UUID_none (Type const&)
      {
      }

      void ImplementationArtifactDescription::
      location (Type& o)
      {
        // VC6 anathema strikes again
        //
        ImplementationArtifactDescription::Type::location_iterator b (o.begin_location()), e (o.end_location());

        if (b != e)
        {
          location_pre (o);
          for (;
           b != e;
          )
          {
            dispatch (*b);
            if (++b != e) location_next (o);
          }

          location_post (o);
        }

        else location_none (o);
      }

      void ImplementationArtifactDescription::
      location (Type const& o)
      {
        // VC6 anathema strikes again
        //
        ImplementationArtifactDescription::Type::location_const_iterator b (o.begin_location()), e (o.end_location());

        if (b != e)
        {
          location_pre (o);
          for (;
           b != e;
          )
          {
            dispatch (*b);
            if (++b != e) location_next (o);
          }

          location_post (o);
        }

        else location_none (o);
      }

      void ImplementationArtifactDescription::
      location_pre (Type&)
      {
      }

      void ImplementationArtifactDescription::
      location_pre (Type const&)
      {
      }

      void ImplementationArtifactDescription::
      location_next (Type&)
      {
      }

      void ImplementationArtifactDescription::
      location_next (Type const&)
      {
      }

      void ImplementationArtifactDescription::
      location_post (Type&)
      {
      }

      void ImplementationArtifactDescription::
      location_post (Type const&)
      {
      }

      void ImplementationArtifactDescription::
      location_none (Type&)
      {
      }

      void ImplementationArtifactDescription::
      location_none (Type const&)
      {
      }

      void ImplementationArtifactDescription::
      dependsOn (Type& o)
      {
        // VC6 anathema strikes again
        //
        ImplementationArtifactDescription::Type::dependsOn_iterator b (o.begin_dependsOn()), e (o.end_dependsOn());

        if (b != e)
        {
          dependsOn_pre (o);
          for (;
           b != e;
          )
          {
            dispatch (*b);
            if (++b != e) dependsOn_next (o);
          }

          dependsOn_post (o);
        }

        else dependsOn_none (o);
      }

      void ImplementationArtifactDescription::
      dependsOn (Type const& o)
      {
        // VC6 anathema strikes again
        //
        ImplementationArtifactDescription::Type::dependsOn_const_iterator b (o.begin_dependsOn()), e (o.end_dependsOn());

        if (b != e)
        {
          dependsOn_pre (o);
          for (;
           b != e;
          )
          {
            dispatch (*b);
            if (++b != e) dependsOn_next (o);
          }

          dependsOn_post (o);
        }

        else dependsOn_none (o);
      }

      void ImplementationArtifactDescription::
      dependsOn_pre (Type&)
      {
      }

      void ImplementationArtifactDescription::
      dependsOn_pre (Type const&)
      {
      }

      void ImplementationArtifactDescription::
      dependsOn_next (Type&)
      {
      }

      void ImplementationArtifactDescription::
      dependsOn_next (Type const&)
      {
      }

      void ImplementationArtifactDescription::
      dependsOn_post (Type&)
      {
      }

      void ImplementationArtifactDescription::
      dependsOn_post (Type const&)
      {
      }

      void ImplementationArtifactDescription::
      dependsOn_none (Type&)
      {
      }

      void ImplementationArtifactDescription::
      dependsOn_none (Type const&)
      {
      }

      void ImplementationArtifactDescription::
      execParameter (Type& o)
      {
        dispatch (o.execParameter ());
      }

      void ImplementationArtifactDescription::
      execParameter (Type const& o)
      {
        dispatch (o.execParameter ());
      }

      void ImplementationArtifactDescription::
      execParameter_none (Type&)
      {
      }

      void ImplementationArtifactDescription::
      execParameter_none (Type const&)
      {
      }

      void ImplementationArtifactDescription::
      deployRequirement (Type& o)
      {
        dispatch (o.deployRequirement ());
      }

      void ImplementationArtifactDescription::
      deployRequirement (Type const& o)
      {
        dispatch (o.deployRequirement ());
      }

      void ImplementationArtifactDescription::
      deployRequirement_none (Type&)
      {
      }

      void ImplementationArtifactDescription::
      deployRequirement_none (Type const&)
      {
      }

      void ImplementationArtifactDescription::
      infoProperty (Type& o)
      {
        dispatch (o.infoProperty ());
      }

      void ImplementationArtifactDescription::
      infoProperty (Type const& o)
      {
        dispatch (o.infoProperty ());
      }

      void ImplementationArtifactDescription::
      infoProperty_none (Type&)
      {
      }

      void ImplementationArtifactDescription::
      infoProperty_none (Type const&)
      {
      }

      void ImplementationArtifactDescription::
      contentLocation (Type& o)
      {
        dispatch (o.contentLocation ());
      }

      void ImplementationArtifactDescription::
      contentLocation (Type const& o)
      {
        dispatch (o.contentLocation ());
      }

      void ImplementationArtifactDescription::
      contentLocation_none (Type&)
      {
      }

      void ImplementationArtifactDescription::
      contentLocation_none (Type const&)
      {
      }

      void ImplementationArtifactDescription::
      href (Type& o)
      {
        dispatch (o.href ());
      }

      void ImplementationArtifactDescription::
      href (Type const& o)
      {
        dispatch (o.href ());
      }

      void ImplementationArtifactDescription::
      href_none (Type&)
      {
      }

      void ImplementationArtifactDescription::
      href_none (Type const&)
      {
      }

      void ImplementationArtifactDescription::
      post (Type&)
      {
      }

      void ImplementationArtifactDescription::
      post (Type const&)
      {
      }
    }
  }
}

namespace CIAO
{
  namespace Config_Handlers
  {
    namespace Writer
    {
      // NamedImplementationArtifact
      //
      //

      NamedImplementationArtifact::
      NamedImplementationArtifact (::XSCRT::XML::Element< ACE_TCHAR >& e)
      : ::XSCRT::Writer< ACE_TCHAR > (e)
      {
      }

      NamedImplementationArtifact::
      NamedImplementationArtifact ()
      {
      }

      void NamedImplementationArtifact::
      traverse (Type const& o)
      {
        Traversal::NamedImplementationArtifact::traverse (o);
      }

      void NamedImplementationArtifact::
      name (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("name", top_ ()));
        Traversal::NamedImplementationArtifact::name (o);
        pop_ ();
      }

      void NamedImplementationArtifact::
      referencedArtifact (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("referencedArtifact", top_ ()));
        Traversal::NamedImplementationArtifact::referencedArtifact (o);
        pop_ ();
      }

      // ImplementationArtifactDescription
      //
      //

      ImplementationArtifactDescription::
      ImplementationArtifactDescription (::XSCRT::XML::Element< ACE_TCHAR >& e)
      : ::XSCRT::Writer< ACE_TCHAR > (e)
      {
      }

      ImplementationArtifactDescription::
      ImplementationArtifactDescription ()
      {
      }

      void ImplementationArtifactDescription::
      traverse (Type const& o)
      {
        Traversal::ImplementationArtifactDescription::traverse (o);
      }

      void ImplementationArtifactDescription::
      label (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("label", top_ ()));
        Traversal::ImplementationArtifactDescription::label (o);
        pop_ ();
      }

      void ImplementationArtifactDescription::
      UUID (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("UUID", top_ ()));
        Traversal::ImplementationArtifactDescription::UUID (o);
        pop_ ();
      }

      void ImplementationArtifactDescription::
      location_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("location", top_ ()));
      }

      void ImplementationArtifactDescription::
      location_next (Type const& o)
      {
        location_post (o);
        location_pre (o);
      }

      void ImplementationArtifactDescription::
      location_post (Type const&)
      {
        pop_ ();
      }

      void ImplementationArtifactDescription::
      dependsOn_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("dependsOn", top_ ()));
      }

      void ImplementationArtifactDescription::
      dependsOn_next (Type const& o)
      {
        dependsOn_post (o);
        dependsOn_pre (o);
      }

      void ImplementationArtifactDescription::
      dependsOn_post (Type const&)
      {
        pop_ ();
      }

      void ImplementationArtifactDescription::
      execParameter (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("execParameter", top_ ()));
        Traversal::ImplementationArtifactDescription::execParameter (o);
        pop_ ();
      }

      void ImplementationArtifactDescription::
      deployRequirement (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("deployRequirement", top_ ()));
        Traversal::ImplementationArtifactDescription::deployRequirement (o);
        pop_ ();
      }

      void ImplementationArtifactDescription::
      infoProperty (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("infoProperty", top_ ()));
        Traversal::ImplementationArtifactDescription::infoProperty (o);
        pop_ ();
      }

      void ImplementationArtifactDescription::
      contentLocation (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > ("contentLocation", top_ ()));
        Traversal::ImplementationArtifactDescription::contentLocation (o);
        pop_ ();
      }

      void ImplementationArtifactDescription::
      href (Type const& o)
      {
        ::XSCRT::XML::Attribute< ACE_TCHAR > a ("href", "", top_ ());
        attr_ (&a);
        Traversal::ImplementationArtifactDescription::href (o);
        attr_ (0);
      }
    }
  }
}

namespace CIAO
{
  namespace Config_Handlers
  {
  }
}


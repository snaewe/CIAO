// $Id$
#include "toplevel.hpp"

namespace CIAO
{
  namespace Config_Handlers
  {
    // TopLevelPackageDescription
    // 

    TopLevelPackageDescription::
    TopLevelPackageDescription ()
    :
    regulator__ ()
    {
    }

    TopLevelPackageDescription::
    TopLevelPackageDescription (::CIAO::Config_Handlers::TopLevelPackageDescription const& s)
    :
    regulator__ ()
    {
      package_.reserve (s.package_.size ());
      {
        for (package_const_iterator i (s.package_.begin ());
        i != s.package_.end ();
        ++i) add_package (*i);
      }
    }

    ::CIAO::Config_Handlers::TopLevelPackageDescription& TopLevelPackageDescription::
    operator= (::CIAO::Config_Handlers::TopLevelPackageDescription const& s)
    {
      package_.clear ();
      package_.reserve (s.package_.size ());
      {
        for (package_const_iterator i (s.package_.begin ());
        i != s.package_.end ();
        ++i) add_package (*i);
      }

      return *this;
    }


    // TopLevelPackageDescription
    // 
    TopLevelPackageDescription::package_iterator TopLevelPackageDescription::
    begin_package ()
    {
      return package_.begin ();
    }

    TopLevelPackageDescription::package_iterator TopLevelPackageDescription::
    end_package ()
    {
      return package_.end ();
    }

    TopLevelPackageDescription::package_const_iterator TopLevelPackageDescription::
    begin_package () const
    {
      return package_.begin ();
    }

    TopLevelPackageDescription::package_const_iterator TopLevelPackageDescription::
    end_package () const
    {
      return package_.end ();
    }

    void TopLevelPackageDescription::
    add_package (::CIAO::Config_Handlers::PackageConfiguration const& e)
    {
      if (package_.capacity () < package_.size () + 1)
      {
        ::std::vector< ::CIAO::Config_Handlers::PackageConfiguration > v;
        v.reserve (package_.size () + 1);

        while (package_.size ())
        {
          //@@ VC6
          ::CIAO::Config_Handlers::PackageConfiguration& t = package_.back ();
          t.container (0);
          v.push_back (t);
          v.back ().container (this);
          package_.pop_back ();
        }

        package_.swap (v);
      }

      package_.push_back (e);
      package_.back ().container (this);
    }
  }
}

namespace CIAO
{
  namespace Config_Handlers
  {
    // TopLevelPackageDescription
    //

    TopLevelPackageDescription::
    TopLevelPackageDescription (::XSCRT::XML::Element< char > const& e)
    :
    Base__ (e),
    regulator__ ()
    {

      ::XSCRT::Parser< char > p (e);

      while (p.more_elements ())
      {
        ::XSCRT::XML::Element< char > e (p.next_element ());
        ::std::basic_string< char > n (::XSCRT::XML::uq_name (e.name ()));

        if (n == "package")
        {
          ::CIAO::Config_Handlers::PackageConfiguration t (e);
          add_package (t);
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


<?xml version="1.0"?> <!-- -*- SGML -*-  -->

<!-- XML doesn't really support the following $(CIAO_ROOT) syntax :) -->
<!DOCTYPE softpkg SYSTEM "$(CIAO_ROOT)/docs/XML/softpkg.dtd">

<!-- RateGen's Software Package Descriptor  -->
<!-- This file describes various RateGen executor -->
<!-- implementations. -->


<softpkg name="CIAO-RateGen" version="1.0">
  <pkgtype>CORBA Component</pkgtype>
  <title>Rate Generator</title>
  <author>
    <company>Washington University in St. Louis</company>
    <webpage href="http://www.cs.wustl.edu/~doc/"/>
  </author>
  <description>A RateGen executor implementation.</description>
  <license href="http://www.cs.wustl.edu/~schmidt/ACE-copying.html"/>
  <idl id="IDL:HUDisplay/RateGen:1.0" homeid="IDL:HUDisplay/RateGenHome:1.0">
    <fileinarchive name="RateGen.idl"/>
  </idl>

  <!-- We don't need a property file for this example.  However,         -->
  <!-- what to do with this element?  Cache it in ComponentInstallation? -->
  <!-- A better question maybe, when do we actually read the file and    -->
  <!-- build the attributes defined in the file?  By Assembly perhaps?   -->
  <!-- Notice that this property file applies to the implementation itself. -->
  <!-- Whatever that means. -->
<!--   <propertyfile> -->
<!--     <fileinarchive name="empty.cpf"/> -->
<!--   </propertyfile> -->

  <descriptor type="CORBA Component">
    <fileinarchive name="RateGen.ccd"/>
  </descriptor>

  <implementation id="DCE:82C2B032-37F0-4315-A59F-7020D3264E4D">

    <!-- CIAO extension -->
    <dependency type="CIAODLL">
      <softpkgref>
        <!-- .ssd stands for Servant Software Descriptors which is a CIAO extension -->
        <fileinarchive name="RateGen.ssd"/>
        <implref idref="DCE:93D254CF-9538-44e8-BB98-AABCD134ADD3"/>
      </softpkgref>
    </dependency>

    <!-- What happens when one define descriptors for both softpkg and -->
    <!-- implementations? -->

    <code type="DLL">
      <!-- No need to specify extension below since ACE takes care of that, -->
      <fileinarchive name="RateGen_exec"/>
      <entrypoint>createRateGenHome_Impl</entrypoint>
    </code>

  </implementation>

  <!-- Let's add more implementation description later when we try to -->
  <!-- compile this stuff on, say, Solaris and Linux.                 -->

</softpkg>
# ADS_FLAGTYPE_ENUM enumeration

## Description

The **ADS_FLAGTYPE_ENUM** enumeration specifies values that can be used to indicate the presence of the **ObjectType** or **InheritedObjectType** fields in the access-control entry (ACE).

## Constants

### `ADS_FLAG_OBJECT_TYPE_PRESENT:0x1`

The **ObjectType** field is present in the ACE.

### `ADS_FLAG_INHERITED_OBJECT_TYPE_PRESENT:0x2`

The **InheritedObjectType** field is present in the ACE.

## Remarks

**ObjectType** indicates what object type, property set, or property an ACE refers to. It takes a GUID as its value. The GUID referenced by **ObjectType** is not physically present in the ACE unless ADS_FLAGS_OBJECT_TYPE_PRESENT is set.

**InheritedObjectType** specifies the GUID of an object that will inherit the ACE. The GUID is not physically present in the ACE unless the ADS_FLAG_INHERITED_OBJECT_TYPE_PRESENT bit is set.

**Note** Because VBScript cannot read information from a type library, VBScript applications do not understand the symbolic constants as defined above. You should use the numerical constants instead to set the appropriate flags in your VBScript applications. If you want to use the symbolic constants as a good programming practice, you should make explicit declarations of such constants, as done here, in your VBScript applications.

## See also

[ADSI Enumerations](https://learn.microsoft.com/windows/desktop/ADSI/adsi-enumerations)
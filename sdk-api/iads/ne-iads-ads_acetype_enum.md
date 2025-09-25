# ADS_ACETYPE_ENUM enumeration

## Description

The **ADS_ACETYPE_ENUM** enumeration is used to specify the type of an access-control entry for Active Directory objects. The [IADsAccessControlEntry.AceType](https://learn.microsoft.com/windows/desktop/ADSI/iadsaccesscontrolentry-property-methods) property contains one of these values for an Active Directory object.

For more information and possible values for file, file share and registry objects, see the **AceType** member of the [ACE_HEADER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-ace_header) structure.

## Constants

### `ADS_ACETYPE_ACCESS_ALLOWED:0`

The ACE is of the standard ACCESS ALLOWED type, where the **ObjectType** and **InheritedObjectType** fields are **NULL**.

### `ADS_ACETYPE_ACCESS_DENIED:0x1`

The ACE is of the standard system-audit type, where the **ObjectType** and **InheritedObjectType** fields are **NULL**.

### `ADS_ACETYPE_SYSTEM_AUDIT:0x2`

The ACE is of the standard system type, where the **ObjectType** and **InheritedObjectType** fields are **NULL**.

### `ADS_ACETYPE_ACCESS_ALLOWED_OBJECT:0x5`

The ACE grants access to an object or a subobject of the object, such as a property set or property. **ObjectType** or **InheritedObjectType** or both contain a GUID that identifies a property set, property, extended right, or type of child object.

### `ADS_ACETYPE_ACCESS_DENIED_OBJECT:0x6`

The ACE denies access to an object or a subobject of the object, such as a property set or property. **ObjectType** or **InheritedObjectType** or both contain a GUID that identifies a property set, property, extended right, or type of child object.

### `ADS_ACETYPE_SYSTEM_AUDIT_OBJECT:0x7`

The ACE audits access to an object or a subobject of the object, such as a property set or property. **ObjectType** or **InheritedObjectType** or both contain a GUID that identifies a property set, property, extended right, or type of child object.

### `ADS_ACETYPE_SYSTEM_ALARM_OBJECT:0x8`

Not used.

### `ADS_ACETYPE_ACCESS_ALLOWED_CALLBACK:0x9`

Same functionality as **ADS_ACETYPE_ACCESS_ALLOWED**, but used with applications that use Authz to verify ACEs.

### `ADS_ACETYPE_ACCESS_DENIED_CALLBACK:0xa`

Same functionality as **ADS_ACETYPE_ACCESS_DENIED**, but used with applications that use Authz to verify ACEs.

### `ADS_ACETYPE_ACCESS_ALLOWED_CALLBACK_OBJECT:0xb`

Same functionality as **ADS_ACETYPE_ACCESS_ALLOWED_OBJECT**, but used with applications that use Authz to verify ACEs.

### `ADS_ACETYPE_ACCESS_DENIED_CALLBACK_OBJECT:0xc`

Same functionality as **ADS_ACETYPE_ACCESS_DENIED_OBJECT**, but used with applications that use Authz to check ACEs.

### `ADS_ACETYPE_SYSTEM_AUDIT_CALLBACK:0xd`

Same functionality as **ADS_ACETYPE_SYSTEM_AUDIT**, but used with applications that use Authz to check ACEs.

### `ADS_ACETYPE_SYSTEM_ALARM_CALLBACK:0xe`

Not used.

### `ADS_ACETYPE_SYSTEM_AUDIT_CALLBACK_OBJECT:0xf`

Same functionality as **ADS_ACETYPE_SYSTEM_AUDIT_OBJECT**, but used with applications that use Authz to verify ACEs.

### `ADS_ACETYPE_SYSTEM_ALARM_CALLBACK_OBJECT:0x10`

Not used.

## Remarks

A standard ACE is one defined and used in a Windows security descriptor. Windows enables the ACE to be applied to objects and properties identified by GUIDs.

Use the [IADsAccessControlEntry](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsaccesscontrolentry) property method to determine the ACE type.

**Note** Because Visual Basic Scripting Edition (VBScript) cannot read data from a type library, VBScript applications cannot recognize symbolic constants as defined above. Use the numeric constants instead to set the appropriate flags in VBScript applications. To use the symbolic constants as a good programming practice, write explicit declarations of such constants, as done here, in VBScript applications.

## See also

[ADSI Enumerations](https://learn.microsoft.com/windows/desktop/ADSI/adsi-enumerations)

[IADsAccessControlEntry](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsaccesscontrolentry)

[IADsAccessControlEntry.AceType](https://learn.microsoft.com/windows/desktop/ADSI/iadsaccesscontrolentry-property-methods)
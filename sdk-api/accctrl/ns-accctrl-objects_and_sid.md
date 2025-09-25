# OBJECTS_AND_SID structure

## Description

The **OBJECTS_AND_SID** structure contains a [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) that identifies a trustee and GUIDs that identify the object types of an object-specific [access control entry](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACE).

## Members

### `ObjectsPresent`

Indicates whether the **ObjectTypeGuid** and **InheritedObjectTypeGuid** members contain GUIDs. This parameter can be a combination of the following values.

| Value | Meaning |
| --- | --- |
| **ACE_OBJECT_TYPE_PRESENT**<br><br>0x1 | The **ObjectTypeGuid** member contains a GUID. |
| **ACE_INHERITED_OBJECT_TYPE_PRESENT**<br><br>0x2 | The **InheritedObjectTypeGuid** member contains a GUID. |

### `ObjectTypeGuid`

A
[GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid) structure that identifies the type of object, property set, or property protected by the ACE. If this ACE is inherited, the GUID identifies the type of object, property set, or property protected by the inherited ACE. This GUID must be a valid schema identifier in the Active Directory schema.

If the ACE_OBJECT_TYPE_PRESENT bit is not set in the **ObjectsPresent** member, the **ObjectTypeGuid** member is ignored, and the ACE protects the object to which the ACL is assigned.

### `InheritedObjectTypeGuid`

A [GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid) structure that identifies the type of object that can inherit the ACE. This GUID must be a valid schema identifier in the Active Directory schema.

If the ACE_INHERITED_OBJECT_TYPE_PRESENT bit is not set in the **ObjectsPresent** member, the **InheritedObjectTypeGuid** member is ignored, and all types of child objects can inherit the ACE. Otherwise, only the specified object type can inherit the ACE. In either case, inheritance is also controlled by the inheritance flags in the [ACE_HEADER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-ace_header) structure as well as by any protection against inheritance placed on the child objects.

### `pSid`

A pointer to the SID of the trustee to whom the ACE applies.

## Remarks

The **ptstrName** member of a [TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a) structure can be a pointer to an **OBJECTS_AND_SID** structure. This enables functions such as [SetEntriesInAcl](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-setentriesinacla) and [GetExplicitEntriesFromAcl](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-getexplicitentriesfromacla) to store object-specific ACE information in the **Trustee** member of an [EXPLICIT_ACCESS](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-explicit_access_a) structure.

When you use this structure in a call to [SetEntriesInAcl](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-setentriesinacla), **ObjectTypeGuid** and **InheritedObjectTypeGuid** must be valid schema identifiers in the Active Directory schema. The system does not verify the GUIDs; they are used as is.

## See also

[ACE_HEADER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-ace_header)

[EXPLICIT_ACCESS](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-explicit_access_a)

[GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid)

[GetExplicitEntriesFromAcl](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-getexplicitentriesfromacla)

[OBJECTS_AND_NAME](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-objects_and_name_a)

[SetEntriesInAcl](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-setentriesinacla)

[TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a)
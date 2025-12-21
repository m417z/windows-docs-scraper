# OBJECTS_AND_NAME_A structure

## Description

The **OBJECTS_AND_NAME** structure contains a string that identifies a trustee by name and additional strings that identify the object types of an object-specific [access control entry](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACE).

## Members

### `ObjectsPresent`

Indicates whether the **ObjectTypeName** and **InheritedObjectTypeName** members contain strings. This parameter can be a combination of the following values.

| Value | Meaning |
| --- | --- |
| **ACE_OBJECT_TYPE_PRESENT**<br><br>0x1 | The **ObjectTypeName** member contains a string. |
| **ACE_INHERITED_OBJECT_TYPE_PRESENT**<br><br>0x2 | The **InheritedObjectTypeName** member contains a string. |

### `ObjectType`

Specifies a value from the
[SE_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/accctrl/ne-accctrl-se_object_type) enumeration that indicates the type of object.

### `ObjectTypeName`

A pointer to a null-terminated string that identifies the type of object to which the ACE applies.

This string must be a valid [LDAP](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) display name in the Active Directory schema.

If the ACE_INHERITED_OBJECT_TYPE_PRESENT bit is not set in the **ObjectsPresent** member, the **ObjectTypeName** member is ignored.

### `InheritedObjectTypeName`

A pointer to a null-terminated string that identifies the type of object that can inherit the ACE.

This string must be a valid [LDAP](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) display name in the Active Directory schema.

If the ACE_INHERITED_OBJECT_TYPE_PRESENT bit is not set in the **ObjectsPresent** member, the **InheritedObjectTypeName** member is ignored, and all types of child objects can inherit the ACE. Otherwise, only the specified object type can inherit the ACE. In either case, inheritance is also controlled by the inheritance flags in the [ACE_HEADER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-ace_header) structure as well as by any protection against inheritance placed on the child objects.

### `ptstrName`

A pointer to a null-terminated string that contains the name of the trustee.

## Remarks

The **ptstrName** member of a [TRUSTEE_A](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a) structure is a pointer to an **OBJECTS_AND_NAME_A** structure if the **TrusteeForm** is **TRUSTEE_IS_OBJECTS_AND_NAME**. This enables functions such as [SetEntriesInAcl](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-setentriesinacla) and [GetExplicitEntriesFromAcl](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-getexplicitentriesfromacla) to store object-specific ACE information in the **Trustee** member of an [EXPLICIT_ACCESS](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-explicit_access_a) structure.

> [!NOTE]
> The accctrl.h header defines OBJECTS_AND_NAME_ as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ACE_HEADER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-ace_header)

[EXPLICIT_ACCESS](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-explicit_access_a)

[GetExplicitEntriesFromAcl](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-getexplicitentriesfromacla)

[OBJECTS_AND_SID](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-objects_and_sid)

[SE_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/accctrl/ne-accctrl-se_object_type)

[SetEntriesInAcl](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-setentriesinacla)

[TRUSTEE_A](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a)
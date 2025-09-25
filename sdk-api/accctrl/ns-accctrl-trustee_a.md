# TRUSTEE_A structure

## Description

The **TRUSTEE** structure identifies the user account, group account, or [logon session](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) to which an [access control entry](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACE) applies. The structure can use a name or a [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) to identify the trustee.

Access control functions, such as
[SetEntriesInAcl](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-setentriesinacla) and
[GetExplicitEntriesFromAcl](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-getexplicitentriesfromacla), use this structure to identify the logon account associated with the access control or audit control information in an [EXPLICIT_ACCESS](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-explicit_access_a) structure.

## Members

### `pMultipleTrustee`

A pointer to a **TRUSTEE** structure that identifies a server account that can impersonate the user identified by the **ptstrName** member. This member is not currently supported and must be **NULL**.

### `MultipleTrusteeOperation`

A value of the
[MULTIPLE_TRUSTEE_OPERATION](https://learn.microsoft.com/windows/desktop/api/accctrl/ne-accctrl-multiple_trustee_operation) enumeration type. Currently, this member must be NO_MULTIPLE_TRUSTEE.

### `TrusteeForm`

A value from the
[TRUSTEE_FORM](https://learn.microsoft.com/windows/desktop/api/accctrl/ne-accctrl-trustee_form) enumeration type that indicates the type of data pointed to by the **ptstrName** member.

### `TrusteeType`

A value from the
[TRUSTEE_TYPE](https://learn.microsoft.com/windows/desktop/api/accctrl/ne-accctrl-trustee_type) enumeration type that indicates whether the trustee is a user account, a group account, or an unknown account type.

### `ptstrName.case`

### `ptstrName.case.TRUSTEE_IS_NAME`

### `pSid`

### `pSid.case`

### `pSid.case.TRUSTEE_IS_SID`

### `pObjectsAndSid`

### `pObjectsAndSid.case`

### `pObjectsAndSid.case.TRUSTEE_IS_OBJECTS_AND_SID`

### `pObjectsAndName`

### `pObjectsAndName.case`

### `pObjectsAndName.case.TRUSTEE_IS_OBJECTS_AND_NAME`

### `ptstrName`

 A pointer to a buffer that identifies the trustee and, optionally, contains information about object-specific ACEs. The type of data depends on the value of the **TrusteeForm** member.

This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **TRUSTEE_IS_NAME** | A pointer to a **null**-terminated string that contains the name of the trustee. |
| **TRUSTEE_IS_OBJECTS_AND_NAME** | A pointer to an [OBJECTS_AND_NAME](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-objects_and_name_a) structure that contains the name of the trustee and the names of the object types in an object-specific ACE. |
| **TRUSTEE_IS_OBJECTS_AND_SID** | A pointer to an [OBJECTS_AND_SID](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-objects_and_sid) structure that contains the SID of the trustee and the GUIDs of the object types in an object-specific ACE. |
| **TRUSTEE_IS_SID** | Pointer to the SID of the trustee. |

## Remarks

A trustee name can have any of the following formats:

* A fully qualified name, such as "g:\remotedir\abc".
* A domain account, such as "domain1\xyz".
* One of the predefined group names, such as "EVERYONE" or "GUEST".
* One of the following special names.

  | Name | Meaning |
  | --- | --- |
  | CREATOR GROUP | The CREATOR_GROUP SID is a SID used in inheritable ACEs. When a new object is created, the system replaces this SID with the primary group SID of the user who created the object. |
  | CREATOR OWNER | The CREATOR_OWNER SID is a SID used in inheritable ACEs. When a new object is created, the system replaces this SID with the SID of the user who created the object. |
  | CURRENT_USER | The owner of the calling thread or process. |

A trustee SID can be any user or group SID. It can also be any of the [universal, well-known SIDs](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly). For more information, see
[Security Identifiers](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-identifiers).

> [!NOTE]
> The accctrl.h header defines TRUSTEE_ as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl)

[EXPLICIT_ACCESS](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-explicit_access_a)

[GetExplicitEntriesFromAcl](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-getexplicitentriesfromacla)

[MULTIPLE_TRUSTEE_OPERATION](https://learn.microsoft.com/windows/desktop/api/accctrl/ne-accctrl-multiple_trustee_operation)

[OBJECTS_AND_NAME](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-objects_and_name_a)

[OBJECTS_AND_SID](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-objects_and_sid)

[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid)

[SetEntriesInAcl](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-setentriesinacla)

[TRUSTEE_FORM](https://learn.microsoft.com/windows/desktop/api/accctrl/ne-accctrl-trustee_form)

[TRUSTEE_TYPE](https://learn.microsoft.com/windows/desktop/api/accctrl/ne-accctrl-trustee_type)
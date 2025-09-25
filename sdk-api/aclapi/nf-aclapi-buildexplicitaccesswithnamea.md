# BuildExplicitAccessWithNameA function

## Description

The **BuildExplicitAccessWithName** function initializes an
[EXPLICIT_ACCESS](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-explicit_access_a) structure with data specified by the caller. The trustee is identified by a name string.

## Parameters

### `pExplicitAccess` [in, out]

A pointer to an
[EXPLICIT_ACCESS](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-explicit_access_a) structure to initialize. The **BuildExplicitAccessWithName** function does not allocate any memory. This parameter cannot be **NULL**.

### `pTrusteeName` [in, optional]

A pointer to a **null**-terminated string that contains the name of the trustee for the **ptstrName** member of the
[TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a) structure. The **BuildExplicitAccessWithName** function sets the other members of the **TRUSTEE** structure as follows.

| Value | Meaning |
| --- | --- |
| ****pMultipleTrustee**** | **NULL** |
| ****MultipleTrusteeOperation**** | NO_MULTIPLE_TRUSTEE |
| ****TrusteeForm**** | TRUSTEE_IS_NAME |
| ****TrusteeType**** | TRUSTEE_IS_UNKNOWN |

### `AccessPermissions` [in]

Specifies an [access mask](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) for the **grfAccessPermissions** member of the [EXPLICIT_ACCESS](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-explicit_access_a) structure. The mask is a set of bit flags that use the
[ACCESS_MASK](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-mask) format to specify the access rights that an
[ACE](https://learn.microsoft.com/windows/desktop/SecAuthZ/ace) allows, denies, or audits for the trustee. The functions that use the **EXPLICIT_ACCESS** structure do not convert, interpret, or validate the bits in this mask.

### `AccessMode` [in]

Specifies an access mode for the **grfAccessMode** member of the [EXPLICIT_ACCESS](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-explicit_access_a) structure. The access mode indicates whether the [access control entry](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACE) allows, denies, or audits the specified rights. For a [discretionary access control list](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DACL), this parameter can be one of the values from the
[ACCESS_MODE](https://learn.microsoft.com/windows/desktop/api/accctrl/ne-accctrl-access_mode) enumeration. For a [system access control list](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SACL), this parameter can be a combination of **ACCESS_MODE** values.

### `Inheritance` [in]

Specifies an inheritance type for the **grfInheritance** member of the [EXPLICIT_ACCESS](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-explicit_access_a) structure. This value is a set of bit flags that determine whether other containers or objects can inherit the ACE from the primary object to which the
[ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl) is attached. The value of this member corresponds to the inheritance portion (low-order byte) of the **AceFlags** member of the
[ACE_HEADER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-ace_header) structure. This parameter can be NO_INHERITANCE to indicate that the ACE is not inheritable, or it can be a combination of the following values.

| Value | Meaning |
| --- | --- |
| **CONTAINER_INHERIT_ACE** | Other containers that are contained by the primary object inherit the ACE. |
| **INHERIT_ONLY_ACE** | The ACE does not apply to the primary object to which the ACL is attached, but objects contained by the primary object inherit the ACE. |
| **NO_PROPAGATE_INHERIT_ACE** | The OBJECT_INHERIT_ACE and CONTAINER_INHERIT_ACE flags are not propagated to an inherited ACE. |
| **OBJECT_INHERIT_ACE** | Noncontainer objects contained by the primary object inherit the ACE. |
| **SUB_CONTAINERS_AND_OBJECTS_INHERIT** | Both containers and noncontainer objects that are contained by the primary object inherit the ACE. This flag corresponds to the combination of the CONTAINER_INHERIT_ACE and OBJECT_INHERIT_ACE flags. |
| **SUB_CONTAINERS_ONLY_INHERIT** | Other containers that are contained by the primary object inherit the ACE. This flag corresponds to the combination of the **CONTAINER_INHERIT_ACE** and **INHERIT_ONLY_ACE** flags. |
| **SUB_OBJECTS_ONLY_INHERIT** | Noncontainer objects contained by the primary object inherit the ACE. This flag corresponds to the combination of the **OBJECT_INHERIT_ACE** and **INHERIT_ONLY_ACE** flags. |

## See also

[ACE](https://learn.microsoft.com/windows/desktop/SecAuthZ/ace)

[ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl)

[Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[EXPLICIT_ACCESS](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-explicit_access_a)

[GetExplicitEntriesFromAcl](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-getexplicitentriesfromacla)

[SetEntriesInAcl](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-setentriesinacla)

[TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a)

## Remarks

> [!NOTE]
> The aclapi.h header defines BuildExplicitAccessWithName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
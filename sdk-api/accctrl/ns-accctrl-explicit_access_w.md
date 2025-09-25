# EXPLICIT_ACCESS_W structure

## Description

The **EXPLICIT_ACCESS** structure defines access control information for a specified trustee. Access control functions, such as
[SetEntriesInAcl](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-setentriesinacla) and
[GetExplicitEntriesFromAcl](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-getexplicitentriesfromacla), use this structure to describe the information in an [access control entry](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly)(ACE) of an [access control list](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACL).

## Members

### `grfAccessPermissions`

A set of bit flags that use the
[ACCESS_MASK](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-mask) format to specify the access rights that an ACE allows, denies, or audits for the trustee. The functions that use the **EXPLICIT_ACCESS** structure do not convert, interpret, or validate the bits in this mask.

### `grfAccessMode`

A value from the
[ACCESS_MODE](https://learn.microsoft.com/windows/desktop/api/accctrl/ne-accctrl-access_mode) enumeration. For a [discretionary access control list](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DACL), this flag indicates whether the ACL allows or denies the specified access rights. For a [system access control list](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SACL), this flag indicates whether the ACL generates audit messages for successful attempts to use the specified access rights, or failed attempts, or both. When modifying an existing ACL, you can specify the REVOKE_ACCESS flag to remove any existing ACEs for the specified trustee.

### `grfInheritance`

A set of bit flags that determines whether other containers or objects can inherit the
ACE from the primary object to which the
ACL is attached. The value of this member corresponds to the inheritance portion (low-order byte) of the **AceFlags** member of the
[ACE_HEADER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-ace_header) structure. This parameter can be NO_INHERITANCE to indicate that the ACE is not inheritable; or it can be a combination of the following values.

| Value | Meaning |
| --- | --- |
| **CONTAINER_INHERIT_ACE** | Other containers that are contained by the primary object inherit the ACE. |
| **INHERIT_NO_PROPAGATE** | Inherit but do not propagate. |
| **INHERIT_ONLY** | Inherit only. |
| **INHERIT_ONLY_ACE** | The ACE does not apply to the primary object to which the ACL is attached, but objects contained by the primary object inherit the ACE. |
| **NO_INHERITANCE** | Do not inherit. |
| **NO_PROPAGATE_INHERIT_ACE** | The OBJECT_INHERIT_ACE and CONTAINER_INHERIT_ACE flags are not propagated to an inherited ACE. |
| **OBJECT_INHERIT_ACE** | Noncontainer objects contained by the primary object inherit the ACE. |
| **SUB_CONTAINERS_AND_OBJECTS_INHERIT** | Both containers and noncontainer objects that are contained by the primary object inherit the ACE. This flag corresponds to the combination of the CONTAINER_INHERIT_ACE and OBJECT_INHERIT_ACE flags. |
| **SUB_CONTAINERS_ONLY_INHERIT** | Other containers that are contained by the primary object inherit the ACE. This flag corresponds to the CONTAINER_INHERIT_ACE flag. |
| **SUB_OBJECTS_ONLY_INHERIT** | Noncontainer objects contained by the primary object inherit the ACE. This flag corresponds to the OBJECT_INHERIT_ACE flag. |

### `Trustee`

A [TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a) structure that identifies the user, group, or program (such as a Windows service) to which the ACE applies.

## See also

[ACCESS_MASK](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-mask)

[ACCESS_MODE](https://learn.microsoft.com/windows/desktop/api/accctrl/ne-accctrl-access_mode)

[ACE](https://learn.microsoft.com/windows/desktop/SecAuthZ/ace)

[ACE_HEADER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-ace_header)

[ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl)

[BuildExplicitAccessWithName](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-buildexplicitaccesswithnamea)

[BuildSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-buildsecuritydescriptora)

[GetExplicitEntriesFromAcl](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-getexplicitentriesfromacla)

[LookupSecurityDescriptorParts](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-lookupsecuritydescriptorpartsa)

[SetEntriesInAcl](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-setentriesinacla)

[TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a)

## Remarks

> [!NOTE]
> The accctrl.h header defines EXPLICIT_ACCESS_ as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
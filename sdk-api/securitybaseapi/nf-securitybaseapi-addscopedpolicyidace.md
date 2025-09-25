# AddScopedPolicyIDAce function

## Description

The **AddScopedPolicyIDAce** function adds a [SYSTEM_SCOPED_POLICY_ID_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_scoped_policy_id_ace) [access control entry](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACE) to the end of a [system access control list](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SACL). A **SYSTEM_SCOPED_POLICY_ID_ACE** structure specifies a central access policy (CAP) to be associated with the resource and can be used during access checks. The set of standard access rights are defined in the [Standard Access Rights](https://learn.microsoft.com/windows/desktop/SecAuthZ/standard-access-rights) topic.

## Parameters

### `pAcl` [in, out]

A pointer to an [access control list](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACL). This function adds an ACE to this ACL. The value of this parameter cannot be **NULL**.

### `dwAceRevision` [in]

Specifies the revision level of the ACL being modified. This value can be ACL_REVISION or ACL_REVISION_DS. Use ACL_REVISION_DS if the ACL contains object-specific ACEs.

### `AceFlags` [in]

A set of bit flags that control ACE inheritance. The function sets these flags in the **AceFlags** member of the [ACE_HEADER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-ace_header) structure of the new ACE.

For consistency with the Windows 8 Advanced File Permissions UI, applications should specify the CONTAINER_INHERIT_ACE and OBJECT_INHERIT_ACE flags in the *AceFlags* parameter.

This parameter can be a combination of the following values.

| Value | Meaning |
| --- | --- |
| **CONTAINER_INHERIT_ACE**<br><br>2 (0x2) | The ACE is inherited by the container objects. |
| **INHERIT_ONLY_ACE**<br><br>8 (0x8) | The ACE does not apply to the object the ACE is assigned to, but it can be inherited by child objects. |
| **INHERITED_ACE**<br><br>16 (0x10) | Indicates an inherited ACE. This flag allows operations that change the security on a tree of objects to modify inherited ACEs while not changing ACEs that were directly applied to the object. |
| **NO_PROPAGATE_INHERIT_ACE**<br><br>4 (0x4) | The OBJECT_INHERIT_ACE and CONTAINER_INHERIT_ACE bits are not propagated to an inherited ACE. |
| **OBJECT_INHERIT_ACE**<br><br>1 (0x1) | The ACE is inherited by non-container objects. |

### `AccessMask` [in]

Must be zero for Windows 8 and Windows Server 2012.

### `pSid` [in]

A pointer to the SID (S-1-17-*) that identifies the Central Access Policy to be associated with the resource.

## Return value

If the function succeeds, it returns **TRUE**.

If the function fails, it returns **FALSE**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[Standard Access Rights](https://learn.microsoft.com/windows/desktop/SecAuthZ/standard-access-rights)
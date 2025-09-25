# AddAuditAccessAceEx function

## Description

The **AddAuditAccessAceEx** function adds a system-audit [access control entry](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACE) to the end of a [system access control list](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SACL).

## Parameters

### `pAcl` [in, out]

A pointer to a SACL. The **AddAuditAccessAceEx** function adds a system-audit ACE to this SACL. The ACE is in the form of a
[SYSTEM_AUDIT_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_audit_ace) structure.

### `dwAceRevision` [in]

Specifies the revision level of the SACL being modified. This value can be ACL_REVISION or ACL_REVISION_DS. Use ACL_REVISION_DS if the SACL contains object-specific ACEs.

### `AceFlags` [in]

A set of bit flags that control ACE inheritance and the type of access attempts to audit. The function sets these flags in the **AceFlags** member of the [ACE_HEADER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-ace_header) structure of the new ACE. This parameter can be a combination of the following values.

| Value | Meaning |
| --- | --- |
| **CONTAINER_INHERIT_ACE** | The ACE is inherited by container objects. |
| **FAILED_ACCESS_ACE_FLAG** | If you set this flag or specify **TRUE** for the *bAuditFailure* parameter, failed attempts to use the specified access rights cause the system to generate an audit record in the security event log. |
| **INHERIT_ONLY_ACE** | The ACE does not apply to the object to which the [access control list](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACL) is assigned, but it can be inherited by child objects. |
| **INHERITED_ACE** | Indicates an inherited ACE. This flag allows operations that change the security on a tree of objects to modify inherited ACEs, while not changing ACEs that were directly applied to the object. |
| **NO_PROPAGATE_INHERIT_ACE** | The OBJECT_INHERIT_ACE and CONTAINER_INHERIT_ACE bits are not propagated to an inherited ACE. |
| **OBJECT_INHERIT_ACE** | The ACE is inherited by noncontainer objects. |
| **SUCCESSFUL_ACCESS_ACE_FLAG** | If you set this flag or specify **TRUE** for the *bAuditSuccess* parameter, successful uses of the specified access rights cause the system to generate an audit record in the security event log. |

### `dwAccessMask` [in]

A set of bit flags that use the
[ACCESS_MASK](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-mask) format to specify the access rights that the new ACE audits for the specified [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID).

### `pSid` [in]

A pointer to a
SID that identifies the user, group, or [logon session](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) for which the new ACE audits access.

### `bAuditSuccess` [in]

Specifies whether successful uses of the specified access rights cause the system to generate an audit record in the security event log. If this flag is **TRUE** or if the *AceFlags* parameter specifies the SUCCESSFUL_ACCESS_ACE_FLAG flag, the system records successful access attempts; otherwise, it does not.

### `bAuditFailure` [in]

Specifies whether failed attempts to use the specified access rights cause the system to generate an audit record in the security event log. If this flag is **TRUE** or if the *AceFlags* parameter specifies the FAILED_ACCESS_ACE_FLAG flag, the system records failed access attempts; otherwise, it does not.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). The following are possible error values.

| Return code | Description |
| --- | --- |
| **ERROR_ALLOTTED_SPACE_EXCEEDED** | The new ACE does not fit into the ACL. A larger ACL buffer is required. |
| **ERROR_INVALID_ACL** | The specified ACL is not properly formed. |
| **ERROR_INVALID_FLAGS** | The *AceFlags* parameter is not valid. |
| **ERROR_INVALID_SID** | The specified SID is not structurally valid. |
| **ERROR_REVISION_MISMATCH** | The specified revision is not known or is incompatible with that of the ACL. |
| **ERROR_SUCCESS** | The ACE was successfully added. |

## See also

[ACCESS_MASK](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-mask)

[ACE_HEADER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-ace_header)

[ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl)

[AddAccessAllowedAceEx](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-addaccessallowedaceex)

[AddAccessDeniedAceEx](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-addaccessdeniedaceex)

[Low-level Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/low-level-access-control)

[Low-level Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[SYSTEM_AUDIT_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_audit_ace)
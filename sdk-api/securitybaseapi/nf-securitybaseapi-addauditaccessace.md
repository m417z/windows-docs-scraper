# AddAuditAccessAce function

## Description

The **AddAuditAccessAce** function adds a system-audit [access control entry](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACE) to a system [access control list](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACL). The access of a specified [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) is audited.

To control whether the new ACE can be inherited by child objects, use the
[AddAuditAccessAceEx](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-addauditaccessaceex) function.

## Parameters

### `pAcl` [in, out]

A pointer to an
ACL. This function adds a system-audit ACE to this ACL. The ACE is in the form of a
[SYSTEM_AUDIT_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_audit_ace) structure.

### `dwAceRevision` [in]

Specifies the revision level of the ACL being modified.

This value can be ACL_REVISION or ACL_REVISION_DS. Use ACL_REVISION_DS if the ACL contains object-specific ACEs.

### `dwAccessMask` [in]

Specifies the mask of access rights to be audited for the specified SID.

### `pSid` [in]

A pointer to the
SID representing the [process](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) whose access is being audited.

### `bAuditSuccess` [in]

Specifies whether successful access attempts are to be audited. Set this flag to **TRUE** to enable auditing; otherwise, set it to **FALSE**.

### `bAuditFailure` [in]

Specifies whether unsuccessful access attempts are to be audited. Set this flag to **TRUE** to enable auditing; otherwise, set it to **FALSE**.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). The following are possible error values.

| Return code | Description |
| --- | --- |
| **ERROR_ALLOTTED_SPACE_EXCEEDED** | The new ACE does not fit into the ACL. A larger ACL buffer is required. |
| **ERROR_INVALID_ACL** | The specified ACL is not properly formed. |
| **ERROR_INVALID_SID** | The specified SID is not structurally valid. |
| **ERROR_REVISION_MISMATCH** | The specified revision is not known or is incompatible with that of the ACL. |
| **ERROR_SUCCESS** | The ACE was successfully added. |

## Remarks

The
[ACE_HEADER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-ace_header) structure placed in the ACE by the **AddAuditAccessAce** function specifies a type and size, but provides no ACE flags.

## See also

[ACE_HEADER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-ace_header)

[AddAccessAllowedAce](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-addaccessallowedace)

[AddAccessDeniedAce](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-addaccessdeniedace)

[AddAce](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-addace)

[AddAuditAccessAceEx](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-addauditaccessaceex)

[DeleteAce](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-deleteace)

[GetAce](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getace)

[Low-level Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/low-level-access-control)

[Low-level Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[SYSTEM_AUDIT_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_audit_ace)
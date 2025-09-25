# AddAccessDeniedAce function

## Description

The **AddAccessDeniedAce** function adds an access-denied [access control entry](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACE) to an [access control list](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACL). The access is denied to a specified [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID).

To control whether the new ACE can be inherited by child objects, use the
[AddAccessDeniedAceEx](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-addaccessdeniedaceex) function.

## Parameters

### `pAcl` [in, out]

A pointer to an
ACL . This function adds an access-denied ACE to the end of this ACL. The ACE is in the form of an
[ACCESS_DENIED_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-access_denied_ace) structure.

### `dwAceRevision` [in]

Specifies the revision level of the ACL being modified.

This value can be ACL_REVISION or ACL_REVISION_DS. Use ACL_REVISION_DS if the ACL contains object-specific ACEs.

### `AccessMask` [in]

Specifies the mask of access rights being denied to the specified SID.

### `pSid` [in]

A pointer to the SID structure representing the user, group, or logon account being denied access.

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
[AddAccessAllowedAce](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-addaccessallowedace) and **AddAccessDeniedAce** functions add a new ACE to the end of the list of ACEs for the ACL. These functions do not automatically place the new ACE in the proper canonical order. It is the caller's responsibility to ensure that the ACL is in canonical order by adding ACEs in the proper sequence.

The
[ACE_HEADER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-ace_header) structure placed in the ACE by the **AddAccessDeniedAce** function specifies a type and size, but provides no ACE flags.

The ACE added by **AddAccessDeniedAce** is not inheritable.

## See also

[ACCESS_DENIED_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-access_denied_ace)

[ACE_HEADER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-ace_header)

[ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl)

[AddAccessAllowedAce](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-addaccessallowedace)

[AddAccessDeniedAceEx](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-addaccessdeniedaceex)

[AddAce](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-addace)

[AddAuditAccessAce](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-addauditaccessace)

[DeleteAce](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-deleteace)

[GetAce](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getace)

[Low-level Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/low-level-access-control)

[Low-level Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)
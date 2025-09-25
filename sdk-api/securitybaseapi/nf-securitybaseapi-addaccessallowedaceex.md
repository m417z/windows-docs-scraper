# AddAccessAllowedAceEx function

## Description

The **AddAccessAllowedAceEx** function adds an access-allowed [access control entry](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACE) to the end of a [discretionary access control list](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DACL).

## Parameters

### `pAcl` [in, out]

A pointer to a DACL. The **AddAccessAllowedAceEx** function adds an access-allowed ACE to the end of this DACL. The ACE is in the form of an
[ACCESS_ALLOWED_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-access_allowed_ace) structure.

### `dwAceRevision` [in]

Specifies the revision level of the DACL being modified. This value can be ACL_REVISION or ACL_REVISION_DS. Use ACL_REVISION_DS if the DACL contains object-specific ACEs.

### `AceFlags` [in]

A set of bit flags that control ACE inheritance. The function sets these flags in the **AceFlags** member of the
[ACE_HEADER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-ace_header) structure of the new ACE. This parameter can be a combination of the following values.

| Value | Meaning |
| --- | --- |
| **CONTAINER_INHERIT_ACE** | The ACE is inherited by container objects. |
| **INHERIT_ONLY_ACE** | The ACE does not apply to the object to which the [access control list](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACL) is assigned, but it can be inherited by child objects. |
| **INHERITED_ACE** | Indicates an inherited ACE. This flag allows operations that change the security on a tree of objects to modify inherited ACEs while not changing ACEs that were directly applied to the object. |
| **NO_PROPAGATE_INHERIT_ACE** | The OBJECT_INHERIT_ACE and CONTAINER_INHERIT_ACE bits are not propagated to an inherited ACE. |
| **OBJECT_INHERIT_ACE** | The ACE is inherited by noncontainer objects. |

### `AccessMask` [in]

A set of bit flags that use the
[ACCESS_MASK](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-mask) format. These flags specify the access rights that the new ACE allows for the specified [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID).

### `pSid` [in]

A pointer to a
SID that identifies the user, group, or [logon session](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) to which the new ACE allows access.

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

## Remarks

The caller must ensure that ACEs are added to the DACL in the correct order. For more information, see
[Order of ACEs in a DACL](https://learn.microsoft.com/windows/desktop/SecAuthZ/order-of-aces-in-a-dacl).

## See also

[ACCESS_ALLOWED_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-access_allowed_ace)

[ACCESS_MASK](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-mask)

[ACE_HEADER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-ace_header)

[ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl)

[AddAccessDeniedAceEx](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-addaccessdeniedaceex)

[AddAuditAccessAceEx](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-addauditaccessaceex)

[Low-level Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/low-level-access-control)

[Low-level Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)
# AddConditionalAce function

## Description

The **AddConditionalAce** function adds a conditional [access control entry](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACE) to the specified [access control list](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACL). A conditional ACE specifies a logical condition that is evaluated during access checks.

## Parameters

### `pAcl` [in, out]

A pointer to an
ACL. This function adds an ACE to this ACL.

The value of this parameter cannot be **NULL**.

### `dwAceRevision` [in]

Specifies the revision level of the ACL being modified. This value can be ACL_REVISION or ACL_REVISION_DS.
Use ACL_REVISION_DS if the ACL contains object-specific ACEs.

### `AceFlags` [in]

A set of bit flags that control ACE inheritance. The function sets these flags in the **AceFlags** member of the
[ACE_HEADER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-ace_header) structure of the new ACE. This parameter can be a combination of the following values.

| Value | Meaning |
| --- | --- |
| **CONTAINER_INHERIT_ACE** | The ACE is inherited by container objects. |
| **INHERIT_ONLY_ACE** | The ACE does not apply to the object to which the ACL is assigned, but it can be inherited by child objects. |
| **INHERITED_ACE** | Indicates an inherited ACE. This flag allows operations that change the security on a tree of objects to modify inherited ACEs while not changing ACEs that were directly applied to the object. |
| **NO_PROPAGATE_INHERIT_ACE** | The OBJECT_INHERIT_ACE and CONTAINER_INHERIT_ACE bits are not propagated to an inherited ACE. |
| **OBJECT_INHERIT_ACE** | The ACE is inherited by noncontainer objects. |

### `AceType` [in]

The type of the ACE.

This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **ACCESS_ALLOWED_CALLBACK_ACE_TYPE**<br><br>0x9 | Access-allowed callback ACE that uses the [ACCESS_ALLOWED_CALLBACK_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-access_allowed_callback_ace) structure. |
| **ACCESS_DENIED_CALLBACK_ACE_TYPE**<br><br>0xA | Access-denied callback ACE that uses the [ACCESS_DENIED_CALLBACK_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-access_denied_callback_ace) structure. |
| **SYSTEM_AUDIT_CALLBACK_ACE_TYPE**<br><br>0xD | System audit callback ACE that uses the [SYSTEM_AUDIT_CALLBACK_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_audit_callback_ace) structure. |

### `AccessMask` [in]

Specifies the mask of access rights to be granted to the specified SID.

### `pSid` [in]

A pointer to the
SID that represents a user, group, or logon account being granted access.

### `ConditionStr` [in]

A string that specifies the conditional statement to be evaluated for the ACE.

### `ReturnLength` [out]

The size, in bytes, of the ACL. If the buffer specified by the *pACL* parameter is not of sufficient size, the value of this parameter is the required size.

## Return value

If the function succeeds, it returns **TRUE**.

If the function fails, it returns **FALSE**. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). The following are possible error values.

| Return code | Description |
| --- | --- |
| **ERROR_INSUFFICIENT_BUFFER** | The new ACE does not fit into the *pAcl* buffer. |
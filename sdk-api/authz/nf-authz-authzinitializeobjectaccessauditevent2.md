# AuthzInitializeObjectAccessAuditEvent2 function

## Description

The **AuthzInitializeObjectAccessAuditEvent2** function allocates and initializes an **AUTHZ_AUDIT_EVENT_HANDLE** handle for use with the [AuthzAccessCheck](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzaccesscheck) function.

## Parameters

### `Flags` [in]

Flags that modify the behavior of the audit. The following table shows the possible values.

| Value | Meaning |
| --- | --- |
| **AUTHZ_NO_ALLOC_STRINGS** | Uses pointers to the passed strings instead of allocating memory and copying the strings. The calling application must ensure that the passed memory remains valid during access checks. |
| **AUTHZ_NO_FAILURE_AUDIT** | Disables generation of failure audits. |
| **AUTHZ_NO_SUCCESS_AUDIT** | Disables generation of success audits. |

### `hAuditEventType` [in]

Reserved. This parameter should be set to **NULL**.

### `szOperationType` [in]

A pointer to a string that indicates the operation that is to be audited.

### `szObjectType` [in]

A pointer to a string that indicates the type of object accessed.

### `szObjectName` [in]

A pointer to a string that indicates the name of the object accessed.

### `szAdditionalInfo` [in]

Pointer to a string defined by the Resource Manager that contains additional audit information.

### `szAdditionalInfo2` [in]

Pointer to a string defined by the Resource Manager that contains additional audit information.

### `phAuditEvent` [out]

A pointer to the returned **AUTHZ_AUDIT_EVENT_HANDLE** handle.

### `dwAdditionalParameterCount` [in]

Must be set to zero.

### `...`

Additional parameters.

## Return value

If the function succeeds, it returns **TRUE**.

If the function fails, it returns **FALSE**. For extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[AuthzAccessCheck](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzaccesscheck)

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)
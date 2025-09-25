# AuthzInitializeObjectAccessAuditEvent function

## Description

The **AuthzInitializeObjectAccessAuditEvent** function initializes auditing for an object.

## Parameters

### `Flags` [in]

Modifies the audit. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **AUTHZ_NO_SUCCESS_AUDIT** | Disable generation of success audits. |
| **AUTHZ_NO_FAILURE_AUDIT** | Disable generation of failure audits. |
| **AUTHZ_NO_ALLOC_STRINGS** | Use pointers to the passed strings instead of allocating memory and copying the strings. The calling application must ensure that the passed memory stays valid during access checks. |

### `hAuditEventType` [in]

Reserved. This parameter should be set to **NULL**.

### `szOperationType` [in]

String that indicates the operation that is to be audited.

### `szObjectType` [in]

String that indicates the type of object being accessed.

### `szObjectName` [in]

String the indicates the name of the object being accessed.

### `szAdditionalInfo` [in]

String, defined by the Resource Manager, for additional audit information.

### `phAuditEvent` [out]

Pointer that receives an **AUTHZ_AUDIT_EVENT_HANDLE** structure.

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
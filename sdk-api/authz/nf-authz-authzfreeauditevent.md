# AuthzFreeAuditEvent function

## Description

The **AuthzFreeAuditEvent** function frees the structure allocated by the
[AuthzInitializeObjectAccessAuditEvent](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzinitializeobjectaccessauditevent) function.

## Parameters

### `hAuditEvent` [in]

A pointer to the **AUTHZ_AUDIT_EVENT_HANDLE** structure to be freed.

## Return value

If the function succeeds, the function returns **TRUE**.

If the function fails, it returns **FALSE**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[AuthzInitializeObjectAccessAuditEvent](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzinitializeobjectaccessauditevent)

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)
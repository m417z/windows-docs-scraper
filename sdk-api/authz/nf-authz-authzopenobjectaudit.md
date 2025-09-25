# AuthzOpenObjectAudit function

## Description

The **AuthzOpenObjectAudit** function reads the [system access control list](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SACL) of the specified security descriptor and generates any appropriate audits specified by that SACL.

## Parameters

### `Flags` [in]

Reserved for future use.

### `hAuthzClientContext` [in]

A handle to the client context of the object to open.

### `pRequest` [in]

A pointer to an
[AUTHZ_ACCESS_REQUEST](https://learn.microsoft.com/windows/desktop/api/authz/ns-authz-authz_access_request) structure.

### `hAuditEvent` [in]

A handle to the audit event to use.

### `pSecurityDescriptor` [in]

A pointer to the
[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure for the object.

### `OptionalSecurityDescriptorArray` [in]

A pointer to an array of [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structures.

### `OptionalSecurityDescriptorCount` [in]

The number of elements in *SecurityDescriptorArray*.

### `pReply` [in]

A pointer to an
[AUTHZ_ACCESS_REPLY](https://learn.microsoft.com/windows/desktop/api/authz/ns-authz-authz_access_reply) structure.

## Return value

If the function succeeds, it returns a nonzero value.

If the function fails, it returns a zero value. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)
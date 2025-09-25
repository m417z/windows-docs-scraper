# PrivilegedServiceAuditAlarmW function

## Description

The **PrivilegedServiceAuditAlarm** function generates an audit message in the security event log. A protected server can use this function to log attempts by a client to use a specified set of [privileges](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly).

Alarms are not currently supported.

## Parameters

### `SubsystemName` [in]

A pointer to a null-terminated string specifying the name of the subsystem calling the function. This information appears in the security event log record.

### `ServiceName` [in]

A pointer to a null-terminated string specifying the name of the privileged subsystem service. This information appears in the security event log record.

### `ClientToken` [in]

Identifies an [access token](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) representing the client that requested the operation. This handle must have been obtained by opening the token of a thread impersonating the client. The token must be open for TOKEN_QUERY access. The function uses this token to get the identity of the client for the security event log record.

### `Privileges` [in]

A pointer to a
[PRIVILEGE_SET](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-privilege_set) structure containing the privileges that the client attempted to use. The names of the privileges appear in the security event log record.

### `AccessGranted` [in]

Indicates whether the client's attempt to use the privileges was successful. If this value is **TRUE**, the security event log record indicates success. If this value is **FALSE**, the security event log record indicates failure.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **PrivilegedServiceAuditAlarm** function does not check the client's access token to determine whether the privileges are held or enabled. Typically, you first call the [PrivilegeCheck](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-privilegecheck) function to determine whether the specified privileges are enabled in the access token, and then call **PrivilegedServiceAuditAlarm** to log the results.

The **PrivilegedServiceAuditAlarm** function requires the calling process to have SE_AUDIT_NAME privilege enabled. The test for this privilege is always performed against the [primary token](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) of the calling process. This allows the calling process to impersonate a client during the call.

## See also

[Client/Server Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)
[Client/Server Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/client-server-access-control)
[ObjectPrivilegeAuditAlarm](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-objectprivilegeauditalarmw)
[PRIVILEGE_SET](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-privilege_set)
[PrivilegeCheck](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-privilegecheck)
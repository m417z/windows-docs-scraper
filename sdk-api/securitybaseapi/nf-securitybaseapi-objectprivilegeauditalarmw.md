# ObjectPrivilegeAuditAlarmW function

## Description

The **ObjectPrivilegeAuditAlarm** function generates an audit message in the security event log. A protected server can use this function to log attempts by a client to use a specified set of [privileges](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) with an open handle to a private object. Alarms are not currently supported.

## Parameters

### `SubsystemName` [in]

A pointer to a null-terminated string specifying the name of the subsystem calling the function. This string appears in the audit message.

### `HandleId` [in]

A pointer to a unique value representing the client's handle to the object.

### `ClientToken` [in]

Identifies an [access token](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) representing the client that requested the operation. This handle must have been obtained by opening the token of a thread impersonating the client. The token must be open for TOKEN_QUERY access. The function uses this token to get the identity of the client for the audit message.

### `DesiredAccess` [in]

Specifies an [access mask](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) indicating the privileged access types being used or whose use is being attempted. The access mask can be mapped by the [MapGenericMask](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-mapgenericmask) function so it does not contain any generic access types.

### `Privileges` [in]

A pointer to a [PRIVILEGE_SET](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-privilege_set) structure containing the [privileges](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) that the client attempted to use. The names of the privileges appear in the audit message.

### `AccessGranted` [in]

Indicates whether the client's attempt to use the privileges was successful. If this value is **TRUE**, the audit message indicates success. If this value is **FALSE**, the audit message indicates failure.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **ObjectPrivilegeAuditAlarm** function does not check the client's access to the object or check the client's access token to determine whether the privileges are held or enabled. Typically, you call the [PrivilegeCheck](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-privilegecheck) function to determine whether the specified privileges are enabled in the access token, call the [AccessCheck](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-accesscheck) function to check the client's access to the object, and then call **ObjectPrivilegeAuditAlarm** to log the results.

The **ObjectPrivilegeAuditAlarm** function requires the calling [process](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) to have SE_AUDIT_NAME privilege enabled. The test for this privilege is always performed against the [primary token](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) of the calling process, not the [impersonation token](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly) of the thread. This allows the calling process to impersonate a client during the call.

## See also

[AccessCheck](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-accesscheck)
[AccessCheckAndAuditAlarm](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-accesscheckandauditalarmw)
[Client/Server Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)
[Client/Server Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/client-server-access-control)
[MapGenericMask](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-mapgenericmask)
[ObjectCloseAuditAlarm](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-objectcloseauditalarmw)
[ObjectOpenAuditAlarm](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-objectopenauditalarmw)
[PRIVILEGE_SET](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-privilege_set)
[PrivilegeCheck](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-privilegecheck)
[PrivilegedServiceAuditAlarm](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-privilegedserviceauditalarmw)
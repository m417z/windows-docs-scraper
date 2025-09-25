# ObjectOpenAuditAlarmW function

## Description

The **ObjectOpenAuditAlarm** function generates audit messages when a client application attempts to gain access to an object or to create a new one. Alarms are not currently supported.

## Parameters

### `SubsystemName` [in]

A pointer to a **null**-terminated string specifying the name of the subsystem calling the function. This string appears in any audit message that the function generates.

### `HandleId` [in]

A pointer to a unique value representing the client's handle to the object. If the access is denied, this parameter is ignored.

For cross-platform compatibility, the value addressed by this pointer must be sizeof(LPVOID) bytes long.

### `ObjectTypeName` [in]

A pointer to a **null**-terminated string specifying the type of object to which the client is requesting access. This string appears in any audit message that the function generates.

### `ObjectName` [in, optional]

A pointer to a **null**-terminated string specifying the name of the object to which the client is requesting access. This string appears in any audit message that the function generates.

### `pSecurityDescriptor` [in]

A pointer to the [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure for the object being accessed.

### `ClientToken` [in]

Identifies an [access token](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) representing the client requesting the operation. This handle must be obtained by opening the token of a thread impersonating the client. The token must be open for TOKEN_QUERY access.

### `DesiredAccess` [in]

Specifies the desired [access mask](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly). This mask must have been previously mapped by the [MapGenericMask](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-mapgenericmask) function to contain no generic access rights.

### `GrantedAccess` [in]

Specifies an [access mask](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) indicating which access rights are granted. This access mask is intended to be the same value set by one of the access-checking functions in its *GrantedAccess* parameter. Examples of access-checking functions include [AccessCheckAndAuditAlarm](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-accesscheckandauditalarmw) and [AccessCheck](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-accesscheck).

### `Privileges` [in, optional]

A pointer to a [PRIVILEGE_SET](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-privilege_set) structure that specifies the set of [privileges](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) required for the access attempt. This parameter can be **NULL**.

### `ObjectCreation` [in]

Specifies a flag that determines whether the application creates a new object when access is granted. When this value is **TRUE**, the application creates a new object; when it is **FALSE**, the application opens an existing object.

### `AccessGranted` [in]

Specifies a flag indicating whether access was granted or denied in a previous call to an access-checking function, such as [AccessCheck](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-accesscheck). If access was granted, this value is **TRUE**. If not, it is **FALSE**.

### `GenerateOnClose` [out]

A pointer to a flag set by the audit-generation routine when the function returns. This value must be passed to the
[ObjectCloseAuditAlarm](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-objectcloseauditalarmw) function when the object handle is closed.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **ObjectOpenAuditAlarm** function requires the calling application to have the SE_AUDIT_NAME privilege enabled. The test for this privilege is always performed against the [primary token](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) of the calling [process](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly), not the [impersonation token](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly) of the thread. This allows the calling process to impersonate a client during the call.

## See also

[AccessCheck](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-accesscheck)
[AccessCheckAndAuditAlarm](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-accesscheckandauditalarmw)
[AreAllAccessesGranted](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-areallaccessesgranted)
[AreAnyAccessesGranted](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-areanyaccessesgranted)
[Client/Server Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/client-server-access-control)
[Client/Server Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)
[MapGenericMask](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-mapgenericmask)
[ObjectCloseAuditAlarm](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-objectcloseauditalarmw)
[ObjectDeleteAuditAlarm](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-objectdeleteauditalarmw)
[ObjectPrivilegeAuditAlarm](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-objectprivilegeauditalarmw)
[PRIVILEGE_SET](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-privilege_set)
[PrivilegeCheck](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-privilegecheck)
[PrivilegedServiceAuditAlarm](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-privilegedserviceauditalarmw)
[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor)
# AccessCheckAndAuditAlarmW function

## Description

The **AccessCheckAndAuditAlarm** function determines whether a [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) grants a specified set of access rights to the client being impersonated by the calling thread. If the security descriptor has a SACL with ACEs that apply to the client, the function generates any necessary audit messages in the security event log.

## Parameters

### `SubsystemName` [in]

A pointer to a null-terminated string specifying the name of the subsystem calling the function. This string appears in any audit message that the function generates.

### `HandleId` [in, optional]

A pointer to a unique value representing the client's handle to the object. If the access is denied, the system ignores this value.

### `ObjectTypeName` [in]

A pointer to a null-terminated string specifying the type of object being created or accessed. This string appears in any audit message that the function generates.

### `ObjectName` [in, optional]

A pointer to a null-terminated string specifying the name of the object being created or accessed. This string appears in any audit message that the function generates.

### `SecurityDescriptor` [in]

A pointer to the
[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure against which access is checked.

### `DesiredAccess` [in]

[Access mask](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) that specifies the access rights to check. This mask must have been mapped by the [MapGenericMask](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-mapgenericmask) function to contain no generic access rights.

If this parameter is MAXIMUM_ALLOWED, the function sets the *GrantedAccess* access mask to indicate the maximum access rights the security descriptor allows the client.

### `GenericMapping` [in]

A pointer to the [GENERIC_MAPPING](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-generic_mapping) structure associated with the object for which access is being checked.

### `ObjectCreation` [in]

Specifies a flag that determines whether the calling application will create a new object when access is granted. A value of **TRUE** indicates the application will create a new object. A value of **FALSE** indicates the application will open an existing object.

### `GrantedAccess` [out]

A pointer to an [access mask](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) that receives the granted access rights. If *AccessStatus* is set to **FALSE**, the function sets the access mask to zero. If the function fails, it does not set the access mask.

### `AccessStatus` [out]

A pointer to a variable that receives the results of the access check. If the security descriptor allows the requested access rights to the client, *AccessStatus* is set to **TRUE**. Otherwise, *AccessStatus* is set to **FALSE**.

### `pfGenerateOnClose` [out]

A pointer to a flag set by the audit-generation routine when the function returns. Pass this flag to the
[ObjectCloseAuditAlarm](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-objectcloseauditalarmw) function when the object handle is closed.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

For more information, see the [How AccessCheck Works](https://learn.microsoft.com/windows/desktop/SecAuthZ/how-dacls-control-access-to-an-object) overview.

The **AccessCheckAndAuditAlarm** function requires the calling [process](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) to have the SE_AUDIT_NAME privilege enabled. The test for this privilege is performed against the [primary token](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) of the calling process, not the [impersonation token](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly) of the thread.

The **AccessCheckAndAuditAlarm** function fails if the calling thread is not impersonating a client.

## See also

[AccessCheck](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-accesscheck)
[Client/Server Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/client-server-access-control)
[Client/Server Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)
[GENERIC_MAPPING](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-generic_mapping)
[How AccessCheck Works](https://learn.microsoft.com/windows/desktop/SecAuthZ/how-dacls-control-access-to-an-object)
[MakeAbsoluteSD](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-makeabsolutesd)
[MapGenericMask](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-mapgenericmask)
[ObjectCloseAuditAlarm](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-objectcloseauditalarmw)
[ObjectOpenAuditAlarm](https://learn.microsoft.com/windows/win32/api/securitybaseapi/nf-securitybaseapi-objectopenauditalarmw)
[ObjectPrivilegeAuditAlarm](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-objectprivilegeauditalarmw)
[PrivilegeCheck](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-privilegecheck)
[PrivilegedServiceAuditAlarm](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-privilegedserviceauditalarmw)
[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor)
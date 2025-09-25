# ObjectDeleteAuditAlarmA function

## Description

The **ObjectDeleteAuditAlarm** function generates audit messages when an object is deleted. Alarms are not currently supported.

## Parameters

### `SubsystemName` [in]

A pointer to a null-terminated string specifying the name of the subsystem calling the function. This string appears in any audit message that the function generates.

### `HandleId` [in]

Specifies a unique value representing the client's handle to the object. This must be the same value that was passed to the
[AccessCheckAndAuditAlarm](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-accesscheckandauditalarma) or
[ObjectOpenAuditAlarm](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-objectopenauditalarma) function.

### `GenerateOnClose` [in]

Specifies a flag set by a call to the
[AccessCheckAndAuditAlarm](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-accesscheckandauditalarma) or
[ObjectOpenAuditAlarm](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-objectopenauditalarma) function when the object handle is created.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **ObjectDeleteAuditAlarm** function requires the calling application to have the SE_AUDIT_NAME privilege enabled. The test for this privilege is always performed against the [primary token](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) of the calling [process](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly), allowing the calling process to impersonate a client.

## See also

[AccessCheck](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-accesscheck)

[AccessCheckAndAuditAlarm](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-accesscheckandauditalarma)

[AreAllAccessesGranted](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-areallaccessesgranted)

[AreAnyAccessesGranted](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-areanyaccessesgranted)

[Client/Server Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/client-server-access-control)

[Client/Server Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[MapGenericMask](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-mapgenericmask)

[ObjectCloseAuditAlarm](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-objectcloseauditalarma)

[ObjectOpenAuditAlarm](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-objectopenauditalarma)

[ObjectPrivilegeAuditAlarm](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-objectprivilegeauditalarma)

[PrivilegeCheck](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-privilegecheck)

[PrivilegedServiceAuditAlarm](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-privilegedserviceauditalarma)
# ObjectCloseAuditAlarmA function

## Description

The **ObjectCloseAuditAlarm** function generates an audit message in the security event log when a handle to a private object is deleted. Alarms are not currently supported.

## Parameters

### `SubsystemName` [in]

A pointer to a null-terminated string specifying the name of the subsystem calling the function. This string appears in any audit message that the function generates.

### `HandleId` [in]

A unique value representing the client's handle to the object. This should be the same value that was passed to the
[AccessCheckAndAuditAlarm](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-accesscheckandauditalarma) or [ObjectOpenAuditAlarm](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-objectopenauditalarma) function.

### `GenerateOnClose` [in]

Specifies a flag set by a call to the [AccessCheckAndAuditAlarm](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-accesscheckandauditalarma) or **ObjectCloseAuditAlarm** function when the object handle is created. If this flag is **TRUE**, the function generates an audit message. If it is **FALSE**, the function does not generate an audit message.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **ObjectCloseAuditAlarm** function requires the calling application to have the SE_AUDIT_NAME privilege enabled. The test for this privilege is always performed against the [primary token](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) of the calling [process](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly), allowing the calling process to impersonate a client.

## See also

[AccessCheckAndAuditAlarm](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-accesscheckandauditalarma)

[Client/Server Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[Client/Server Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/client-server-access-control)

[ObjectDeleteAuditAlarm](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-objectdeleteauditalarma)

[ObjectOpenAuditAlarm](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-objectopenauditalarma)

[ObjectPrivilegeAuditAlarm](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-objectprivilegeauditalarma)
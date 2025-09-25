# AUDIT_EVENT_TYPE enumeration

## Description

The **AUDIT_EVENT_TYPE** enumeration type defines values that indicate the type of object being audited. The [AccessCheckByTypeAndAuditAlarm](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-accesscheckbytypeandauditalarma) and [AccessCheckByTypeResultListAndAuditAlarm](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-accesscheckbytyperesultlistandauditalarma) functions use these values.

## Constants

### `AuditEventObjectAccess`

Indicates an object that generates audit messages only if the system administrator has enabled auditing access to files and objects.

### `AuditEventDirectoryServiceAccess`

Indicates a directory service object that generates audit messages only if the system administrator has enabled auditing access to directory service objects.

## See also

[AccessCheckByTypeAndAuditAlarm](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-accesscheckbytypeandauditalarma)

[AccessCheckByTypeResultListAndAuditAlarm](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-accesscheckbytyperesultlistandauditalarma)

[Authorization Enumerations](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-enumerations)

[Client/Server Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/client-server-access-control)
# SeDeleteObjectAuditAlarm function

## Description

The **SeDeleteObjectAuditAlarm** routine generates audit and alarm messages for an object that is marked for deletion.

## Parameters

### `Object` [in]

Address of the object.

### `Handle` [in]

A unique 32-bit value representing the client's handle to the object.

## Remarks

Callers of **SeDeleteObjectAuditAlarm** must have **SeAuditPrivilege** enabled. The test for this privilege is always performed against the primary token of the calling process, allowing the calling process to impersonate a client.

For more information about security and access control, see [Windows security model for driver developers](https://learn.microsoft.com/windows-hardware/drivers/driversecurity/windows-security-model) and the documentation on these topics in the Windows SDK.

## See also

[SeAuditingFileEvents](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seauditingfileevents)

[SeAuditingFileOrGlobalEvents](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seauditingfileorglobalevents)

[SeOpenObjectAuditAlarm](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seopenobjectauditalarm)

[SeOpenObjectForDeleteAuditAlarm](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seopenobjectfordeleteauditalarm)
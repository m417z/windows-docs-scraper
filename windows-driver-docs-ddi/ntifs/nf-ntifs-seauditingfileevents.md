# SeAuditingFileEvents function

## Description

The **SeAuditingFileEvents** routine determines whether file open events are currently being audited.

## Parameters

### `AccessGranted` [in]

Set to **TRUE** if the access attempt was successful, **FALSE** otherwise.

### `SecurityDescriptor` [in]

This parameter is ignored.

## Return value

**SeAuditingFileEvents** returns **TRUE** if file open events are currently being audited, **FALSE** otherwise.

## Remarks

For more information about security and access control, see [Windows security model for driver developers](https://learn.microsoft.com/windows-hardware/drivers/driversecurity/windows-security-model) and the documentation on these topics in the Windows SDK.

## See also

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor)

[SeAuditingFileOrGlobalEvents](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seauditingfileorglobalevents)

[SeDeleteObjectAuditAlarm](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sedeleteobjectauditalarm)

[SeOpenObjectAuditAlarm](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seopenobjectauditalarm)

[SeOpenObjectForDeleteAuditAlarm](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seopenobjectfordeleteauditalarm)
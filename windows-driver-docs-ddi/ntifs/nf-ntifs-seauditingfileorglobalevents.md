# SeAuditingFileOrGlobalEvents function

## Description

The **SeAuditingFileOrGlobalEvents** routine determines whether file or global events are currently being audited.

## Parameters

### `AccessGranted` [in]

Set to TRUE if the access attempt was successful, FALSE otherwise.

### `SecurityDescriptor` [in]

Pointer to the security descriptor protecting the object being accessed.

### `SubjectSecurityContext` [in]

Pointer to the subject's captured security context.

## Return value

**SeAuditingFileOrGlobalEvents** returns TRUE if file or global events are currently being audited, FALSE otherwise.

## Remarks

For more information about security and access control, see [Windows security model for driver developers](https://learn.microsoft.com/windows-hardware/drivers/driversecurity/windows-security-model) and the documentation on these topics in the Windows SDK.

## See also

[**SECURITY_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor)

[**SECURITY_SUBJECT_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess#security_subject_context)

[**SeAuditingFileEvents**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seauditingfileevents)

[**SeDeleteObjectAuditAlarm**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sedeleteobjectauditalarm)

[**SeOpenObjectAuditAlarm**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seopenobjectauditalarm)

[**SeOpenObjectForDeleteAuditAlarm**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seopenobjectfordeleteauditalarm)
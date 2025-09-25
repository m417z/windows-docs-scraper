# SeOpenObjectAuditAlarm function

## Description

The **SeOpenObjectAuditAlarm** routine generates audit and alarm messages when an attempt is made to open an object.

## Parameters

### `ObjectTypeName` [in]

Pointer to a null-terminated string specifying the type of object to which the client is requesting access. This string appears in any audit message that is generated.

### `Object` [in, optional]

Address of the object being opened. This value is needed only to enter into log messages. If the open attempt fails, the value of *Object* is ignored. Otherwise, it must be provided.

### `AbsoluteObjectName` [in, optional]

Pointer to a null-terminated string specifying the name of the object being opened. This string appears in any audit message that is generated.

### `SecurityDescriptor` [in]

A pointer to the security descriptor structure for the object being opened.

### `AccessState` [in]

Pointer to an access state structure containing the object's subject context, remaining desired access types, granted access types, and, optionally, a privilege set to indicate which privileges were used to permit the access.

### `ObjectCreated` [in]

Set to **TRUE** if the open operation causes a new object to be created, or **FALSE** if an existing object is opened.

### `AccessGranted` [in]

Set to **TRUE** if open access was granted based on a previous access check or privilege check, or **FALSE** if it was denied.

### `AccessMode` [in]

Access mode used for the access check. Either **UserMode** or **KernelMode**.

### `GenerateOnClose` [out]

Pointer to a flag set by the audit generation routine when **SeOpenObjectAuditAlarm** returns.

## Remarks

**SeOpenObjectAuditAlarm** generates any necessary audit or alarm messages for user-mode accesses. No messages are generated for kernel-mode accesses.

Before calling **SeOpenObjectAuditAlarm**, the caller must call **SeLockSubjectContext** to lock the caller's primary and impersonation tokens. After calling **SeOpenObjectAuditAlarm**, the caller must call **SeUnlockSubjectContext** to release these tokens.

For more information about security and access control, see [Windows security model for driver developers](https://learn.microsoft.com/windows-hardware/drivers/driversecurity/windows-security-model) and the documentation on these topics in the Windows SDK.

## See also

[ACCESS_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_access_state)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor)

[SeAuditingFileEvents](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seauditingfileevents)

[SeAuditingFileOrGlobalEvents](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seauditingfileorglobalevents)

[SeDeleteObjectAuditAlarm](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sedeleteobjectauditalarm)

[SeLockSubjectContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-selocksubjectcontext)

[SeOpenObjectForDeleteAuditAlarm](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seopenobjectfordeleteauditalarm)

[SeSetAccessStateGenericMapping](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sesetaccessstategenericmapping)

[SeUnlockSubjectContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seunlocksubjectcontext)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)
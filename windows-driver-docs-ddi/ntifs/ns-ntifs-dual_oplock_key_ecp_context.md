## Description

The **DUAL_OPLOCK_KEY_ECP_CONTEXT** structure contains the extra create parameter context for a dual oplock key. Oplocks keys for both a target and a parent file object can be set in this structure.

## Members

### `ParentOplockKey`

A **GUID** representing the parent oplock key value.

### `TargetOplockKey`

A **GUID** representing the target oplock key value.

### `ParentOplockKeySet`

Set to TRUE if **ParentOplockKey** contains a valid GUID for the parent's oplock key.

### `TargetOplockKeySet`

Set to TRUE if **TargetOplockKey** contains a valid GUID for the target's oplock key.

## Remarks

The **DUAL_OPLOCK_KEY_ECP_CONTEXT** structure provides dual oplock keys to allow oplock requests on files and directories. Like the [**OPLOCK_KEY_ECP_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-oplock_key_ecp_context) structure, **DUAL_OPLOCK_KEY_ECP_CONTEXT** is set in an extra create parameter list ([**ECP_LIST**](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff540148(v=vs.85))) and later associated with a file object during processing of [**IRP_MJ_CREATE**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-create) by a file system or file system filter driver.

The value **GUID_ECP_DUAL_OPLOCK_KEY** is used when calling support routines such as [**FsRtlAllocateExtraCreateParameter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlallocateextracreateparameter), [**FsRtlInitializeExtraCreateParameter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlinitializeextracreateparameter), or [**FltRemoveExtraCreateParameter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltremoveextracreateparameter).

## See also

[**ECP_LIST**](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff540148(v=vs.85))

[**IO_DRIVER_CREATE_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_io_driver_create_context)

[**IoCreateFileEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iocreatefileex)

[**IRP_MJ_CREATE**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-create)

[**OPLOCK_KEY_ECP_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-oplock_key_ecp_context)
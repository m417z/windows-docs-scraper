## Description

The **FS_BPIO_RESULTS** structure defines BypassIO operation-specific outputs for [**FS_BPIO_OP_ENABLE** and **FS_BPIO_OP_QUERY** operations](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-fs_bpio_operations) when a driver is failing the operation.

## Members

### `OpStatus`

Receives a NTSTATUS code available to the caller that identifies why the failing driver cannot support BypassIO for this file. This field should only be set by the first driver to fail the enable/query request.

### `FailingDriverNameLen`

Receives the length of the string stored in **FailingDriverName**, in characters.

### `FailingDriverName`

Receives a string that specifies the name of the driver that failed the request. For diagnostic reasons, a driver must store its name when it fails a [**FS_BPIO_OP_ENABLE** or **FS_BPIO_OP_QUERY** operation](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-fs_bpio_operations). The name must match the actual name of the driver that is used by the system; for example, *ntfs.sys*. This string is not guaranteed to be NULL-terminated.

### `FailureReasonLen`

Receives the length of the string stored in **FailingReason**, in characters.

### `FailureReason`

Receives a unique, descriptive string describing why the driver vetoed the enable/query request. This string is used for diagnostic reasons, and should be in English so that it does not need to be localized. This string is not guaranteed to be NULL-terminated.

## Remarks

**FS_BPIO_RESULTS** is returned in the [**FS_BPIO_OPERATIONS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-fs_bpio_operations) structure when a driver fails an enable or query BypassIO operation.

See [BypassIO for filter drivers](https://learn.microsoft.com/windows-hardware/drivers/ifs/bypassio) and [Supporting BypassIO operations](https://learn.microsoft.com/windows-hardware/drivers/ifs/bypassio-operations) for more information.

## See also

[**FS_BPIO_OPERATIONS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-fs_bpio_operations)

[**FSCTL_MANAGE_BYPASS_IO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_manage_bypass_io)
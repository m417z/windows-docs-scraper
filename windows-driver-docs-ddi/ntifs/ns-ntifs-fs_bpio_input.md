## Description

The **FS_BPIO_INPUT** structure specifies the requested BypassIO operation and flags for the [**FSCTL_MANAGE_BYPASS_IO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_manage_bypass_io) control code.

## Members

### `Operation`

A [**FS_BPIO_OPERATIONS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-fs_bpio_operations) enum value that identifies the requested BypassIO operation.

### `InFlags`

A [**FS_BPIO_INFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-fs_bpio_inflags) enum value that specifies the input flags for the operation.

### `Reserved1`

Reserved for system use. Must be set to zero.

### `Reserved2`

Reserved for system use. Must be set to zero.

## Remarks

See [BypassIO for filter drivers](https://learn.microsoft.com/windows-hardware/drivers/ifs/bypassio) and [Supporting BypassIO operations](https://learn.microsoft.com/windows-hardware/drivers/ifs/bypassio-operations) for more information.

## See also

[**FS_BPIO_INFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-fs_bpio_inflags)

[**FS_BPIO_OPERATIONS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-fs_bpio_operations)

[**FSCTL_MANAGE_BYPASS_IO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_manage_bypass_io)
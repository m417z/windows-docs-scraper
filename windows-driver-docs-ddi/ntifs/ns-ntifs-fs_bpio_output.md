## Description

The **FS_BPIO_OUTPUT** structure is used to return information about the BypassIO operation for the [**FSCTL_MANAGE_BYPASS_IO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_manage_bypass_io) control code.

## Members

### `Operation`

A [**FS_BPIO_OPERATIONS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-fs_bpio_operations) enum value that identifies the requested BypassIO operation. This field should be set to the same value passed in [**FS_BPIO_INPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-fs_bpio_input)**.Operation**.

### `OutFlags`

A [**FS_BPIO_OUTFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-fs_bpio_outflags) enum value that specifies the output flags for the operation.

### `Reserved1`

Reserved for system use. Set to zero.

### `Reserved2`

Reserved for system use. Set to zero.

### `Enable`

A caller-allocated [**FS_BPIO_RESULTS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-fs_bpio_results) structure in which to write the results when a [**FS_BPIO_OP_ENABLE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-fs_bpio_operations) operation was requested.

### `Query`

A caller-allocated [**FS_BPIO_RESULTS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-fs_bpio_results) structure in which to write the results when a [**FS_BPIO_OP_QUERY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-fs_bpio_operations) operation was requested.

### `VolumeStackResume`

A caller-allocated [**FS_BPIO_RESULTS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-fs_bpio_results) structure in which to write the results when a [**FS_BPIO_OP_VOLUME_STACK_RESUME**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-fs_bpio_operations) operation was requested.

### `StreamResume`

A caller-allocated [**FS_BPIO_RESULTS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-fs_bpio_results) structure in which to write the results when a [**FS_BPIO_OP_STREAM_RESUME**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-fs_bpio_operations) operation was requested.

### `GetInfo`

A caller-allocated [**FS_BPIO_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-fs_bpio_info) structure in which to return information about the requested operation when a [**FS_BPIO_OP_GET_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-fs_bpio_operations) operation was requested.

## Remarks

**FS_BPIO_OUTPUT** is a variable length structure.

See [BypassIO for filter drivers](https://learn.microsoft.com/windows-hardware/drivers/ifs/bypassio) and [Supporting BypassIO operations](https://learn.microsoft.com/windows-hardware/drivers/ifs/bypassio-operations) for more information.

## See also

[**FS_BPIO_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-fs_bpio_info)

[**FS_BPIO_OPERATIONS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-fs_bpio_operations)

[**FS_BPIO_OUTFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-fs_bpio_outflags)

[**FS_BPIO_RESULTS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-fs_bpio_results)

[**FSCTL_MANAGE_BYPASS_IO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_manage_bypass_io)
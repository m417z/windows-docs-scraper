## Description

The **FS_BPIO_INFO** structure provides information about the BypassIO state of the volume.

## Members

### `ActiveBypassIoCount`

The number of BypassIO-enabled files that are currently open.

### `StorageDriverNameLen`

Receives the length of the string stored in **StorageDriverName**, in characters.

### `StorageDriverName`

Receives a string that specifies the name of the storage driver for this volume.

## Remarks

**FS_BPIO_INFO** is returned when the requested BypassIO operation is **FS_BPIO_OP_GET_INFO**, and in the [**FS_BPIO_OPERATIONS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-fs_bpio_operations) structure when the requested BypassIO operation is **FS_BPIO_OP_ENABLE** or **FS_BPIO_OP_QUERY**.

See [BypassIO for filter drivers](https://learn.microsoft.com/windows-hardware/drivers/ifs/bypassio) and [Supporting BypassIO operations](https://learn.microsoft.com/windows-hardware/drivers/ifs/bypassio-operations) for more information.

## See also

[**FS_BPIO_OPERATIONS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-fs_bpio_operations)

[**FS_BPIO_OUTPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-fs_bpio_output)

[**FSCTL_MANAGE_BYPASS_IO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_manage_bypass_io)
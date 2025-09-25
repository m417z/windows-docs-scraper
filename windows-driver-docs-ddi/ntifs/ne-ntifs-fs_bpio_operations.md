## Description

**FS_BPIO_OPERATIONS** defines the various BypassIO operations supported by the [**FSCTL_MANAGE_BYPASS_IO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_manage_bypass_io) control code.

## Constants

### `FS_BPIO_OP_ENABLE:1`

Requests that BypassIO be enabled for the given file, which means a driver might not see all non-cached reads for that file.

### `FS_BPIO_OP_DISABLE:2`

Informs filters and file systems that BypassIO is being disabled on the specified file.

### `FS_BPIO_OP_QUERY:3`

Queries whether BypassIO can be enabled for the given file.

### `FS_BPIO_OP_VOLUME_STACK_PAUSE:4`

Requests that BypassIO be paused on the specified volume/storage stack.

### `FS_BPIO_OP_VOLUME_STACK_RESUME:5`

Requests that BypassIO processing be resumed on the given volume.

### `FS_BPIO_OP_STREAM_PAUSE:6`

Requests that BypassIO processing be paused on a stream.

### `FS_BPIO_OP_STREAM_RESUME:7`

Requests that BypassIO processing be resumed on a stream.

### `FS_BPIO_OP_GET_INFO:8`

Requests information about the BypassIO state of the volume.

### `FS_BPIO_OP_MAX_OPERATION`

Valid BypassIO operation values are less than this value.

## Remarks

See [BypassIO for filter drivers](https://learn.microsoft.com/windows-hardware/drivers/ifs/bypassio) and [Supporting BypassIO operations](https://learn.microsoft.com/windows-hardware/drivers/ifs/bypassio-operations) for more information.

## See also

[**FSCTL_MANAGE_BYPASS_IO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_manage_bypass_io)
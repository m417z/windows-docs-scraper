## Description

**FS_BPIO_OUTFLAGS** defines the BypassIO output flags for the [**FSCTL_MANAGE_BYPASS_IO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_manage_bypass_io) control code.

## Constants

### `FSBPIO_OUTFL_None`

No output flag(s) are set.

### `FSBPIO_OUTFL_VOLUME_STACK_BYPASS_PAUSED`

When set, indicates that ByPassIO has been temporarily paused for this volume per a **FS_BPIO_OP_VOLUME_STACK_PAUSE** operation request.

### `FSBPIO_OUTFL_STREAM_BYPASS_PAUSED`

When set, indicates that BypassIO has been temporarily paused for this stream per a **FS_BPIO_OP_STREAM_PAUSE** operation request.

### `FSBPIO_OUTFL_FILTER_ATTACH_BLOCKED`

When set, indicates that a minifilter has attached to this volume whose supported features state indicates that it does not support BypassIO. All BypassIO is blocked on this volume.

### `FSBPIO_OUTFL_COMPATIBLE_STORAGE_DRIVER`

When set, indicates that the storage driver for this volume is BypassIO-compatible. This flag is defined only for **FS_BPIO_OP_ENABLE**, **FS_BPIO_OP_QUERY**, and **FS_BPIO_OP_GET_INFO** operations.

## Remarks

See [BypassIO for filter drivers](https://learn.microsoft.com/windows-hardware/drivers/ifs/bypassio) for more information.

## See also

[**FS_BPIO_OUTPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-fs_bpio_output)

[**FSCTL_MANAGE_BYPASS_IO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_manage_bypass_io)
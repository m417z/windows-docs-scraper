## Description

**FS_BPIO_INFLAGS** defines the BypassIO input flags for the [**FSCTL_MANAGE_BYPASS_IO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_manage_bypass_io) control code.

## Constants

### `FSBPIO_INFL_None`

No input flag(s) are set.

### `FSBPIO_INFL_SKIP_STORAGE_STACK_QUERY`

This flag suppresses the file system from sending [**IOCTL_STORAGE_MANAGE_BYPASS_IO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_manage_bypass_io) to the storage stack, and returns results based only on the filter stack. It applies to [**FS_BPIO_OP_QUERY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-fs_bpio_operations) operations only, and has no effect on **FS_BPIO_OP_ENABLE** operations.

## Remarks

**FS_BPIO_INFLAGS** is passed as an [input parameter](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-fs_bpio_input) to [**FSCTL_MANAGE_BYPASS_IO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_manage_bypass_io).

See [BypassIO for filter drivers](https://learn.microsoft.com/windows-hardware/drivers/ifs/bypassio) and [Supporting BypassIO operations](https://learn.microsoft.com/windows-hardware/drivers/ifs/bypassio-operations) for more information.

## See also

[**FS_BPIO_INPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-fs_bpio_input)

[**FSCTL_MANAGE_BYPASS_IO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_manage_bypass_io)
# _FILE_ZERO_DATA_INFORMATION_EX structure

## Description

Contains a range of a file to set to zeros. This structure is used by the
[FSCTL_SET_ZERO_DATA](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-set-zero-data) control code. It's similar to [FILE_ZERO_DATA_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_zero_data_information), but contains an additional **Flags** member.

## Members

### `FileOffset`

The file offset of the start of the range to set to zeros, in bytes.

### `BeyondFinalZero`

The byte offset of the first byte beyond the last zeroed byte.

### `Flags`

The following flags are supported:

| Flag | Description |
| --- | --- |
| **FILE_ZERO_DATA_INFORMATION_FLAG_PRESERVE_CACHED_DATA** | Indicates not to purge the contents of the cache corresponding to this range of the file. Only drivers can set this flag. |

## See also

[FILE_ZERO_DATA_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_zero_data_information)

[FSCTL_SET_ZERO_DATA](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-set-zero-data)

[FltFsControlFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile)
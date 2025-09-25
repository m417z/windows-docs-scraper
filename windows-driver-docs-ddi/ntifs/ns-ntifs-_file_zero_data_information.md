# _FILE_ZERO_DATA_INFORMATION structure

## Description

Contains a range of a file to set to zeros. This structure is used by the
[FSCTL_SET_ZERO_DATA](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-set-zero-data) control code.

## Members

### `FileOffset`

The file offset of the start of the range to set to zeros, in bytes.

### `BeyondFinalZero`

The byte offset of the first byte beyond the last zeroed byte.

## See also

[FILE_ZERO_DATA_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_zero_data_information_ex)

[FSCTL_SET_ZERO_DATA](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-set-zero-data)

[FltFsControlFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile)
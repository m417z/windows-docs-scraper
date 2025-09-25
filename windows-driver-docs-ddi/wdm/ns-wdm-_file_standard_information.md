# _FILE_STANDARD_INFORMATION structure

## Description

The **FILE_STANDARD_INFORMATION** structure is used as an argument to routines that query or set file information.

## Members

### `AllocationSize`

The file allocation size in bytes. Usually, this value is a multiple of the sector or cluster size of the underlying physical device.

### `EndOfFile`

The end of file location as a byte offset.

### `NumberOfLinks`

The number of hard links to the file.

### `DeletePending`

The delete pending status. **TRUE** indicates that a file deletion has been requested.

### `Directory`

The file directory status. **TRUE** indicates the file object represents a directory.

## Remarks

**EndOfFile** specifies the byte offset to the end of the file. Because this value is zero-based, it actually refers to the first free byte in the file; that is, it is the offset to the byte immediately following the last valid byte in the file.

## See also

[ZwCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile)

[ZwQueryInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationfile)

[ZwSetInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntsetinformationfile)
# _FILE_END_OF_FILE_INFORMATION structure

## Description

The **FILE_END_OF_FILE_INFORMATION** structure is used as an argument to the [ZwSetInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntsetinformationfile) routine.

## Members

### `EndOfFile`

The absolute new end of file position as a byte offset from the start of the file.

## Remarks

**EndOfFile** specifies the byte offset to the end of the file. Because this value is zero-based, it actually refers to the first free byte in the file: that is, it is the offset to the byte immediately following the last valid byte in the file.

## See also

[ZwQueryInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationfile)

[ZwSetInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntsetinformationfile)
# _FILE_NAME_INFORMATION structure

## Description

The **FILE_NAME_INFORMATION** structure is used as argument to the [ZwQueryInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationfile) and [ZwSetInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntsetinformationfile) routines.

## Members

### `FileNameLength`

Specifies the length, in bytes, of the file name string.

### `FileName`

Specifies the first character of the file name string. This is followed in memory by the remainder of the string.

## Remarks

The **ZwQueryInformationFile** routine uses this structure to return the file name string to the caller. For more information about the form of the name returned, see [ZwQueryInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationfile).

Callers of [ZwSetInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntsetinformationfile) can use this structure to specify a new short name for a file.

## See also

[ZwQueryInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationfile)

[ZwSetInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntsetinformationfile)
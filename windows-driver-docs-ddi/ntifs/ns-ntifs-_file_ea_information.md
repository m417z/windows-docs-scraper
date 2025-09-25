# _FILE_EA_INFORMATION structure

## Description

The **FILE_EA_INFORMATION** structure is used to query for the size of the extended attributes (EA) for a file.

## Members

### `EaSize`

Specifies the combined length, in bytes, of the extended attributes for the file.

## Remarks

This structure is used by the [ZwQueryInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationfile) routine.

An extended attribute is a piece of application-specific metadata that an application can associate with a file that is not part of the file's data. In addition to the built-in attributes of a file, such as creation and modification times, applications can add non-file system attributes, such as the author's name and a description of the file content.

## See also

[ZwQueryInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationfile)
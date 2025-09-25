# _FILE_ATTRIBUTE_TAG_INFORMATION structure

## Description

The **FILE_ATTRIBUTE_TAG_INFORMATION** structure is used as an argument to [ZwQueryInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationfile).

## Members

### `FileAttributes`

Specifies one or more FILE_ATTRIBUTE_*XXX* flags. For descriptions of these flags, see the documentation of the **GetFileAttributes** function in the Microsoft Windows SDK.

### `ReparseTag`

Specifies the reparse point tag. If the **FileAttributes** member includes the FILE_ATTRIBUTE_REPARSE_POINT attribute flag, this member specifies the reparse tag. Otherwise, this member is unused.

## Remarks

FILE_READ_ATTRIBUTES access to the file is required to query this information.

For more information about reparse points and reparse point tags, see the Windows SDK.

This structure must be aligned on a LONG (4-byte) boundary.

## See also

[ZwQueryInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationfile)
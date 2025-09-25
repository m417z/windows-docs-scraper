# FILE_STAT_INFORMATION structure

## Description

**FILE_STAT_INFORMATION** contains metadata about a file.

## Members

### `FileId`

Specifies the id of a file.

### `CreationTime`

Specifies the creation time of a file.

### `LastAccessTime`

Specifies the last time a file was accessed.

### `LastWriteTime`

Specifies the last time a file was written to.

### `ChangeTime`

Specifies the last time a file was changed.

### `AllocationSize`

File allocation size, in bytes. Usually this value is a multiple of the sector or cluster size of the underlying physical device.

### `EndOfFile`

Absolute new end-of-file position as a byte offset from the start of the file. **EndOfFile** specifies the byte offset to the end of the file. Because this value is zero-based, it actually refers to the first free byte in the file. In other words, **EndOfFile** is the offset to the byte immediately following the last valid byte in the file.

### `FileAttributes`

File attributes, which can be any valid combination of the following:

Attribute | Value
------------|------------
FILE_ATTRIBUTE_READONLY |0x00000001
FILE_ATTRIBUTE_HIDDEN |0x00000002
FILE_ATTRIBUTE_SYSTEM |0x00000004
FILE_ATTRIBUTE_DIRECTORY|0x00000010
FILE_ATTRIBUTE_ARCHIVE |0x00000020
FILE_ATTRIBUTE_NORMAL |0x00000080

### `ReparseTag`

Reparse point tag. See [About reparse points](https://learn.microsoft.com/windows-hardware/drivers/ifs/reparse-points) for more information.

### `NumberOfLinks`

Specifies the number of links to the file.

### `EffectiveAccess`

Specifies the access rights of the file.

## Remarks

[**NtQueryInformationByName**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationbyname) and [**NtQueryInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationfile) return information in a **FILE_STAT_INFORMATION** structure when their **FileInformationClass** parameter is FileStatInformation.

## See also

[**NtQueryInformationByName**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationbyname)

[**NtQueryInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationfile)
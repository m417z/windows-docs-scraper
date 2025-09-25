# FILE_STAT_LX_INFORMATION structure

## Description

**FILE_STAT_LX_INFORMATION** contains Linux metadata extended attributes present on the file. This is used and created by the Windows Subsystem for Linux (WSL).

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

### `LxFlags`

The flags associated with **FILE_STAT_LX_INFORMATION** that specify which metadata fields were present in the file.

Flag|Value
----|-----
LX_FILE_METADATA_HAS_UID|x1
LX_FILE_METADATA_HAS_GID|x2
LX_FILE_METADATA_HAS_MODE|x4
LX_FILE_METADATA_HAS_DEVICE_ID|x8
LX_FILE_CASE_SENSITIVE_DIR|x10

### `LxUid`

Specifies the User id of the file.

### `LxGid`

Specifies the Group id of the file.

### `LxMode`

Specifies the Linux file type and file system permissions. These values are defined in sys/stat.h in the Windows SDK.

- S_IFLNK
- S_IFSOCK
- S_IFBLK

| Flag | Description|
|---|---|
|_S_IFMT 0xF000 |File type mask|
|_S_IFDIR 0x4000 | Directory|
|_S_IFCHR 0x2000 | Character special|
|_S_IFIFO 0x1000 | Pipe|
|_S_IFREG 0x8000 | Regular|
|_S_IREAD 0x0100 | Read permission, owner|
|_S_IWRITE 0x0080 | Write permission, owner|
|_S_IEXEC 0x0040 | Execute/search permission, owner|

### `LxDeviceIdMajor`

For device files (_S_IFCHR or S_IFBLK), specifies the device major number. For other file types, this field is not used.

### `LxDeviceIdMinor`

For device files (_S_IFCHR or S_IFBLK), specifies the device minor number. For other file types, this field is not used.

## Remarks

[**NtQueryInformationByName**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationbyname) and [**NtQueryInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationfile) return information in a **FILE_STAT_LX_INFORMATION** structure when their **FileInformationClass** parameter is FileStatLxInformation.

For more information about absolute and relative symbolic links, see Creating Symbolic Links in the Microsoft Windows SDK documentation.

## See also

[**NtQueryInformationByName**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationbyname)

[**NtQueryInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationfile)
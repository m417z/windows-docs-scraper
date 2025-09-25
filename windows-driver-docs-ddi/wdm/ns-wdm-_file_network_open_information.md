# _FILE_NETWORK_OPEN_INFORMATION structure

## Description

The **FILE_NETWORK_OPEN_INFORMATION** structure is used as an argument to [ZwQueryInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationfile).

## Members

### `CreationTime`

Specifies the time that the file was created.

### `LastAccessTime`

Specifies the time that the file was last accessed.

### `LastWriteTime`

Specifies the time that the file was last written to.

### `ChangeTime`

Specifies the time that the file was last changed.

### `AllocationSize`

Specifies the file allocation size, in bytes. Usually, this value is a multiple of the sector or cluster size of the underlying physical device.

### `EndOfFile`

Specifies the absolute end-of-file position as a byte offset from the start of the file. **EndOfFile** specifies the byte offset to the end of the file. Because this value is zero-based, it actually refers to the first free byte in the file. In other words, **EndOfFile** is the offset to the byte immediately following the last valid byte in the file.

### `FileAttributes`

Specifies one or more FILE_ATTRIBUTE_*XXX* flags. For descriptions of these flags, see the documentation of the **GetFileAttributes** function in the Microsoft Windows SDK.

## Remarks

FILE_READ_ATTRIBUTES access to the file is required to query this information.

Time values **CreationTime**, **LastAccessTime**, **LastWriteTime**, and **ChangeTime** are expressed in absolute system time format. Absolute system time is the number of 100-nanosecond intervals since the start of the year 1601 in the Gregorian calendar.

This structure must be aligned on a LONGLONG (8-byte) boundary.

## See also

[ZwQueryInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationfile)
# FILE_BASIC_INFORMATION structure

## Description

The **FILE_BASIC_INFORMATION** structure contains timestamps and basic attributes of a file. It is used as an argument to routines that query or set file information.

## Members

### `CreationTime`

Specifies the time that the file was created.

### `LastAccessTime`

Specifies the time that the file was last accessed.

### `LastWriteTime`

Specifies the time that the file was last written to.

### `ChangeTime`

Specifies the last time the file was changed.

### `FileAttributes`

Specifies one or more FILE_ATTRIBUTE_*XXX* flags. For descriptions of these flags, see [File Attribute Constants](https://learn.microsoft.com/windows/win32/fileio/file-attribute-constants) in the Microsoft Windows SDK.

## Remarks

The FILE_ATTRIBUTE_NORMAL flag cannot be set or returned in combination with any other attributes. All other **FileAttributes** values override this attribute.

Time values **CreationTime**, **LastAccessTime**, **LastWriteTime**, and **ChangeTime** are expressed in absolute system time format. Absolute system time is the number of 100-nanosecond intervals since the start of the year 1601 in the Gregorian calendar.

If you specify a value of zero for any of the *Xxx***Time** members of the **FILE_BASIC_INFORMATION** structure, the [ZwSetInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntsetinformationfile) function keeps a file's current setting for that time.

The file system updates the values of the **LastAccessTime**, **LastWriteTime**, and **ChangeTime** members as appropriate after an I/O operation is performed on a file. A driver or application can request that the file system not update one or more of these members for I/O operations that are performed on the caller's file handle by setting the appropriate members to -1. The caller can set one, all, or any other combination of these three members to -1. Only the members that are set to -1 will be unaffected by I/O operations on the file handle; the other members will be updated as appropriate. On NTFS and ReFS systems, time stamp updates on the file handle can be restored by setting the appropriate member(s) to -2.

To set the members of this structure, the caller must have FILE_WRITE_ATTRIBUTES access to the file.

## See also

[KeQuerySystemTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequerysystemtime-r1)

[ZwCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile)

[ZwQueryInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationfile)

[ZwSetInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntsetinformationfile)
# GetVolumeInformationW function

## Description

Retrieves information about the file system and volume associated with the specified root directory.

To specify a handle when retrieving this information, use the [GetVolumeInformationByHandleW](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-getvolumeinformationbyhandlew) function.

To retrieve the current compression state of a file or directory, use [FSCTL_GET_COMPRESSION](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_get_compression).

## Parameters

### `lpRootPathName` [in, optional]

A pointer to a string that contains the root directory of the volume to be described.

If this parameter is **NULL**, the root of the current directory is used. A trailing backslash is required. For example, specify \\\\MyServer\\MyShare as "\\\\MyServer\\MyShare\\", or the C drive as "C:\\".

### `lpVolumeNameBuffer` [out, optional]

A pointer to a buffer that receives the name of a specified volume. The buffer size is specified by the _nVolumeNameSize_ parameter.

### `nVolumeNameSize` [in]

The length of a volume name buffer, in **TCHARs**. The maximum buffer size is **MAX_PATH**+1.

This parameter is ignored if the volume name buffer is not supplied.

### `lpVolumeSerialNumber` [out, optional]

A pointer to a variable that receives the volume serial number.

This parameter can be **NULL** if the serial number is not required.

This function returns the volume serial number that the operating system assigns when a hard disk is formatted. To programmatically obtain the hard disk's serial number that the manufacturer assigns, use the Windows Management Instrumentation (WMI) [Win32_PhysicalMedia](https://learn.microsoft.com/previous-versions/windows/desktop/cimwin32a/win32-physicalmedia) property **SerialNumber**.

### `lpMaximumComponentLength` [out, optional]

A pointer to a variable that receives the maximum length, in **TCHARs**, of a file name component that a specified file system supports.

A file name component is the portion of a file name between backslashes.

The value that is stored in the variable that *_lpMaximumComponentLength_ points to is used to indicate that a specified file system supports long names. For example, for a FAT file system that supports long names, the function stores the value 255, rather than the previous 8.3 indicator. Long names can also be supported on systems that use the NTFS file system.

### `lpFileSystemFlags` [out, optional]

A pointer to a variable that receives flags associated with the specified file system.

This parameter can be one or more of the following flags. However, **FILE_FILE_COMPRESSION** and **FILE_VOL_IS_COMPRESSED** are mutually exclusive.

| Value | Meaning |
|--------|--------|
| **FILE_CASE_SENSITIVE_SEARCH**<br>0x00000001 | The specified volume supports case-sensitive file names. |
| **FILE_CASE_PRESERVED_NAMES**<br>0x00000002 | The specified volume supports preserved case of file names when it places a name on disk. |
| **FILE_UNICODE_ON_DISK**<br>0x00000004 | The specified volume supports Unicode in file names as they appear on disk. |
| **FILE_PERSISTENT_ACLS**<br>0x00000008 | The specified volume preserves and enforces access control lists (ACL). For example, the NTFS file system preserves and enforces ACLs, and the FAT file system does not. |
| **FILE_FILE_COMPRESSION**<br>0x00000010 | The specified volume supports file-based compression. |
| **FILE_VOLUME_QUOTAS**<br>0x00000020 | The specified volume supports disk quotas. |
| **FILE_SUPPORTS_SPARSE_FILES**<br>0x00000040 | The specified volume supports sparse files. |
| **FILE_SUPPORTS_REPARSE_POINTS**<br>0x00000080 | The specified volume supports reparse points.<br><br>**ReFS:** ReFS supports reparse points but does not index them so [FindFirstVolumeMountPoint](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-findfirstvolumemountpointa) and [FindNextVolumeMountPoint](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-findnextvolumemountpointa) will not function as expected. |
| **FILE_SUPPORTS_REMOTE_STORAGE**<br>0x00000100 | The file system supports remote storage. |
| **FILE_RETURNS_CLEANUP_RESULT_INFO**<br>0x00000200 | On a successful cleanup operation, the file system returns information that describes additional actions taken during cleanup, such as deleting the file. File system filters can examine this information in their post-cleanup callback. |
| **FILE_SUPPORTS_POSIX_UNLINK_RENAME**<br>0x00000400 | The file system supports POSIX-style delete and rename operations. |
| **FILE_VOLUME_IS_COMPRESSED**<br>0x00008000 | The specified volume is a compressed volume, for example, a DoubleSpace volume. |
| **FILE_SUPPORTS_OBJECT_IDS**<br>0x00010000 | The specified volume supports object identifiers. |
| **FILE_SUPPORTS_ENCRYPTION**<br>0x00020000 | The specified volume supports the Encrypted File System (EFS). For more information, see [File Encryption](https://learn.microsoft.com/windows/win32/FileIO/file-encryption). |
| **FILE_NAMED_STREAMS**<br>0x00040000 | The specified volume supports named streams. |
| **FILE_READ_ONLY_VOLUME**<br>0x00080000 | The specified volume is read-only. |
| **FILE_SEQUENTIAL_WRITE_ONCE**<br>0x00100000 | The specified volume supports a single sequential write. |
| **FILE_SUPPORTS_TRANSACTIONS**<br>0x00200000 | The specified volume supports transactions. For more information, see [About KTM](https://learn.microsoft.com/windows/win32/Ktm/about-ktm). |
| **FILE_SUPPORTS_HARD_LINKS**<br>0x00400000 | The specified volume supports hard links. For more information, see [Hard Links and Junctions](https://learn.microsoft.com/windows/desktop/FileIO/hard-links-and-junctions).\
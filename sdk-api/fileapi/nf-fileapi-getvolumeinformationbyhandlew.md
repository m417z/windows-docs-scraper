# GetVolumeInformationByHandleW function

## Description

Retrieves information about the file system and volume associated with the specified file.

To retrieve the current compression state of a file or directory, use [FSCTL_GET_COMPRESSION](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_get_compression).

## Parameters

### `hFile` [in]

A handle to the file.

### `lpVolumeNameBuffer` [out, optional]

A pointer to a buffer that receives the name of a specified volume. The maximum buffer size is `MAX_PATH+1`.

### `nVolumeNameSize` [in]

The length of a volume name buffer, in **WCHAR**s. The maximum buffer size is `MAX_PATH+1`.

This parameter is ignored if the volume name buffer is not supplied.

### `lpVolumeSerialNumber` [out, optional]

A pointer to a variable that receives the volume serial number.

This parameter can be **NULL** if the serial number is not required.

This function returns the volume serial number that the operating system assigns when a hard disk is formatted. To programmatically obtain the hard disk's serial number that the manufacturer assigns, use the Windows Management Instrumentation (WMI) [Win32_PhysicalMedia](https://learn.microsoft.com/previous-versions/windows/desktop/cimwin32a/win32-physicalmedia) property **SerialNumber**.

### `lpMaximumComponentLength` [out, optional]

A pointer to a variable that receives the maximum length, in **WCHAR**s, of a file name component that a specified file system supports.

A file name component is the portion of a file name between backslashes.

The value that is stored in the variable that *_lpMaximumComponentLength_ points to is used to indicate that a specified file system supports long names. For example, for a FAT file system that supports long names, the function stores the value 255, rather than the previous 8.3 indicator. Long names can also be supported on systems that use the NTFS file system.

### `lpFileSystemFlags` [out, optional]

A pointer to a variable that receives flags associated with the specified file system.

This parameter can be one or more of the following flags. However, **FILE_FILE_COMPRESSION** and **FILE_VOL_IS_COMPRESSED** are mutually exclusive.

| Value | Meaning |
| --- | --- |
| **FILE_CASE_SENSITIVE_SEARCH**<br><br>0x00000001 | The specified volume supports case-sensitive file names. |
| **FILE_CASE_PRESERVED_NAMES**<br><br>0x00000002 | The specified volume supports preserved case of file names when it places a name on disk. |
| **FILE_UNICODE_ON_DISK**<br><br>0x00000004 | The specified volume supports Unicode in file names as they appear on disk. |
| **FILE_PERSISTENT_ACLS**<br><br>0x00000008 | The specified volume preserves and enforces access control lists (ACL). For example, the NTFS file system preserves and enforces ACLs, and the FAT file system does not. |
| **FILE_FILE_COMPRESSION**<br><br>0x00000010 | The specified volume supports file-based compression. |
| **FILE_VOLUME_QUOTAS**<br><br>0x00000020 | The specified volume supports disk quotas. |
| **FILE_SUPPORTS_SPARSE_FILES**<br><br>0x00000040 | The specified volume supports sparse files. |
| **FILE_SUPPORTS_REPARSE_POINTS**<br><br>0x00000080 | The specified volume supports re-parse points. |
| **FILE_VOLUME_IS_COMPRESSED**<br><br>0x00008000 | The specified volume is a compressed volume, for example, a DoubleSpace volume. |
| **FILE_SUPPORTS_OBJECT_IDS**<br><br>0x00010000 | The specified volume supports object identifiers. |
| **FILE_SUPPORTS_ENCRYPTION**<br><br>0x00020000 | The specified volume supports the Encrypted File System (EFS). For more information, see [File Encryption](https://learn.microsoft.com/windows/win32/FileIO/file-encryption). |
| **FILE_NAMED_STREAMS**<br><br>0x00040000 | The specified volume supports named streams. |
| **FILE_READ_ONLY_VOLUME**<br><br>0x00080000 | The specified volume is read-only. |
| **FILE_SEQUENTIAL_WRITE_ONCE**<br><br>0x00100000 | The specified volume supports a single sequential write. |
| **FILE_SUPPORTS_TRANSACTIONS**<br><br>0x00200000 | The specified volume supports transactions. For more information, see [About KTM](https://learn.microsoft.com/windows/win32/Ktm/about-ktm). |
| **FILE_SUPPORTS_HARD_LINKS**<br><br>0x00400000 | The specified volume supports hard links. For more information, see [Hard Links and Junctions](https://learn.microsoft.com/windows/win32/FileIO/hard-links-and-junctions).<br><br>**Windows Vista and Windows Server 2008:** This value is not supported. |
| **FILE_SUPPORTS_EXTENDED_ATTRIBUTES**<br><br>0x00800000 | The specified volume supports extended attributes. An extended attribute is a piece of application-specific metadata that an application can associate with a file and is not part of the file's data.<br><br>**Windows Vista and Windows Server 2008:** This value is not supported. |
| **FILE_SUPPORTS_OPEN_BY_FILE_ID**<br><br>0x01000000 | The file system supports open by FileID. For more information, see [FILE_ID_BOTH_DIR_INFO](https://learn.microsoft.com/windows/win32/api/winbase/ns-winbase-file_id_both_dir_info).<br><br>**Windows Vista and Windows Server 2008:** This value is not supported. |
| **FILE_SUPPORTS_USN_JOURNAL**<br><br>0x02000000 | The specified volume supports update sequence number (USN) journals. For more information, see [Change Journal Records](https://learn.microsoft.com/windows/win32/FileIO/change-journal-records).<br><br>**Windows Vista and Windows Server 2008:** This value is not supported. |
| **FILE_SUPPORTS_BLOCK_REFCOUNTING**<br><br>0x08000000 | The specified volume supports sharing logical clusters between files on the same volume. The file system reallocates on writes to shared clusters. Indicates that FSCTL_DUPLICATE_EXTENTS_TO_FILE is a supported operation. |

### `lpFileSystemNameBuffer` [out, optional]

A pointer to a buffer that receives the name of the file system, for example, the FAT file system or the NTFS file system. The buffer size is specified by the _nFileSystemNameSize_ parameter.

### `nFileSystemNameSize` [in]

The length of the file system name buffer, in **WCHAR**s. The maximum buffer size is `MAX_PATH+1`.

This parameter is ignored if the file system name buffer is not supplied.

## Return value

If all the requested information is retrieved, the return value is nonzero.

If not all the requested information is retrieved, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
|--------|--------|
| Server Message Block (SMB) 3.0 protocol | No |
| SMB 3.0 Transparent Failover (TFO) | No |
| SMB 3.0 with Scale-out File Shares (SO) | No |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

SMB does not support volume management functions.

## See also

[About KTM](https://learn.microsoft.com/windows/win32/Ktm/about-ktm)

[File Encryption](https://learn.microsoft.com/windows/win32/FileIO/file-encryption)

[GetCompressedFileSize](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-getcompressedfilesizea)

[GetFileAttributes](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-getfileattributesa)

[GetVolumeInformation](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-getvolumeinformationa)

[SetErrorMode](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-seterrormode)

[SetVolumeLabel](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-setvolumelabela)

[Volume Management Functions](https://learn.microsoft.com/windows/win32/FileIO/volume-management-functions)
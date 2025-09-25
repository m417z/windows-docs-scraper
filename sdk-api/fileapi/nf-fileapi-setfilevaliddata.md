# SetFileValidData function

## Description

Sets the valid data length of the specified file. This function is useful in very limited scenarios. For more information, see the Remarks section.

**Caution** Use of this function without proper security considerations may compromise data privacy and security. For more information, see the Remarks section.

## Parameters

### `hFile` [in]

A handle to the file. The file must have been opened with the **GENERIC_WRITE** access right, and the **SE_MANAGE_VOLUME_NAME** privilege enabled. For more information, see
[File Security and Access Rights](https://learn.microsoft.com/windows/desktop/FileIO/file-security-and-access-rights).

**Note** The file cannot be a network file, or be compressed, sparse, or transacted.

### `ValidDataLength` [in]

The new valid data length.

This parameter must be a positive value that is greater than the current valid data length, but less than the current file size.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is 0. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **SetFileValidData** function sets the logical end of a file. To set the size of a file, use the [SetEndOfFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setendoffile) function. The physical file size is also referred to as the end of the file.

Each file stream has the following properties:

* File size: the size of the data in a file, to the byte.
* Allocation size: the size of the space that is allocated for a file on a disk, which is always an even multiple of the cluster size.
* Valid data length: the length of the data in a file that is actually written, to the byte. This value is always less than or equal to the file size.

Typically, the
**SetFileValidData** function is used by system-level applications on their own private data. Not all file systems use valid data length. Some file systems can track multiple valid data ranges.
In general, most applications will never need to call this function.

The **SetFileValidData** function allows you to avoid filling data with zeros when writing nonsequentially to a file. The function makes the data in the file valid without writing to the file. As a result, although some performance gain may be realized, existing data on disk from previously existing files can inadvertently become available to unintended readers. The following paragraphs provide a more detailed description of this potential security and privacy issue.

A caller must have the **SE_MANAGE_VOLUME_NAME** privilege enabled when opening a file initially. Applications should call **SetFileValidData** only on files that restrict access to those entities that have **SE_MANAGE_VOLUME_NAME** access. The application must ensure that the unwritten ranges of the file are never exposed, or security issues can result as follows.

If **SetFileValidData** is used on a file, the potential performance gain is obtained by not filling the allocated clusters for the file with zeros. Therefore, reading from the file will return whatever the allocated clusters contain, potentially content from other users. This is not necessarily a security issue at this point, because the caller needs to have **SE_MANAGE_VOLUME_NAME** privilege for **SetFileValidData** to succeed, and all data on disk can be read by such users. However, this caller can inadvertently expose this data to other users that cannot acquire the **SE_MANAGE_VOLUME_PRIVILEGE** privilege if the following holds:

* If the file was not opened with a sharing mode that denies other readers, a nonprivileged user can open it and read the exposed data.
* If the system stops responding before the caller finishes writing up the *ValidDataLength* supplied in the call, then, on a reboot, such a nonprivileged user can open the file and read exposed content.

If the caller of **SetFileValidData** opened the file with adequately restrictive access control, the previous conditions would not apply. However, for partially written files extended with **SetFileValidData** (that is, writing was not completed up to the *ValidDataLength* supplied in the call) there exists yet another potential privacy or security vulnerability. An administrator could copy the file to a target that is not properly controlled with restrictive ACL permissions, thus inadvertently exposing the extended area's data to unauthorized reading.

It is for these reasons that **SetFileValidData** is not recommended for general purpose use, in addition to performance considerations, as discussed below.

For more information about security and access privileges, see
[Running with Special Privileges](https://learn.microsoft.com/windows/desktop/SecBP/running-with-special-privileges) and [File Security and Access Rights](https://learn.microsoft.com/windows/desktop/FileIO/file-security-and-access-rights).

You can use the **SetFileValidData** function to create large files in very specific circumstances so that the performance of subsequent file I/O can be better than other methods. Specifically, if the extended portion of the file is large and will be written to randomly, such as in a database type of application, the time it takes to extend and write to the file will be faster than using [SetEndOfFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setendoffile) and writing randomly. In most other situations, there is usually no performance gain to using **SetFileValidData**, and sometimes there can be a performance penalty.

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | Yes |
| SMB 3.0 with Scale-out File Shares (SO) | Yes |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

## See also

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[SetEndOfFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setendoffile)
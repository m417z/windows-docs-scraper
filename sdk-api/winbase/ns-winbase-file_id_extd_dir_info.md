# FILE_ID_EXTD_DIR_INFO structure

## Description

Contains identification information for a file. This structure is returned from the
[GetFileInformationByHandleEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfileinformationbyhandleex) function when
**FileIdExtdDirectoryInfo** (0x13) or **FileIdExtdDirectoryRestartInfo** (0x14)
is passed in the *FileInformationClass* parameter.

## Members

### `NextEntryOffset`

The offset for the next **FILE_ID_EXTD_DIR_INFO**
structure that is returned. Contains zero (0) if no other entries follow this one.

### `FileIndex`

The byte offset of the file within the parent directory. This member is undefined for file systems, such as
NTFS, in which the position of a file within the parent directory is not fixed and can be changed at any time to
maintain sort order.

### `CreationTime`

The time that the file was created.

### `LastAccessTime`

The time that the file was last accessed.

### `LastWriteTime`

The time that the file was last written to.

### `ChangeTime`

The time that the file was last changed.

### `EndOfFile`

The absolute new end-of-file position as a byte offset from the start of the file to the end of the file.
Because this value is zero-based, it actually refers to the first free byte in the file. In other words,
**EndOfFile** is the offset to the byte that immediately follows the last valid byte in
the file.

### `AllocationSize`

The number of bytes that are allocated for the file. This value is usually a multiple of the sector or
cluster size of the underlying physical device.

### `FileAttributes`

The file attributes. This member can be any valid combination of the following attributes:

| Value | Meaning |
| --- | --- |
| **FILE_ATTRIBUTE_ARCHIVE**<br><br>32 (0x20) | A file or directory that is an archive file or directory. Applications typically use this attribute to mark files for backup or removal . |
| **FILE_ATTRIBUTE_COMPRESSED**<br><br>2048 (0x800) | A file or directory that is compressed. For a file, all of the data in the file is compressed. For a directory, compression is the default for newly created files and subdirectories. |
| **FILE_ATTRIBUTE_DEVICE**<br><br>64 (0x40) | This value is reserved for system use. |
| **FILE_ATTRIBUTE_DIRECTORY**<br><br>16 (0x10) | The handle that identifies a directory. |
| **FILE_ATTRIBUTE_ENCRYPTED**<br><br>16384 (0x4000) | A file or directory that is encrypted. For a file, all data streams in the file are encrypted. For a directory, encryption is the default for newly created files and subdirectories. |
| **FILE_ATTRIBUTE_HIDDEN**<br><br>2 (0x2) | The file or directory is hidden. It is not included in an ordinary directory listing. |
| **FILE_ATTRIBUTE_NORMAL**<br><br>128 (0x80) | A file that does not have other attributes set. This attribute is valid only when used alone. |
| **FILE_ATTRIBUTE_NOT_CONTENT_INDEXED**<br><br>8192 (0x2000) | The file or directory is not to be indexed by the content indexing service. |
| **FILE_ATTRIBUTE_OFFLINE**<br><br>4096 (0x1000) | The data of a file is not available immediately. This attribute indicates that the file data is physically moved to offline storage. This attribute is used by Remote Storage, which is the hierarchical storage management software. Applications should not arbitrarily change this attribute. |
| **FILE_ATTRIBUTE_READONLY**<br><br>1 (0x1) | A file that is read-only. Applications can read the file, but cannot write to it or delete it. This attribute is not honored on directories. For more information, see [You cannot view or change the Read-only or the System attributes of folders in Windows Server 2003, in Windows XP, in Windows Vista or in Windows 7](https://support.microsoft.com/kb/326549). |
| **FILE_ATTRIBUTE_REPARSE_POINT**<br><br>1024 (0x400) | A file or directory that has an associated reparse point, or a file that is a symbolic link. |
| **FILE_ATTRIBUTE_SPARSE_FILE**<br><br>512 (0x200) | A file that is a sparse file. |
| **FILE_ATTRIBUTE_SYSTEM**<br><br>4 (0x4) | A file or directory that the operating system uses a part of, or uses exclusively. |
| **FILE_ATTRIBUTE_TEMPORARY**<br><br>256 (0x100) | A file that is being used for temporary storage. File systems avoid writing data back to mass storage if sufficient cache memory is available, because typically, an application deletes a temporary file after the handle is closed. In that scenario, the system can entirely avoid writing the data. Otherwise, the data is written after the handle is closed. |
| **FILE_ATTRIBUTE_VIRTUAL**<br><br>65536 (0x10000) | This value is reserved for system use. |

### `FileNameLength`

The length of the file name.

### `EaSize`

The size of the extended attributes for the file.

### `ReparsePointTag`

If the **FileAttributes** member includes the
**FILE_ATTRIBUTE_REPARSE_POINT** attribute, this member specifies the reparse point
tag.

Otherwise, this value is undefined and should not be used.

For more information see [Reparse Point Tags](https://learn.microsoft.com/windows/desktop/FileIO/reparse-point-tags).

#### IO_REPARSE_TAG_CSV (0x80000009)

#### IO_REPARSE_TAG_DEDUP (0x80000013)

#### IO_REPARSE_TAG_DFS (0x8000000A)

#### IO_REPARSE_TAG_DFSR (0x80000012)

#### IO_REPARSE_TAG_HSM (0xC0000004)

#### IO_REPARSE_TAG_HSM2 (0x80000006)

#### IO_REPARSE_TAG_MOUNT_POINT (0xA0000003)

#### IO_REPARSE_TAG_NFS (0x80000014)

#### IO_REPARSE_TAG_SIS (0x80000007)

#### IO_REPARSE_TAG_SYMLINK (0xA000000C)

#### IO_REPARSE_TAG_WIM (0x80000008)

### `FileId`

The file ID.

### `FileName`

The first character of the file name string. This is followed in memory by the remainder of the
string.

## See also

[FILE_ID_128](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-file_id_128)

[FILE_INFO_BY_HANDLE_CLASS](https://learn.microsoft.com/windows/desktop/api/minwinbase/ne-minwinbase-file_info_by_handle_class)

[File Management Structures](https://learn.microsoft.com/windows/desktop/FileIO/file-management-structures)

[GetFileInformationByHandleEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfileinformationbyhandleex)
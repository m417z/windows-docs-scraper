# FILE_NOTIFY_EXTENDED_INFORMATION structure

## Description

Describes the changes found by the
[ReadDirectoryChangesExW](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-readdirectorychangesexw) function.

## Members

### `NextEntryOffset`

The number of bytes that must be skipped to get to the next record. A value of zero indicates that this is
the last record.

### `Action`

The type of change that has occurred. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **FILE_ACTION_ADDED**<br><br>0x00000001 | The file was added to the directory. |
| **FILE_ACTION_REMOVED**<br><br>0x00000002 | The file was removed from the directory. |
| **FILE_ACTION_MODIFIED**<br><br>0x00000003 | The file was modified. This can be a change in the time stamp or attributes. |
| **FILE_ACTION_RENAMED_OLD_NAME**<br><br>0x00000004 | The file was renamed and this is the old name. |
| **FILE_ACTION_RENAMED_NEW_NAME**<br><br>0x00000005 | The file was renamed and this is the new name. |

### `CreationTime`

 The date and time that the directory or file was created and added to the file system.

### `LastModificationTime`

 The date and time that the content of the directory or file was last modified in the file system.

### `LastChangeTime`

The date and time that the metadata or content of the directory or file was last changed in the file system.

### `LastAccessTime`

The date and time the directory or file was last accessed in the file system.

### `AllocatedLength`

The allocated size of the file, in bytes.

### `FileSize`

The new size of the directory or file in bytes, or the old size if
the size is unchanged.

### `FileAttributes`

The attributes of the directory or file.

### `ReparsePointTag`

The identifier tag of a reparse point for the directory or file.

### `FileId`

 The identifier of the directory or file.

### `ParentFileId`

The identifier of the parent directory for the file.

### `FileNameLength`

The size of the file name portion of the record, in bytes. This value does not include a
terminating null character.

### `FileName`

A variable-length field that contains the file name relative to the directory handle. The file name is in
the Unicode character format and is not null-terminated.

If there is both a short and long name for the file, the function will return one of these names, but it is
unspecified which one.

## See also

[ReadDirectoryChangesExW](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-readdirectorychangesexw)
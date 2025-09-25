# FILE_NOTIFY_INFORMATION structure

## Description

Describes the changes found by the
[ReadDirectoryChangesW](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-readdirectorychangesw) function.

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

### `FileNameLength`

The size of the file name portion of the record, in bytes. Note that this value does not include the
terminating null character.

### `FileName`

A variable-length field that contains the file name relative to the directory handle. The file name is in
the Unicode character format and is not null-terminated.

If there is both a short and long name for the file, the function will return one of these names, but it is
unspecified which one.

## See also

[ReadDirectoryChangesW](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-readdirectorychangesw)
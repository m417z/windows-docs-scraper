# FIND_BY_SID_OUTPUT structure

## Description

The FIND_BY_SID_OUTPUT structure represents the fully qualified path name of a file.

## Members

### `NextEntryOffset`

Number of bytes that must be skipped to get to the next record. A value of zero indicates that this is the last record.

### `FileIndex`

Index of the file.

### `FileNameLength`

The size of the file name, in bytes. This size does not include the NULL character.

### `FileName`

A null-terminated string that specifies the file name.

## See also

[FSCTL_FIND_FILES_BY_SID](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_find_files_by_sid)
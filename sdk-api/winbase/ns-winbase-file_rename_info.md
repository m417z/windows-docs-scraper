# FILE_RENAME_INFO structure

## Description

Contains the target name to which the source file should be renamed. Use only when calling
[SetFileInformationByHandle](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setfileinformationbyhandle).

## Members

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.ReplaceIfExists`

This field is used when **SetFileInformationByHandle**'s *FileInformationClass* parameter is set to **FileRenameInfo**.
If this field is **TRUE** and the target file exists then the target file will be replaced by the source file. If this
field is **FALSE** and the target file exists then operation will return an error.

### `DUMMYUNIONNAME.Flags`

This field is used when **SetFileInformationByHandle**'s *FileInformationClass* parameter is set to **FileRenameInfoEx**.

### `RootDirectory`

This field should be set to NULL.

### `FileNameLength`

The size of **FileName** in bytes, not including the NUL-termination.

### `FileName`

A NUL-terminated wide-character string containing the new path to the file. The value can be one of the following:

- An absolute path (drive, directory, and filename).
- A path relative to the process's current directory.
- The new name of an NTFS file stream, starting with `:`.

## See also

[FILE_INFO_BY_HANDLE_CLASS](https://learn.microsoft.com/windows/desktop/api/minwinbase/ne-minwinbase-file_info_by_handle_class)

[SetFileInformationByHandle](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setfileinformationbyhandle)
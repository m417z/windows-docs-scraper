# FINDEX_SEARCH_OPS enumeration

## Description

Defines values that are used with the
[FindFirstFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstfileexa) function to specify the type of
filtering to perform.

## Constants

### `FindExSearchNameMatch`

The search for a file that matches a specified file name.

The *lpSearchFilter* parameter of
[FindFirstFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstfileexa) must be
**NULL** when this search operation is used.

### `FindExSearchLimitToDirectories`

This is an advisory flag.
If the file system supports directory filtering, the function searches for a file that matches the specified name and is also a directory.
If the file system does not support directory filtering, this flag is silently ignored.

The *lpSearchFilter* parameter of the [FindFirstFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstfileexa) function must be **NULL** when this search value is used.

If directory filtering is desired, this flag can be used on all file systems, but because it is an advisory flag and only affects file systems that support it, the application must examine the file attribute data stored in the *lpFindFileData* parameter of the [FindFirstFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstfileexa) function to determine whether the function has returned a handle to a directory.

### `FindExSearchLimitToDevices`

This filtering type is not available.

For more information, see
[Device Interface Classes](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-interface-classes).

### `FindExSearchMaxSearchOp`

## See also

[FindFirstFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstfileexa)
# ResUtilCreateDirectoryTree function

## Description

Creates every directory specified in a path, skipping directories that already exist. The **PRESUTIL_CREATE_DIRECTORY_TREE** type defines a pointer to this function.

## Parameters

### `pszPath` [in]

Pointer to a null-terminated Unicode string specifying a path. The string can end with a trailing backslash.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

If the path only contains a drive specification (L"c:\\"), **ResUtilCreateDirectoryTree** will return **ERROR_SUCCESS** but take no action.

#### Examples

```cpp
// BEFORE
//   C:
//   |--Program Files
//      |-- MyApp
//          |--Data
ResUtilCreateDirectoryTree( L"C:\\Program Files\\MyApp\\Startup\\Parameters\\Users" );

ResUtilCreateDirectoryTree( L"C:\\Program Files\\MyApp\\Data\\Archive\\" );

ResUtilCreateDirectoryTree( L"C:\\Program Files\\MyApp\\Bin" );

// This call will return ERROR_SUCCESS even though all directories
// in the path already exist.
ResUtilCreateDirectoryTree( L"C:\\Program Files\\MyApp\\Bin" );

// AFTER
//   C:
//   |--Program Files
//      |--MyApp
//         |--Bin
//         |--Data
//         |  |--Archive
//         |--Startup
//            |--Parameters
//               |--Users
//

```
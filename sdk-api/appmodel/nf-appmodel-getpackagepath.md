# GetPackagePath function

## Description

Gets the path for the specified package.

## Parameters

### `packageId` [in]

Type: **const [PACKAGE_ID](https://learn.microsoft.com/windows/desktop/api/appmodel/ns-appmodel-package_id)***

The package identifier.

### `reserved`

Type: **const UINT32**

Reserved, do not use.

### `pathLength` [in, out]

Type: **UINT32***

On input, the size of the *path* buffer, in characters. On output, the size of the package path returned, in characters, including the null-terminator.

### `path` [out, optional]

Type: **PWSTR**

The package path.

## Return value

Type: **LONG**

If the function succeeds it returns **ERROR_SUCCESS**. Otherwise, the function returns an error code. The possible error codes include the following.

| Return code | Description |
| --- | --- |
| **ERROR_INSUFFICIENT_BUFFER** | The buffer specified by *path* is not large enough to hold the data. The required size is specified by *pathLength*. |

## See also

[GetPackageInfo](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-getpackageinfo)
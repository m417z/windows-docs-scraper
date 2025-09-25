# OpenPackageInfoByFullName function

## Description

Opens the package information of the specified package.

## Parameters

### `packageFullName` [in]

Type: **PCWSTR**

The full name of the package.

### `reserved`

Type: **const UINT32**

Reserved; must be 0.

### `packageInfoReference` [out]

Type: **PACKAGE_INFO_REFERENCE***

A reference to package information.

## Return value

Type: **LONG**

If the function succeeds it returns **ERROR_SUCCESS**. Otherwise, the function returns an error code. The possible error codes include the following.

| Return code | Description |
| --- | --- |
| **ERROR_NOT_FOUND** | The package is not installed for the current user. |

## See also

[ClosePackageInfo](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-closepackageinfo)

[GetPackageInfo](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-getpackageinfo)
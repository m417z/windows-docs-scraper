# GetPackageInfo function

## Description

Gets the package information for the specified package.

## Parameters

### `packageInfoReference` [in]

Type: **PACKAGE_INFO_REFERENCE**

A reference to package information.

### `flags` [in]

Type: **const UINT32**

The [package constants](https://learn.microsoft.com/windows/desktop/appxpkg/package-constants) that specify how package information is retrieved.

### `bufferLength` [in, out]

Type: **UINT32***

On input, the size of *buffer*, in bytes. On output, the size of the package information returned, in bytes.

### `buffer` [out, optional]

Type: **BYTE***

The package information, represented as an array of [PACKAGE_INFO](https://learn.microsoft.com/windows/desktop/api/appmodel/ns-appmodel-package_info) structures.

### `count` [out, optional]

Type: **UINT32***

The number of packages in the buffer.

## Return value

Type: **LONG**

If the function succeeds it returns **ERROR_SUCCESS**. Otherwise, the function returns an error code. The possible error codes include the following.

| Return code | Description |
| --- | --- |
| **ERROR_INSUFFICIENT_BUFFER** | The buffer is not large enough to hold the data. The required size is specified by *bufferLength*. |

## See also

[GetPackageInfo2](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-getpackageinfo2)

[ClosePackageInfo](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-closepackageinfo)

[GetCurrentPackageInfo](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-getcurrentpackageinfo)

[GetPackagePath](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-getpackagepath)

[OpenPackageInfoByFullName](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-openpackageinfobyfullname)
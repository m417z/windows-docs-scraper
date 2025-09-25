# GetCurrentPackageInfo function

## Description

Gets the package information for the calling process.

## Parameters

### `flags` [in]

Type: **const UINT32**

The [package constants](https://learn.microsoft.com/windows/desktop/appxpkg/package-constants) that specify how package information is retrieved. The **PACKAGE_FILTER_*** flags are supported.

### `bufferLength` [in, out]

Type: **UINT32***

On input, the size of *buffer*, in bytes. On output, the size of the array of structures returned, in bytes.

### `buffer` [out, optional]

Type: **BYTE***

The package information, represented as an array of [PACKAGE_INFO](https://learn.microsoft.com/windows/desktop/api/appmodel/ns-appmodel-package_info) structures.

### `count` [out, optional]

Type: **UINT32***

The number of structures in the buffer.

## Return value

Type: **LONG**

If the function succeeds it returns **ERROR_SUCCESS**. Otherwise, the function returns an error code. The possible error codes include the following.

| Return code | Description |
| --- | --- |
| **APPMODEL_ERROR_NO_PACKAGE** | The process has no package identity. |
| **ERROR_INSUFFICIENT_BUFFER** | The buffer is not large enough to hold the data. The required size is specified by *bufferLength*. |

## See also

[GetCurrentPackageInfo2](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-getcurrentpackageinfo2)

[GetCurrentPackageFamilyName](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-getcurrentpackagefamilyname)

[GetCurrentPackageFullName](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-getcurrentpackagefullname)

[GetCurrentPackageId](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-getcurrentpackageid)

[GetCurrentPackagePath](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-getcurrentpackagepath)

[GetPackageInfo](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-getpackageinfo)
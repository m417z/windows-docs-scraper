# GetCurrentPackagePath function

## Description

Gets the package path for the calling process.

## Parameters

### `pathLength` [in, out]

Type: **UINT32***

On input, the size of the *path* buffer, in characters. On output, the size of the package path returned, in characters, including the null terminator.

### `path` [out, optional]

Type: **PWSTR**

The package path.

## Return value

Type: **LONG**

If the function succeeds it returns **ERROR_SUCCESS**. Otherwise, the function returns an error code. The possible error codes include the following.

| Return code | Description |
| --- | --- |
| **APPMODEL_ERROR_NO_PACKAGE** | The process has no package identity. |
| **ERROR_INSUFFICIENT_BUFFER** | The buffer is not large enough to hold the data. The required size is specified by *pathLength*. |

## See also

[GetCurrentPackagePath2](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-getcurrentpackagepath2)

[GetCurrentPackageFamilyName](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-getcurrentpackagefamilyname)

[GetCurrentPackageFullName](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-getcurrentpackagefullname)

[GetCurrentPackageId](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-getcurrentpackageid)

[GetCurrentPackageInfo](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-getcurrentpackageinfo)

[GetPackagePath](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-getpackagepath)
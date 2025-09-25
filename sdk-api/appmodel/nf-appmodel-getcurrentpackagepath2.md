# GetCurrentPackagePath2 function

## Description

Gets the package path for the calling process, with the option to specify the type of folder path to retrieve for the package.

## Parameters

### `packagePathType`

Type: [**PackagePathType**](https://learn.microsoft.com/windows/win32/api/appmodel/ne-appmodel-packagepathtype)

Indicates the type of folder path to retrieve for the package (the original install folder or the mutable folder).

### `pathLength`

Type: **UINT32***

On input, the size of the *path* buffer, in characters. On output, the size of the package path returned, in characters, including the null terminator.

### `path`

Type: **PWSTR**

The package path.

## Return value

Type: **LONG**

If the function succeeds it returns **ERROR_SUCCESS**. Otherwise, the function returns an error code. The possible error codes include the following.

| Return code | Description |
| --- | --- |
| **APPMODEL_ERROR_NO_PACKAGE** | The process has no package identity. |
| **ERROR_INSUFFICIENT_BUFFER** | The buffer is not large enough to hold the data. The required size is specified by *pathLength*. |

## Remarks

The *packagePathType* parameter is useful for applications that use the [windows.mutablePackageDirectories extension](https://learn.microsoft.com/uwp/schemas/appxpackage/uapmanifestschema/element-desktop6-package-extension) in their package manifest. This extension specifies a folder under the %ProgramFiles%\ModifiableWindowsApps path where the contents of the application's install folder are projected so that users can modify the installation files. This feature is currently available only for certain types of desktop PC games that are published by Microsoft and our partners, and it enables these types of games to support mods.

## See also

[GetCurrentPackagePath](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-getcurrentpackagepath)

[GetCurrentPackageFamilyName](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-getcurrentpackagefamilyname)

[GetCurrentPackageFullName](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-getcurrentpackagefullname)

[GetCurrentPackageId](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-getcurrentpackageid)

[GetCurrentPackageInfo](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-getcurrentpackageinfo)

[GetCurrentPackageInfo2](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-getcurrentpackageinfo2)

[GetPackagePath](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-getpackagepath)
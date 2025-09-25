# GetPackageInfo2 function

## Description

Gets the package information for the specified package, with the option to specify the type of folder path to retrieve for the package.

## Parameters

### `packageInfoReference`

Type: **PACKAGE_INFO_REFERENCE**

A reference to package information.

### `flags`

Type: **const UINT32**

The [package constants](https://learn.microsoft.com/windows/desktop/appxpkg/package-constants) that specify how package information is retrieved.

### `packagePathType`

Type: [**PackagePathType**](https://learn.microsoft.com/windows/win32/api/appmodel/ne-appmodel-packagepathtype)

Indicates the type of folder path to retrieve for the package (the original install folder or the mutable folder).

### `bufferLength`

Type: **UINT32***

On input, the size of *buffer*, in bytes. On output, the size of the package information returned, in bytes.

### `buffer`

Type: **BYTE***

The package information, represented as an array of [PACKAGE_INFO](https://learn.microsoft.com/windows/win32/api/appmodel/ns-appmodel-package_info) structures.

### `count`

Type: **UINT32***

The number of packages in the buffer.

## Return value

Type: **LONG**

If the function succeeds it returns **ERROR_SUCCESS**. Otherwise, the function returns an error code. The possible error codes include the following.

| Return code | Description |
| --- | --- |
| **ERROR_INSUFFICIENT_BUFFER** | The buffer is not large enough to hold the data. The required size is specified by *bufferLength*. |

## Remarks

The *packagePathType* parameter is useful for applications that use the [windows.mutablePackageDirectories extension](https://learn.microsoft.com/uwp/schemas/appxpackage/uapmanifestschema/element-desktop6-package-extension) in their package manifest. This extension specifies a folder under the %ProgramFiles%\ModifiableWindowsApps path where the contents of the application's install folder are projected so that users can modify the installation files. This feature is currently available only for certain types of desktop PC games that are published by Microsoft and our partners, and it enables these types of games to support mods.

## See also

[GetPackageInfo](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-getpackageinfo)

[GetCurrentPackageInfo2](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-getcurrentpackageinfo2)

[ClosePackageInfo](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-closepackageinfo)

[GetCurrentPackageInfo](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-getcurrentpackageinfo)

[GetPackagePath](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-getpackagepath)

[OpenPackageInfoByFullName](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-openpackageinfobyfullname)
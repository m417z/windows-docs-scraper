# GetStagedPackagePathByFullName2 function

## Description

Gets the path of the specified staged package, with the option to specify the type of folder path to retrieve for the package.

## Parameters

### `packageFullName`

Type: **PCWSTR**

The full name of the staged package.

### `packagePathType`

Type: [**PackagePathType**](https://learn.microsoft.com/windows/win32/api/appmodel/ne-appmodel-packagepathtype)

Indicates the type of folder path to retrieve for the package (the original install folder or the mutable folder).

### `pathLength`

Type: **UINT32***

A pointer to a variable that holds the number of characters (**WCHAR**s) in the package path string, which includes the null-terminator.

First you pass **NULL** to *path* to get the number of characters. You use this number to allocate memory space for *path*. Then you pass the address of this memory space to fill *path*.

### `path`

Type: **PWSTR**

A pointer to memory space that receives the package path string, which includes the null-terminator.

## Return value

Type: **LONG**

If the function succeeds it returns **ERROR_SUCCESS**. Otherwise, the function returns an error code. The possible error codes include the following.

| Return code | Description |
| --- | --- |
| **ERROR_INSUFFICIENT_BUFFER** | The buffer specified by *path* is not large enough to hold the data. The required size is specified by *pathLength*. |

## Remarks

The *packagePathType* parameter is useful for applications that use the [windows.mutablePackageDirectories extension](https://learn.microsoft.com/uwp/schemas/appxpackage/uapmanifestschema/element-desktop6-package-extension) in their package manifest. This extension specifies a folder under the %ProgramFiles%\ModifiableWindowsApps path where the contents of the application's install folder are projected so that users can modify the installation files. This feature is currently available only for certain types of desktop PC games that are published by Microsoft and our partners, and it enables these types of games to support mods.

## See also

[GetStagedPackagePathByFullName](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-getstagedpackagepathbyfullname)
# GetCurrentPackageInfo3 function (appmodel.h)

Retrieves the package graph's current generation ID.

See **Remarks** for info about how to call the function.

## Parameters

`flags`

Type: **const UINT32**

The [package constants](https://learn.microsoft.com/windows/desktop/appxpkg/package-constants) that specify how package information is retrieved. The **PACKAGE_FILTER_\*** flags are supported.

`packageInfoType`

Type: **PackageInfo3Type**

```cpp
enum PackageInfo3Type
{
	PackageInfo3Type_PackageInfoGeneration = 16,
} PackageInfoType;
```

Declare **PackageInfo3Type** as shown above, and pass **PackageInfo3Type::PackageInfo3Type_PackageInfoGeneration**.

`bufferLength`

Type: **UINT32\***

On input, the size of *buffer*, in bytes. On output, the size of the array of structures returned, in bytes.

`buffer`

Type: **BYTE\***

The package graph's current generation ID, represented as an array of [PACKAGE_INFO](https://learn.microsoft.com/windows/win32/api/appmodel/ns-appmodel-package_info) structures.

`count`

Type: **UINT32\***

The number of structures in the buffer.

## Return value

Type: **LONG**

If the function succeeds it returns **ERROR_SUCCESS**. Otherwise, the function returns an error code. The possible error codes include the following.

|Return code|Description|
|-|-|
|**APPMODEL_ERROR_NO_PACKAGE**|The process has no package identity.|
|**ERROR_INSUFFICIENT_BUFFER**|The buffer is not large enough to hold the data. The required size is specified by *bufferLength*.|

## Remarks

This function does not have an associated header file or library file. Your application can call [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) with the DLL name (`Kernelbase.dll`) to obtain a module handle. It can then call [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) with the module handle and the name of this function to get the function address.

## Requirements

|   |   |
| ---- |:---- |
| **Minimum supported client** | Windows 10 [desktop apps only] |
| **Minimum supported server** | Windows Server 2016 [desktop apps only] |
| **Target Platform** | Windows |
| **Header** | None |
| **Library** | None |
| **DLL** | Kernelbase.dll |

## See also

* [GetCurrentPackageInfo](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-getcurrentpackageinfo)
* [GetCurrentPackageFamilyName](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-getcurrentpackagefamilyname)
* [GetCurrentPackageFullName](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-getcurrentpackagefullname)
* [GetCurrentPackageId](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-getcurrentpackageid)
* [GetCurrentPackagePath](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-getcurrentpackagepath)
* [GetPackageInfo](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-getpackageinfo)
* [GetPackageInfo2](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-getpackageinfo2)
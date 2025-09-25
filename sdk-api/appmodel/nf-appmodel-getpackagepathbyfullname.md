# GetPackagePathByFullName function

## Description

Gets the path of the specified package.

## Parameters

### `packageFullName` [in]

Type: **PCWSTR**

The full name of the package.

### `pathLength` [in, out]

Type: **UINT32***

A pointer to a variable that holds the number of characters (**WCHAR**s) in the package path string, which includes the null-terminator.

First you pass **NULL** to *path* to get the number of characters. You use this number to allocate memory space for *path*. Then you pass the address of this memory space to fill *path*.

### `path` [out, optional]

Type: **PWSTR**

A pointer to memory space that receives the package path string, which includes the null-terminator.

## Return value

Type: **LONG**

If the function succeeds it returns **ERROR_SUCCESS**. Otherwise, the function returns an error code. The possible error codes include the following.

| Return code | Description |
| --- | --- |
| **ERROR_INSUFFICIENT_BUFFER** | The buffer specified by *path* is not large enough to hold the data. The required size is specified by *pathLength*. |

## See also

[GetPackagePathByFullName2](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-getpackagepathbyfullname2)
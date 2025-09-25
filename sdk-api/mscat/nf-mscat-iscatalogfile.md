# IsCatalogFile function

## Description

[The **IsCatalogFile** function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **IsCatalogFile** function retrieves a Boolean value that indicates whether the specified file is a catalog file.

**Note** This function has no associated import library. You must use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Wintrust.dll.

## Parameters

### `hFile` [in, optional]

A handle to the file to check. This parameter is optional, but it must contain a valid handle if the *pwszFileName* parameter is **NULL**.

### `pwszFileName` [in, optional]

A pointer to a null-terminated wide character string that contains the name of the file to check. This parameter is optional, but it must contain a valid file name if the *hFile* parameter is **NULL**.

## Return value

Returns nonzero if the specified file is a catalog file or zero otherwise.
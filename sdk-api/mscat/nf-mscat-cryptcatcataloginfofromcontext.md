# CryptCATCatalogInfoFromContext function

## Description

[The **CryptCATCatalogInfoFromContext** function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **CryptCATCatalogInfoFromContext** function retrieves catalog information from a specified catalog context. This function has no associated import library. You must use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Wintrust.dll.

## Parameters

### `hCatInfo` [in]

A handle to the catalog context. This value cannot be **NULL**.

### `psCatInfo` [in, out]

A pointer to the [CATALOG_INFO](https://learn.microsoft.com/windows/desktop/api/mscat/ns-mscat-catalog_info) structure. This value cannot be **NULL**. Upon return from this function, the *wszCatalogFile* member of the CATALOG_INFO structure contains the catalog file name.

### `dwFlags` [in]

Unused; set to zero.

## Return value

The return value is **TRUE** if the function succeeds; **FALSE** if the function fails.

For extended error information, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function. For a complete list of error codes provided by the operating system, see [System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).
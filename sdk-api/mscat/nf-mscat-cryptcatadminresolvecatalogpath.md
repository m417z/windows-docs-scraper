# CryptCATAdminResolveCatalogPath function

## Description

[The **CryptCATAdminResolveCatalogPath** function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **CryptCATAdminResolveCatalogPath** function retrieves the fully qualified path of the specified catalog.

**Note** This function has no associated import library. You must use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Wintrust.dll.

## Parameters

### `hCatAdmin` [in]

A handle that was previously assigned by the [CryptCATAdminAcquireContext](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatadminacquirecontext) function.

### `pwszCatalogFile` [in]

The name of the catalog file for which to retrieve the fully qualified path.

### `psCatInfo` [in, out]

A pointer to the [CATALOG_INFO](https://learn.microsoft.com/windows/desktop/api/mscat/ns-mscat-catalog_info) structure. This value cannot be **NULL**. Upon return from this function, the *wszCatalogFile* member of the **CATALOG_INFO** structure contains the catalog file name.

### `dwFlags` [in]

This parameter is reserved and must be set to zero.

## Return value

Returns nonzero if successful or zero otherwise.

For extended error information, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function. For a complete list of error codes provided by the operating system, see [System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).
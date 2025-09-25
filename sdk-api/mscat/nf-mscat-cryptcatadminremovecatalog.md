# CryptCATAdminRemoveCatalog function

## Description

[The **CryptCATAdminRemoveCatalog** function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **CryptCATAdminRemoveCatalog** function deletes a catalog file and removes that catalog's entry from the Windows catalog database. This function is the only supported way to remove catalogs from the database while ensuring the integrity of the database. The function has no associated import library. You must use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Wintrust.dll.

## Parameters

### `hCatAdmin` [in]

Handle previously assigned by the [CryptCATAdminAcquireContext](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatadminacquirecontext) function.

### `pwszCatalogFile` [in]

A pointer to a null-terminated string for the name of the catalog to remove. This string must contain only the name, without any path information.

### `dwFlags` [in]

This parameter is reserved for future use and must be set to zero.

## Return value

The return value is **TRUE** if the function succeeds; **FALSE** if the function fails.

For extended error information, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function. For a complete list of error codes provided by the operating system, see [System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## See also

[CryptCATAdminAddCatalog](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatadminaddcatalog)
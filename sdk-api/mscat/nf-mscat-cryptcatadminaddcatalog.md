# CryptCATAdminAddCatalog function

## Description

[The **CryptCATAdminAddCatalog** function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **CryptCATAdminAddCatalog** function adds a catalog to the catalog database. The catalog database is an index that associates file hashes with the catalogs that contain them. It is used to speed the identification of the catalogs when verifying the file signature. This function is the only supported way to programmatically add catalogs to the Windows catalog database. The function has no associated import library. You must use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Wintrust.dll.

## Parameters

### `hCatAdmin` [in]

Handle previously assigned by the [CryptCATAdminAcquireContext](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatadminacquirecontext) function.

### `pwszCatalogFile` [in]

A pointer to a **null**-terminated string for the fully qualified path of the catalog to be added.

### `pwszSelectBaseName` [in]

A pointer to a **null**-terminated string for the name of the catalog when it is stored. If the parameter is **NULL**, then a unique name will be generated for the catalog.

### `dwFlags` [in]

If the CRYPTCAT_ADDCATALOG_HARDLINK (0x00000001) flag is specified, the catalog specified in the call will be hard-linked to rather than copied. Hard-linking instead of copying a catalog reduces the amount of disk space required by Windows.

## Return value

If the function succeeds, the return value is a handle to the catalog information context. If the function fails, the return value is **NULL**. After you have finished using the returned handle, free it by calling the [CryptCATAdminReleaseCatalogContext](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatadminreleasecatalogcontext) function.

For extended error information, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function. For a complete list of error codes provided by the operating system, see [System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## See also

[CryptCATAdminAcquireContext](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatadminacquirecontext)

[CryptCATAdminReleaseCatalogContext](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatadminreleasecatalogcontext)
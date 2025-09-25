# CryptCATAdminReleaseCatalogContext function

## Description

[The **CryptCATAdminReleaseCatalogContext** function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **CryptCATAdminReleaseCatalogContext** function releases a handle to a catalog context previously returned by the [CryptCATAdminAddCatalog](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatadminaddcatalog) function. This function has no associated import library. You must use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Wintrust.dll.

## Parameters

### `hCatAdmin` [in]

Valid handle previously assigned by the [CryptCATAdminAcquireContext](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatadminacquirecontext) function.

### `hCatInfo` [in]

Valid handle previously assigned by the [CryptCATAdminAddCatalog](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatadminaddcatalog) function or the [CryptCATAdminEnumCatalogFromHash](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatadminenumcatalogfromhash) function.

### `dwFlags` [in]

This parameter is reserved for future use and must be set to zero.

## Return value

The return value is **TRUE** if the function succeeds; **FALSE** if the function fails.

## See also

[CryptCATAdminAddCatalog](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatadminaddcatalog)
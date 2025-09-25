# CryptCATAdminAcquireContext function

## Description

[The **CryptCATAdminAcquireContext** function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **CryptCATAdminAcquireContext** function acquires a handle to a catalog administrator context. This handle can be used by subsequent calls to the [CryptCATAdminAddCatalog](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatadminaddcatalog), [CryptCATAdminEnumCatalogFromHash](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatadminenumcatalogfromhash), and [CryptCATAdminRemoveCatalog](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatadminremovecatalog) functions. This function has no associated import library. You must use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Wintrust.dll.

## Parameters

### `phCatAdmin` [out]

A pointer to the catalog administrator context handle that is assigned by this function. When you have finished using the handle, close it by calling the [CryptCATAdminReleaseContext](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatadminreleasecontext) function.

### `pgSubsystem` [in]

A pointer to the GUID that identifies the subsystem. DRIVER_ACTION_VERIFY represents the subsystem for operating system components and third party drivers. This is the subsystem used by most implementations.

### `dwFlags` [in]

Not used; set to zero.

## Return value

The return value is **TRUE** if the function succeeds; **FALSE** if the function fails.

For extended error information, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function. For a complete list of error codes provided by the operating system, see [System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## See also

[CryptCATAdminAddCatalog](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatadminaddcatalog)

[CryptCATAdminReleaseContext](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatadminreleasecontext)

[CryptCATAdminRemoveCatalog](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatadminremovecatalog)
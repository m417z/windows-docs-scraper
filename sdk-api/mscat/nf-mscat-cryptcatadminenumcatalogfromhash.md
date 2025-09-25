# CryptCATAdminEnumCatalogFromHash function

## Description

[The **CryptCATAdminEnumCatalogFromHash** function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **CryptCATAdminEnumCatalogFromHash** function enumerates the catalogs that contain a specified hash. The hash is typically returned from the [CryptCATAdminCalcHashFromFileHandle](https://docs.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatadmincalchashfromfilehandle) function. After the final call to this function, call [CryptCATAdminReleaseCatalogContext](https://docs.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatadminreleasecatalogcontext) to release allocated memory.

## Parameters

### `hCatAdmin` [in]

A handle to a catalog administrator context previously assigned by the [CryptCATAdminAcquireContext](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatadminacquirecontext) function.

### `pbHash` [in]

A pointer to the buffer that contains the hash retrieved by calling [CryptCATAdminCalcHashFromFileHandle](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatadmincalchashfromfilehandle).

### `cbHash` [in]

Number of bytes in the buffer allocated for *pbHash*.

### `dwFlags` [in]

This parameter is reserved for future use and must be set to zero.

### `phPrevCatInfo` [in]

A pointer to the handle to the previous catalog context or **NULL**. To get the first catalog that contains the hash, or to start an enumeration of all catalogs, pass **NULL** for this parameter. To continue the enumeration, pass the previous call's return value until no more catalogs are found.

## Return value

The return value is a handle to the catalog context, or **NULL** if there are no more catalogs to enumerate.
**Note:** The type HCATINFO is simply a typedef for HANDLE, which makes it easy to accidentally use the HCATINFO in the wrong context. In particular, this is NOT the same as a HANDLE returned from **CryptCATOpen**, even though the compiler will not prevent you from using the HCATINFO in any function that expects a catalog handle. To acquire a catalog handle from this function, first call [**CryptCATCatalogInfoFromContext**](https://learn.microsoft.com/windows/win32/api/mscat/nf-mscat-cryptcatcataloginfofromcontext) to get the filename of the catalog, and then call [**CryptCATOpen**](https://learn.microsoft.com/windows/win32/api/mscat/nf-mscat-cryptcatopen) with that filename.

For extended error information, call the [GetLastError](https://docs.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function. For a complete list of error codes provided by the operating system, see [System Error Codes](https://docs.microsoft.com/windows/desktop/Debug/system-error-codes).

**Note:** The function returns a value of type **HCATINFO**, but this is simply a typedef for **HANDLE**. Because of this, it is easy to accidentally use the **HCATINFO** when calling a function that expects a different kind of **HANDLE**. In particular, this is not the same as a **HANDLE** returned from **CryptCATOpen**, even though the compiler will not prevent you from using the **HCATINFO** in any function that expects a catalog handle.
To acquire a catalog handle from this function, first call [CryptCATCatalogInfoFromContext](https://learn.microsoft.com/windows/win32/api/mscat/nf-mscat-cryptcatcataloginfofromcontext) to get the filename of the catalog, and then call [CryptCATOpen](https://learn.microsoft.com/windows/win32/api/mscat/nf-mscat-cryptcatopen) with that filename to open the catalog.
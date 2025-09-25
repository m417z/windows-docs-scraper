# CryptCATAdminAcquireContext2 function

## Description

The **CryptCATAdminAcquireContext2** function acquires a handle to a catalog administrator context for a given hash algorithm and hash policy.

 You can use this handle in subsequent calls to the following functions:

* [CryptCATAdminAddCatalog](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatadminaddcatalog)
* [CryptCATAdminEnumCatalogFromHash](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatadminenumcatalogfromhash)
* [CryptCATAdminRemoveCatalog](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatadminremovecatalog)

This function has no associated import library. You must use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Wintrust.dll.

## Parameters

### `phCatAdmin` [out]

A pointer to the catalog administrator context handle that is assigned by this function. When you have finished using the handle, close it by calling the [CryptCATAdminReleaseContext](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatadminreleasecontext) function.

### `pgSubsystem` [in, optional]

A pointer to the **GUID** that identifies the subsystem. DRIVER_ACTION_VERIFY represents the subsystem for operating system components and third party drivers. This is the subsystem used by most implementations.

### `pwszHashAlgorithm` [in, optional]

Optional null-terminated Unicode string that specifies the name of the hash algorithm to use when calculating and verifying hashes. This value can be **NULL**. If it is **NULL**, the default hashing algorithm may be chosen, depending on the value you set for the *pStrongHashPolicy* parameter. The default algorithm in Windows 8 is SHA1. The default may change in future Windows versions. For more information, see Remarks.

### `pStrongHashPolicy` [in, optional]

Pointer to a [CERT_STRONG_SIGN_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_strong_sign_para) structure that contains the parameters used to check for strong signatures. The function chooses the lowest common hashing algorithm that satisfies the specified policy and the algorithm specified by the *pwszHashAlgorithm* parameter or the system default algorithm (if no algorithm is specified).

### `dwFlags`

Reserved. This value must be zero.

## Return value

If the function succeeds, the return value is nonzero (**TRUE**).

If the function fails, the return value is zero (**FALSE**). For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following table lists the error codes most commonly returned by the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The *phCatAdmin* parameter cannot be **NULL**.<br><br>The *dwFlags* parameter must be zero (0). |
| **ERROR_NOT_ENOUGH_MEMORY** | There was insufficient memory to create a new catalog administrator object. |
| **NTE_BAD_ALGID** | The hash algorithm specified by the *pwszHashAlgorithm* parameter cannot be found. |

## Remarks

This function enables you to choose, or chooses for you, the hash algorithm to be used in functions that require the catalog administrator context. Although you can set the name of the hashing algorithm, we recommend that you let the function determine the algorithm. Doing so protects your application from hard coding algorithms that may become untrusted in the future.

## See also

[CryptCATAdminAddCatalog](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatadminaddcatalog)

[CryptCATAdminReleaseContext](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatadminreleasecontext)

[CryptCATAdminRemoveCatalog](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatadminremovecatalog)
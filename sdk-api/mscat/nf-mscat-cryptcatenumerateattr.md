# CryptCATEnumerateAttr function

## Description

[The **CryptCATEnumerateAttr** function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **CryptCATEnumerateAttr** function enumerates the attributes associated with a member of a catalog. This function has no associated import library. You must use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Wintrust.dll.

## Parameters

### `hCatalog` [in]

Handle for the catalog that contains the member identified by *pCatMember*. This value cannot be **NULL**.

### `pCatMember` [in]

A pointer to the [CRYPTCATMEMBER](https://learn.microsoft.com/windows/desktop/api/mscat/ns-mscat-cryptcatmember) structure that identifies which member of the catalog is being enumerated.

### `pPrevAttr` [in]

A pointer to the previously returned value from this function or pointer to **NULL** to start the enumeration.

## Return value

The return value is a pointer to the CRYPTCATATTRIBUTE structure that contains the attribute information or **NULL**, if no more attributes are in the enumeration or if an error is encountered. The returned pointer is passed in as the *pPrevAttr* parameter for subsequent calls to this function.

## Remarks

Do not free the returned pointer nor any of the members pointed to by the returned pointer.

## See also

[CryptCATEnumerateCatAttr](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatenumeratecatattr)
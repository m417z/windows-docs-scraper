# CryptCATGetMemberInfo function

## Description

[The **CryptCATGetMemberInfo** function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **CryptCATGetMemberInfo** function retrieves member information from the catalog's PKCS #7. In addition to retrieving the member information for a specified reference tag, this function opens a member context. This function has no associated import library. You must use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Wintrust.dll.

## Parameters

### `hCatalog` [in]

A handle to the catalog. This parameter cannot be **NULL**.

### `pwszReferenceTag` [in]

A pointer to a **null**-terminated string that represents the reference tag for the member information being retrieved.

## Return value

A pointer to the [CRYPTCATMEMBER](https://learn.microsoft.com/windows/desktop/api/mscat/ns-mscat-cryptcatmember) structure that contains the member information or **NULL**, if no information can be found.

## Remarks

Do not free the returned pointer nor any of the members pointed to by the returned pointer.
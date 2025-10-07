# PStoreEnumProviders function

\[Protected Storage (Pstore) is available for use in Windows Server 2003 and Windows XP. It is only available for read-only operations in Windows Server 2008 and Windows Vista, but may be unavailable in subsequent versions. Pstore uses an older implementation of data protection. Developers are strongly encouraged to take advantage of the stronger data protection provided by the [**CryptProtectData**](https://learn.microsoft.com/windows/win32/api/dpapi/nf-dpapi-cryptprotectdata) and [**CryptUnprotectData**](https://learn.microsoft.com/windows/win32/api/dpapi/nf-dpapi-cryptunprotectdata) functions.\]

Gets an enumerator object that can be used in turn to enumerate the protected storage providers that are currently installed on the system.

## Parameters

*dwFlags*

This parameter is not used and must be zero.

*ppenum*

A pointer to a pointer to an [**IEnumPStoreProviders**](https://learn.microsoft.com/windows/win32/devnotes/ienumpstoreproviders) interface that can be used to enumerate installed providers.

## Return value

This function returns an **HRESULT**.

## Remarks

The protected storage component has a provider-based architecture. Applications that make use of protected storage can specify which of the installed providers to use when storing and retrieving their data.

The **PStoreEnumProviders** function is used to enumerate the installed protected storage providers. Each provider is identified by a globally unique identifier (GUID).

Up to this time, only one protected storage provider has ever been written. Given that the protected storage service is currently deprecated, it is very unlikely that any additional providers will ever be produced. As a result, this function should not be used for any purpose.

This function has no associated import library; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | Pstore.h |
| DLL<br> | Pstorec.dll |

## See also

[**IEnumPStoreProviders**](https://learn.microsoft.com/windows/win32/devnotes/ienumpstoreproviders)


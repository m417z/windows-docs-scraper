# FreeCryptProvFromCert function

> [!IMPORTANT]
> This API is deprecated. Microsoft may remove this API in future releases.

The **FreeCryptProvFromCert** function releases the handle to a [*cryptographic service provider*](https://learn.microsoft.com/windows/win32/secgloss/c-gly) (CSP) and optionally deletes the temporary container created by the [**GetCryptProvFromCert**](https://learn.microsoft.com/windows/win32/seccrypto/getcryptprovfromcert) function.

> [!Note]
> This function has no associated header file or import library. To call this function, you must create a user-defined header file and use the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Mssign32.dll.

## Parameters

*fAcquired* \[in\]

A value that specifies whether the provider handle was acquired from the [*certificate*](https://learn.microsoft.com/windows/win32/secgloss/c-gly).

*hProv* \[in\]

A pointer to an [**HCRYPTPROV**](https://learn.microsoft.com/windows/win32/seccrypto/hcryptprov) structure for the CSP.

*pwszCapiProvider* \[in, optional\]

A pointer to a null-terminated string for the provider name.

*dwProviderType* \[in\]

Specifies the CSP type. This can be zero or one of the [Cryptographic Provider Types](https://learn.microsoft.com/windows/win32/seccrypto/cryptographic-provider-types). If this member is zero, the key container is one of the CNG key storage providers.

*pwszTmpContainer* \[in, optional\]

A pointer to a null-terminated string for the name of the temporary key container.

## Return value

This function does not return a value.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| DLL<br> | Mssign32.dll |


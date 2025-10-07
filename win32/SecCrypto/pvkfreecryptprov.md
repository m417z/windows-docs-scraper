# PvkFreeCryptProv function

> [!IMPORTANT]
> This API is deprecated. Microsoft may remove this API in future releases.

The **PvkFreeCryptProv** function releases the handle to a [*cryptographic service provider*](https://learn.microsoft.com/windows/win32/secgloss/c-gly) (CSP) and optionally deletes the temporary container created by the [**PvkGetCryptProv**](https://learn.microsoft.com/windows/win32/seccrypto/pvkgetcryptprov) function.

> [!Note]
> This function has no associated header file or import library. To call this function, you must create a user-defined header file and use the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Mssign32.dll.

## Parameters

*hProv* \[in\]

A handle to the CSP.

*pwszCapiProvider* \[in\]

A pointer to a null-terminated string for the CSP name.

*dwProviderType* \[in\]

A **DWORD** value that represents the cryptographic provider type. For more information, see [Cryptographic Provider Types](https://learn.microsoft.com/windows/win32/seccrypto/cryptographic-provider-types).

*pwszTmpContainer* \[in, optional\]

A pointer to a null-terminated string for the temporary key container name.

## Return value

This function does not return a value.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| DLL<br> | Mssign32.dll |


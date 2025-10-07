# PvkGetCryptProv function

> [!IMPORTANT]
> This API is deprecated. Microsoft may remove this API in future releases.

The **PvkGetCryptProv** function gets a handle to a [*cryptographic service provider*](https://learn.microsoft.com/windows/win32/secgloss/c-gly) (CSP) based on either a [*private key*](https://learn.microsoft.com/windows/win32/secgloss/p-gly) file or a key container name.

> [!Note]
> This function has no associated header file or import library. To call this function, you must create a user-defined header file and use the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Mssign32.dll.

## Parameters

*hwnd* \[in\]

If a password is required to decrypt the private key file, this parameter is a handle to the parent of the password dialog box; otherwise, it is **NULL**.

*pwszCaption* \[in\]

A pointer to a null-terminated string for the dialog box caption.

*pwszCapiProvider* \[in\]

A pointer to a null-terminated string for the CSP name.

*dwProviderType* \[in\]

A **DWORD** value that represents the cryptographic provider type. For more information, see [Cryptographic Provider Types](https://learn.microsoft.com/windows/win32/seccrypto/cryptographic-provider-types).

*pwszPvkFile* \[in\]

A pointer to a null-terminated string that contains the name of a private key file.

*pwszKeyContainerName* \[in\]

A pointer to a null-terminated string for the private key container name.

*pdwKeySpec* \[out\]

A pointer to a **DWORD** value for the type of key of the container returned with *phCryptProv* and *ppwszTmpContainer*.

*ppwszTmpContainer* \[out, optional\]

The address of a pointer to a null-terminated string for the temporary key container name. The **PvkGetCryptProv** function provides and initializes the temporary container. When calling **PvkGetCryptProv**, the address should point to a **NULL** value.

*phCryptProv* \[out\]

A pointer to a handle for the CSP.

## Return value

If the method succeeds, it returns **S\_OK**.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/win32/seccrypto/common-hresult-values).

## Remarks

The **PvkGetCryptProv** function first tries to get the provider handle from the key container name specified by the *pwszKeyContainerName* parameter. If you pass **NULL** for the *pwszKeyContainerName* parameter, **PvkGetCryptProv** tries to get the provider from the private key file specified in the *pwszPvkFile* parameter.

When you have finished using the CSP, free the provider handle and temporary key container by calling the [**PvkFreeCryptProv**](https://learn.microsoft.com/windows/win32/seccrypto/pvkfreecryptprov) function.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| DLL<br> | Mssign32.dll |


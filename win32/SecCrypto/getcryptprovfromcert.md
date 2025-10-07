# GetCryptProvFromCert function

> [!IMPORTANT]
> This API is deprecated. Microsoft may remove this API in future releases.

The **GetCryptProvFromCert** function gets a handle to a [*cryptographic service provider*](https://learn.microsoft.com/windows/win32/secgloss/c-gly) (CSP) and a key specification for a [*certificate*](https://learn.microsoft.com/windows/win32/secgloss/c-gly) context. Use this function to get access to the [*private key*](https://learn.microsoft.com/windows/win32/secgloss/p-gly) of the certificate issuer.

> [!Note]
> This function has no associated header file or import library. To call this function, you must create a user-defined header file and use the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Mssign32.dll.

## Parameters

*hwnd* \[in\]

The handle of the window to use as the owner of any dialog boxes that are displayed. This member is not currently used and is ignored. It is safe to pass **NULL** for this parameter.

*pCert* \[in\]

A pointer to a [**CERT\_CONTEXT**](https://learn.microsoft.com/windows/desktop/api/Wincrypt/ns-wincrypt-cert_context) structure for the certificate.

*phCryptProv* \[out\]

A pointer to an [**HCRYPTPROV**](https://learn.microsoft.com/windows/win32/seccrypto/hcryptprov) structure that is a handle to the CSP.

*pdwKeySpec* \[out\]

The specification of the private key to retrieve. Possible values include **AT\_KEYEXCHANGE** or **AT\_SIGNATURE**.

*pfDidCryptAcquire* \[in\]

A value that specifies whether the function acquired the provider handle based on the certificate.

*ppwszTmpContainer* \[out, optional\]

The address of a pointer to a null-terminated string for the temporary key container name. The **GetCryptProvFromCert** function provides and initializes the temporary container. When calling **GetCryptProvFromCert**, the address should point to a **NULL** value.

*ppwszProviderName* \[out, optional\]

The address of a pointer to a null-terminated string for the provider name. The **GetCryptProvFromCert** function returns the provider name. When calling **GetCryptProvFromCert**, the address should point to a **NULL** value.

*pdwProviderType* \[out\]

Specifies the CSP type. This can be zero or one of the [Cryptographic Provider Types](https://learn.microsoft.com/windows/win32/seccrypto/cryptographic-provider-types). If this member is zero, the key container is one of the CNG key storage providers.

## Return value

Upon success, this function returns **TRUE**. The **GetCryptProvFromCert** function returns **FALSE** if it fails.

## Remarks

The [MakeCert](https://learn.microsoft.com/windows/win32/seccrypto/makecert) tool calls **GetCryptProvFromCert** when you invoke it by using the **-is** command line option.

If the *pfDidCryptAcquire* parameter is set to **TRUE**, the function sets *phCryptProv*, *pdwKeySpec*, and *pdwProviderType* parameters to the provider values.

When you have finished using the CSP, free it by calling the [**FreeCryptProvFromCert**](https://learn.microsoft.com/windows/win32/seccrypto/freecryptprovfromcert) function.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| DLL<br> | Mssign32.dll |


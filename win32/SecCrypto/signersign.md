# SignerSign function

The **SignerSign** function signs the specified file.

> [!Note]
> This function has no associated header file or import library. To call this function, you must create a user-defined header file and use the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Mssign32.dll.

## Parameters

*pSubjectInfo* \[in\]

A pointer to a [**SIGNER\_SUBJECT\_INFO**](https://learn.microsoft.com/windows/win32/seccrypto/signer-subject-info) structure that specifies the subject to sign.

*pSignerCert* \[in\]

A pointer to a [**SIGNER\_CERT**](https://learn.microsoft.com/windows/win32/seccrypto/signer-cert) structure that specifies the certificate to use to create the digital signature.

*pSignatureInfo* \[in\]

A pointer to a [**SIGNER\_SIGNATURE\_INFO**](https://learn.microsoft.com/windows/win32/seccrypto/signer-signature-info) structure that contains information about the digital signature.

*pProviderInfo* \[in, optional\]

A pointer to a [**SIGNER\_PROVIDER\_INFO**](https://learn.microsoft.com/windows/win32/seccrypto/signer-provider-info) structure that specifies the [*cryptographic service provider*](https://learn.microsoft.com/windows/win32/secgloss/c-gly) (CSP) and [*private key*](https://learn.microsoft.com/windows/win32/secgloss/p-gly) information used to create the digital signature.

If the value of this parameter is **NULL**, the value of the *pSignerCert* parameter must specify a certificate that is associated with a CSP.

*pwszHttpTimeStamp* \[in, optional\]

The URL of a time stamp server.

*psRequest* \[in, optional\]

A pointer to an array of [**CRYPT\_ATTRIBUTE**](https://learn.microsoft.com/windows/desktop/api/Wincrypt/ns-wincrypt-crypt_attribute) structures that are added to a sign request. This parameter is ignored if the *pwszHttpTimeStamp* parameter does not contain a valid value that is not **NULL**.

*pSipData* \[in, optional\]

A 32-bit value that is passed as additional data to SIP functions. The format and content of this is defined by the SIP provider.

## Return value

If the function succeeds, the function returns S\_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/win32/seccrypto/common-hresult-values).

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| DLL<br> | Mssign32.dll |

## See also

[**SignerSignEx**](https://learn.microsoft.com/windows/win32/seccrypto/signersignex)


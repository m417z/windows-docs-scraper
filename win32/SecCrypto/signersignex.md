# SignerSignEx function

The **SignerSignEx** function signs the specified file and returns a pointer to the signed data.

> [!Note]
> This function has no associated header file or import library. To call this function, you must create a user-defined header file and use the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Mssign32.dll.

## Parameters

*dwFlags* \[in\]

Modifies the behavior of this function.

If the file to be signed is a portable executable (PE) file, this can be zero or a combination of one or more of the following values. These identifiers are defined in Mssip.h.

| Value | Meaning |
|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **SPC\_EXC\_PE\_PAGE\_HASHES\_FLAG**

0x10 | Exclude page hashes when creating SIP indirect data for the PE file. This flag takes precedence over the **SPC\_INC\_PE\_PAGE\_HASHES\_FLAG** flag.\ If neither the **SPC\_EXC\_PE\_PAGE\_HASHES\_FLAG** or the **SPC\_INC\_PE\_PAGE\_HASHES\_FLAG** flag is specified, the value set with the [**WintrustSetDefaultIncludePEPageHashes**](https://learn.microsoft.com/windows/desktop/api/Wintrust/nf-wintrust-wintrustsetdefaultincludepepagehashes) function is used for this setting. The default for this setting is to exclude page hashes when creating SIP indirect data for PE files.\ **Windows Server 2003 and Windows XP:** This value is not supported.\ | | **SPC\_INC\_PE\_IMPORT\_ADDR\_TABLE\_FLAG**

0x20 | This value is not supported.\ | | **SPC\_INC\_PE\_DEBUG\_INFO\_FLAG**

0x40 | This value is not supported.\ | | **SPC\_INC\_PE\_RESOURCES\_FLAG**

0x80 | This value is not supported.\ | | **SPC\_INC\_PE\_PAGE\_HASHES\_FLAG**

0x100 | Include page hashes when creating SIP indirect data for the PE file.\ **Windows Server 2003 and Windows XP:** This value is not supported.\ |

*pSubjectInfo* \[in\]

A pointer to a [**SIGNER\_SUBJECT\_INFO**](https://learn.microsoft.com/windows/win32/seccrypto/signer-subject-info) structure that specifies the subject to sign.

*pSignerCert* \[in\]

A pointer to a [**SIGNER\_CERT**](https://learn.microsoft.com/windows/win32/seccrypto/signer-cert) structure that specifies the certificate to use to create the digital signature.

*pSignatureInfo* \[in\]

A pointer to a [**SIGNER\_SIGNATURE\_INFO**](https://learn.microsoft.com/windows/win32/seccrypto/signer-signature-info) structure that contains information about the digital signature.

*pProviderInfo* \[in, optional\]

A pointer to a [**SIGNER\_PROVIDER\_INFO**](https://learn.microsoft.com/windows/win32/seccrypto/signer-provider-info) structure that specifies the [*cryptographic service provider*](https://learn.microsoft.com/windows/win32/secgloss/c-gly) (CSP) and private key information used to create the digital signature.

If the value of this parameter is **NULL**, the value of the *pSignerCert* parameter must specify a certificate that is associated with a CSP.

*pwszHttpTimeStamp* \[in, optional\]

The URL of a time stamp server.

*psRequest* \[in, optional\]

A pointer to an array of [**CRYPT\_ATTRIBUTE**](https://learn.microsoft.com/windows/desktop/api/Wincrypt/ns-wincrypt-crypt_attribute) structures that are added to a sign request. This parameter is ignored if the *pwszHttpTimeStamp* parameter does not contain a valid value that is not **NULL**.

*pSipData* \[in, optional\]

A 32-bit value that is passed as additional data to SIP functions. The format and content of this is defined by the SIP provider.

*ppSignerContext* \[out\]

The address of a pointer to the [**SIGNER\_CONTEXT**](https://learn.microsoft.com/windows/win32/seccrypto/signer-context) structure that contains the signed [*BLOB*](https://learn.microsoft.com/windows/win32/secgloss/b-gly). When you have finished using the **SIGNER\_CONTEXT** structure, free the **SIGNER\_CONTEXT** structure by calling the [**SignerFreeSignerContext**](https://learn.microsoft.com/windows/win32/seccrypto/signerfreesignercontext) function.

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

[**SignerSign**](https://learn.microsoft.com/windows/win32/seccrypto/signersign)

[**SignerFreeSignerContext**](https://learn.microsoft.com/windows/win32/seccrypto/signerfreesignercontext)


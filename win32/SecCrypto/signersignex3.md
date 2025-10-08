# SignerSignEx3 function

The **SignerSignEx3** function signs and time stamps the specified file, allowing multiple nested signatures.

> [!NOTE]
> This function has no associated header file or import library. To call this function, you must create a user-defined header file and use the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Mssign32.dll.

## Parameters

*dwFlags* \[in\]

Modifies the behavior of this function.

If the file to be signed is a portable executable (PE) file, this can be zero or a combination of one or more of the following values.

| Value | Meaning |
|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **SPC\_EXC\_PE\_PAGE\_HASHES\_FLAG**<br>0x10 | Exclude page hashes when creating SIP indirect data for the PE file. This flag takes precedence over the **SPC\_INC\_PE\_PAGE\_HASHES\_FLAG** flag.<br> If neither the **SPC\_EXC\_PE\_PAGE\_HASHES\_FLAG** or the **SPC\_INC\_PE\_PAGE\_HASHES\_FLAG** flag is specified, the value set with the [**WintrustSetDefaultIncludePEPageHashes**](https://learn.microsoft.com/windows/desktop/api/Wintrust/nf-wintrust-wintrustsetdefaultincludepepagehashes) function is used for this setting. The default for this setting is to exclude page hashes when creating SIP indirect data for PE files.<br> This value is defined in the Mssip.h header file.<br> **Windows Server 2003 and Windows XP:** This value is not supported.<br> |
| **SPC\_INC\_PE\_IMPORT\_ADDR\_TABLE\_FLAG**<br>0x20 | This value is not supported.<br> |
| **SPC\_INC\_PE\_DEBUG\_INFO\_FLAG**<br>0x40 | This value is not supported.<br> |
| **SPC\_INC\_PE\_RESOURCES\_FLAG**<br>0x80 | This value is not supported.<br> |
| **SPC\_INC\_PE\_PAGE\_HASHES\_FLAG**<br>0x100 | Include page hashes when creating SIP indirect data for the PE file.<br> **Windows Server 2003 and Windows XP:** This value is not supported.<br> This value is defined in the Mssip.h header file.<br> |
| **SPC\_DIGEST\_SIGN\_FLAG**<br>0x800 | Digest signing will be done.<br> |
| **SIG\_APPEND**<br>0x1000 | The signature will be nested. If you set this flag before any signature has been added, the generated signature will be added as the outer signature. If you do not set this flag, the generated signature replaces the outer signature, deleting all inner signatures.<br> |
| **SPC\_DIGEST\_SIGN\_EX\_FLAG**<br>0x4000 | Digest signing will be done. The caller’s digest signing function will select and return the code signing certificate which performed the signing operation. |

*pSubjectInfo* \[in\]

Pointer to a [**SIGNER\_SUBJECT\_INFO**](https://learn.microsoft.com/windows/win32/seccrypto/signer-subject-info) structure that specifies the subject to sign.

*pSignerCert* \[in\]

Pointer to a [**SIGNER\_CERT**](https://learn.microsoft.com/windows/win32/seccrypto/signer-cert) structure that specifies the certificate to use to create the digital signature.

*pSignatureInfo* \[in\]

A pointer to a [**SIGNER\_SIGNATURE\_INFO**](https://learn.microsoft.com/windows/win32/seccrypto/signer-signature-info) structure that contains information about the digital signature.

*pProviderInfo* \[in, optional\]

Pointer to a [**SIGNER\_PROVIDER\_INFO**](https://learn.microsoft.com/windows/win32/seccrypto/signer-provider-info) structure that specifies the [*cryptographic service provider*](https://learn.microsoft.com/windows/win32/secgloss/c-gly) (CSP) and private key information used to create the digital signature.

If the value of this parameter is **NULL**, the *pSignerCert* parameter must specify a certificate that is associated with a CSP.

*dwTimestampFlags* \[in, optional\]

Flags that will be passed to [**SignerTimeStampEx3**](https://learn.microsoft.com/windows/win32/seccrypto/signertimestampex3) if the *pwszHttpTimeStamp* parameter is not **NULL**. This can be one of the following values.

| Value | Meaning |
|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|----------------------------------------------------------------|
| **SIGNER\_TIMESTAMP\_AUTHENTICODE** | Default value. Specifies an Authenticode timestamp.<br> |
| **SIGNER\_TIMESTAMP\_RFC3161** | Specifies an RFC 3161 timestamp.<br> |

This parameter is ignored if the *pwszHttpTimeStamp* parameter is **NULL**.

*pszTimestampAlgorithmOid* \[in, optional\]

Object identifier of the algorithm to be used for creating an RFC 3161 timestamp. This parameter is ignored for Authenticode time stamps.

*pwszHttpTimeStamp* \[in, optional\]

URL of the time stamp server.

*psRequest* \[in, optional\]

Pointer to an array of [**CRYPT\_ATTRIBUTE**](https://learn.microsoft.com/windows/desktop/api/Wincrypt/ns-wincrypt-crypt_attribute) structures that are added to a sign request. This parameter is ignored if the *pwszHttpTimeStamp* parameter does not contain a valid value or is **NULL**.

*pSipData* \[in, optional\]

A 32-bit value that is passed as additional data to SIP functions. The format and content of this is defined by the SIP provider.

*ppSignerContext* \[out\]

The address of a pointer to the [**SIGNER\_CONTEXT**](https://learn.microsoft.com/windows/win32/seccrypto/signer-context) structure that contains the signed [*BLOB*](https://learn.microsoft.com/windows/win32/secgloss/b-gly). When you have finished using the **SIGNER\_CONTEXT** structure, free the **SIGNER\_CONTEXT** structure by calling the [**SignerFreeSignerContext**](https://learn.microsoft.com/windows/win32/seccrypto/signerfreesignercontext) function.

*pCryptoPolicy* \[in, optional\]

If present, a pointer to a [**CERT\_STRONG\_SIGN\_PARA**](https://learn.microsoft.com/windows/win32/api/Wincrypt/ns-wincrypt-cert_strong_sign_para) structure that contains the parameters used to check for strong signatures. If either a certificate or its chain does not pass, the file is not altered in any way. If a URL is passed in to specify a Time Stamping Authority (TSA), this policy is also applied to the time stamp.

*pDigestSignInfo* \[in, optional\]

If present, a pointer to a [**SIGNER\_DIGEST\_SIGN\_INFO**](https://learn.microsoft.com/windows/win32/seccrypto/signer-digest-sign-info) structure that contains information regarding digest signing.

*pReserved*

Reserved. This value must be **NULL**.

## Return value

If the function succeeds, the function returns S\_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible error codes returned by this function include, but are not limited to, the following. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/win32/seccrypto/common-hresult-values).

| Return code | Description |
|----------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------|
| **E\_INVALIDARG** | If you set the *dwTimestampFlags* parameter to **SIGNER\_TIMESTAMP\_AUTHENTICODE**, you cannot set the *dwFlags* parameter to **SIG\_APPEND**.<br> |

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 10 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2016 \[desktop apps only\]<br> |
| DLL<br> | Mssign32.dll |

## See also

[**SignerSign**](https://learn.microsoft.com/windows/win32/seccrypto/signersign)

[**SignerSignEx**](https://learn.microsoft.com/windows/win32/seccrypto/signersignex)

[**SignerFreeSignerContext**](https://learn.microsoft.com/windows/win32/seccrypto/signerfreesignercontext)

[**SIGNER\_DIGEST\_SIGN\_INFO**](https://learn.microsoft.com/windows/win32/seccrypto/signer-digest-sign-info)
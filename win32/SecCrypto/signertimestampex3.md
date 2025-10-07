# SignerTimeStampEx3 function

The **SignerTimeStampEx3** function time stamps the specified subject and supports setting time stamps on multiple signatures.

> [!Note]
> This function has no associated header file or import library. To call this function, you must create a user-defined header file and use the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Mssign32.dll.

## Parameters

*dwFlags* \[in\]

Flag that specifies the type of time stamp to generate. This parameter can be one of the following values. The values are mutually exclusive.

| Value | Meaning |
|-------|---------|
| **SIGNER_TIMESTAMP_AUTHENTICODE**<br> | Specifies an Authenticode time stamp.<br> **Note:** Authenticode is no longer the preferred type of time stamp. Support for Authenticode time stamps may be removed in the future. We recommend that you use RFC 3161 instead.<br> |
| **SIGNER_TIMESTAMP_RFC3161** | Specifies an RFC 3161–compliant time stamp.<br>
*dwIndex* \[in\]

Specifies the sequence number of the signature to which the timestamp will be added. If this value is zero (0), the outer signature will be time stamped.

*pSubjectInfo* \[in\]

The address of a [**SIGNER\_SUBJECT\_INFO**](https://learn.microsoft.com/windows/win32/seccrypto/signer-subject-info) structure that represents the subject to be time stamped.

*pwszHttpTimeStamp* \[in\]

The address of a null-terminated Unicode string that contains the URL of a time stamp server.

*pszAlgorithmOid* \[in\]

A hash algorithm to be used for performing RFC 3161–compliant time stamps. This parameter is ignored for Authenticode time stamps.

*psRequest* \[in, optional\]

Optional. The address of a [**CRYPT\_ATTRIBUTES**](https://learn.microsoft.com/windows/desktop/api/Wincrypt/ns-wincrypt-crypt_attributes) structure that contains additional attributes that are added to the time stamp request.

This parameter is optional and can be **NULL** if it is not included.

*pSipData* \[in, optional\]

Optional. A 32-bit value that is passed as additional data to [*subject interface package*](https://learn.microsoft.com/windows/win32/secgloss/s-gly) (SIP) functions. The format and content of this parameter is defined by the SIP provider.

This parameter is optional and can be **NULL** if it is not included.

*ppSignerContext* \[out\]

Optional. The address of a pointer to the [**SIGNER\_CONTEXT**](https://learn.microsoft.com/windows/win32/seccrypto/signer-context) structure that contains the signed BLOB. When you have finished using the **SIGNER\_CONTEXT** structure, free it by calling the [**SignerFreeSignerContext**](https://learn.microsoft.com/windows/win32/seccrypto/signerfreesignercontext) function.

*pCryptoPolicy* \[in, optional\]

If present, a pointer to a [**CERT\_STRONG\_SIGN\_PARA**](https://learn.microsoft.com/windows/desktop/api/Wincrypt/ns-wincrypt-cert_strong_sign_para) structure that contains the parameters used to check for strong signatures. The time stamp must pass this cryptographic policy.

*pReserved*

Reserved. This value must be **NULL**.

## Return value

If the function succeeds, the function returns S\_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible error codes returned by this function include, but are not limited to, the following. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/win32/seccrypto/common-hresult-values).

| Return code | Description |
|-------------|-------------|
| **E_INVALIDARG** | This error can be returned for the following conditions:\
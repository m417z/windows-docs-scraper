# SignerTimeStampEx2 function

The **SignerTimeStampEx2** function time stamps the specified subject and optionally returns a pointer to a [**SIGNER\_CONTEXT**](https://learn.microsoft.com/windows/win32/seccrypto/signer-context) structure that contains a pointer to a [*BLOB*](https://learn.microsoft.com/windows/win32/secgloss/b-gly). This function can be used to perform X.509 Public Key Infrastructure, RFC 3161–compliant, time stamps.

> [!Note]
> This function has no associated header file or import library. To call this function, you must create a user-defined header file and use the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Mssign32.dll.

## Parameters

*dwFlags* \[in\]

Value that specifies the type of time stamp to generate. This parameter can be one of the following values. The values are mutually exclusive.

| Value | Meaning |
|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------------------------|
|

**SIGNER\_TIMESTAMP\_AUTHENTICODE**

| Specifies an Authenticode time stamp.<br> |
|

**SIGNER\_TIMESTAMP\_RFC3161**

| Specifies an RFC 3161–compliant time stamp.<br> |

*pSubjectInfo* \[in\]

The address of a [**SIGNER\_SUBJECT\_INFO**](https://learn.microsoft.com/windows/win32/seccrypto/signer-subject-info) structure that represents the subject to be time stamped.

*pwszHttpTimeStamp* \[in\]

The address of a null-terminated Unicode string that contains the URL of a time stamp server.

*dwAlgId* \[in\]

Specifies a hash algorithm to be used for performing RFC 3161–compliant time stamps. This parameter is ignored for Authenticode time stamps.

*psRequest* \[in\]

Optional. The address of a [**CRYPT\_ATTRIBUTES**](https://learn.microsoft.com/windows/desktop/api/Wincrypt/ns-wincrypt-crypt_attributes) structure that contains additional attributes that are added to the time stamp request.

This parameter is optional and can be **NULL** if it is not included.

*pSipData* \[in\]

Optional. A 32-bit value that is passed as additional data to [*subject interface package*](https://learn.microsoft.com/windows/win32/secgloss/s-gly) (SIP) functions. The format and content of this parameter is defined by the SIP provider.

This parameter is optional and can be **NULL** if it is not included.

*ppSignerContext* \[out\]

Optional. The address of a pointer to the [**SIGNER\_CONTEXT**](https://learn.microsoft.com/windows/win32/seccrypto/signer-context) structure that contains the signed BLOB. When you have finished using the **SIGNER\_CONTEXT** structure, free it by calling the [**SignerFreeSignerContext**](https://learn.microsoft.com/windows/win32/seccrypto/signerfreesignercontext) function.

## Return value

If the function succeeds, the function returns S\_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/win32/seccrypto/common-hresult-values).

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 7 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 R2 \[desktop apps only\]<br> |
| DLL<br> | Mssign32.dll |

## See also

[**SignerTimeStamp**](https://learn.microsoft.com/windows/win32/seccrypto/signertimestamp)

[**SignerTimeStampEx**](https://learn.microsoft.com/windows/win32/seccrypto/signertimestampex)


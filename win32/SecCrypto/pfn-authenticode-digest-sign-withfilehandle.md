# PFN\_AUTHENTICODE\_DIGEST\_SIGN\_WITHFILEHANDLE callback function

The **PFN_AUTHENTICODE_DIGST_SIGN_WITHFILEHANDLE** user supplied callback function implements digest signing. You must implement this function as part of your provided dll. This function is currently called by [**SignerSignEx3**](https://learn.microsoft.com/windows/win32/seccrypto/signersignex3) for digest signing.

## Parameters

*pSigningCert* \[in\]

Pointer to a [**CERT_CONTEXT**](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-cert_context) structure that specifies the certificate used to create the digital signature.

*pMetadataBlob* \[in, optional\]

Pointer to a [**CRYPT_DATA_BLOB**](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-crypt_integer_blob) structure that contains metadata for digest signing.

*digestAlgId* \[in\]

Specifies the digest algorithm to be used for digest signing.

*pbToBeSignedDigest* \[in\]

Pointer to a buffer which contains the digest to be signed.

*cbToBeSignedDigest* \[in\]

The size, in bytes, of the pbToBeSignedDigest buffer.

*hFile* \[in\]

Handle to the file being signed.

*pSignedDigest* \[out\]

Pointer to [**CRYPT_DATA_BLOB**](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-crypt_integer_blob) which receives the signed digest.

## Return value

If the function succeeds, the function returns S_OK.
If the function fails, it returns an HRESULT value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/win32/seccrypto/common-hresult-values).

## Remarks

The parameter pSignedDigest->pbData must be allocated by calling HeapAlloc passing the result of GetProcessHeap() as the first parameter.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------|
| Minimum supported client<br> | Windows 11 \[desktop apps only\]<br> |
| DLL<br> | Mssign32.dll<br> |


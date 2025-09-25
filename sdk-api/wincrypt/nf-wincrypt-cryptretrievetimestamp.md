# CryptRetrieveTimeStamp function

## Description

The **CryptRetrieveTimeStamp** function encodes a time stamp request and retrieves the time stamp token from a location specified by a URL to a Time Stamping Authority (TSA).

## Parameters

### `wszUrl` [in]

A pointer to a null-terminated wide character string that contains the URL of the TSA to which to send the request.

### `dwRetrievalFlags`

A set of flags that specify how the time stamp is retrieved.

| Value | Meaning |
| --- | --- |
| **TIMESTAMP_DONT_HASH_DATA**<br><br>0x00000001 | Inhibit hash calculation on the array of bytes pointed to by the *pbData* parameter. |
| **TIMESTAMP_VERIFY_CONTEXT_SIGNATURE**<br><br>0x00000020 | Enforce signature validation on the retrieved time stamp.<br><br>**Note** The **TIMESTAMP_VERIFY_CONTEXT_SIGNATURE** flag is valid only if the **fRequestCerts** member of the [CRYPT_TIMESTAMP_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_timestamp_para) pointed to by the *pPara* parameter is set to **TRUE**. |
| **TIMESTAMP_NO_AUTH_RETRIEVAL**<br><br>0x00020000 | Set this flag to inhibit automatic authentication handling. |

### `dwTimeout`

A **DWORD** value that specifies the maximum number of milliseconds to wait for retrieval. If this parameter is set to zero, this function does not time out.

### `pszHashId` [in]

A pointer to a null-terminated character string that contains the hash algorithm [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID).

### `pPara` [in, optional]

A pointer to a [CRYPT_TIMESTAMP_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_timestamp_para) structure that contains additional parameters for the request.

### `pbData` [in]

A pointer to an array of bytes to be time stamped.

### `cbData`

The size, in bytes, of the array pointed to by the *pbData* parameter.

### `ppTsContext` [out]

A pointer to a [PCRYPT_TIMESTAMP_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_timestamp_context) structure. When you have finished using the context, you must free it by calling the [CryptMemFree](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmemfree) function.

### `ppTsSigner` [out, optional]

A pointer to a [PCERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) that
receives the certificate of the signer.
When you have finished using this structure, you must free it by passing this
pointer to the [CertFreeCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecertificatecontext) function.

Set this parameter to **NULL** if the TSA signer's certificate is not needed.

### `phStore` [out, optional]

The handle of a certificate store initialized with certificates from the time stamp response. This store can be used for validating the signer certificate of the time stamp response.

This parameter can be **NULL** if the TSA supporting certificates are not needed. When you have finished using this handle, release it by passing it to the [CertCloseStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certclosestore) function.

## Return value

If the function is unable to retrieve, decode, and validate the time stamp context, it returns **FALSE**. For extended error information, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## See also

[CryptVerifyTimeStampSignature](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptverifytimestampsignature)
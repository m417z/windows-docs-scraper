# CryptVerifyTimeStampSignature function

## Description

The **CryptVerifyTimeStampSignature** function validates the time stamp signature on a specified array of bytes.

## Parameters

### `pbTSContentInfo` [in]

A pointer to a buffer that contains time stamp content.

### `cbTSContentInfo`

The size, in bytes, of the buffer pointed to by the *pbTSContentInfo* parameter.

### `pbData` [in, optional]

A pointer to an array of bytes on which to validate the time stamp signature.

### `cbData`

The size, in bytes, of the array pointed to by the *pbData* parameter.

### `hAdditionalStore` [in, optional]

The handle of an additional store to search for supporting
Time Stamping Authority (TSA) signing certificates and [certificate trust lists](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CTLs).
This parameter can be **NULL** if no additional store is to be searched.

### `ppTsContext` [out]

A pointer to a [PCRYPT_TIMESTAMP_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_timestamp_context) structure. When you have finished using the context, you must free it by calling the [CryptMemFree](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmemfree) function.

### `ppTsSigner` [out, optional]

A pointer to a [PCERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) that
receives the certificate of the signer.
When you have finished using this structure, you must free it by passing this
pointer to the [CertFreeCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecertificatecontext) function.

Set this parameter to **NULL** if the TSA signer's certificate is not needed.

### `phStore` [out, optional]

A pointer to a handle that receives the certificate store opened on CMS to search for supporting certificates.

This parameter can be **NULL** if the TSA supporting certificates are not needed. When you have finished using this handle, you must release it by passing it to the [CertCloseStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certclosestore) function.

## Return value

If the function succeeds, the function returns **TRUE**. For extended error information, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## Remarks

The caller should validate the **pszTSAPolicyId** member of the [CRYPT_TIMESTAMP_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_timestamp_info) structure when it is returned by the [CryptRetrieveTimeStamp](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptretrievetimestamp) function. If a TSA policy was specified in the request
and the **ftTime** member contains a valid value, the caller should build a certificate context chain with which to populate the *ppTsSigner* parameter and validate the trust.

## See also

[CryptRetrieveTimeStamp](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptretrievetimestamp)
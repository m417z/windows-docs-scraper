# CryptSignAndEncodeCertificate function

## Description

The **CryptSignAndEncodeCertificate** function encodes and signs a certificate, [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL), [certificate trust list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CTL), or [certificate request](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

This function performs the following operations:

* Calls
  [CryptEncodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptencodeobject) using *lpszStructType* to encode the "to be signed" information.
* Calls
  [CryptSignCertificate](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsigncertificate) to sign this encoded information.
* Calls [CryptEncodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptencodeobject) again, with *lpszStructType* set to X509_CERT, to further encode the resulting signed, encoded information.

## Parameters

### `hBCryptKey` [in]

A handle of the [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) to do the signature. This handle is an [HCRYPTPROV](https://learn.microsoft.com/windows/desktop/SecCrypto/hcryptprov) handle that has been created by using the
[CryptAcquireContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecontexta) function or an **NCRYPT_KEY_HANDLE** handle that has been created by using the [NCryptOpenKey](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncryptopenkey) function. New applications should always pass in a **NCRYPT_KEY_HANDLE** handle of a CNG CSP.

### `dwKeySpec` [in]

Identifies the [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) to use from the provider's container. This must be one of the following values. This parameter is ignored if a CNG key is passed in the *hCryptProvOrNCryptKey* parameter.

| Value | Meaning |
| --- | --- |
| **AT_KEYEXCHANGE** | Use the key exchange key. |
| **AT_SIGNATURE** | Use the digital signature key. |

### `dwCertEncodingType` [in]

Specifies the encoding type used. This can be the following value.

| Value | Meaning |
| --- | --- |
| **X509_ASN_ENCODING** | Specifies [X.509](https://learn.microsoft.com/windows/desktop/SecGloss/x-gly) certificate encoding. |

### `lpszStructType` [in]

A pointer to a null-terminated ANSI string that contains the type of data to be encoded and signed. The following predefined *lpszStructType* constants are used with encode operations.

| Value | Meaning |
| --- | --- |
| **X509_CERT_CRL_TO_BE_SIGNED** | *pvStructInfo* is the address of a [CRL_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_info) structure. |
| **X509_CERT_REQUEST_TO_BE_SIGNED** | *pvStructInfo* is the address of a [CERT_REQUEST_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_request_info) structure. |
| **X509_CERT_TO_BE_SIGNED** | *pvStructInfo* is the address of a [CERT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_info) structure. |
| **X509_KEYGEN_REQUEST_TO_BE_SIGNED** | *pvStructInfo* is the address of a [CERT_KEYGEN_REQUEST_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_keygen_request_info) structure. |

### `pvStructInfo` [in]

The address of a structure that contains the data to be signed and encoded. The format of this structure is determined by the *lpszStructType* parameter.

### `pSignatureAlgorithm` [in]

A pointer to a
[CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure that contains the [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) of the signature algorithm and any additional parameters needed. This function uses the following algorithm OIDs:

* szOID_RSA_MD5RSA
* szOID_RSA_SHA1RSA
* szOID_X957_SHA1DSA

If the signature algorithm is a [hash](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) algorithm, the signature contains only the unencrypted hash octets. A private key is not used to encrypt the hash. *dwKeySpec* is not used and *hCryptProvOrNCryptKey* can be **NULL** if an appropriate default CSP can be used for hashing.

### `pvHashAuxInfo` [in]

Reserved. Must be **NULL**.

### `pbEncoded` [out]

A pointer to a buffer to receive the signed and encoded output.

This parameter can be **NULL** to set the size of this information for memory allocation purposes. For more information, see
[Retrieving Data of Unknown Length](https://learn.microsoft.com/windows/desktop/SecCrypto/retrieving-data-of-unknown-length).

### `pcbEncoded` [in, out]

A pointer to a **DWORD** that contains the size, in bytes, of the buffer pointed to by the *pbEncoded* parameter. When the function returns, the **DWORD** contains the number of bytes stored or to be stored in the buffer.

**Note** When processing the data returned in the buffer, applications need to use the actual size of the data returned. The actual size can be slightly smaller than the size of the buffer specified on input. (On input, buffer sizes are usually specified large enough to ensure that the largest possible output data will fit in the buffer.) On output, the variable pointed to by this parameter is updated to reflect the actual size of the data copied to the buffer.

## Return value

If the function succeeds, the return value is nonzero (**TRUE**).

If the function fails, the return value is zero (**FALSE**). For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Note** Errors from the called functions
[CryptCreateHash](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptcreatehash),
[CryptSignHash](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsignhasha) and
[CryptHashData](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-crypthashdata) might be propagated to this function.

Possible error codes include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **ERROR_MORE_DATA** | If the buffer specified by the *pbEncoded* parameter is not large enough to hold the returned data, the function sets the ERROR_MORE_DATA code and stores the required buffer size, in bytes, into the variable pointed to by *pcbEncoded*. |
| **ERROR_FILE_NOT_FOUND** | Invalid certificate encoding type. Currently only X509_ASN_ENCODING is supported. |
| **NTE_BAD_ALGID** | The signature algorithm's OID does not map to a known or supported hash algorithm. |
| **CRYPT_E_BAD_ENCODE** | An error was encountered while encoding or decoding. The most likely cause of this error is the improper initialization of the fields in the structure pointed to by *pvStructInfo*. |

If the function fails, [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) may return an [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) encoding/decoding error. For information about these errors, see
[ASN.1 Encoding/Decoding Return Values](https://learn.microsoft.com/windows/desktop/SecCrypto/asn-1-encoding-decoding-return-values).

## See also

[CryptSignCertificate](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsigncertificate)

[Data Management Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)
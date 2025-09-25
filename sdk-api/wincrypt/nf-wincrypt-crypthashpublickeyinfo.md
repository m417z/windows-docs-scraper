# CryptHashPublicKeyInfo function

## Description

**Important** This API is deprecated. New and existing software should start using [Cryptography Next Generation APIs.](https://learn.microsoft.com/windows/desktop/SecCNG/cng-portal) Microsoft may remove this API in future releases.

The **CryptHashPublicKeyInfo** function encodes the [public key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) information in a
[CERT_PUBLIC_KEY_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_public_key_info) structure and computes the [hash](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) of the encoded bytes. The hash created is used with
[key identifier functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions).

## Parameters

### `hCryptProv` [in]

This parameter is not used and should be set to **NULL**.

**Windows Server 2003 and Windows XP:** A handle of the [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) to use to compute the hash.This parameter's data type is **HCRYPTPROV**.

Unless there is a strong reason for passing in a specific cryptographic provider in *hCryptProv*, zero is passed in. Passing in zero causes the default [RSA](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) or [Digital Signature Standard](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DSS) provider to be acquired before doing hash, [signature verification](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly), or recipient [encryption](https://learn.microsoft.com/windows/desktop/SecGloss/e-gly) operations.

### `Algid` [in]

An [ALG_ID](https://learn.microsoft.com/windows/desktop/SecCrypto/alg-id) structure that specifies the CryptoAPI hash algorithm to use. If *Algid* is zero, the default hash algorithm, MD5, is used.

### `dwFlags` [in]

Values to be passed on to
[CryptCreateHash](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptcreatehash).

### `dwCertEncodingType` [in]

Specifies the encoding type used. It is always acceptable to specify both the [certificate](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) and [message encoding types](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) by combining them with a bitwise-**OR** operation as shown in the following example:

X509_ASN_ENCODING | PKCS_7_ASN_ENCODING

Currently defined encoding types are:

* X509_ASN_ENCODING
* PKCS_7_ASN_ENCODING

### `pInfo` [in]

A pointer to a
[CERT_PUBLIC_KEY_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_public_key_info) structure that contains the [public key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) information to be encoded and hashed.

### `pbComputedHash` [out]

A pointer to a buffer to receive the computed hash.

To set the size of this information for memory allocation purposes, this parameter can be **NULL**. For more information, see
[Retrieving Data of Unknown Length](https://learn.microsoft.com/windows/desktop/SecCrypto/retrieving-data-of-unknown-length).

### `pcbComputedHash` [in, out]

A pointer to a **DWORD** that contains the size, in bytes, of the buffer pointed to by the *pbComputedHash* parameter. When the function returns, the **DWORD** contains the number of bytes stored in the buffer.

**Note** When processing the data returned in the buffer, applications need to use the actual size of the data returned. The actual size can be slightly smaller than the size of the buffer specified on input. On input, buffer sizes are usually specified large enough to ensure that the largest possible output data will fit in the buffer. On output, the variable pointed to by this parameter is updated to reflect the actual size of the data copied to the buffer.

## Return value

If the function succeeds, the function returns nonzero (**TRUE**).

If the function fails, it returns zero (**FALSE**). For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Note** Errors from the called functions
[CryptCreateHash](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptcreatehash),
[CryptGetHashParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgethashparam), and
[CryptHashData](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-crypthashdata) can be propagated to this function. This function has the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_MORE_DATA** | If the buffer specified by the *pbComputedHash* parameter is not large enough to hold the returned data, the function sets the ERROR_MORE_DATA code, and stores the required buffer size, in bytes, in the variable pointed to by *pcbComputedHash*. |
| **ERROR_FILE_NOT_FOUND** | Invalid certificate encoding type. Currently only X509_ASN_ENCODING is supported. |

If the function fails, [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) may return an [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) encoding/decoding error. For information about these errors, see
[ASN.1 Encoding/Decoding Return Values](https://learn.microsoft.com/windows/desktop/SecCrypto/asn-1-encoding-decoding-return-values).

## See also

[CryptHashCertificate](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-crypthashcertificate)

[CryptHashToBeSigned](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-crypthashtobesigned)

[Data Management Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)
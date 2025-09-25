# CryptHashCertificate function

## Description

**Important** This API is deprecated. New and existing software should start using [Cryptography Next Generation APIs.](https://learn.microsoft.com/windows/desktop/SecCNG/cng-portal) Microsoft may remove this API in future releases.

The **CryptHashCertificate** function [hashes](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) the entire encoded content of a [certificate](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) including its signature.

## Parameters

### `hCryptProv` [in]

This parameter is not used and should be set to **NULL**.

**Windows Server 2003 and Windows XP:** A handle of the [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) to use to compute the hash.

This parameter's data type is **HCRYPTPROV**.

Unless there is a strong reason for passing in a specific CSP in *hCryptProv*, zero is passed in. Passing in zero causes the default [RSA](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) or [Digital Signature Standard](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DSS) provider to be acquired before doing hash, signature verification, or recipient encryption operations.

### `Algid` [in]

An
[ALG_ID](https://learn.microsoft.com/windows/desktop/SecCrypto/alg-id) structure that specifies the [hash algorithm](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) to use. If *Algid* is zero, the default hash algorithm, SHA1, is used.

### `dwFlags` [in]

Value to be passed to the hash API. For details, see
[CryptCreateHash](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptcreatehash).

### `pbEncoded` [in]

Address of the encoded content to be hashed.

### `cbEncoded` [in]

The size, in bytes, of the encoded content.

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
[CryptGetHashParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgethashparam) and
[CryptHashData](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-crypthashdata) might be propagated to this function.

## See also

[CryptHashPublicKeyInfo](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-crypthashpublickeyinfo)

[CryptHashToBeSigned](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-crypthashtobesigned)

[Data Management Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)
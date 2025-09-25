# CertIsStrongHashToSign function

## Description

Determines whether the specified hash algorithm and the public key in the signing certificate can be used to perform strong signing.

## Parameters

### `pStrongSignPara` [in]

Pointer to a [CERT_STRONG_SIGN_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_strong_sign_para) structure that contains information about supported signing and hashing algorithms.

### `pwszCNGHashAlgid` [in]

Pointer to a Unicode string that contains the name of the hashing algorithm. The following algorithms are supported:

* L"MD5" (BCRYPT_MD5_ALGORITHM)
* L"SHA1" (BCRYPT_SHA1_ALGORITHM)
* L"SHA256" (BCRYPT_SHA256_ALGORITHM)
* L"SHA256" (BCRYPT_SHA256_ALGORITHM)
* L"SHA512" (BCRYPT_SHA512_ALGORITHM)

### `pSigningCert` [in, optional]

Pointer to a [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure that contains the signing certificate. The public key algorithm in the signing certificate is checked for strength. The public key (asymmetric) algorithm is used for signing. The following signature algorithms are supported:

* L"RSA" (BCRYPT_RSA_ALGORITHM)
* L"DSA" (BCRYPT_DSA_ALGORITHM)
* L"ECDSA" (SSL_ECDSA_ALGORITHM)

This parameter can be **NULL** if you want to check only whether the hashing algorithm is strong.

## Return value

If the function succeeds, the function returns **TRUE**.

If the function fails, it returns **FALSE**.
For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). This function has the following error codes.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more of the input arguments is not correct. |
| **NTE_BAD_ALGID** | A specified algorithm is not supported. |

## See also

[CERT_STRONG_SIGN_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_strong_sign_para)
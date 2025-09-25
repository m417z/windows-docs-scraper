# CERT_STRONG_SIGN_SERIALIZED_INFO structure

## Description

Contains the *signature algorithm*/*hash algorithm* and *public key algorithm*/*bit length* pairs that can be used for strong signing. This structure is used by the [CERT_STRONG_SIGN_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_strong_sign_para) structure.

## Members

### `dwFlags`

By default, certificate strong signing parameters do not apply to certificate revocation lists (CRLs) or online certificate status protocol (OCSP) responses. You can set one or both of the following values to enable strong signing on CRLs and OCSP responses.

| Value | Meaning |
| --- | --- |
| **CERT_STRONG_SIGN_ENABLE_CRL_CHECK**<br><br>0x1 | Enable strong signing of CRLs. |
| **CERT_STRONG_SIGN_ENABLE_OCSP_CHECK**<br><br>0x2 | Enable strong signing of OCSP responses. |

### `pwszCNGSignHashAlgids`

Pointer to a null-terminated Unicode string that contains a set of *signature algorithm*/*hash algorithm* pairs. A Unicode semicolon (L";") separates the pairs. This is shown by the following example.

`L"RSA/SHA256;RSA/SHA384;ECDSA/SHA256;ECDSA/SHA384"`

The following signature algorithms are supported:

* L"RSA" (BCRYPT_RSA_ALGORITHM)
* L"DSA" (BCRYPT_DSA_ALGORITHM)
* L"ECDSA" (SSL_ECDSA_ALGORITHM)

The following signature algorithms are not supported:

* L"ECDSA_P256" (BCRYPT_ECDSA_P256_ALGORITHM)
* L"ECDSA_P384" (BCRYPT_ECDSA_P384_ALGORITHM)
* L"ECDSA_P521" (BCRYPT_ECDSA_P521_ALGORITHM)

The following hash algorithms are supported:

* L"MD5" (BCRYPT_MD5_ALGORITHM)
* L"SHA1" (BCRYPT_SHA1_ALGORITHM)
* L"SHA256" (BCRYPT_SHA256_ALGORITHM)
* L"SHA256" (BCRYPT_SHA256_ALGORITHM)
* L"SHA512" (BCRYPT_SHA512_ALGORITHM)

### `pwszCNGPubKeyMinBitLengths`

Pointer to a null-terminated Unicode string that contains a set of *public key algorithm*/*bit length* pairs. A Unicode semicolon (L";") separates the pairs. This is shown by the following example.

`L”RSA/2048;ECDSA/256”`

The following public key algorithms are supported:

* L"RSA" (BCRYPT_RSA_ALGORITHM)
* L"DSA" (BCRYPT_DSA_ALGORITHM)
* L"ECDSA" (SSL_ECDSA_ALGORITHM)

## Remarks

This structure is used by the [CERT_STRONG_SIGN_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_strong_sign_para) structure which is directly referenced by the following functions:

* [CertIsStrongHashToSign](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certisstronghashtosign)
* [CryptMsgControl](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgcontrol)
* [CryptMsgVerifyCountersignatureEncodedEx](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgverifycountersignatureencodedex)

Also, [CERT_STRONG_SIGN_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_strong_sign_para) is indirectly referenced by the following:

* [CryptDecodeMessage](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdecodemessage)
* [CryptDecryptAndVerifyMessageSignature](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdecryptandverifymessagesignature)
* [CertGetCertificateChain](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcertificatechain)
* [CertSelectCertificateChains](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certselectcertificatechains)
* [CryptVerifyDetachedMessageSignature](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptverifydetachedmessagesignature)
* [CryptVerifyMessageSignature](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptverifymessagesignature)

## See also

[CERT_STRONG_SIGN_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_strong_sign_para)
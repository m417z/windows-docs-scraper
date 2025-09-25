# CRYPT_KEY_SIGN_MESSAGE_PARA structure

## Description

The **CRYPT_KEY_SIGN_MESSAGE_PARA** structure contains information about the [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) and algorithms used to sign a message.

## Members

### `cbSize`

The size, in bytes, of this data structure.

### `dwMsgAndCertEncodingType`

Specifies the type of message and certificate encoding used. This can be a combination of one or more of the following values.

| Value | Meaning |
| --- | --- |
| **X509_ASN_ENCODING** | Specifies [X.509](https://learn.microsoft.com/windows/desktop/SecGloss/x-gly) certificate encoding. |
| **PKCS_7_ASN_ENCODING** | Specifies PKCS 7 message encoding. |

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.hCryptProv`

The handle of the CSP to use to sign the message. The [CryptAcquireContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecontexta) function is called to obtain this handle.

### `DUMMYUNIONNAME.hNCryptKey`

The handle of the Cryptography API: Next Generation (CNG) CSP to use to sign the message. CNG signature algorithms are only supported in CNG functions.

### `dwKeySpec`

Identifies the type of [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) to use to sign the message. This must be one of the following values. This member is ignored if a CNG key is passed in the *hNCryptKey* member.

| Value | Meaning |
| --- | --- |
| **AT_KEYEXCHANGE** | Use the key exchange key. |
| **AT_SIGNATURE** | Use the digital signature key. |

### `HashAlgorithm`

A [CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure that specifies the algorithm to use to generate the hash of the message. This must be a hash algorithm.

### `pvHashAuxInfo`

This member is not used and must be set to **NULL**.

### `PubKeyAlgorithm`

A [CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure that specifies the algorithm to use to sign the message. This must be either a public key or a signature algorithm.
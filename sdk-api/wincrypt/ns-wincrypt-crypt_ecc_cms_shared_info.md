# CRYPT_ECC_CMS_SHARED_INFO structure

## Description

The **CRYPT_ECC_CMS_SHARED_INFO** structure represents key-encryption key information when using Elliptic Curve Cryptography (ECC) in the Cryptographic Message Syntax (CMS) EnvelopedData content type. This structure is used in a key-exchange scenario for exchange of keys to encrypt and decrypt content. A pointer to this structure can be used in the *pvStructInfo* parameter of [CryptEncodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptencodeobject) or [CryptDecodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdecodeobject) and is specified by the constant **ECC_CMS_SHARED_INFO**. For more information, see [Constants for CryptEncodeObject and CryptDecodeObject](https://learn.microsoft.com/windows/desktop/SecCrypto/constants-for-cryptencodeobject-and-cryptdecodeobject).

## Members

### `Algorithm`

A [CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure that contains the object identifier of the key-encryption algorithm used to wrap the content-encryption key.

### `EntityUInfo`

An optional member that contains additional user keying material as an octet string supplied by the sending agent.

### `rgbSuppPubInfo`

An array of four bytes that represent the length, in bits, of the key-encryption key. The byte array is in [little-endian](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) order.

The following table contains the definition of the array dimension.

#### CRYPT_ECC_CMS_SHARED_INFO_SUPPPUBINFO_BYTE_LENGTH (4)

## See also

[RFC 3278](https://www.ietf.org/rfc/rfc3278.txt)
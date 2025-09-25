# CRYPT_HASH_MESSAGE_PARA structure

## Description

The **CRYPT_HASH_MESSAGE_PARA** structure contains data for [hashing](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) messages.

## Members

### `cbSize`

Size of this structure in bytes.

### `dwMsgEncodingType`

Type of encoding used. It is always acceptable to specify both the certificate and [message encoding types](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) by combining them with a bitwise-**OR** operation as shown in the following example:

X509_ASN_ENCODING | PKCS_7_ASN_ENCODING

Currently defined encoding types are:

* X509_ASN_ENCODING
* PKCS_7_ASN_ENCODING

### `hCryptProv`

This member is not used and should be set to **NULL**.

**Windows Server 2003 and Windows XP:** A handle to the [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) to be used.Unless there is a strong reason for passing in a specific cryptographic provider in **hCryptProv**, pass zero to use the default RSA or DSS provider.

This member's data type is **HCRYPTPROV**.

### `HashAlgorithm`

[CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) containing the algorithm for generating the hash of the message.

### `pvHashAuxInfo`

Not currently used, and must be set to **NULL**.

## See also

[CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier)

[CryptHashMessage](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-crypthashmessage)

[CryptVerifyDetachedMessageHash](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptverifydetachedmessagehash)

[CryptVerifyMessageHash](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptverifymessagehash)
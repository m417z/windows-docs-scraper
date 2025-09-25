# CMSG_SIGNER_INFO structure

## Description

The **CMSG_SIGNER_INFO** structure contains the content of the PKCS #7 defined SignerInfo in signed messages. In decoding a received message,
[CryptMsgGetParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsggetparam) is called for each signer to get a **CMSG_SIGNER_INFO** structure.

## Members

### `dwVersion`

The version of this structure.

### `Issuer`

A [CERT_NAME_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that contains the issuer of a certificate with the public key needed to verify a signature.

### `SerialNumber`

A [CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that contains the serial number of the certificate that contains the public key needed to verify a signature. For more information, see
[CERT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_info).

### `HashAlgorithm`

[CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure specifying the algorithm used in generating the hash of a message.

### `HashEncryptionAlgorithm`

[CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure specifying the algorithm used to encrypt the hash.

### `EncryptedHash`

A
[CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) that contains the encrypted hash of the message, the signature.

### `AuthAttrs`

[CRYPT_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_attributes) structure containing authenticated attributes of the signer.

### `UnauthAttrs`

[CRYPT_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_attributes) structure containing unauthenticated attributes of the signer.

## See also

[CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier)

[CRYPT_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_attributes)

[CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85))
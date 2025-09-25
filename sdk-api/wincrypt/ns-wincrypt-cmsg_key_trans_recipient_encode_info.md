# CMSG_KEY_TRANS_RECIPIENT_ENCODE_INFO structure

## Description

The **CMSG_KEY_TRANS_RECIPIENT_ENCODE_INFO** structure contains encoded key transport information for a message recipient.

## Members

### `cbSize`

A **DWORD** value that indicates the size, in bytes, of the structure.

### `KeyEncryptionAlgorithm`

A
[CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) value that identifies the key-encryption algorithm and any associated parameters used to encrypt the content encryption key.

For RSA AES, the **pszObjId** member of the [CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure should be set to szOID_RSAES_OAEP. The **Parameters** member of the **CRYPT_ALGORITHM_IDENTIFIER** structure should be set to the encoded **PKCS_RSAES_OAEP_PARAMETERS**. If the **Parameters.cbData** member is equal to zero, then the default parameters are used and encoded.

### `pvKeyEncryptionAuxInfo`

A void pointer to a structure that contains additional information about the encryption. The format of the structure is dependent upon the algorithm indicated by **KeyEncryptionAlgorithm**.

### `hCryptProv`

This member is not used and should be set to **NULL**.

**Windows Server 2003 and Windows XP:**  A [HCRYPTPROV](https://learn.microsoft.com/windows/desktop/SecCrypto/hcryptprov) value used to do the recipient key encryption and export. The provider's private keys are not used. If **hCryptProv** is **NULL**, the **HCRYPTPROV** specified in the
[CMSG_ENVELOPED_ENCODE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_enveloped_encode_info) is used.Note that this [HCRYPTPROV](https://learn.microsoft.com/windows/desktop/SecCrypto/hcryptprov) is not released even if CMSG_CRYPT_RELEASE_CONTEXT_FLAG is set in the *dwFlags* parameter passed to [CryptMsgOpenToEncode](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgopentoencode).

### `RecipientPublicKey`

A **CRYPT_BIT_BLOB** variable that contains the public key of the recipient.

### `RecipientId`

A [CERT_ID](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_id) value that identifies the recipient. CMS supports the KEY_IDENTIFIER and ISSUER_SERIAL_NUMBER **CERT_ID**s. PKCS #7 version 1.5 supports only the ISSUER_SERIAL_NUMBER **CERT_ID**s.
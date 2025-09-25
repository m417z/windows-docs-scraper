# CMSG_RECIPIENT_ENCRYPTED_KEY_ENCODE_INFO structure

## Description

The **CMSG_RECIPIENT_ENCRYPTED_KEY_ENCODE_INFO** structure contains information on a message receiver used to decrypt the session key needed to decrypt the message contents. This structure is used with CMS low level messages using any of the key management methods.

## Members

### `cbSize`

The size, in bytes, of this data structure.

### `RecipientPublicKey`

A [CRYPT_BIT_BLOB](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_bit_blob) structure that contains the recipient's public key.

### `RecipientId`

The [CERT_ID](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_id) that identifies a message recipient's public key.

### `Date`

Optional **FILETIME**. Applicable only if the [CERT_ID](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_id) identifies the receiver's public key with a KEY_IDENTIFIER.

### `pOtherAttr`

Optional. Pointer to a [CRYPT_ATTRIBUTE_TYPE_VALUE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_attribute_type_value). Applicable only if the CERT_ID identifies the receiver's public key with a KEY_IDENTIFIER.
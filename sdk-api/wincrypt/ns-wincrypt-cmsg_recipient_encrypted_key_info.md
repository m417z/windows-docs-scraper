# CMSG_RECIPIENT_ENCRYPTED_KEY_INFO structure

## Description

The **CMSG_RECIPIENT_ENCRYPTED_KEY_INFO** structure contains information used for an individual key agreement recipient.

## Members

### `RecipientId`

[CERT_ID](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_id) structure identifying the recipient. Currently, only the ISSUER_SERIAL_NUMBER or KEYID choices in the **CERT_ID** structure are valid.

### `EncryptedKey`

A [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that contains the encrypted content encryption key.

### `Date`

Optional. When present, this member specifies which of the recipient's previously distributed UKMs was used by the sender. Only applicable to KEYID choice in the **RecipientId** [CERT_ID](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_id) structure.

### `pOtherAttr`

Optional pointer to a
[CRYPT_ATTRIBUTE_TYPE_VALUE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_attribute_type_value) structure containing additional information. Only applicable to KEYID choice in the **RecipientId** [CERT_ID](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_id) structure.
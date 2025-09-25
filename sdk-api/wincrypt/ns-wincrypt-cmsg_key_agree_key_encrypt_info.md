# CMSG_KEY_AGREE_KEY_ENCRYPT_INFO structure

## Description

The **CMSG_KEY_AGREE_KEY_ENCRYPT_INFO** structure contains the encrypted key for a key agreement recipient of an enveloped message. The [CMSG_KEY_AGREE_ENCRYPT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_key_agree_encrypt_info) structure references this structure.

## Members

### `cbSize`

The size, in bytes, of this structure.

### `EncryptedKey`

A [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that contains the session key encrypted by the negotiated key of the recipient.
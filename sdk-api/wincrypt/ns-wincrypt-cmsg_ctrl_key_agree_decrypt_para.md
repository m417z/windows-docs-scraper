# CMSG_CTRL_KEY_AGREE_DECRYPT_PARA structure

## Description

The **CMSG_CTRL_KEY_AGREE_DECRYPT_PARA** structure contains information about a key agreement recipient.

## Members

### `cbSize`

The size, in bytes, of this data structure.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.hCryptProv`

A handle to the [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) used to do the recipient key encryption and export. If **NULL**, the provider specified in [CMSG_ENVELOPED_ENCODE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_enveloped_encode_info) is used.
The CNG function [NCryptIsKeyHandle](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncryptiskeyhandle) is called to determine the union choice.

### `DUMMYUNIONNAME.hNCryptKey`

A handle to the CNG CSP used to do the recipient key encryption and export. The CNG function [NCryptIsKeyHandle](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncryptiskeyhandle) is called to determine the union choice. New encrypt algorithms are only supported in CNG functions. The CNG function [NCryptTranslateHandle](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncrypttranslatehandle) will be called to convert the CryptoAPI CSP *hCryptProv* choice where necessary. We recommend that applications pass, to the *hNCryptKey* member, the CNG CSP handle that is returned from the [NCryptOpenKey](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncryptopenkey) function.

### `dwKeySpec`

Specifies the encrypted key. The encrypted key is the result of encrypting the content-encryption key. This member is not used when the *hNCryptKey* member is used.

### `pKeyAgree`

A pointer to a [CMSG_KEY_AGREE_RECIPIENT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_key_agree_recipient_info) structure.

### `dwRecipientIndex`

Indicates a specific recipient in an array of recipients.

### `dwRecipientEncryptedKeyIndex`

Indicates a specific encrypted key in an array of encrypted keys.

### `OriginatorPublicKey`

A [CRYPT_BIT_BLOB](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_bit_blob) structure that contains the sender's public key information.
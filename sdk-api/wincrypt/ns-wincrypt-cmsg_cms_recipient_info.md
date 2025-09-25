# CMSG_CMS_RECIPIENT_INFO structure

## Description

The **CMSG_CMS_RECIPIENT_INFO** structure is used with the
[CryptMsgGetParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsggetparam) function to get information on a key transport, key agreement, or mail list envelope message recipient. This structure is returned in *pvData* when [CryptMsgGetParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsggetparam) is called with *dwParamType* set to CMSG_CMS_RECIPIENT_INFO_PARAM.

## Members

### `dwRecipientChoice`

Indicates the member of the union to be used.

Possible values are:

| Value | Meaning |
| --- | --- |
| **CMSG_KEY_TRANS_RECIPIENT** | pKeyTrans |
| **CMSG_KEY_AGREE_RECIPIENT** | pKeyAgree |
| **CMSG_MAIL_LIST_RECIPIENT** | pMailList |

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.pKeyTrans`

A pointer to a
[CMSG_KEY_TRANS_RECIPIENT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_key_trans_recipient_info) structure that identifies a key transport recipient. Used for RSA recipients.

### `DUMMYUNIONNAME.pKeyAgree`

A pointer to a
[CMSG_KEY_AGREE_RECIPIENT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_key_agree_recipient_info) structure that identifies a key agreement recipient. Used for Diffie-Hellman recipients.

### `DUMMYUNIONNAME.pMailList`

A pointer to a
[CMSG_MAIL_LIST_RECIPIENT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_mail_list_recipient_info) structure that identifies a recipient using a previously distributed key encryption key for the encryption/decryption of the envelopes message's [symmetric key](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly).
# CMSG_RECIPIENT_ENCODE_INFO structure

## Description

The **CMSG_RECIPIENT_ENCODE_INFO** structure contains information a message recipient's content encryption key management type.

**Note** Only key transport recipients are supported in PKCS #7 version 1.5.

## Members

### `dwRecipientChoice`

Indicates the union member to be used. The following values are defined.

| Value | Meaning |
| --- | --- |
| **CMSG_KEY_TRANS_RECIPIENT** | Use with key transport key management |
| **CMSG_KEY_AGREE_RECIPIENT** | Used with key agreement key management |
| **CMSG_MAIL_LIST_RECIPIENT** | Use with previously distributed key encryption key management |

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.pKeyTrans`

A pointer to a
[CMSG_KEY_TRANS_RECIPIENT_ENCODE_INFO](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-cmsg_key_trans_recipient_encode_info) structure. Used with CMSG_KEY_TRANS_RECIPIENT

### `DUMMYUNIONNAME.pKeyAgree`

A pointer to a
[CMSG_KEY_AGREE_RECIPIENT_ENCODE_INFO](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-cmsg_key_agree_recipient_encode_info) structure. Used with CMSG_KEY_AGREE_RECIPIENT

### `DUMMYUNIONNAME.pMailList`

A pointer to a
[CMSG_MAIL_LIST_RECIPIENT_ENCODE_INFO](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-cmsg_mail_list_recipient_encode_info) structure. Used with CMSG_MAIL_LIST_RECIPIENT
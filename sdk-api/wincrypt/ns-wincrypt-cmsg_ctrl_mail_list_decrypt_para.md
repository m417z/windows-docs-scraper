# CMSG_CTRL_MAIL_LIST_DECRYPT_PARA structure

## Description

The **CMSG_CTRL_MAIL_LIST_DECRYPT_PARA** structure contains information on a mail list message recipient.

## Members

### `cbSize`

The size, in bytes, of this data structure.

### `hCryptProv`

The provider used to do the recipient key encryption and export. If **hCryptProv** is **NULL**, the provider specified in [CMSG_ENVELOPED_ENCODE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_enveloped_encode_info) is used.

### `pMailList`

A pointer to a [CMSG_MAIL_LIST_RECIPIENT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_mail_list_recipient_info) structure.

### `dwRecipientIndex`

Indicates a specific recipient in any array of recipients.

### `dwKeyChoice`

Indicates the member of the following union that will be used. Currently only CMSG_MAIL_LIST_HANDLE_KEY_CHOICE is defined.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.hKeyEncryptionKey`

Handle of the key encryption key. Used with **dwKeyChoice** set to CMSG_MAIL_LIST_HANDLE_KEY_CHOICE.

### `DUMMYUNIONNAME.pvKeyEncryptionKey`

A pointer to a void. Reserved for future use.
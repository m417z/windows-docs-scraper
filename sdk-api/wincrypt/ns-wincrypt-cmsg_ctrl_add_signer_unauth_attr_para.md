# CMSG_CTRL_ADD_SIGNER_UNAUTH_ATTR_PARA structure

## Description

The **CMSG_CTRL_ADD_SIGNER_UNAUTH_ATTR_PARA** structure is used to add an unauthenticated attribute to a signer of a signed message. This structure is passed to
[CryptMsgControl](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgcontrol) if the *dwCtrlType* parameter is set to **CMSG_CTRL_ADD_SIGNER_UNAUTH_ATTR**.

## Members

### `cbSize`

Size of this structure in bytes.

### `dwSignerIndex`

Index of the signer in the **rgSigners** array of pointers of
[CMSG_SIGNER_ENCODE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_signer_encode_info) structures in a signed message's
[CMSG_SIGNED_ENCODE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_signed_encode_info) structure. The unauthenticated attribute is to be added to this signer's information.

### `blob`

### `BLOB`

A [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that contains the encoded unauthenticated attribute as its **pbData** member.

## See also

[CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85))

[CryptMsgControl](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgcontrol)
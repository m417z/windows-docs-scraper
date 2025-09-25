# CMSG_CTRL_DEL_SIGNER_UNAUTH_ATTR_PARA structure

## Description

The **CMSG_CTRL_DEL_SIGNER_UNAUTH_ATTR_PARA** structure is used to delete an unauthenticated attribute of a signer of a signed message. This structure is passed to
[CryptMsgControl](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgcontrol) if the *dwCrlType* parameter is **CMSG_CTRL_DEL_SIGNER_UNAUTH_ATTR**.

## Members

### `cbSize`

Size of this structure in bytes.

### `dwSignerIndex`

Index of the signer in the **rgSigners** array of pointers to [CMSG_SIGNER_ENCODE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_signer_encode_info) structures in a signed message's [CMSG_SIGNED_ENCODE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_signed_encode_info) structure. The unauthenticated attribute for this signer is deleted.

### `dwUnauthAttrIndex`

Index of the element in the **rgUnauthAttr** array of the [CMSG_SIGNER_ENCODE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_signer_encode_info) structure holding the unauthenticated attribute to be removed.

## See also

[CryptMsgControl](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgcontrol)
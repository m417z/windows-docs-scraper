# CMSG_CTRL_DECRYPT_PARA structure

## Description

The **CMSG_CTRL_DECRYPT_PARA** structure contains information used to decrypt an enveloped message for a key transport recipient. This structure is passed to
[CryptMsgControl](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgcontrol) if the *dwCtrlType* parameter is CMSG_CTRL_DECRYPT.

For information about how CryptoAPI supports [Secure/Multipurpose Internet Mail Extensions](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (S/MIME) email interoperability, see the Remarks section of
[CryptMsgOpenToEncode](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgopentoencode).

## Members

### `cbSize`

The size, in bytes, of this structure.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.hCryptProv`

[Cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) handle. The CNG function [NCryptIsKeyHandle](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncryptiskeyhandle) is called to determine the union choice.

### `DUMMYUNIONNAME.hNCryptKey`

A handle to the CNG [Cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP). The CNG function, [NCryptIsKeyHandle](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncryptiskeyhandle), is called to determine the union choice. New encrypt algorithms are only supported in CNG functions. The CNG function, [NCryptTranslateHandle](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncrypttranslatehandle), will be called to convert the CryptoAPI *hCryptProv* choice where necessary. We recommend that applications pass, to the *hNCryptKey* member, the CNG CSP handle that is returned from the [NCryptOpenKey](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncryptopenkey) function.

### `dwKeySpec`

The private key to be used. This member is not used when the *hNCryptKey* member is used.

The following **dwKeySpec** values are defined for the default provider.

| Value | Meaning |
| --- | --- |
| **AT_KEYEXCHANGE** | Keys used to encrypt and decrypt session keys. |
| **AT_SIGNATURE** | Keys used to create and verify digital signatures. |

If **dwKeySpec** is zero, the default AT_KEYEXCHANGE is used.

### `dwRecipientIndex`

Index of the recipient in the message associated with the **hCryptProv** private key.

## See also

[CryptMsgControl](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgcontrol)
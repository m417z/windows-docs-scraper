# PFN_CMSG_CNG_IMPORT_CONTENT_ENCRYPT_KEY callback function

## Description

The **PFN_CMSG_CNG_IMPORT_CONTENT_ENCRYPT_KEY** callback function imports an already decrypted content encryption key (CEK). The **PFN_CMSG_CNG_IMPORT_CONTENT_ENCRYPT_KEY** function can be installed by using a Cryptography API: Next Generation (CNG) [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID).

## Parameters

### `pCNGContentDecryptInfo` [in, out]

A pointer to a [CMSG_CNG_CONTENT_DECRYPT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_cng_content_decrypt_info) structure to be updated with the imported CEK. This structure contains all the relevant information passed to the [CryptMsgControl](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgcontrol) function.

### `dwFlags` [in]

This parameter is reserved. Set it to zero.

### `pvReserved`

This parameter is reserved. Set it to **NULL**.

## Return value

If the function succeeds, the return value is nonzero (**TRUE**).

If the function fails, the return value is zero (**FALSE**). For extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If this callback function does not support the key encryption algorithm, it must return **FALSE** and call [SetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setlasterror) with ERROR_NOT_SUPPORTED.

## Remarks

The [CryptMsgControl](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgcontrol) function calls this function for the following operations specified by its *dwCtrlType* parameter:

**CMSG_CTRL_DECRYPT**

**CMSG_CTRL_KEY_TRANS_DECRYPT**

**CMSG_CTRL_KEY_AGREE_DECRYPT**

You can use [OID Support Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions) to deploy this callback function. Wincrypt.h defines the following constant for this purpose.

| Constant | Definition |
| --- | --- |
| CMSG_OID_CNG_IMPORT_CONTENT_ENCRYPT_KEY_FUNC | "CryptMsgDllCNGImportContentEncryptKey" |

#### Examples

For an example that deploys an OID-installable callback function, see [Extending CryptoAPI Functionality](https://learn.microsoft.com/windows/desktop/SecCrypto/extending-cryptoapi-functionality).

## See also

[Decoding Enveloped Data](https://learn.microsoft.com/windows/desktop/SecCrypto/decoding-enveloped-data)
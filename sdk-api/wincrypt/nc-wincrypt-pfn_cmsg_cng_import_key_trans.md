# PFN_CMSG_CNG_IMPORT_KEY_TRANS callback function

## Description

The **PFN_CMSG_CNG_IMPORT_KEY_TRANS** callback function imports and decrypts a content encryption key (CEK) that is intended for a key transport recipient. **PFN_CMSG_CNG_IMPORT_KEY_TRANS** can be installed by using a Cryptography API: Next Generation (CNG) [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID).

## Parameters

### `pCNGContentDecryptInfo` [in, out]

A pointer to a [CMSG_CNG_CONTENT_DECRYPT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_cng_content_decrypt_info) structure to be updated with the decrypted CEK bytes. This parameter contains the key used to decrypt the CEK.
The following *pKeyTransDecryptPara* parameter contains the CEK bytes to be decrypted.

### `pKeyTransDecryptPara` [in]

A pointer to a [CMSG_CTRL_KEY_TRANS_DECRYPT_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_ctrl_key_trans_decrypt_para) structure that contains the key transport information passed to the [CryptMsgControl](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgcontrol) function in the **CMSG_CTRL_DECRYPT** or **CMSG_CTRL_KEY_TRANS_DECRYPT** cases. For the **CMSG_CTRL_DECRYPT** case, **CryptMsgControl** converts the [CMSG_CTRL_DECRYPT_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_ctrl_decrypt_para) structure to a **CMSG_CTRL_KEY_TRANS_DECRYPT_PARA** structure.

The
**EncryptedKey** member of the **pKeyTrans** member contains the CEK bytes to be decrypted. Because a
[CMSG_CTRL_KEY_TRANS_DECRYPT_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_ctrl_key_trans_decrypt_para) structure might contain an **HCRYPTPROV** choice, its **hNCryptKey** member must not be used to decrypt **EncryptedKey**. Instead, you must use the **hNCryptKey** specified in the *pCNGContentDecryptInfo* parameter.

This function must not update members of the [CMSG_CTRL_KEY_TRANS_DECRYPT_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_ctrl_key_trans_decrypt_para) structure.

### `dwFlags` [in]

This parameter is reserved. Set it to zero.

### `pvReserved`

This parameter is reserved. Set it to **NULL**.

## Return value

If the function succeeds, the return value is nonzero (**TRUE**).

If the function fails, the return value is zero (**FALSE**). For extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If this callback function does not support the key encryption algorithm, it must return **FALSE** and call [SetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setlasterror) with ERROR_NOT_SUPPORTED.

## Remarks

The [CryptMsgControl](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgcontrol) function calls this function for the following operations specified by the *dwCtrlType* parameter:

**CMSG_CTRL_DECRYPT**
**CMSG_CTRL_KEY_TRANS_DECRYPT**
You can use [OID Support Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions) to deploy this callback function. Wincrypt.h defines the following constant for this purpose.

| Constant | Definition |
| --- | --- |
| CMSG_OID_CNG_IMPORT_KEY_TRANS_FUNC | "CryptMsgDllCNGImportKeyTrans" |

#### Examples

For an example that deploys an OID-installable callback function, see [Extending CryptoAPI Functionality](https://learn.microsoft.com/windows/desktop/SecCrypto/extending-cryptoapi-functionality).

## See also

[Decoding Enveloped Data](https://learn.microsoft.com/windows/desktop/SecCrypto/decoding-enveloped-data)
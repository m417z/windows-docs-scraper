# PFN_CMSG_EXPORT_KEY_TRANS callback function

## Description

The **PFN_CMSG_EXPORT_KEY_TRANS** callback function encrypts and exports the content encryption key for a key transport recipient of an enveloped message. **PFN_CMSG_EXPORT_KEY_TRANS** can be installed by using a [CryptoAPI](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID). This function is called by the [CryptMsgOpenToEncode](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgopentoencode) function when its *dwMsgType* parameter is set to **CMSG_ENVELOPED**.

## Parameters

### `pContentEncryptInfo` [in]

A pointer to a [CMSG_CONTENT_ENCRYPT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_content_encrypt_info) structure that contains the content encryption key.

### `pKeyTransEncodeInfo` [in]

A pointer to a [CMSG_KEY_TRANS_RECIPIENT_ENCODE_INFO](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-cmsg_key_trans_recipient_encode_info) structure that specifies the recipient public key used to encrypt the content encryption key.

### `pKeyTransEncryptInfo` [in, out]

A pointer to a [CMSG_KEY_TRANS_ENCRYPT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_key_trans_encrypt_info) structure that contains the encrypted content encryption key.

### `dwFlags` [in]

This value is not used. Set it to zero.

### `pvReserved`

This value is reserved. Set it to **NULL**.

## Return value

If the function succeeds, the return value is nonzero (TRUE).

If the function fails, the return value is zero (FALSE). For extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **PFN_CMSG_EXPORT_KEY_TRANS** function must update the **EncryptedKey** member of the [CMSG_KEY_TRANS_ENCRYPT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_key_trans_encrypt_info) structure pointed to by the *pKeyTransEncryptInfo* parameter. This function must use the **pfnAlloc** and **pfnFree** members of the [CMSG_CONTENT_ENCRYPT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_content_encrypt_info) structure pointed to by the *pContentEncryptInfo* parameter to manage memory allocation for the encrypted key.

You can use [OID Support Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions) to deploy this callback function. Wincrypt.h defines the following constants for this purpose.

You must define different callback functions for CAPI1 keys and Cryptography API: Next Generation (CNG) keys. Both functions have the same signature but use different OIDs. Which function is called depends on the value of the **fCNG** member of the [CMSG_CONTENT_ENCRYPT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_content_encrypt_info) structure pointed to by the *pContentEncryptInfo* parameter. The following table shows the relationship between the callback function and the value of the **fCNG** member.

| fCNG value | Constant | Definition |
| --- | --- | --- |
| FALSE | CMSG_OID_EXPORT_KEY_TRANS_FUNC or CMSG_OID_CAPI1_EXPORT_KEY_TRANS_FUNC | "CryptMsgDllExportKeyTrans" |
| TRUE | CMSG_OID_CNG_EXPORT_KEY_TRANS_FUNC | "CryptMsgDllCNGExportKeyTrans" |
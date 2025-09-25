# PFN_CMSG_EXPORT_MAIL_LIST callback function

## Description

The **PFN_CMSG_EXPORT_MAIL_LIST** callback function encrypts and exports the content encryption key for a mailing list recipient of an enveloped message. **PFN_CMSG_EXPORT_MAIL_LIST** can be installed by using a [CryptoAPI](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID). This function is called by the [CryptMsgOpenToEncode](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgopentoencode) function when its *dwMsgType* parameter is set to **CMSG_ENVELOPED**.

## Parameters

### `pContentEncryptInfo` [in]

A pointer to a [CMSG_CONTENT_ENCRYPT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_content_encrypt_info) structure that contains the content encryption key.

### `pMailListEncodeInfo` [in]

A pointer to a [CMSG_MAIL_LIST_RECIPIENT_ENCODE_INFO](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-cmsg_mail_list_recipient_encode_info) structure that specifies the key used to encrypt the content encryption key.

### `pMailListEncryptInfo` [in, out]

A pointer to a [CMSG_MAIL_LIST_ENCRYPT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_mail_list_encrypt_info) structure that contains the encrypted content encryption key.

### `dwFlags` [in]

This value is not used. Set it to zero.

### `pvReserved`

This parameter is reserved and must be **NULL**.

## Return value

If the function succeeds, the return value is nonzero (**TRUE**).

If the function fails, the return value is zero (**FALSE**). For extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **PFN_CMSG_EXPORT_MAIL_LIST** function must update the **EncryptedKey** member of the [CMSG_MAIL_LIST_ENCRYPT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_mail_list_encrypt_info) structure pointed to by the *pMailListEncryptInfo* parameter. This function must use the **pfnAlloc** and **pfnFree** members of the [CMSG_CONTENT_ENCRYPT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_content_encrypt_info) structure pointed to by the *pContentEncryptInfo* parameter to manage memory for any values that it updates.

You can use [OID Support Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions) to deploy this callback function. Wincrypt.h defines the following constants for this purpose.

| Constant | Definition |
| --- | --- |
| CMSG_OID_EXPORT_MAIL_LIST_FUNC or CMSG_OID_CAPI1_EXPORT_MAIL_LIST_FUNC | "CryptMsgDllExportMailList" |
# PFN_CMSG_GEN_CONTENT_ENCRYPT_KEY callback function

## Description

The **PFN_CMSG_GEN_CONTENT_ENCRYPT_KEY** callback function generates the symmetric key used to encrypt content for an enveloped message. This function is called by the [CryptMsgOpenToEncode](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgopentoencode) function when it initializes the [CMSG_CONTENT_ENCRYPT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_content_encrypt_info) structure.

## Parameters

### `pContentEncryptInfo` [in, out]

A pointer to a [CMSG_CONTENT_ENCRYPT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_content_encrypt_info) structure that contains the key.

### `dwFlags` [in]

This value is not used. Set it to zero.

### `pvReserved`

This parameter is reserved and must be **NULL**.

## Return value

If the function succeeds, the return value is nonzero (**TRUE**).

If the function fails, the return value is zero (**FALSE**). For extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

You can use [OID Support Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions) to deploy this callback function. Wincrypt.h defines the following constants for this purpose.

You must define different callback functions for CAPI1 keys and Cryptography API: Next Generation (CNG) keys. Both functions have the same signature but use different [object identifiers](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OIDs). Which function is called depends on the value of the **fCNG** member of the [CMSG_CONTENT_ENCRYPT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_content_encrypt_info) structure pointed to by the *pContentEncryptInfo* parameter. The following table shows the relationship between the callback function and the value of the **fCNG** member.

| fCNG value | Constant | Definition |
| --- | --- | --- |
| **FALSE** | CMSG_OID_GEN_CONTENT_ENCRYPT_KEY_FUNC or CMSG_OID_CAPI1_GEN_CONTENT_ENCRYPT_KEY_FUNC | "CryptMsgDllGenContentEncryptKey" |
| **TRUE** | CMSG_OID_CNG_GEN_CONTENT_ENCRYPT_KEY_FUNC | "CryptMsgDllCNGGenContentEncryptKey" |
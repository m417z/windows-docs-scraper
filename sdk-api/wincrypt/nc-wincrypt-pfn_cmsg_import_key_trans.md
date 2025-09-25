# PFN_CMSG_IMPORT_KEY_TRANS callback function

## Description

The **PFN_CMSG_IMPORT_KEY_TRANS** callback function imports a content encryption key for a key transport recipient of an enveloped message. **PFN_CMSG_IMPORT_KEY_TRANS** can be installed by using a [CryptoAPI](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly). This function is called by the [CryptMsgControl](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgcontrol) function when its *dwCtrlType* parameter is set to **CMSG_CTRL_DECRYPT**.

## Parameters

### `pContentEncryptionAlgorithm` [in]

A pointer to a [CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure that specifies the algorithm used to encrypt the message contents and any associated parameters.

### `pKeyTransDecryptPara` [in]

A pointer to a [CMSG_CTRL_KEY_TRANS_DECRYPT_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_ctrl_key_trans_decrypt_para) structure that contains information about the key transport recipient.

### `dwFlags` [in]

This value is not used. Set it to zero.

### `pvReserved`

This parameter is reserved and must be **NULL**.

### `phContentEncryptKey` [out]

The address of a handle to the content encryption key returned by this function.

## Return value

If the function succeeds, the return value is nonzero (**TRUE**).

If the function fails, the return value is zero (**FALSE**). For extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If this callback function does not support the key encryption algorithm, it must return **FALSE** and call [SetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setlasterror) with **E_NOTIMPL**.

## Remarks

You can use [OID Support Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions) to deploy this callback function. Wincrypt.h defines the following constants for this purpose.

| Constant | Definition |
| --- | --- |
| CMSG_OID_IMPORT_KEY_TRANS_FUNC or CMSG_OID_CAPI1_IMPORT_KEY_TRANS_FUNC | "CryptMsgDllImportKeyTrans" |
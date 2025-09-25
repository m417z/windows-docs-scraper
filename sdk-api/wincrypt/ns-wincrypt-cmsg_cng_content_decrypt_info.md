# CMSG_CNG_CONTENT_DECRYPT_INFO structure

## Description

The **CMSG_CNG_CONTENT_DECRYPT_INFO** structure contains all the relevant information passed between [CryptMsgControl](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgcontrol) and [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) installable functions for the import and decryption of a Cryptography API: Next Generation (CNG) content encryption key (CEK). The [CryptMsgControl](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgcontrol) function uses this structure to call the following functions:

* [PFN_CMSG_CNG_IMPORT_KEY_TRANS](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cmsg_cng_import_key_trans)
* [PFN_CMSG_CNG_IMPORT_KEY_AGREE](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cmsg_cng_import_key_agree)
* [PFN_CMSG_CNG_IMPORT_CONTENT_ENCRYPT_KEY](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cmsg_cng_import_content_encrypt_key)

## Members

### `cbSize`

Contains the size, in bytes, of this structure.

### `ContentEncryptionAlgorithm`

A [CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure that specifies the algorithm used to encrypt the message contents and any associated parameters.

### `pfnAlloc`

A pointer to an installable function used to allocate memory for any updated member.

### `pfnFree`

A pointer to an installable function used to free memory allocated by *pfnAlloc*.

### `hNCryptKey`

A handle to the CNG [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) to be used for decryption of the CEK contained in the *pKeyTransDecryptPara* parameter or the *pKeyAgreeDecryptPara* parameter of the [PFN_CMSG_CNG_IMPORT_KEY_TRANS](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cmsg_cng_import_key_trans) function. Callback functions must use this key instead of the one contained in the *DecryptPara* structure because that structure might contain a converted **HCRYPTPROV** handle.

### `pbContentEncryptKey`

Using the **hNCryptKey** member, the [PFN_CMSG_CNG_IMPORT_KEY_TRANS](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cmsg_cng_import_key_trans) function must update this member by decrypting the CEK in the *pKeyTransDecryptPara* parameter or the [PFN_CMSG_CNG_IMPORT_KEY_AGREE](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cmsg_cng_import_key_agree) function must update this member by decrypting the EncryptedKey in the *pKeyAgreeDecryptPara* parameter. The memory for this member must be allocated by using the **pfnAlloc** member. The [PFN_CMSG_CNG_IMPORT_CONTENT_ENCRYPT_KEY](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cmsg_cng_import_content_encrypt_key) function will use these bytes as the secret to generate the **hCNGContentEncryptKey** member. Even for an error, you must free and zero any allocated memory by using the **pfnFree** member.

### `cbContentEncryptKey`

The [PFN_CMSG_CNG_IMPORT_KEY_TRANS](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cmsg_cng_import_key_trans) or [PFN_CMSG_CNG_IMPORT_KEY_AGREE](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cmsg_cng_import_key_agree) function must update this member with the size, in bytes, of the above **pbContentEncryptKey** member.

### `hCNGContentEncryptKey`

The [PFN_CMSG_CNG_IMPORT_CONTENT_ENCRYPT_KEY](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cmsg_cng_import_content_encrypt_key) function must update this member with the generated **BCRYPT_KEY_HANDLE** to be used for content decryption. Even for an error, you must release this handle by using the [BCryptDestroyKey](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptdestroykey) function.

### `pbCNGContentEncryptKeyObject`

The [PFN_CMSG_CNG_IMPORT_CONTENT_ENCRYPT_KEY](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cmsg_cng_import_content_encrypt_key) function must update this member with the memory allocated by the **pfnAlloc** member to be associated with the **hCNGContentEncryptKey** member. Even for an error, you must free and zero any allocated memory by using the **pfnFree** member.
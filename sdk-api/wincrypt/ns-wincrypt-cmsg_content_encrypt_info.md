# CMSG_CONTENT_ENCRYPT_INFO structure

## Description

The **CMSG_CONTENT_ENCRYPT_INFO** structure contains information shared between the [PFN_CMSG_GEN_CONTENT_ENCRYPT_KEY](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cmsg_gen_content_encrypt_key), [PFN_CMSG_EXPORT_KEY_TRANS](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cmsg_export_key_trans), [PFN_CMSG_EXPORT_KEY_AGREE](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cmsg_export_key_agree), and [PFN_CMSG_EXPORT_MAIL_LIST](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cmsg_export_mail_list) functions used for the encryption and export of a content encryption key, which can be installed by using a Cryptography API: Next Generation (CNG) [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID).

## Members

### `cbSize`

The size, in bytes, of this structure.

### `hCryptProv`

A handle to a [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP). If the **fCNG** member is **FALSE** and the **hCryptProv** member is **NULL** upon input, **hCryptProv** must be updated by the callback function. If a provider is acquired that must be released, the **CMSG_CONTENT_ENCRYPT_RELEASE_CONTEXT_FLAG** must be set in the **dwFlags** member.

### `ContentEncryptionAlgorithm`

A [CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure that specifies the algorithm used to encrypt the key. If the callback function updates either the **pszObjId** member or the **Parameters** member of the **CRYPT_ALGORITHM_IDENTIFIER** structure, set the appropriate value in the **dwFlags** member. You must allocate and free memory for these values by using the **pfnAlloc** and **pfnFree** members.

### `pvEncryptionAuxInfo`

A pointer to a structure that depends on the encryption algorithm. The following table lists possible algorithm IDs and the corresponding member content.

| Value | Meaning |
| --- | --- |
| **RC2** | [CMSG_RC2_AUX_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_rc2_aux_info) |
| **RC4** | [CMSG_RC4_AUX_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_rc4_aux_info) |

For all other encryption algorithms, this value is **NULL**.

### `cRecipients`

A value that specifies the number of recipients of a message.

### `rgCmsRecipients`

A pointer to an array of [CMSG_RECIPIENT_ENCODE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_recipient_encode_info) structures that contain the message recipient information.

### `pfnAlloc`

A pointer to an installable function used to allocate memory for an updated member.

### `pfnFree`

A pointer to an installable function used to free memory allocated by **pfnAlloc**.

### `dwEncryptFlags`

A value that indicates whether the encoded output should be padded with zeros to obtain a consistent maximum length required for definite-length streaming in the [CryptMsgCalculateEncodedLength](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgcalculateencodedlength) or [CryptMsgOpenToEncode](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgopentoencode) functions.

#### CMSG_CONTENT_ENCRYPT_PAD_ENCODED_LEN_FLAG (0x00000001)

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.hContentEncryptKey`

A handle to the content encryption key when the **fCNG** member is **FALSE**.

### `DUMMYUNIONNAME.hCNGContentEncryptKey`

A handle to the content encryption key when the **fCNG** member is **TRUE**.

### `dwFlags`

A value that indicates whether memory must be freed for the **hCryptProv** or **ContentEncryptionAlgorithm** members.

| Value | Meaning |
| --- | --- |
| **CMSG_CONTENT_ENCRYPT_FREE_PARA_FLAG**<br><br>0x00000001 | Set if the callback function updates the **Parameters** member of the [CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure referred to by the **ContentEncryptionAlgorithm** member. |
| **CMSG_CONTENT_ENCRYPT_FREE_OBJID_FLAG**<br><br>0x00000002 | Set if the callback function updates the **pszObjId** member of the [CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure referred to by the **ContentEncryptionAlgorithm** member. |
| **CMSG_CONTENT_ENCRYPT_RELEASE_CONTEXT_FLAG**<br><br>0x00008000 | Set if the callback function acquires an **hCryptProv** member that must be freed. |

### `fCNG`

A value that indicates whether to use a [Cryptography API: Next Generation](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CNG) provider to generate the content encryption key.

If the **fCNG** member is **FALSE**, the **CMSG_OID_GEN_CONTENT_ENCRYPT_KEY_FUNC** function is called to update the **hContentEncryptKey** member.

If the **fCNG** member is **TRUE**, the **CMSG_OID_CNG_GEN_CONTENT_ENCRYPT_KEY_FUNC** function is called to update the **hCNGContentEncryptKey** and **cbContentEncryptKey** members, and the **pbCNGContentEncryptKeyObject** and **pbContentEncryptKey** members must be allocated by the **pfnAlloc** member. Free and release the content encryption key by calling the [CryptMsgClose](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgclose) function.

### `pbCNGContentEncryptKeyObject`

A pointer to the buffer that contains the CNG content encryption key.

### `pbContentEncryptKey`

A pointer to the buffer that contains a CAPI1 content encryption key.

### `cbContentEncryptKey`

The size, in bytes, of the **pbCNGContentEncryptKeyObject** or **pbContentEncryptKey** member depending on the value of the **fCNG** member.

## Remarks

When called with the *dwMsgType* parameter set to **CMSG_ENVELOPED**, the [CryptMsgOpenToEncode](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgopentoencode) function initializes the **CMSG_CONTENT_ENCRYPT_INFO** structure from the [CMSG_ENVELOPED_ENCODE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_enveloped_encode_info) structure.

If the [CMSG_ENVELOPED_ENCODE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_enveloped_encode_info) structure uses the **rgpRecipients** member instead of the **rgCmsRecipients** member, the [CryptMsgOpenToEncode](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgopentoencode) function converts the **rgpRecipients** member structures to [CMSG_RECIPIENT_ENCODE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_recipient_encode_info) structures for the **rgCmsRecipients** member of the **CMSG_CONTENT_ENCRYPT_INFO** structure.

When the **fCNG** member is **FALSE**, the following members can be changed in the **CMSG_CONTENT_ENCRYPT_INFO** structure:

**hContentEncryptKey**

**hCryptProv**

The **pszObjId** member of the [CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure referred to by the **ContentEncryptionAlgorithm** member

The **Parameters** member of the [CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure referred to by the **ContentEncryptionAlgorithm** member

**dwFlags**

When the **fCNG** member is **TRUE**, the following members can be changed in the **CMSG_CONTENT_ENCRYPT_INFO** structure:

**hCNGContentEncryptKey**

**pbCNGContentEncryptKeyObject**

**pbContentEncryptKey**

**cbContentEncryptKey**

The **pszObjId** member of the [CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure referred to by the **ContentEncryptionAlgorithm** member

The **Parameters** member of the [CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure referred to by the **ContentEncryptionAlgorithm** member

**dwFlags**

The following members are read-only:

**cbSize**

**pvEncryptionAuxInfo**

**cRecipients**

**rgCmsRecipients**

**pfnAlloc**

**pfnFree**

**dwEncryptFlags**

## See also

[PFN_CMSG_EXPORT_KEY_AGREE](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cmsg_export_key_agree)

[PFN_CMSG_EXPORT_KEY_TRANS](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cmsg_export_key_trans)

[PFN_CMSG_EXPORT_MAIL_LIST](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cmsg_export_mail_list)

[PFN_CMSG_GEN_CONTENT_ENCRYPT_KEY](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cmsg_gen_content_encrypt_key)
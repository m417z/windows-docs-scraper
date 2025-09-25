# CMSG_KEY_AGREE_ENCRYPT_INFO structure

## Description

The **CMSG_KEY_AGREE_ENCRYPT_INFO** structure contains encryption information applicable to all key agreement recipients of an enveloped message. The [PFN_CMSG_EXPORT_KEY_AGREE](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cmsg_export_key_agree) function updates this structure.

## Members

### `cbSize`

The size, in bytes, of this structure.

### `dwRecipientIndex`

A value that specifies the ordinal number of a recipient in the recipient list specified by the *pContentEncryptInfo* parameter of the [PFN_CMSG_EXPORT_KEY_AGREE](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cmsg_export_key_agree) function.

### `KeyEncryptionAlgorithm`

A [CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure that specifies the algorithm used to encrypt the content encryption key. The [CryptMsgOpenToEncode](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgopentoencode) function uses the **pszObjId** member of the **CRYPT_ALGORITHM_IDENTIFIER** structure to get the address of the function used to export the key. The function can be installed by using a Cryptography API: Next Generation (CNG) [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID).

### `UserKeyingMaterial`

A [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that contains user keying material provided by the sender to ensure that a different key is generated each time the same two parties generate a pair-wise key.

### `dwOriginatorChoice`

A **DWORD** that indicates the key identifier to use. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CMSG_KEY_AGREE_ORIGINATOR_CERT** | OriginatorCertId |
| **CMSG_KEY_AGREE_ORIGINATOR_PUBLIC_KEY** | OriginatorPublicKeyInfo |

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.OriginatorCertId`

A [CERT_ID](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_id) structure that identifies the public key of the message originator.

### `DUMMYUNIONNAME.OriginatorPublicKeyInfo`

A [CERT_PUBLIC_KEY_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_public_key_info) structure that contains the [public key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) of the message originator.

### `cKeyAgreeKeyEncryptInfo`

A value that specifies the number of recipients in the *rgpKeyAgreeKeyEncryptInfo* parameter.

### `rgpKeyAgreeKeyEncryptInfo`

An array of [CMSG_KEY_AGREE_KEY_ENCRYPT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_key_agree_key_encrypt_info) structures that contain the encrypted key for each recipient.

### `dwFlags`

A value that specifies what members have been updated, and whose memory allocation must be freed by using the [CryptMsgOpenToEncode](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgopentoencode) function.

| Value | Meaning |
| --- | --- |
| **CMSG_KEY_AGREE_ENCRYPT_FREE_MATERIAL_FLAG**<br><br>0x00000002 | The **UserKeyingMaterial** member was updated. |
| **CMSG_KEY_AGREE_ENCRYPT_FREE_OBJID_FLAG**<br><br>0x00000020 | The **pszObjId** member of the [CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure referred to by the **KeyEncryptionAlgorithm** member was updated. |
| **CMSG_KEY_AGREE_ENCRYPT_FREE_PARA_FLAG**<br><br>0x00000001 | The **Parameters** member of the [CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure referred to by **KeyEncryptionAlgorithm** member was updated. |
| **CMSG_KEY_AGREE_ENCRYPT_FREE_PUBKEY_ALG_FLAG**<br><br>0x00000004 | The **Algorithm.pszObjId** member of the [CERT_PUBLIC_KEY_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_public_key_info) structure referred to by the **OriginatorPublicKeyInfo** member was updated. |
| **CMSG_KEY_AGREE_ENCRYPT_FREE_PUBKEY_BITS_FLAG**<br><br>0x00000010 | The **PublicKey** member of the [CERT_PUBLIC_KEY_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_public_key_info) structure referred to by the **OriginatorPublicKeyInfo** member was updated. |
| **CMSG_KEY_AGREE_ENCRYPT_FREE_PUBKEY_PARA_FLAG**<br><br>0x00000008 | The **Algorithm.Parameters** member of the [CERT_PUBLIC_KEY_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_public_key_info) structure referred to by the **OriginatorPublicKeyInfo** member was updated. |

## Remarks

 When called with the *dwMsgType* parameter set to **CMSG_ENVELOPED**, the [CryptMsgOpenToEncode](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-cmsg_key_agree_recipient_encode_info) function initializes the **CMSG_KEY_AGREE_ENCRYPT_INFO** structure from the [CMSG_KEY_AGREE_RECIPIENT_ENCODE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_key_agree_recipient_encode_info) structure. The **CryptMsgOpenToEncode** function calls the [PFN_CMSG_EXPORT_KEY_AGREE](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cmsg_export_key_agree) function to update the **CMSG_KEY_AGREE_ENCRYPT_INFO** structure. If the callback function cannot be found, the **CryptMsgOpenToEncode** function fills this structure with default key information from the [CMSG_CONTENT_ENCRYPT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_content_encrypt_info) structure.

The following members of the **CMSG_KEY_AGREE_ENCRYPT_INFO** structure can be updated by the callback function:

**UserKeyingMaterial**

**KeyEncryptionAlgorithm.pszObjId**

**KeyEncryptionAlgorithm.Parameters**

**dwOriginatorChoice**

**OriginatorCertId**

**OriginatorPublicKeyInfo**

**dwFlags**

The other members are read-only.
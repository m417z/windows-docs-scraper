# CMSG_KEY_TRANS_ENCRYPT_INFO structure

## Description

The **CMSG_KEY_TRANS_ENCRYPT_INFO** structure contains encryption information for a key transport recipient of enveloped data. The [PFN_CMSG_EXPORT_KEY_TRANS](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cmsg_export_key_trans) function updates this structure.

## Members

### `cbSize`

The size, in bytes, of this structure.

### `dwRecipientIndex`

A value that specifies the ordinal number of a recipient in the recipient list specified by the *pContentEncryptInfo* parameter of the [PFN_CMSG_EXPORT_KEY_TRANS](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cmsg_export_key_trans) function.

### `KeyEncryptionAlgorithm`

A [CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure that specifies the algorithm of the recipient public key. The [CryptMsgOpenToEncode](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgopentoencode) function uses the **pszObjId** member of the **CRYPT_ALGORITHM_IDENTIFIER** structure to get the address of the function used to export the key. The function can be installed by using a Cryptography API: Next Generation (CNG) [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID).

### `EncryptedKey`

A [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that contains the session key encrypted by the public key of the recipient.

### `dwFlags`

A value that specifies what members have been updated, and whose memory allocation must be freed by using the [CryptMsgOpenToEncode](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgopentoencode) function.

| Value | Meaning |
| --- | --- |
| **CMSG_KEY_TRANS_ENCRYPT_FREE_OBJID_FLAG**<br><br>0x00000002 | The **pszObjId** member of the [CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure referred to by the **KeyEncryptionAlgorithm** member was updated. |
| **CMSG_KEY_TRANS_ENCRYPT_FREE_PARA_FLAG**<br><br>0x00000001 | The **Parameters** **pbData** member of the [CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure referred to by the **KeyEncryptionAlgorithm** member was updated. |

## Remarks

 When called with the *dwMsgType* parameter set to **CMSG_ENVELOPED**, the [CryptMsgOpenToEncode](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-cmsg_key_trans_recipient_encode_info) function initializes the **CMSG_KEY_TRANS_ENCRYPT_INFO** structure from the [CMSG_KEY_TRANS_RECIPIENT_ENCODE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_key_trans_recipient_encode_info) structure. The **CryptMsgOpenToEncode** function calls the [PFN_CMSG_EXPORT_KEY_TRANS](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cmsg_export_key_trans) function to update the **CMSG_KEY_TRANS_ENCRYPT_INFO** structure. If the callback function cannot be found, the **CryptMsgOpenToEncode** function fills this structure with default key information from the [CMSG_CONTENT_ENCRYPT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_content_encrypt_info) structure.

The following members of the **CMSG_KEY_TRANS_ENCRYPT_INFO** structure can be updated by the callback function:

**EncryptedKey**

**KeyEncryptionAlgorithm.pszObjId**

**KeyEncryptionAlgorithm.Parameters**

**dwFlags**

The other members are read-only.

## See also

[Encoding Enveloped Data](https://learn.microsoft.com/windows/desktop/SecCrypto/encoding-enveloped-data)
# CMSG_RC2_AUX_INFO structure

## Description

The **CMSG_RC2_AUX_INFO** structure contains the bit length of the key for RC2 encryption algorithms. The **pvEncryptionAuxInfo** member in [CMSG_ENVELOPED_ENCODE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_enveloped_encode_info) can be set to point to an instance of this structure.

**Note** This structure is only used when the other members of a [CMSG_ENVELOPED_ENCODE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_enveloped_encode_info) structure indicate that a default key length of 40 bits is to be used with an RC2 encryption algorithm. For more information, see
**CMSG_ENVELOPED_ENCODE_INFO**.

## Members

### `cbSize`

Size of this structure in bytes.

### `dwBitLen`

Specifies the RC2 effective key length. Currently 40-, 64-, and 128-bit lengths are supported.

**Note** This value is the actual key bit length to be used. The values of the **dwVersion** member of a
[CRYPT_RC2_CBC_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_rc2_cbc_parameters) structure to indicate the use of a specific key length is not that specific key length. For example, the **dwVersion** value that indicates the use of a 128-bit key length is CRYPT_RC2_128BIT_VERSION, which is defined as 58, not 128 bits.

**Note** If **dwBitLen** is set to CMSG_SP3_COMPATIBLE_ENCRYPT_FLAG, SP3 compatible encryption is done and the 40-bit default length is ignored.

## See also

[CMSG_ENVELOPED_ENCODE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_enveloped_encode_info)

[CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier)
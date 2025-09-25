# CMSG_RC4_AUX_INFO structure

## Description

The **CMSG_RC4_AUX_INFO** structure contains the bit length of the key for RC4 encryption algorithms. The **pvEncryptionAuxInfo** member in [CMSG_ENVELOPED_ENCODE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_enveloped_encode_info) can be set to point to an instance of this structure.

## Members

### `cbSize`

Size of this structure in bytes.

### `dwBitLen`

Determines the RC4 [salt length](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). If set to CMSG_RC4_NO_SALT_FLAG, no salt is generated. For any other value, (128 - the length set) /8 bytes of salt are generated and encoded as an OCTET STRING in the algorithm parameters field.
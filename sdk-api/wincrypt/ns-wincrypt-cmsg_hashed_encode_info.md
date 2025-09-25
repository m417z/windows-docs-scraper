# CMSG_HASHED_ENCODE_INFO structure

## Description

The **CMSG_HASHED_ENCODE_INFO** structure is used with [hashed](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) messages. It is passed to
the [CryptMsgOpenToEncode](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgopentoencode) function if the **CryptMsgOpenToEncode** function's *dwMsgType* parameter is **CMSG_ENVELOPED**.

## Members

### `cbSize`

The size, in bytes, of this structure.

### `hCryptProv`

This member is not used and should be set to **NULL**.

**Windows Server 2003 and Windows XP:** Specifies a handle to the [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) used to do the hash. The *hCryptProv* private keys are not used.

This member's data type is **HCRYPTPROV**.

Unless there is a strong reason for passing in a specific cryptographic provider in *hCryptProv*, pass zero to use the default RSA or DSS provider to be acquired before doing hash, signature verification, or recipient encryption operations.

### `HashAlgorithm`

A [CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure that contains the hash algorithm type and any associated additional parameters.

### `pvHashAuxInfo`

This member is currently not used and must be set to **NULL**.

## See also

[CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier)
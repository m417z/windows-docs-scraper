# CRYPT_SMIME_CAPABILITIES structure

## Description

The **CRYPT_SMIME_CAPABILITIES** structure contains a prioritized array of supported capabilities. Capabilities include signature algorithms, [symmetric algorithms](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly), key enciphering algorithms, and non-algorithm capabilities, which are the preference for [signed data](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) and the preference for unencrypted messages.

**Note** The **CRYPT_SMIME_CAPABILITIES** are part of an Internet draft proposal. For a complete definition, see "draft-dusse-s/mime-cert-01.txt" dated May 5, 1997.

## Members

### `cCapability`

Count of elements in the **rgCapability** array.

### `rgCapability`

Prioritized array of pointers to
[CRYPT_SMIME_CAPABILITY](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_smime_capability) structures each indicating a capability or preference of a user.

## See also

[CRYPT_SMIME_CAPABILITY](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_smime_capability)
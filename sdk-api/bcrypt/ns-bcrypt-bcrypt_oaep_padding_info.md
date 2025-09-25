# BCRYPT_OAEP_PADDING_INFO structure

## Description

The **BCRYPT_OAEP_PADDING_INFO** structure is used to provide options for the Optimal Asymmetric Encryption Padding (OAEP) scheme.

## Members

### `pszAlgId`

A pointer to a null-terminated Unicode string that identifies the [cryptographic algorithm](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) to use to create the padding. This algorithm must be a [hashing algorithm](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly).

### `pbLabel`

The address of a buffer that contains the data to use to create the padding. The **cbLabel** member contains the size of this buffer.

### `cbLabel`

Contains the number of bytes in the **pbLabel** buffer to use to create the padding.

## See also

[BCryptDecrypt](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptdecrypt)

[BCryptEncrypt](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptencrypt)
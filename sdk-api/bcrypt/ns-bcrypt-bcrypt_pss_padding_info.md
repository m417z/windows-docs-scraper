# BCRYPT_PSS_PADDING_INFO structure

## Description

The **BCRYPT_PSS_PADDING_INFO** structure is used to provide options for the Probabilistic Signature Scheme (PSS) padding scheme.

## Members

### `pszAlgId`

A pointer to a null-terminated Unicode string that identifies the [cryptographic algorithm](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) to use to create the padding. This algorithm must be a [hashing algorithm](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly).

### `cbSalt`

The size, in bytes, of the random salt to use for the padding.

## See also

[BCryptSignHash](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptsignhash)

[BCryptVerifySignature](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptverifysignature)
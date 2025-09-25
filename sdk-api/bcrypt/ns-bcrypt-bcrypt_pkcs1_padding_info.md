# BCRYPT_PKCS1_PADDING_INFO structure

## Description

The **BCRYPT_PKCS1_PADDING_INFO** structure is used to provide options for the [PKCS #1](https://learn.microsoft.com/windows/win32/SecGloss/p-gly) padding scheme.

## Members

### `pszAlgId`

A pointer to a null-terminated Unicode string that identifies the [cryptographic algorithm](https://learn.microsoft.com/windows/win32/SecGloss/c-gly) to use to create the padding. This algorithm must be a [hashing algorithm](https://learn.microsoft.com/windows/win32/SecGloss/h-gly). When creating a signature, the [object identifier](https://learn.microsoft.com/windows/win32/SecGloss/o-gly) (OID) that corresponds to this algorithm is added to the **DigestInfo** element in the signature, and if this member is `NULL`, then the OID is not added. When verifying a signature, the verification fails if the OID that corresponds to this member is not the same as the OID in the signature. If there is no OID in the signature, then verification fails unless this member is `NULL`.

## See also

[CNG Algorithm Identifiers](https://learn.microsoft.com/windows/win32/seccng/cng-algorithm-identifiers)

[BCryptDecrypt](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptdecrypt)

[BCryptEncrypt](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptencrypt)

[BCryptSignHash](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptsignhash)

[BCryptVerifySignature](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptverifysignature)
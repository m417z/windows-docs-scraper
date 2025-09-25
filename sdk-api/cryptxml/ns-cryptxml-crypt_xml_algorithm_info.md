# CRYPT_XML_ALGORITHM_INFO structure

## Description

The **CRYPT_XML_ALGORITHM_INFO** structure contains algorithm information.

## Members

### `cbSize`

The size, in bytes, of this structure.

### `wszAlgorithmURI`

A pointer to a null-terminated Unicode string that contains the URI associated with the attribute of the **SignatureMethod** or **DigestMethod** element of the XML signature.

### `wszName`

Optional. A pointer to a null-terminated Unicode string that contains the display name of the algorithm.

### `dwGroupId`

A **DWORD** value that specifies the group type to which the algorithm belongs. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CRYPT_XML_GROUP_ID_HASH**<br><br>1 | Hash algorithms |
| **CRYPT_XML_GROUP_ID_SIGN**<br><br>2 | Signature algorithms |

### `wszCNGAlgid`

A pointer to a null-terminated Unicode string that contains an algorithm identifier string that is passed to Cryptography API: Next Generation (CNG) functions. CNG functions use algorithm identifier strings, such as L"SHA1", instead of the **ALG_ID** data type constants, such as CALG_SHA1.

**Note** BCrypt* and NCrypt* functions are defined in Bcrypt.h and Ncrypt.h.

### `wszCNGExtraAlgid`

A pointer to a null-terminated Unicode string that contains an extra algorithm string, other than the string in the **pwszCNGAlgid** member, that is passed to CNG functions.

**Note** BCrypt* and NCrypt* functions are defined in Bcrypt.h and Ncrypt.h.

### `dwSignFlags`

A **DWORD** value that contains flag values to be passed to the [NCryptSignHash](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncryptsignhash) function.

### `dwVerifyFlags`

A **DWORD** value that is passed to the [BCryptVerifySignature](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptverifysignature) function.

### `pvPaddingInfo`

A pointer to a structure that contains padding information to be passed to the [NCryptSignHash](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncryptsignhash) or [BCryptVerifySignature](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptverifysignature) function. The actual type of structure this member points to depends on the value of the **dwGroupId** member.

### `pvExtraInfo`

Optional. A pointer to a structure that contains extra information that can be passed to the CNG functions.

**Note** BCrypt* and NCrypt* functions are defined in Bcrypt.h and Ncrypt.h.

## See also

[Digital Signature Cryptographic Algorithms](https://learn.microsoft.com/windows/desktop/SecCrypto/xml-digital-signature-cryptographic-algorithms)
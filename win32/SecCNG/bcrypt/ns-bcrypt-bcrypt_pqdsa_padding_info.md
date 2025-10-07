# BCRYPT_PQDSA_PADDING_INFO structure

> [!NOTE]
> Some information relates to a prerelease product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here. The feature described in this topic is available in pre-release versions of the [Windows Insider Preview](https://www.microsoft.com/software-download/windowsinsiderpreviewSDK).

The **BCRYPT_PQDSA_PADDING_INFO** structure is used to specify the padding scheme for Post-Quantum Digital Signature algorithms (PQDSA).

## Fields

### pbCtx

A pointer to the buffer that contains the context string.

May be `NULL`. If **pbCtx** is `NULL`, then **cbCtx** must be set to `0`.

### cbCtx

The size, in bytes, of the context string pointed to by **pbCtx**. Its value must be `0` if **pbCtx** is `NULL`. Otherwise, it must be a non-zero integer less than `256`.

### pszPrehashAlgId

A CNG hash [algorithm identifier](https://learn.microsoft.com/windows/win32/SecCNG/cng-algorithm-identifiers). This parameter indicates whether the pure (e.g. ML-DSA) or the pre-hash (e.g. HashML-DSA) variant will be used. A `NULL` value indicates the use of pure variant. To use a pre-hash variant, this identifier must refer to an approved hash algorithm: SHA-2, SHA-3, or SHAKE.

## Remarks

For many PQDSA signatures, the use of **BCRYPT_PQDSA_PADDING_INFO** is not required. Using `NULL` *pPaddingInfo* in calls to [BCryptSignHash](https://learn.microsoft.com/windows/win32/api/Bcrypt/nf-bcrypt-bcryptsignhash) and [BCryptVerifySignature](https://learn.microsoft.com/windows/win32/api/Bcrypt/nf-bcrypt-bcryptverifysignature) is equivalent to using pure variant with an empty context string.

## Requirements

| Requirement | Value |
| ---- | ---- |
| **Minimum supported client** | **Windows Insiders (build 27843):** Support for ML-DSA begins. [desktop apps only] |
| **Minimum supported server** | **Windows Insiders (build 27843):** Support for ML-DSA begins. [desktop apps only] |
| **Header** | `bcrypt.h` |

## See also

[BCryptSignHash](https://learn.microsoft.com/windows/win32/api/Bcrypt/nf-bcrypt-bcryptsignhash)

[BCryptVerifySignature](https://learn.microsoft.com/windows/win32/api/Bcrypt/nf-bcrypt-bcryptverifysignature)
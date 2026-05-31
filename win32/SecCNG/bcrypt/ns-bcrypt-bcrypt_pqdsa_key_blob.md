# BCRYPT_PQDSA_KEY_BLOB structure

> [!NOTE]
> Some information relates to a prerelease product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here. The composite features described in this topic is available in pre-release versions of the [Windows Insider Preview](https://www.microsoft.com/software-download/windowsinsiderpreviewSDK).

This structure is used to import and export keys for Post-Quantum Digital Signature algorithms (PQDSA).
The **BCRYPT_PQDSA_KEY_BLOB** structure is used as a header for a Post-Quantum Digital Signature algorithm (PQDSA)
[public key](https://learn.microsoft.com/windows/win32/SecGloss/p-gly) (byte-encoded encapsulation key) or [private key](https://learn.microsoft.com/windows/win32/SecGloss/p-gly) [BLOB](https://learn.microsoft.com/windows/win32/SecGloss/b-gly) in memory.

## Fields

### dwMagic

The **dwMagic** field is a 4-byte value that indicates the format of the key being used. The following values are defined:

| Value | Meaning |
|--|--|
| **BCRYPT_MLDSA_PUBLIC_MAGIC** `0x4B505344` | The structure represents a public key. |
| **BCRYPT_MLDSA_PRIVATE_MAGIC** `0x4B535344` | The structure represents an expanded private key. |
| **BCRYPT_MLDSA_PRIVATE_SEED_MAGIC** `0x53535344` | The structure represents a private seed. |
| **BCRYPT_COMPOSITE_MLDSA_PUBLIC_MAGIC** `0x4B504D43` | The structure represents a public key. |
| **BCRYPT_COMPOSITE_MLDSA_PRIVATE_MAGIC** `0x4B534D43` | The structure represents a private key. |

### cbParameterSet

The length, in bytes, of the buffer `parameterSet` directly following the struct. This buffer contains a null-terminated Unicode string that identifies the parameter set of the key. The following values are currently supported:

| parameterSet | Meaning |
|--|--|
| **BCRYPT_MLDSA_PARAMETER_SET_44** `L"44"` | ML-DSA-44, security category 2. |
| **BCRYPT_MLDSA_PARAMETER_SET_65** `L"65"` | ML-DSA-65, security category 3. |
| **BCRYPT_MLDSA_PARAMETER_SET_87** `L"87"` | ML-DSA-87, security category 5. |
| **BCRYPT_COMPOSITE_MLDSA_PARAMETER_SET_44_ECDSA_P256_SHA256** `L"44-ECDSA-P256-SHA256"` | Composite ML-DSA-44 and ECDSA P256 |
| **BCRYPT_COMPOSITE_MLDSA_PARAMETER_SET_65_ECDSA_P256_SHA512** `L"65-ECDSA-P256-SHA512"` | Composite ML-DSA-65 and ECDSA P256 |
| **BCRYPT_COMPOSITE_MLDSA_PARAMETER_SET_65_ECDSA_P384_SHA512** `L"65-ECDSA-P384-SHA512"` | Composite ML-DSA-65 and ECDSA P384 |
| **BCRYPT_COMPOSITE_MLDSA_PARAMETER_SET_87_ECDSA_P384_SHA512** `L"87-ECDSA-P384-SHA512"` | Composite ML-DSA-87 and ECDSA P384 |

### cbKey

The length, in bytes, of the buffer **key** directly following **parameterSet**. This size is static and depends on the key format and parameter set in use.

## Remarks

The consumers of Post-Quantum Digital Signature algorithms will use the same subset of the BCrypt API as the existing (non-Post-Quantum) Digital Signature Algorithms supported by CNG in order to perform the operations the algorithms support. These are:

- Algorithm handle manipulation: [BCryptOpenAlgorithmProvider](https://learn.microsoft.com/windows/win32/api/Bcrypt/nf-bcrypt-bcryptopenalgorithmprovider), [BCryptCloseAlgorithmProvider](https://learn.microsoft.com/windows/win32/api/Bcrypt/nf-bcrypt-bcryptclosealgorithmprovider)
- Key management: [BCryptGenerateKeyPair](https://learn.microsoft.com/windows/win32/api/Bcrypt/nf-bcrypt-bcryptgeneratekeypair), [BCryptImportKeyPair](https://learn.microsoft.com/windows/win32/api/Bcrypt/nf-bcrypt-bcryptimportkeypair), [BCryptExportKey](https://learn.microsoft.com/windows/win32/api/Bcrypt/nf-bcrypt-bcryptexportkey), [BCryptDestroyKey](https://learn.microsoft.com/windows/win32/api/Bcrypt/nf-bcrypt-bcryptdestroykey), [BCryptFinalizeKeyPair](https://learn.microsoft.com/windows/win32/api/Bcrypt/nf-bcrypt-bcryptfinalizekeypair)
- Signature generation/verification: [BCryptSignHash](https://learn.microsoft.com/windows/win32/api/Bcrypt/nf-bcrypt-bcryptsignhash), [BCryptVerifySignature](https://learn.microsoft.com/windows/win32/api/Bcrypt/nf-bcrypt-bcryptverifysignature)
- Updating/Querying properties: [BCryptGetProperty](https://learn.microsoft.com/windows/win32/api/Bcrypt/nf-bcrypt-bcryptgetproperty), [BCryptSetProperty](https://learn.microsoft.com/windows/win32/api/Bcrypt/nf-bcrypt-bcryptsetproperty)

## Requirements

| Requirement | Value |
| ---- | ---- |
| **Minimum supported client** | **Windows 11 24H2:** Support for ML-DSA begins. [desktop apps only] |
| **Minimum supported server** | **Windows Server 2025:** Support for ML-DSA begins. [desktop apps only] |
| **Header** | `bcrypt.h` |
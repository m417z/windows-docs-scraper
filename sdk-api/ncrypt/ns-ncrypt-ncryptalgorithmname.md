# NCryptAlgorithmName structure

## Description

The **NCryptAlgorithmName** structure is used to contain information about a CNG algorithm.

## Members

### `pszName`

A pointer to a null-terminated Unicode string that contains the name of the algorithm. This can be one of the standard [CNG Algorithm Identifiers](https://learn.microsoft.com/windows/desktop/SecCNG/cng-algorithm-identifiers) or the identifier for another registered algorithm.

### `dwClass`

A **DWORD** value that defines which algorithm class this algorithm belongs to. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **NCRYPT_ASYMMETRIC_ENCRYPTION_INTERFACE**<br><br>0x00000003 | The algorithm belongs to the asymmetric encryption class of algorithms. |
| **NCRYPT_SECRET_AGREEMENT_INTERFACE**<br><br>0x00000004 | The algorithm belongs to the secret agreement (Diffie-Hellman) class of algorithms. |
| **NCRYPT_SIGNATURE_INTERFACE**<br><br>0x00000005 | The algorithm belongs to the signature class of algorithms. |

### `dwAlgOperations`

A **DWORD** value that defines which operational classes this algorithm belongs to. This can be a combination of one or more of the following values.

| Value | Meaning |
| --- | --- |
| **NCRYPT_ASYMMETRIC_ENCRYPTION_OPERATION**<br><br>0x00000004 | The algorithm is an asymmetric encryption algorithm. |
| **NCRYPT_SECRET_AGREEMENT_OPERATION**<br><br>0x00000008 | The algorithm is a secret agreement (Diffie-Hellman) algorithm. |
| **NCRYPT_SIGNATURE_OPERATION**<br><br>0x00000010 | The algorithm is a digital signature algorithm. |

### `dwFlags`

A set of flags that provide more information about the algorithm.

## See also

[NCryptEnumAlgorithms](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncryptenumalgorithms)
# BCryptEnumAlgorithms function

## Description

The **BCryptEnumAlgorithms** function gets a list of the registered algorithm identifiers.

## Parameters

### `dwAlgOperations` [in]

A value that specifies the algorithm operation types to include in the enumeration. This can be a combination of one or more of the following values.

| Value | Meaning |
| --- | --- |
| **BCRYPT_CIPHER_OPERATION**<br><br>0x00000001 | Include the cipher algorithms in the enumeration. |
| **BCRYPT_HASH_OPERATION**<br><br>0x00000002 | Include the hash algorithms in the enumeration. |
| **BCRYPT_ASYMMETRIC_ENCRYPTION_OPERATION**<br><br>0x00000004 | Include the asymmetric encryption algorithms in the enumeration. |
| **BCRYPT_SECRET_AGREEMENT_OPERATION**<br><br>0x00000008 | Include the secret agreement algorithms in the enumeration. |
| **BCRYPT_SIGNATURE_OPERATION**<br><br>0x00000010 | Include the signature algorithms in the enumeration. |
| **BCRYPT_RNG_OPERATION**<br><br>0x00000020 | Include the random number generator (RNG) algorithms in the enumeration. |
| **BCRYPT_KEY_DERIVATION_OPERATION**<br><br>0x00000040 | Include the key derivation algorithms in the enumeration. |

### `pAlgCount` [out]

A pointer to a **ULONG** variable to receive the number of elements in the *ppAlgList* array.

### `ppAlgList` [out]

The address of a [BCRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/bcrypt/ns-bcrypt-bcrypt_algorithm_identifier) structure pointer to receive the array of registered algorithm identifiers. This pointer must be passed to the [BCryptFreeBuffer](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptfreebuffer) function when it is no longer needed.

### `dwFlags` [in]

A set of flags that modify the behavior of this function. No flags are defined for this function.

## Return value

Returns a status code that indicates the success or failure of the function.

Possible return codes include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The function was successful. |
| **STATUS_INVALID_PARAMETER** | One or more parameters are not valid. |
| **STATUS_NO_MEMORY** | A memory allocation failure occurred. |

## Remarks

**BCryptEnumAlgorithms** can be called either from user mode or kernel mode. Kernel mode callers must be executing at **PASSIVE_LEVEL** [IRQL](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly).
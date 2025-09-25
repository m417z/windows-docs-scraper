# BCryptRemoveContextFunction function

## Description

[**BCryptRemoveContextFunction** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **BCryptRemoveContextFunction** function removes a cryptographic function from the list of functions that are supported by an existing CNG context.

## Parameters

### `dwTable` [in]

Identifies the configuration table that the context exists in. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CRYPT_LOCAL** | The context exists in the local-machine configuration table. |
| **CRYPT_DOMAIN** | This value is not available for use. |

### `pszContext` [in]

A pointer to a null-terminated Unicode string that contains the identifier of the context to remove the function from.

### `dwInterface` [in]

Identifies the cryptographic interface to remove the function from. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **BCRYPT_ASYMMETRIC_ENCRYPTION_INTERFACE** | Remove the function from the list of asymmetric encryption functions. |
| **BCRYPT_CIPHER_INTERFACE** | Remove the function from the list of cipher functions. |
| **BCRYPT_HASH_INTERFACE** | Remove the function from the list of hash functions. |
| **BCRYPT_RNG_INTERFACE** | Remove the function from the list of random number generator functions. |
| **BCRYPT_SECRET_AGREEMENT_INTERFACE** | Remove the function from the list of secret agreement functions. |
| **BCRYPT_SIGNATURE_INTERFACE** | Remove the function from the list of signature functions. |
| **NCRYPT_KEY_STORAGE_INTERFACE** | Remove the function from the list of key storage functions. |
| **NCRYPT_SCHANNEL_INTERFACE** | Remove the function from the list of Schannel functions. |
| **NCRYPT_SCHANNEL_SIGNATURE_INTERFACE** | Remove the function from the list of signature suites that Schannel accepts for TLS 1.2.<br><br>**Windows Vista and Windows Server 2008:** This value is not supported. |

### `pszFunction` [in]

A pointer to a null-terminated Unicode string that contains the identifier of the cryptographic function to remove.

## Return value

Returns a status code that indicates the success or failure of the function.

Possible return codes include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The function was successful. |
| **STATUS_INVALID_PARAMETER** | One or more parameters are not valid. |
| **STATUS_NOT_FOUND** | The specified context or function could not be found. |

## Remarks

**BCryptRemoveContextFunction** can be called only in user mode.

## See also

[BCryptAddContextFunction](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptaddcontextfunction)
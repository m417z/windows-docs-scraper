# BCryptAddContextFunction function

## Description

[**BCryptAddContextFunction** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **BCryptAddContextFunction** function adds a cryptographic function to the list of functions that are supported by an existing CNG context.

## Parameters

### `dwTable` [in]

Identifies the configuration table that the context exists in. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CRYPT_LOCAL** | The context exists in the local-machine configuration table. |
| **CRYPT_DOMAIN** | This value is not available for use. |

### `pszContext` [in]

A pointer to a null-terminated Unicode string that contains the identifier of the context to add the function to.

### `dwInterface` [in]

Identifies the cryptographic interface to add the function to. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **BCRYPT_ASYMMETRIC_ENCRYPTION_INTERFACE** | Add the function to the list of asymmetric encryption functions. |
| **BCRYPT_CIPHER_INTERFACE** | Add the function to the list of cipher functions. |
| **BCRYPT_HASH_INTERFACE** | Add the function to the list of hash functions. |
| **BCRYPT_RNG_INTERFACE** | Add the function to the list of random number generator functions. |
| **BCRYPT_SECRET_AGREEMENT_INTERFACE** | Add the function to the list of secret agreement functions. |
| **BCRYPT_SIGNATURE_INTERFACE** | Add the function to the list of signature functions. |
| **NCRYPT_KEY_STORAGE_INTERFACE** | Add the function to the list of key storage functions. |
| **NCRYPT_SCHANNEL_INTERFACE** | Add the function to the list of Schannel functions. |
| **NCRYPT_SCHANNEL_SIGNATURE_INTERFACE** | Add the function to the list of signature suites that Schannel will accept for TLS 1.2.<br><br>**Windows Vista and Windows Server 2008:** This value is not supported. |

### `pszFunction` [in]

A pointer to a null-terminated Unicode string that contains the identifier of the cryptographic function to add.

### `dwPosition` [in]

Specifies the position in the list at which to insert this function. The function is inserted at this position ahead of any existing functions. The **CRYPT_PRIORITY_TOP** value is used to insert the function at the top of the list. The **CRYPT_PRIORITY_BOTTOM** value is used to insert the function at the end of the list.

## Return value

Returns a status code that indicates the success or failure of the function.

Possible return codes include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The function was successful. |
| **STATUS_INVALID_PARAMETER** | One or more parameters are not valid. |
| **STATUS_NO_MEMORY** | A memory allocation failure occurred. |
| **STATUS_NOT_FOUND** | The context could not be found. |

## Remarks

If the function added is already in the list, it will be removed and inserted at the new position.

**BCryptAddContextFunction** can be called only in user mode.

## See also

[BCryptRemoveContextFunction](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptremovecontextfunction)
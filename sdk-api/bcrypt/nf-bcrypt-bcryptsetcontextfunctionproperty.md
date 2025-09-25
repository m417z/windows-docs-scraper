# BCryptSetContextFunctionProperty function

## Description

The **BCryptSetContextFunctionProperty** function sets the value of a named property for a cryptographic function in an existing CNG context.

## Parameters

### `dwTable` [in]

Identifies the configuration table that the context exists in. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CRYPT_LOCAL** | The context exists in the local-machine configuration table. |
| **CRYPT_DOMAIN** | This value is not available for use. |

### `pszContext` [in]

A pointer to a null-terminated Unicode string that contains the identifier of the context to set the function property in.

### `dwInterface` [in]

Identifies the cryptographic interface that the function exists in. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **BCRYPT_ASYMMETRIC_ENCRYPTION_INTERFACE** | The function exists in the list of asymmetric encryption functions. |
| **BCRYPT_CIPHER_INTERFACE** | The function exists in the list of cipher functions. |
| **BCRYPT_HASH_INTERFACE** | The function exists in the list of hash functions. |
| **BCRYPT_RNG_INTERFACE** | The function exists in the list of random number generator functions. |
| **BCRYPT_SECRET_AGREEMENT_INTERFACE** | The function exists in the list of secret agreement functions. |
| **BCRYPT_SIGNATURE_INTERFACE** | The function exists in the list of signature functions. |
| **NCRYPT_KEY_STORAGE_INTERFACE** | The function exists in the list of key storage functions. |
| **NCRYPT_SCHANNEL_INTERFACE** | The function exists in the list of Schannel functions. |

### `pszFunction` [in]

A pointer to a null-terminated Unicode string that contains the identifier of the cryptographic function to set the property for.

### `pszProperty` [in]

A pointer to a null-terminated Unicode string that contains the identifier of the property to set.

### `cbValue` [in]

Contains the size, in bytes, of the *pbValue* buffer. This is the exact number of bytes that will be stored. If the property value is a string, you should add the size of one character to also store the terminating null character, if needed.

### `pbValue` [in]

The address of a buffer that contains the new property value.

## Return value

Returns a status code that indicates the success or failure of the function.

Possible return codes include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The function was successful. |
| **STATUS_ACCESS_DENIED** | The caller does not have write access to the properties for the function. |
| **STATUS_INVALID_PARAMETER** | One or more parameters are not valid. |
| **STATUS_NO_MEMORY** | A memory allocation failure occurred. |
| **STATUS_NOT_FOUND** | The specified context or function could not be found. |

## Remarks

**BCryptSetContextFunctionProperty** can be called only in user mode.
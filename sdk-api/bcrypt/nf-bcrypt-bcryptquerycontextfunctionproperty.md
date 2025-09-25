# BCryptQueryContextFunctionProperty function

## Description

The **BCryptQueryContextFunctionProperty** function obtains the value of a named property for a cryptographic function in an existing CNG context.

## Parameters

### `dwTable` [in]

Identifies the configuration table that the context exists in. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CRYPT_LOCAL** | The context exists in the local-machine configuration table. |
| **CRYPT_DOMAIN** | This value is not available for use. |

### `pszContext` [in]

A pointer to a null-terminated Unicode string that contains the identifier of the context to obtain the function property from.

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

A pointer to a null-terminated Unicode string that contains the identifier of the cryptographic function to obtain the property for.

### `pszProperty` [in]

A pointer to a null-terminated Unicode string that contains the identifier of the property to obtain.

### `pcbValue` [in, out]

The address of a **ULONG** variable that, on entry, contains the size, in bytes, of the buffer pointed to by *ppbValue*. If this size is not large enough to hold the property value, this function will fail with **STATUS_BUFFER_TOO_SMALL**.

After this function returns, this variable contains the number of bytes that were copied to the *ppbValue* buffer.

### `ppbValue` [in, out]

The address of a pointer to a buffer that receives the property data. The size and format of this buffer depends on the format of the property being retrieved. The value pointed to by the *pcbValue* parameter contains the size of this buffer.

If the value pointed to by this parameter is **NULL**, this function will allocate the required memory. This memory must be freed when it is no longer needed by passing this pointer to the [BCryptFreeBuffer](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptfreebuffer) function.

If this parameter is **NULL**, this function will place the required size, in bytes, in the variable pointed to by the *pcbValue* parameter and return **STATUS_BUFFER_TOO_SMALL**.

## Return value

Returns a status code that indicates the success or failure of the function.

Possible return codes include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The function was successful. |
| **STATUS_BUFFER_TOO_SMALL** | The *ppbValue* parameter is not **NULL**, and the value pointed to by the *pcbValue* parameter is not large enough to hold the set of contexts. |
| **STATUS_INVALID_PARAMETER** | One or more parameters are not valid. |
| **STATUS_NO_MEMORY** | A memory allocation failure occurred. |
| **STATUS_NOT_FOUND** | The specified context, function, or property could not be found. |

## Remarks

**BCryptQueryContextFunctionProperty** can be called only in user mode.
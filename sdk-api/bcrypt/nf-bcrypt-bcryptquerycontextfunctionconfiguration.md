# BCryptQueryContextFunctionConfiguration function

## Description

[**BCryptQueryContextFunctionConfiguration** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **BCryptQueryContextFunctionConfiguration** function obtains the cryptographic function configuration information for an existing CNG context.

## Parameters

### `dwTable` [in]

Identifies the configuration table that the context exists in. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CRYPT_LOCAL** | The context exists in the local-machine configuration table. |
| **CRYPT_DOMAIN** | This value is not available for use. |

### `pszContext` [in]

A pointer to a null-terminated Unicode string that contains the identifier of the context to obtain the function configuration information for.

### `dwInterface` [in]

Identifies the cryptographic interface to obtain the function configuration information for. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **BCRYPT_ASYMMETRIC_ENCRYPTION_INTERFACE** | Obtain the function configuration information from the list of asymmetric encryption functions. |
| **BCRYPT_CIPHER_INTERFACE** | Obtain the function configuration information from the list of cipher functions. |
| **BCRYPT_HASH_INTERFACE** | Obtain the function configuration information from the list of hash functions. |
| **BCRYPT_RNG_INTERFACE** | Obtain the function configuration information from the list of random number generator functions. |
| **BCRYPT_SECRET_AGREEMENT_INTERFACE** | Obtain the function configuration information from the list of secret agreement functions. |
| **BCRYPT_SIGNATURE_INTERFACE** | Obtain the function configuration information from the list of signature functions. |
| **NCRYPT_KEY_STORAGE_INTERFACE** | Obtain the function configuration information from the list of key storage functions. |
| **NCRYPT_SCHANNEL_INTERFACE** | Obtain the function configuration information from the list of Schannel functions. |

### `pszFunction` [in]

A pointer to a null-terminated Unicode string that contains the identifier of the cryptographic function to obtain the configuration information for.

### `pcbBuffer` [in, out]

The address of a **ULONG** variable that, on entry, contains the size, in bytes, of the buffer pointed to by *ppBuffer*. If this size is not large enough to hold the context information, this function will fail with **STATUS_BUFFER_TOO_SMALL**.

After this function returns, this variable contains the number of bytes that were copied to the *ppBuffer* buffer.

### `ppBuffer` [in, out]

The address of a pointer to a [CRYPT_CONTEXT_FUNCTION_CONFIG](https://learn.microsoft.com/windows/desktop/api/bcrypt/ns-bcrypt-crypt_context_function_config) structure that receives the function configuration information retrieved by this function. The value pointed to by the *pcbBuffer* parameter contains the size of this buffer.

If the value pointed to by this parameter is **NULL**, this function will allocate the required memory. This memory must be freed when it is no longer needed by passing this pointer to the [BCryptFreeBuffer](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptfreebuffer) function.

If this parameter is **NULL**, this function will place the required size, in bytes, in the variable pointed to by the *pcbBuffer* parameter and return **STATUS_BUFFER_TOO_SMALL**.

For more information about the usage of this parameter, see Remarks.

## Return value

Returns a status code that indicates the success or failure of the function.

Possible return codes include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The function was successful. |
| **STATUS_BUFFER_TOO_SMALL** | The *ppBuffer* parameter is not **NULL**, and the value pointed to by the *pcbBuffer* parameter is not large enough to hold the set of contexts. |
| **STATUS_INVALID_PARAMETER** | One or more parameters are not valid. |
| **STATUS_NO_MEMORY** | A memory allocation failure occurred. |
| **STATUS_NOT_FOUND** | The specified context or function could not be found. |

## Remarks

Each cryptographic function has only one set of configuration information, so although the *ppBuffer* parameter appears to be a used as an array, this function treats this as an array with only one element. The following example helps clarify how this parameter is used.

```cpp
// Get the function configuration information.
CRYPT_CONTEXT_FUNCTION_CONFIG FuncConfig;
ULONG uSize = sizeof(FuncConfig);
PCRYPT_CONTEXT_FUNCTION_CONFIG pFuncConfig = &FuncConfig;
status = BCryptQueryContextFunctionConfiguration(
    CRYPT_LOCAL,
    pszContext,
    NCRYPT_SCHANNEL_INTERFACE,
    pszFunction,
    &uSize,
    &pFuncConfig);

```

**BCryptQueryContextFunctionConfiguration** can be called only in user mode.

## See also

[CRYPT_CONTEXT_FUNCTION_CONFIG](https://learn.microsoft.com/windows/desktop/api/bcrypt/ns-bcrypt-crypt_context_function_config)
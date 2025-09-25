# BCryptQueryContextConfiguration function

## Description

[**BCryptQueryContextConfiguration** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **BCryptQueryContextConfiguration** function retrieves the current configuration for the specified CNG context.

## Parameters

### `dwTable` [in]

Identifies the configuration table that the context exists in. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CRYPT_LOCAL** | The context exists in the local-machine configuration table. |
| **CRYPT_DOMAIN** | This value is not available for use. |

### `pszContext` [in]

A pointer to a null-terminated Unicode string that contains the identifier of the context to obtain the configuration information for.

### `pcbBuffer` [in, out]

The address of a **ULONG** variable that, on entry, contains the size, in bytes, of the buffer pointed to by *ppBuffer*. If this size is not large enough to hold the context information, this function will fail with **STATUS_BUFFER_TOO_SMALL**.

After this function returns, this variable contains the number of bytes that were copied to the *ppBuffer* buffer.

### `ppBuffer` [in, out]

The address of a pointer to a [CRYPT_CONTEXT_CONFIG](https://learn.microsoft.com/windows/desktop/api/bcrypt/ns-bcrypt-crypt_context_config) structure that receives the context configuration information retrieved by this function. The value pointed to by the *pcbBuffer* parameter contains the size of this buffer.

If the value pointed to by this parameter is **NULL**, this function will allocate the required memory. This memory must be freed when it is no longer needed by passing this pointer to the [BCryptFreeBuffer](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptfreebuffer) function.

If this parameter is **NULL**, this function will place the required size, in bytes, in the variable pointed to by the *pcbBuffer* parameter and return **STATUS_BUFFER_TOO_SMALL**.

For more information on the usage of this parameter, see Remarks.

## Return value

Returns a status code that indicates the success or failure of the function.

Possible return codes include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The function was successful. |
| **STATUS_BUFFER_TOO_SMALL** | The *ppBuffer* parameter is not **NULL**, and the value pointed to by the *pcbBuffer* parameter is not large enough to hold the set of contexts. |
| **STATUS_INVALID_PARAMETER** | One or more parameters are not valid. |
| **STATUS_NO_MEMORY** | A memory allocation failure occurred. |
| **STATUS_NOT_FOUND** | The specified context could not be found. |

## Remarks

Each context has only one set of configuration information, so although the *ppBuffer* parameter appears to be a used as an array, this function treats this as an array with only one element. The following example helps clarify how this parameter is used.

```cpp
// Get the configuration information for the context.
CRYPT_CONTEXT_CONFIG config;
ULONG uSize = sizeof(config);
PCRYPT_CONTEXT_CONFIG pConfig = &config;
status = BCryptQueryContextConfiguration(
    CRYPT_LOCAL,
    pszContextID,
    &uSize,
    &pConfig);

```

**BCryptQueryContextConfiguration** can be called only in user mode.
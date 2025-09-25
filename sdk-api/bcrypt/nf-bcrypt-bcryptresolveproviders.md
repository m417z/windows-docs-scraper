# BCryptResolveProviders function

## Description

The **BCryptResolveProviders** function obtains a collection of all of the providers that meet the specified criteria.

## Parameters

### `pszContext` [in, optional]

A pointer to a null-terminated Unicode string that contains the identifier of the context for which to obtain the providers. If this is set to **NULL** or to an empty string, the default context is assumed.

### `dwInterface` [in, optional]

The identifier of an interface that the provider must support. This must be one of the [CNG Interface Identifiers](https://learn.microsoft.com/windows/desktop/SecCNG/cng-interface-identifiers). If the *pszFunction* parameter is not **NULL** or an empty string, you can set *dwInterface* to zero to force the function to infer the interface.

### `pszFunction` [in, optional]

A pointer to a null-terminated Unicode string that contains the algorithm or function identifier that the provider must support. This can be one of the standard [CNG Algorithm Identifiers](https://learn.microsoft.com/windows/desktop/SecCNG/cng-algorithm-identifiers) or the identifier for another registered algorithm. If *dwInterface* is set to a nonzero value, then *pszFunction* can be **NULL** to include all algorithms and functions.

### `pszProvider` [in, optional]

A pointer to a null-terminated Unicode string that contains the name of the provider to retrieve. If this parameter is **NULL**, then all providers will be included.

This parameter allows you to specify a specific provider to retrieve in the event that more than one provider meets the other criteria.

### `dwMode` [in]

Specifies the type of provider to retrieve. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CRYPT_UM** | Retrieve user mode providers. |
| **CRYPT_KM** | Retrieve kernel mode providers. |
| **CRYPT_MM** | Retrieve both user mode and kernel mode providers. |

### `dwFlags` [in]

A set of flags that modify the behavior of this function.

This can be a zero or a combination of one or more of the following values.

| Value | Meaning |
| --- | --- |
| **CRYPT_ALL_FUNCTIONS**<br><br>1 | This function will retrieve all of the functions supported by each provider that meets the specified criteria. If this flag is not specified, this function will only retrieve the first function of the provider or providers that meet the specified criteria. |
| **CRYPT_ALL_PROVIDERS**<br><br>2 | This function will retrieve all of the providers that meet the specified criteria. If this flag is not specified, this function will only retrieve the first provider that is found that meets the specified criteria. |

### `pcbBuffer` [in, out]

A pointer to a **DWORD** value that, on entry, contains the size, in bytes, of the buffer pointed to by the *ppBuffer* parameter. On exit, this value receives either the number of bytes copied to the buffer or the required size, in bytes, of the buffer.

### `ppBuffer` [in, out]

The address of a [CRYPT_PROVIDER_REFS](https://learn.microsoft.com/windows/desktop/api/bcrypt/ns-bcrypt-crypt_provider_refs) pointer that receives the collection of providers that meet the specified criteria.

If this parameter is **NULL**, this function will return **STATUS_SUCCESS** and place in the value pointed to by the *pcbBuffer* parameter, the required size, in bytes, of all the data.

If this parameter is the address of a **NULL** pointer, this function will allocate the required memory, fill the memory with the information about the providers, and place the pointer to this memory in this parameter. When you have finished using this memory, free it by passing this pointer to the [BCryptFreeBuffer](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptfreebuffer) function.

If this parameter is the address of a non-**NULL** pointer, this function will copy the provider information into this buffer. The *pcbBuffer* parameter must contain the size, in bytes, of the entire buffer. If the buffer is not large enough to hold all of the provider information, this function will return **STATUS_BUFFER_TOO_SMALL**.

## Return value

Returns a status code that indicates the success or failure of the function.

Possible return codes include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The function was successful. |
| **STATUS_BUFFER_TOO_SMALL** | The size specified by the *pcbBuffer* parameter is not large enough to hold all of the data. |
| **STATUS_INVALID_PARAMETER** | One or more parameters are not valid. |
| **STATUS_NOT_FOUND** | No provider could be found that meets all of the specified criteria. |

## Remarks

**BCryptResolveProviders** can be called either from user mode or kernel mode. Kernel mode callers must be executing at **PASSIVE_LEVEL** [IRQL](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly).
# BCryptEnumRegisteredProviders function

## Description

The **BCryptEnumRegisteredProviders** function retrieves information about the registered providers.

## Parameters

### `pcbBuffer` [in, out]

A pointer to a **ULONG** value that, on entry, contains the size, in bytes, of the buffer pointed to by the *ppBuffer* parameter. On exit, this value receives either the number of bytes copied to the buffer or the required size, in bytes, of the buffer.

**Note** This is the total size, in bytes, of the entire buffer, not just the size of the [CRYPT_PROVIDERS](https://learn.microsoft.com/windows/desktop/api/bcrypt/ns-bcrypt-crypt_providers) structure. The buffer must be able to hold other data for the providers in addition to the **CRYPT_PROVIDERS** structure.

### `ppBuffer` [in, out]

A pointer to a buffer pointer that receives a [CRYPT_PROVIDERS](https://learn.microsoft.com/windows/desktop/api/bcrypt/ns-bcrypt-crypt_providers) structure and other data that describes the collection of registered providers.

If this parameter is **NULL**, this function will return **STATUS_BUFFER_TOO_SMALL** and place in the value pointed to by the *pcbBuffer* parameter, the required size, in bytes, of all the data.

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

## Remarks

The **BCryptEnumRegisteredProviders** function can be called in one of two ways:

* The first is to have the **BCryptEnumRegisteredProviders** function allocate the memory. This is accomplished by passing the address of a **NULL** pointer for the *ppBuffer* parameter.

  The following example shows how to use the **BCryptEnumRegisteredProviders** function to allocate memory by passing the address of a **NULL** pointer for the *ppBuffer* parameter.

  ```cpp
  PCRYPT_PROVIDERS pBuffer = NULL;
  BCryptEnumRegisteredProviders(/*...*/, &pBuffer);

  ```

  This code will allocate the memory required for the [CRYPT_PROVIDERS](https://learn.microsoft.com/windows/desktop/api/bcrypt/ns-bcrypt-crypt_providers) structure and the associated strings. When the **BCryptEnumRegisteredProviders** function is used in this manner, you must free the memory when it is no longer needed by passing *ppBuffer* to the [BCryptFreeBuffer](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptfreebuffer) function.
* The second method is to allocate the required memory yourself. This is accomplished by calling the **BCryptEnumRegisteredProviders** function with **NULL** for the *ppBuffer* parameter. The **BCryptEnumRegisteredProviders** function will place in the value pointed to by the *pcbBuffer* parameter, the required size, in bytes, of the [CRYPT_PROVIDERS](https://learn.microsoft.com/windows/desktop/api/bcrypt/ns-bcrypt-crypt_providers) structure and all strings. You then allocate the required memory and pass the address of this buffer pointer for the *ppBuffer* parameter in a second call to the **BCryptEnumRegisteredProviders** function.

**BCryptEnumRegisteredProviders** can be called only in user mode.

## See also

[BCryptFreeBuffer](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptfreebuffer)

[CRYPT_PROVIDERS](https://learn.microsoft.com/windows/desktop/api/bcrypt/ns-bcrypt-crypt_providers)
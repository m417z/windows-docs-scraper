# BCryptQueryProviderRegistration function

## Description

The **BCryptQueryProviderRegistration** function retrieves information about a CNG provider.

## Parameters

### `pszProvider` [in]

A pointer to a null-terminated Unicode string that contains the name of the provider to obtain information about.

### `dwMode` [in]

Specifies the type of information to retrieve. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CRYPT_ANY** | Retrieve any information for the provider. |
| **CRYPT_UM** | Retrieve the user mode information for the provider. |
| **CRYPT_KM** | Retrieve the kernel mode information for the provider. |
| **CRYPT_MM** | Retrieve both the user mode and kernel mode information for the provider. |

### `dwInterface` [in]

Specifies the interface to retrieve information for. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **BCRYPT_ASYMMETRIC_ENCRYPTION_INTERFACE** | Retrieve the asymmetric encryption interface. |
| **BCRYPT_CIPHER_INTERFACE** | Retrieve the cipher interface. |
| **BCRYPT_HASH_INTERFACE** | Retrieve the hash interface. |
| **NCRYPT_KEY_STORAGE_INTERFACE** | Retrieve the key storage interface. |
| **BCRYPT_RNG_INTERFACE** | Retrieve the random number generator interface. |
| **NCRYPT_SCHANNEL_INTERFACE** | Retrieve the Schannel interface. |
| **BCRYPT_SECRET_AGREEMENT_INTERFACE** | Retrieve the secret agreement interface. |
| **BCRYPT_SIGNATURE_INTERFACE** | Retrieve the signature interface. |

### `pcbBuffer` [in, out]

A pointer to a **ULONG** value that, on entry, contains the size, in bytes, of the buffer pointed to by the *ppBuffer* parameter. On exit, this value receives either the number of bytes copied to the buffer or the required size, in bytes, of the buffer.

**Note** This is the total size, in bytes, of the entire buffer, not just the size of the [CRYPT_PROVIDER_REG](https://learn.microsoft.com/windows/desktop/api/bcrypt/ns-bcrypt-crypt_provider_reg) structure. The buffer must be able to hold other data for the providers in addition to the **CRYPT_PROVIDER_REG** structure.

### `ppBuffer` [in, out]

A pointer to a buffer pointer that receives a [CRYPT_PROVIDER_REG](https://learn.microsoft.com/windows/desktop/api/bcrypt/ns-bcrypt-crypt_provider_reg) structure and other data that describes the provider.

If this parameter is **NULL**, this function will return **STATUS_BUFFER_TOO_SMALL** and place in the value pointed to by the *pcbBuffer* parameter, the required size, in bytes, of all data.

If this parameter is the address of a **NULL** pointer, this function will allocate the required memory, fill it in with the provider information, and place a pointer to this memory in this parameter. When you have finished using this memory, free it by passing this pointer to the [BCryptFreeBuffer](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptfreebuffer) function.

If this parameter is the address of a non-**NULL** pointer, this function will copy the provider information into this buffer. The *pcbBuffer* parameter must contain the size, in bytes, of the entire buffer. If the buffer is not large enough to hold all of the provider information, this function will return **STATUS_BUFFER_TOO_SMALL**.

## Return value

Returns a status code that indicates the success or failure of the function.

Possible return codes include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The function was successful. |
| **STATUS_INVALID_PARAMETER** | One or more parameters are not valid. |
| **STATUS_BUFFER_TOO_SMALL** | The size specified by the *pcbBuffer* parameter is not large enough to hold all of the data. |
| **STATUS_NOT_FOUND** | No provider could be found that matches the specified criteria. |

## Remarks

**BCryptQueryProviderRegistration** can be called only in user mode.

## See also

[BCryptFreeBuffer](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptfreebuffer)

[CRYPT_PROVIDER_REG](https://learn.microsoft.com/windows/desktop/api/bcrypt/ns-bcrypt-crypt_provider_reg)
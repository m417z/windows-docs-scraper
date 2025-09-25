# BCryptEnumProviders function

## Description

The **BCryptEnumProviders** function obtains all of the CNG providers that support a specified algorithm.

## Parameters

### `pszAlgId` [in]

A pointer to a null-terminated Unicode string that identifies the algorithm to obtain the providers for. This can be one of the predefined [CNG Algorithm Identifiers](https://learn.microsoft.com/windows/desktop/SecCNG/cng-algorithm-identifiers) or another algorithm identifier.

### `pImplCount` [out]

A pointer to a **ULONG** variable to receive the number of elements in the *ppImplList* array.

### `ppImplList` [out]

The address of an array of [BCRYPT_PROVIDER_NAME](https://learn.microsoft.com/windows/desktop/api/bcrypt/ns-bcrypt-bcrypt_provider_name) structures to receive the collection of providers that support the specified algorithm. The *pImplCount* parameter receives the number of elements in this array. This memory must be freed when it is no longer needed by passing this pointer to the [BCryptFreeBuffer](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptfreebuffer) function.

### `dwFlags` [in]

A set of flags that modifies the behavior of this function. There are currently no flags defined, so this parameter must be zero.

## Return value

Returns a status code that indicates the success or failure of the function.

Possible return codes include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The function was successful. |
| **STATUS_INVALID_PARAMETER** | One or more parameters are not valid. |
| **STATUS_NO_MEMORY** | A memory allocation failure occurred. |

## Remarks

**BCryptEnumProviders** can be called either from user mode or kernel mode. Kernel mode callers must be executing at **PASSIVE_LEVEL** [IRQL](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly).

## See also

[BCRYPT_PROVIDER_NAME](https://learn.microsoft.com/windows/desktop/api/bcrypt/ns-bcrypt-bcrypt_provider_name)

[BCryptFreeBuffer](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptfreebuffer)
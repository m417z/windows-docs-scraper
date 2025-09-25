# NCryptGetProtectionDescriptorInfo function

## Description

The **NCryptGetProtectionDescriptorInfo** function retrieves a protection descriptor rule string.

## Parameters

### `hDescriptor` [in]

Protection descriptor handle created by calling [NCryptCreateProtectionDescriptor](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptcreateprotectiondescriptor).

### `pMemPara` [in, optional]

Pointer to an [NCRYPT_ALLOC_PARA](https://learn.microsoft.com/windows/desktop/api/ncrypt/ns-ncrypt-ncrypt_alloc_para) structure that you can use to specify custom memory management functions. If you set this argument to **NULL**, the [LocalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localalloc) function is used internally to allocate memory and your application must call [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) to release memory pointed to by the *ppvInfo* parameter.

### `dwInfoType`

Specifies how to return descriptor information to the *ppvInfo* parameter. This can be the following value:

| Value | Meaning |
| --- | --- |
| **NCRYPT_PROTECTION_INFO_TYPE_DESCRIPTOR_STRING** | The *ppvInfo* argument returns the descriptor rule string. |

### `ppvInfo` [out]

Pointer to the descriptor information.

## Return value

Returns a status code that indicates the success or failure of the function. Possible return codes include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **ERROR_SUCCESS** | The function was successful. |
| **NTE_INVALID_PARAMETER** | The *ppvInfo* parameter cannot be **NULL**. |
| **NTE_NOT_SUPPORTED** | An unsupported value was specified in the *dwInfoType* parameter. |
| **NTE_INVALID_HANDLE** | The handle specified by the *hDescriptor* parameter is not valid. |

## See also

[CNG DPAPI Functions](https://learn.microsoft.com/windows/desktop/SecCNG/cng-dpapi-functions)

[NCryptCreateProtectionDescriptor](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptcreateprotectiondescriptor)
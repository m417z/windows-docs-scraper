# NCryptProtectSecret function

## Description

The **NCryptProtectSecret** function encrypts data to a specified protection descriptor. Call [NCryptUnprotectSecret](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptunprotectsecret) to decrypt the data.

## Parameters

### `hDescriptor` [in]

Handle of the protection descriptor object. Create the handle by calling [NCryptCreateProtectionDescriptor](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptcreateprotectiondescriptor).

### `dwFlags` [in]

The flag can be zero or the following value.

| Value | Meaning |
| --- | --- |
| **NCRYPT_SILENT_FLAG** | Requests that the key service provider not display a user interface. |

### `pbData` [in]

Pointer to the byte array to be protected.

### `cbData` [in]

Number of bytes in the binary array specified by the *pbData* parameter.

### `pMemPara` [in, optional]

Pointer to an [NCRYPT_ALLOC_PARA](https://learn.microsoft.com/windows/desktop/api/ncrypt/ns-ncrypt-ncrypt_alloc_para) structure that you can use to specify custom memory management functions. If you set this argument to **NULL**, the [LocalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localalloc) function is used internally to allocate memory and your application must call [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) to release memory pointed to by the *ppbProtectedBlob* parameter.

### `hWnd` [in, optional]

Handle to the parent window of the user interface, if any, to be displayed.

### `ppbProtectedBlob` [out]

Address of a variable that receives a pointer to the encrypted data.

### `pcbProtectedBlob` [out]

Pointer to a **ULONG** variable that contains the size, in bytes, of the encrypted data pointed to by the *ppbProtectedBlob* variable.

## Return value

Returns a status code that indicates the success or failure of the function. Possible return codes include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **ERROR_SUCCESS** | The function was successful. |
| **NTE_INVALID_PARAMETER** | The *pbData*, *ppbProtectedBlob*, and *pcbProtectedBlob* parameters cannot be **NULL**.<br><br>The *cbData* parameter cannot be less than one. |
| **NTE_NO_MEMORY** | Insufficient memory exists to allocate the content encryption key. |
| **NTE_INVALID_HANDLE** | The handle specified by the *hDescriptor* parameter is not valid. |

## Remarks

Use the **NCryptProtectSecret** function to protect keys, key material, and passwords. Use the [NCryptStreamOpenToProtect](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptstreamopentoprotect) and the [NCryptStreamUpdate](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptstreamupdate) functions to encrypt larger messages.

## See also

[CNG DPAPI Functions](https://learn.microsoft.com/windows/desktop/SecCNG/cng-dpapi-functions)

[NCryptCreateProtectionDescriptor](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptcreateprotectiondescriptor)

[NCryptUnprotectSecret](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptunprotectsecret)
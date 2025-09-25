# NCryptUnprotectSecret function

## Description

The **NCryptUnprotectSecret** function decrypts data to a specified protection descriptor. Call [NCryptProtectSecret](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptprotectsecret) to encrypt the data.

## Parameters

### `phDescriptor` [out, optional]

Pointer to the protection descriptor handle.

### `dwFlags` [in]

The flag can be zero or a bitwise OR of the following values.

| Value | Meaning |
| --- | --- |
| **NCRYPT_SILENT_FLAG** | Requests that the key service provider not display a user interface. |
| **NCRYPT_UNPROTECT_NO_DECRYPT** | Decodes only the header of the protected data blob. No actual decryption takes place. |

### `pbProtectedBlob` [in]

Pointer to an array of bytes that contains the data to decrypt.

### `cbProtectedBlob`

The number of bytes in the array pointed to by the *pbProtectedBlob* parameter.

### `pMemPara` [in, optional]

Pointer to an [NCRYPT_ALLOC_PARA](https://learn.microsoft.com/windows/desktop/api/ncrypt/ns-ncrypt-ncrypt_alloc_para) structure that you can use to specify custom memory management functions. If you set this argument to **NULL**, the [LocalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localalloc) function is used internally to allocate memory and your application must call [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) to release memory pointed to by the *ppbData* parameter.

### `hWnd` [in, optional]

Handle to the parent window of the user interface, if any, to be displayed.

### `ppbData` [out]

Address of a variable that receives a pointer to the decrypted data.

### `pcbData` [out]

Pointer to a **ULONG** variable that contains the size, in bytes, of the decrypted data pointed to by the *ppbData* variable.

## Return value

Returns a status code that indicates the success or failure of the function. Possible return codes include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **ERROR_SUCCESS** | The function was successful. |
| **NTE_BAD_FLAGS** | The dwFlags parameter can only contain **NCRYPT_SILENT_FLAG** or **NCRYPT_UNPROTECT_NO_DECRYPT**. |
| **NTE_INVALID_PARAMETER** | The *pbProtectedBlob*, *ppbData*, and *pcbData* parameters cannot be **NULL**.<br><br>The *cbData* parameter cannot be less than one. |

## Remarks

Use the **NCryptUnprotectSecret** function to decrypt keys, key material, and passwords. Use the [NCryptStreamOpenToUnprotect](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptstreamopentounprotect) and the [NCryptStreamUpdate](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptstreamupdate) functions to decrypt larger messages.

## See also

[CNG DPAPI Functions](https://learn.microsoft.com/windows/desktop/SecCNG/cng-dpapi-functions)

[NCryptProtectSecret](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptprotectsecret)
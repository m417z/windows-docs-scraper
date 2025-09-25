# NCryptStreamOpenToProtect function

## Description

The **NCryptStreamOpenToProtect** function opens a stream object that can be used to encrypt large amounts of data to a given protection descriptor. Call [NCryptStreamUpdate](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptstreamupdate) to encrypt the content. To encrypt smaller messages such as keys and passwords, call [NCryptProtectSecret](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptprotectsecret).

## Parameters

### `hDescriptor` [in]

Handle of the protection descriptor. Create the handle by calling [NCryptCreateProtectionDescriptor](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptcreateprotectiondescriptor).

### `dwFlags`

The flag can be zero or the following value.

| Value | Meaning |
| --- | --- |
| **NCRYPT_SILENT_FLAG** | Requests that the key service provider not display a user interface. |

### `hWnd` [in, optional]

Handle to the parent window of the user interface, if any, to be displayed.

### `pStreamInfo` [in]

Pointer to an [NCRYPT_PROTECT_STREAM_INFO](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/ns-ncryptprotect-ncrypt_protect_stream_info) structure that contains the address of a user defined callback function to receive the encrypted data and a pointer to user-defined context data.

### `phStream` [out]

Pointer to the stream object handle.

## Return value

Returns a status code that indicates the success or failure of the function. Possible return codes include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **ERROR_SUCCESS** | The function was successful. |
| **NTE_BAD_FLAGS** | The dwFlags parameter must contain zero (0), **NCRYPT_MACHINE_KEY_FLAG**, or **NCRYPT_SILENT_FLAG**. |
| **NTE_INVALID_HANDLE** | The handle specified by the *hDescriptor* parameter is not valid. |
| **NTE_INVALID_PARAMETER** | The *phStream* and *pStreamInfo* parameters cannot be **NULL**.<br><br>The callback function pointed to by the **pfnStreamOutput** member of the [NCRYPT_PROTECT_STREAM_INFO](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/ns-ncryptprotect-ncrypt_protect_stream_info) structure pointed to by the *pStreamInfo* parameter cannot be **NULL**. |
| **NTE_NO_MEMORY** | There was insufficient memory to allocate a data stream. |

## Remarks

The **NCryptStreamOpenToProtect** function creates an internal stream object that can be used to encrypt large messages. You cannot use the object directly. Instead, you must use the object handle returned by this function.

Call this function before calling the [NCryptStreamUpdate](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptstreamupdate) function. If you are encrypting a large file, use **NCryptStreamUpdate** in a loop that advances through the file block by block, encrypting each block as it advances and notifying your callback when each block is finished. For more information, see **NCryptStreamUpdate**.

The **NCryptStreamOpenToProtect** function writes the unencrypted protection descriptor rule string to the stream object header so that [NCryptStreamOpenToUnprotect](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptstreamopentounprotect) will be able to start the decrypting the stream by using the same protector used during encryption.

## See also

[CNG DPAPI Functions](https://learn.microsoft.com/windows/desktop/SecCNG/cng-dpapi-functions)

[NCRYPT_PROTECT_STREAM_INFO](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/ns-ncryptprotect-ncrypt_protect_stream_info)

[NCryptCreateProtectionDescriptor](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptcreateprotectiondescriptor)

[NCryptStreamClose](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptstreamclose)

[NCryptStreamOpenToUnprotect](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptstreamopentounprotect)

[NCryptStreamUpdate](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptstreamupdate)
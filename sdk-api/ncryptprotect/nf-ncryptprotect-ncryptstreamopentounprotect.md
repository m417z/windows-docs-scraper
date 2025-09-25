# NCryptStreamOpenToUnprotect function

## Description

The **NCryptStreamOpenToUnprotect** function opens a stream object that can be used to decrypt large amounts of data to the same protection descriptor used for encryption. Call [NCryptStreamUpdate](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptstreamupdate) to perform the decryption. To decrypt smaller messages such as keys and passwords, call [NCryptUnprotectSecret](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptunprotectsecret).

## Parameters

### `pStreamInfo` [in]

Pointer to an [NCRYPT_PROTECT_STREAM_INFO](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/ns-ncryptprotect-ncrypt_protect_stream_info) structure that contains the address of a user defined callback function to receive the decrypted data and a pointer to user-defined context data.

### `dwFlags`

A flag that specifies additional information for the key service provider. This can be zero or the following value.

| Value | Meaning |
| --- | --- |
| **NCRYPT_SILENT_FLAG** | Requests that the key service provider not display a user interface. |

### `hWnd` [in, optional]

Handle to the parent window of the user interface, if any, to be displayed.

### `phStream` [out]

Pointer to the handle of the decrypted stream of data.

## Return value

Returns a status code that indicates the success or failure of the function. Possible return codes include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **ERROR_SUCCESS** | The function was successful. |
| **NTE_BAD_FLAGS** | The dwFlags parameter must contain zero (0) or **NCRYPT_SILENT_FLAG**. |
| **NTE_INVALID_PARAMETER** | The *phStream* and *pStreamInfo* parameters cannot be **NULL**.<br><br>The callback function pointed to by the **pfnStreamOutput** member of the [NCRYPT_PROTECT_STREAM_INFO](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/ns-ncryptprotect-ncrypt_protect_stream_info) structure pointed to by the *pStreamInfo* parameter cannot be **NULL**. |
| **NTE_NO_MEMORY** | There was insufficient memory to allocate a data stream. |

## Remarks

The **NCryptStreamOpenToUnprotect** function creates an internal stream object that can be used to encrypt large messages. You cannot use the object directly. Instead, you must use the object handle returned by this function.

Call this function before calling the [NCryptStreamUpdate](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptstreamupdate) function. If you are encrypting a large file, use **NCryptStreamUpdate** in a loop that advances through the file block by block, encrypting each block as it advances and notifying your callback when each block is finished. For more information, see **NCryptStreamUpdate**.

The **NCryptStreamOpenToUnprotect** function retrieves the unencrypted protection descriptor rule string from the stream header. The rule string is placed in the header by the **NCryptStreamOpenToUnprotect** function.

## See also

[CNG DPAPI Functions](https://learn.microsoft.com/windows/desktop/SecCNG/cng-dpapi-functions)

[NCRYPT_PROTECT_STREAM_INFO](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/ns-ncryptprotect-ncrypt_protect_stream_info)

[NCryptStreamClose](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptstreamclose)

[NCryptStreamOpenToProtect](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptstreamopentoprotect)

[NCryptStreamUpdate](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptstreamupdate)
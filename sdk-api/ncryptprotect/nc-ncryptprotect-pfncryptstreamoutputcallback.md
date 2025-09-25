# PFNCryptStreamOutputCallback callback function

## Description

The **PFNCryptStreamOutputCallback** function receives encrypted or decrypted data from tasks started by using the [NCryptStreamOpenToProtect](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptstreamopentoprotect) or [NCryptStreamOpenToUnprotect](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptstreamopentounprotect) functions. This callback must be defined by your application using the following syntax.

## Parameters

### `pvCallbackCtxt` [in]

Pointer to data that you can use to keep track of your application. The data is not modified by the data protection API.

**Note** You can set a pointer to your context data in the **pvCallbackCtxt** member of the [NCRYPT_PROTECT_STREAM_INFO](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/ns-ncryptprotect-ncrypt_protect_stream_info) structure before passing a pointer to that structure in the *pStreamInfo* parameter of the [NCryptStreamOpenToProtect](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptstreamopentoprotect) or [NCryptStreamOpenToUnprotect](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptstreamopentounprotect) functions.

### `pbData` [in]

Pointer to a block of processed data that can be used by the application.

### `cbData`

The size, in bytes, of the processed data pointed to by the *pbData* parameter.

### `fFinal`

If this value is **TRUE**, the current data block is the last to be processed and this
is the last time the callback will be called.

## Return value

If you return any status code other than **ERROR_SUCCESS** from your implementation of this callback function, the stream encryption or decryption process will fail.

| Return code | Description |
| --- | --- |
| **ERROR_SUCCESS** | The function was successful. |

## Remarks

 Set a pointer to this callback function in the **pfnStreamOutput** member of the [NCRYPT_PROTECT_STREAM_INFO](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/ns-ncryptprotect-ncrypt_protect_stream_info) structure. Set a pointer to the structure in the *pStreamInfo* parameter of the [NCryptStreamOpenToProtect](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptstreamopentoprotect) or [NCryptStreamOpenToUnprotect](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptstreamopentounprotect) functions.

You can use this callback to further process the encrypted or decrypted data. A common use of the function is to write the data to disk as it is received from the data protection API. The blocks of encrypted or unencrypted data are created by the [NCryptStreamUpdate](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptstreamupdate) function.

## See also

[CNG DPAPI Functions](https://learn.microsoft.com/windows/desktop/SecCNG/cng-dpapi-functions)

[NCRYPT_PROTECT_STREAM_INFO](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/ns-ncryptprotect-ncrypt_protect_stream_info)

[NCryptStreamOpenToProtect](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptstreamopentoprotect)

[NCryptStreamOpenToUnprotect](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptstreamopentounprotect)

[NCryptStreamUpdate](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptstreamupdate)
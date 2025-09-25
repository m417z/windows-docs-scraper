# NCRYPT_PROTECT_STREAM_INFO structure

## Description

The **NCRYPT_PROTECT_STREAM_INFO** structure is used by the [NCryptStreamOpenToProtect](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptstreamopentoprotect) and [NCryptStreamOpenToUnprotect](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptstreamopentounprotect) functions to pass blocks of processed data to your application.

## Members

### `pfnStreamOutput`

Address of a callback function that accepts data from the stream encryption or decryption process. for more information, see [PFNCryptStreamOutputCallback](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nc-ncryptprotect-pfncryptstreamoutputcallback).

### `pvCallbackCtxt`

Pointer to a buffer supplied by the caller. The buffer is not modified by the data protection API. You can use the buffer to pass generic data to the callback or keep track of your application.

## See also

[NCryptStreamOpenToProtect](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptstreamopentoprotect)

[NCryptStreamOpenToUnprotect](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptstreamopentounprotect)

[PFNCryptStreamOutputCallback](https://learn.microsoft.com/windows/win32/api/ncryptprotect/nc-ncryptprotect-pfncryptstreamoutputcallback)
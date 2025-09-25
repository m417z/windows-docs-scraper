# AVIMakeStreamFromClipboard function

## Description

The **AVIMakeStreamFromClipboard** function creates an editable stream from stream data on the clipboard.

## Parameters

### `cfFormat`

Clipboard flag.

### `hGlobal`

Handle to stream data on the clipboard.

### `ppstream`

Handle to the created stream.

## Return value

Returns zero if successful or an error otherwise.

## Remarks

When an application finishes using the editable stream, it must release the stream to free the resources associated with it.

The argument ppstream is the address of a pointer to an [IAVIStream](https://learn.microsoft.com/windows/desktop/api/vfw/nn-vfw-iavistream) interface.

## See also

[AVIFile Functions](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions)

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)
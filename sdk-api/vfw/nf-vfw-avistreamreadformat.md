# AVIStreamReadFormat function

## Description

The **AVIStreamReadFormat** function reads the stream format data.

## Parameters

### `pavi`

Handle to an open stream.

### `lPos`

Position in the stream used to obtain the format data.

### `lpFormat`

Pointer to a buffer to contain the format data.

### `lpcbFormat`

Pointer to a location indicating the size of the memory block referenced by *lpFormat*. On return, the value is changed to indicate the amount of data read. If *lpFormat* is **NULL**, this parameter can be used to obtain the amount of memory needed to return the format.

## Return value

Returns zero if successful or an error otherwise.

The argument *pavi* is a pointer to an [IAVIStream](https://learn.microsoft.com/windows/desktop/api/vfw/nn-vfw-iavistream) interface.

## Remarks

Standard video stream handlers provide format information in a [BITMAPINFOHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfoheader) structure. Standard audio stream handlers provide format information in a [PCMWAVEFORMAT](https://learn.microsoft.com/previous-versions/dd743663(v=vs.85)) structure. Other data streams can use other structures that describe the stream data.

## See also

[AVIFile Functions](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions)

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)
# AVIStreamEndStreaming function

## Description

The **AVIStreamEndStreaming** function ends streaming.

## Parameters

### `pavi`

Pointer to a stream.

## Return value

Returns zero if successful or an error otherwise.

## Remarks

Many stream implementations ignore this function.

The argument *pavi* contains a pointer to an [IAVIStream](https://learn.microsoft.com/windows/desktop/api/vfw/nn-vfw-iavistream) interface.

## See also

[AVIFile Functions](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions)

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)
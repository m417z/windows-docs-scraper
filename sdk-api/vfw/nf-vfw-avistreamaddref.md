# AVIStreamAddRef function

## Description

The **AVIStreamAddRef** function increments the reference count of an AVI stream.

## Parameters

### `pavi`

Handle to an open AVI stream.

## Return value

Returns the current reference count of the stream. This value should be used only for debugging purposes.

## Remarks

The argument *pavi* contains a pointer to an [IAVIStream](https://learn.microsoft.com/windows/desktop/api/vfw/nn-vfw-iavistream) interface.

## See also

[AVIFile Functions](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions)

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)
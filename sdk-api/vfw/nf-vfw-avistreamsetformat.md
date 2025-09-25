# AVIStreamSetFormat function

## Description

The **AVIStreamSetFormat** function sets the format of a stream at the specified position.

## Parameters

### `pavi`

Handle to an open stream.

### `lPos`

Position in the stream to receive the format.

### `lpFormat`

Pointer to a structure containing the new format.

### `cbFormat`

Size, in bytes, of the block of memory referenced by *lpFormat*.

## Return value

Returns zero if successful or an error otherwise.

## Remarks

The handler for writing AVI files does not accept format changes. Besides setting the initial format for a stream, only changes in the palette of a video stream are allowed in an AVI file. The palette change must occur after any frames already written to the AVI file. Other handlers might impose different restrictions.

The argument *pavi* is a pointer to an [IAVIStream](https://learn.microsoft.com/windows/desktop/api/vfw/nn-vfw-iavistream) interface.

## See also

[AVIFile Functions](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions)

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)
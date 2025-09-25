# AVIStreamReadData function

## Description

The **AVIStreamReadData** function reads optional header data from a stream.

## Parameters

### `pavi`

Handle to an open stream.

### `fcc`

Four-character code identifying the data.

### `lp`

Pointer to the buffer to contain the optional header data.

### `lpcb`

Pointer to the location that specifies the buffer size used for *lpData*. If the read is successful, AVIFile changes this value to indicate the amount of data written into the buffer for *lpData*.

## Return value

Returns zero if successful or an error otherwise. The return value AVIERR_NODATA indicates the system could not find any data with the specified chunk identifier.

## Remarks

This function retrieves only optional header information from the stream. This information is custom and does not have a set format.

The argument *pavi* is a pointer to an [IAVIStream](https://learn.microsoft.com/windows/desktop/api/vfw/nn-vfw-iavistream) interface.

## See also

[AVIFile Functions](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions)

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)
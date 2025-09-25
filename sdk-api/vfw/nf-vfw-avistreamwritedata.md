# AVIStreamWriteData function

## Description

The **AVIStreamWriteData** function writes optional header information to the stream.

## Parameters

### `pavi`

Handle to an open stream.

### `fcc`

Four-character code identifying the data.

### `lp`

Pointer to a buffer containing the data to write.

### `cb`

Number of bytes of data to write into the stream.

## Return value

Returns zero if successful or an error otherwise. The return value AVIERR_READONLY indicates the file was opened without write access.

## Remarks

Use the [AVIStreamWrite](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-avistreamwrite) function to write the multimedia content of the stream. Use [AVIFileWriteData](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-avifilewritedata) to write data that applies to an entire file.

The argument *pavi* is a pointer to an [IAVIStream](https://learn.microsoft.com/windows/desktop/api/vfw/nn-vfw-iavistream) interface.

## See also

[AVIFile Functions](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions)

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)
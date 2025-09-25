# AVIMakeCompressedStream function

## Description

The **AVIMakeCompressedStream** function creates a compressed stream from an uncompressed stream and a compression filter, and returns the address of a pointer to the compressed stream. This function supports audio and video compression.

## Parameters

### `ppsCompressed`

Pointer to a buffer that receives the compressed stream pointer.

### `ppsSource`

Pointer to the stream to be compressed.

### `lpOptions`

Pointer to a structure that identifies the type of compression to use and the options to apply. You can specify video compression by identifying an appropriate handler in the [AVICOMPRESSOPTIONS](https://learn.microsoft.com/windows/desktop/api/vfw/ns-vfw-avicompressoptions) structure. For audio compression, specify the compressed data format.

### `pclsidHandler`

Pointer to a class identifier used to create the stream.

## Return value

Returns AVIERR_OK if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **AVIERR_NOCOMPRESSOR** | A suitable compressor cannot be found. |
| **AVIERR_MEMORY** | There is not enough memory to complete the operation. |
| **AVIERR_UNSUPPORTED** | Compression is not supported for this type of data. This error might be returned if you try to compress data that is not audio or video. |

## Remarks

Applications can read from or write to the compressed stream.

A **PAVISTREAM** is a pointer to an [IAVIStream](https://learn.microsoft.com/windows/desktop/api/vfw/nn-vfw-iavistream) interface.

## See also

[AVIFile Functions](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions)

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)
# AVIStreamCreate function

## Description

The **AVIStreamCreate** function creates a stream not associated with any file.

## Parameters

### `ppavi`

Pointer to a buffer that receives the new stream interface.

### `lParam1`

Stream-handler specific information.

### `lParam2`

Stream-handler specific information.

### `pclsidHandler`

Pointer to the class identifier used for the stream.

## Return value

Returns zero if successful or an error otherwise.

## Remarks

You should not need to call this function. Some functions, such as [CreateEditableStream](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-createeditablestream) and [AVIMakeCompressedStream](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-avimakecompressedstream), use it internally.

The argument *ppavi* contains the address of a pointer to an [IAVIStream](https://learn.microsoft.com/windows/desktop/api/vfw/nn-vfw-iavistream) interface.

## See also

[AVIFile Functions](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions)

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)
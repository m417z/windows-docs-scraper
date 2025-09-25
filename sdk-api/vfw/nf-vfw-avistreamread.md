# AVIStreamRead function

## Description

The **AVIStreamRead** function reads audio, video or other data from a stream according to the stream type.

## Parameters

### `pavi`

Handle to an open stream.

### `lStart`

First sample to read.

### `lSamples`

Number of samples to read. You can also specify the value AVISTREAMREAD_CONVENIENT to let the stream handler determine the number of samples to read.

### `lpBuffer`

Pointer to a buffer to contain the data.

### `cbBuffer`

Size, in bytes, of the buffer pointed to by *lpBuffer*.

### `plBytes`

Pointer to a buffer that receives the number of bytes of data written in the buffer referenced by *lpBuffer*. This value can be **NULL**.

### `plSamples`

Pointer to a buffer that receives the number of samples written in the buffer referenced by *lpBuffer*. This value can be **NULL**.

## Return value

Returns zero if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **AVIERR_BUFFERTOOSMALL** | The buffer size *cbBuffer* was smaller than a single sample of data. |
| **AVIERR_MEMORY** | There was not enough memory to complete the read operation. |
| **AVIERR_FILEREAD** | A disk error occurred while reading the file. |

## Remarks

If *lpBuffer* is **NULL**, this function does not read any data; it returns information about the size of data that would be read.

The argument *pavi* is a pointer to an [IAVIStream](https://learn.microsoft.com/windows/desktop/api/vfw/nn-vfw-iavistream) interface.

## See also

[AVIFile Functions](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions)

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)
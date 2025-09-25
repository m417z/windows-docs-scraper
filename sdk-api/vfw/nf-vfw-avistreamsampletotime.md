# AVIStreamSampleToTime function

## Description

The **AVIStreamSampleToTime** function converts a stream position from samples to milliseconds.

## Parameters

### `pavi`

Handle to an open stream.

### `lSample`

Position information. A sample can correspond to blocks of audio, a video frame, or other format, depending on the stream type.

## Return value

Returns the converted time if successful or −1 otherwise.

## Remarks

The argument *pavi* is a pointer to an [IAVIStream](https://learn.microsoft.com/windows/desktop/api/vfw/nn-vfw-iavistream) interface.

## See also

[AVIFile Functions](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions)

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)
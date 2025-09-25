# AVIStreamTimeToSample function

## Description

The **AVIStreamTimeToSample** function converts from milliseconds to samples.

## Parameters

### `pavi`

Handle to an open stream.

### `lTime`

Time, expressed in milliseconds.

## Return value

Returns the converted time if successful or -1 otherwise.

## Remarks

Samples typically correspond to audio samples or video frames. Other stream types might support different formats than these.

The argument *pavi* is a pointer to an [IAVIStream](https://learn.microsoft.com/windows/desktop/api/vfw/nn-vfw-iavistream) interface.

## See also

[AVIFile Functions](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions)

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)
# AVIStreamBeginStreaming function

## Description

The **AVIStreamBeginStreaming** function specifies the parameters used in streaming and lets a stream handler prepare for streaming.

## Parameters

### `pavi`

Pointer to a stream.

### `lStart`

Starting frame for streaming.

### `lEnd`

Ending frame for streaming.

### `lRate`

Speed at which the file is read relative to its natural speed. Specify 1000 for the normal speed. Values less than 1000 indicate a slower-than-normal speed; values greater than 1000 indicate a faster-than-normal speed.

## Return value

Returns zero if successful or an error otherwise.

## Remarks

The argument *pavi* is a pointer to an [IAVIStream](https://learn.microsoft.com/windows/desktop/api/vfw/nn-vfw-iavistream) interface.

## See also

[AVIFile Functions](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions)

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)
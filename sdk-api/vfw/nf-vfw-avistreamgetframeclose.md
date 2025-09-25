# AVIStreamGetFrameClose function

## Description

The **AVIStreamGetFrameClose** function releases resources used to decompress video frames.

## Parameters

### `pg`

Handle returned from the [AVIStreamGetFrameOpen](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-avistreamgetframeopen) function. After calling this function, the handle is invalid.

## Return value

Returns zero if successful or an error otherwise.

## See also

[AVIFile Functions](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions)

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)
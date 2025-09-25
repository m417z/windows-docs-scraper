# AVIStreamGetFrame function

## Description

The **AVIStreamGetFrame** function returns the address of a decompressed video frame.

## Parameters

### `pg`

Pointer to the [IGetFrame](https://learn.microsoft.com/windows/desktop/api/vfw/nn-vfw-igetframe) interface.

### `lPos`

Position, in samples, within the stream of the desired frame.

## Return value

Returns a pointer to the frame data if successful or **NULL** otherwise. The frame data is returned as a packed DIB.

## Remarks

The returned frame is valid only until the next call to this function or the [AVIStreamGetFrameClose](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-avistreamgetframeclose) function.

## See also

[AVIFile Functions](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions)

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)
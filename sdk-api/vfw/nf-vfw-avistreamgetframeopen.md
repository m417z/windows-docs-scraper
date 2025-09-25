# AVIStreamGetFrameOpen function

## Description

The **AVIStreamGetFrameOpen** function prepares to decompress video frames from the specified video stream.

## Parameters

### `pavi`

Pointer to the video stream used as the video source.

### `lpbiWanted`

Pointer to a structure that defines the desired video format. Specify **NULL** to use a default format. You can also specify AVIGETFRAMEF_BESTDISPLAYFMT to decode the frames to the best format for your display.

## Return value

Returns a **GetFrame** object that can be used with the [AVIStreamGetFrame](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-avistreamgetframe) function. If the system cannot find a decompressor that can decompress the stream to the given format, or to any RGB format, the function returns **NULL**.

The argument *pavi* is a pointer to an [IAVIStream](https://learn.microsoft.com/windows/desktop/api/vfw/nn-vfw-iavistream) interface.

## See also

[AVIFile Functions](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions)

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)
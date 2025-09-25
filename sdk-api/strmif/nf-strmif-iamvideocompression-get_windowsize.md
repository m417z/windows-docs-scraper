# IAMVideoCompression::get_WindowSize

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `get_WindowSize` method retrieves the number of frames over which the compressor will maintain the average data rate.

For example, assuming a data rate of 100K/sec and a frame rate of 10 frames per second, if the window size is 1, then every frame will be 10K or less. If the window size is 5, then every five consecutive frames will average 10K per frame, but individual frames may exceed this size.

The default window size is 1.

## Parameters

### `pWindowSize` [out]

Pointer to a variable that receives the window size, expressed as a number of frames.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_NOTIMPL** | Not implemented. |
| **E_POINTER** | **NULL** pointer argument. |

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMVideoCompression Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamvideocompression)

[IAMVideoCompression::put_WindowSize](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamvideocompression-put_windowsize)
# IQualProp::get_AvgFrameRate

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `get_AvgFrameRate` method retrieves the actual average frame rate since streaming started.

## Parameters

### `piAvgFrameRate`

Pointer to a variable that receives the actual number of frames per second, multiplied by 100. For example, an average frame rate of 30 frames per second will be represented as 3000.

## Return value

Returns an **HRESULT** value.

## Remarks

The actual frame rate during playback might be less than the authored frame rate. For more information on actual versus authored frame rates, see the Remarks section for the [VIDEOINFOHEADER](https://learn.microsoft.com/previous-versions/windows/desktop/api/amvideo/ns-amvideo-videoinfoheader) structure.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IQualProp Interface](https://learn.microsoft.com/windows/desktop/api/amvideo/nn-amvideo-iqualprop)
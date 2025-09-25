# IBasicVideo::get_AvgTimePerFrame

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `get_AvgTimePerFrame` method retrieves the average time between successive frames.

## Parameters

### `pAvgTimePerFrame` [out]

Pointer to a variable of type [REFTIME](https://learn.microsoft.com/windows/desktop/DirectShow/reftime) that receives the average frame time, in seconds.

## Return value

Returns an **HRESULT** value.

## Remarks

This method returns the authored time per frame. This value is typically set by the source filter, which obtains it from information in the video stream itself. This value is not necessarily equal to the actual time per frame at which the video is rendered.

To retrieve the actual frame rate during playback, use the [IQualProp::get_AvgFrameRate](https://learn.microsoft.com/previous-versions/ms786607(v=vs.85)). For more information on actual versus authored frame rates, see the Remarks section for the [VIDEOINFOHEADER](https://learn.microsoft.com/previous-versions/windows/desktop/api/amvideo/ns-amvideo-videoinfoheader) structure.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IBasicVideo Interface](https://learn.microsoft.com/windows/desktop/api/control/nn-control-ibasicvideo)
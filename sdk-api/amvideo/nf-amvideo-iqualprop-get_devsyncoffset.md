# IQualProp::get_DevSyncOffset

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `get_DevSyncOffset` method retrieves the average time difference between when the video frames should have been displayed and when they actually were. This method is the same as the [IQualProp::get_AvgSyncOffset](https://learn.microsoft.com/windows/desktop/api/amvideo/nf-amvideo-iqualprop-get_avgsyncoffset) method except that the value returned is calculated as a standard deviation rather than as a simple average.

## Parameters

### `piDev`

Pointer to a value denoting the accuracy of the video frames displayed.

## Return value

Returns an **HRESULT** value.

## Remarks

When playing video from networks, the presentation can often be disrupted by network glitches. For this reason, expressing the accuracy of video frames by a simple average is inappropriate. Looking at a standard deviation provides a better idea of the overall accuracy.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IQualProp Interface](https://learn.microsoft.com/windows/desktop/api/amvideo/nn-amvideo-iqualprop)
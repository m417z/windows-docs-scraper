# IAMMediaTypeSample::IsSyncPoint

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

> [!NOTE]
> This interface is deprecated. New applications should not use it.

The `IsSyncPoint` method determines if the beginning of a sample is a synchronization point.

## Return value

Returns S_OK if the beginning of the sample is a synchronization point, or S_FALSE otherwise.

## See also

[IAMMediaTypeSample Interface](https://learn.microsoft.com/windows/desktop/api/amstream/nn-amstream-iammediatypesample)
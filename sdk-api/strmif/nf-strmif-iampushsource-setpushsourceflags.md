# IAMPushSource::SetPushSourceFlags

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetPushSourceFlags` method sets flags that specify the behavior of the filter. Currently, applications should not call this method, because request flags are not supported and an application should not override the flags set by the filter.

## Parameters

### `Flags` [in]

Combination of flags from the [AM_PUSHSOURCE_FLAGS](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-_am_pushsource_flags) enumeration.

## Return value

Returns an **HRESULT** value that depends on the implementation of the interface.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMPushSource Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iampushsource)
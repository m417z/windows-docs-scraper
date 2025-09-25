# IAMPushSource::SetMaxStreamOffset

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetMaxStreamOffset` method specifies the stream offset that will be allowed in the filter graph.

## Parameters

### `rtMaxOffset` [in]

Reference time specifying the maximum stream offset.

## Return value

Returns an **HRESULT** value that depends on the implementation of the interface.

## Remarks

If this method is called prior to connecting the filter, the filter can allocate an appropriately sized buffer.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMPushSource Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iampushsource)
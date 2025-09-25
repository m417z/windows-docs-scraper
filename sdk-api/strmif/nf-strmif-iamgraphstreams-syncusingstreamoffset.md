# IAMGraphStreams::SyncUsingStreamOffset

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SyncUsingStreamOffset` method enables or disables synchronization using time-stamp offsets.

## Parameters

### `bUseStreamOffset` [in]

Boolean value indicating whether to use a time-stamp offset. If **TRUE**, live sources will use a time-stamp offset to synchronize streams.

## Return value

Returns S_OK if successful, or an error code otherwise.

## Remarks

By default, the filter graph does not attempt to synchronize live streams by means of time-stamp offsets. Call this method with a value of **TRUE** if you want the filter graph to determine the maximum latency in the graph and adjust time stamps accordingly. For more information, see [IAMPushSource::SetStreamOffset](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iampushsource-setstreamoffset).

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMGraphStreams Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamgraphstreams)
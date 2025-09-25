# IAMGraphStreams::SetMaxGraphLatency

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetMaxGraphLatency` method sets the maximum latency for the graph. You must call the [IAMGraphStreams::SyncUsingStreamOffset](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamgraphstreams-syncusingstreamoffset) method before calling this method.

## Parameters

### `rtMaxGraphLatency` [in]

Specifies the maximum latency in 100-nanosecond units.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_FAIL** | Failure |
| **S_OK** | Success |

## Remarks

At connection time, some live source filters use the maximum latency to determine the size of buffer to allocate. Calling this method before constructing the graph can help to ensure that sufficient buffers are allocated for the expected latency.

If you call this method before calling **SyncUsingStreamOffset**, the method returns E_FAIL.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMGraphStreams Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamgraphstreams)
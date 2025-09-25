# IMediaObjectInPlace::GetLatency

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetLatency` method retrieves the latency introduced by this DMO.

## Parameters

### `pLatencyTime` [out]

Pointer to a variable that receives the latency, in 100-nanosecond units.

## Return value

Returns S_OK if successful. Otherwise, returns an **HRESULT** value indicating the cause of the error.

## Remarks

This method returns the average time required to process each buffer. This value usually depends on factors in the run-time environment, such as the processor speed and the CPU load. One possible way to implement this method is for the DMO to keep a running average based on historical data.

## See also

[IMediaObjectInPlace Interface](https://learn.microsoft.com/windows/desktop/api/mediaobj/nn-mediaobj-imediaobjectinplace)
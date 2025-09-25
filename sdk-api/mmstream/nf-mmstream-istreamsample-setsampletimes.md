# IStreamSample::SetSampleTimes

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This interface is deprecated. New applications should not use it.

Sets the current sample's start and end times. You can call this method prior to updating the sample.

## Parameters

### `pStartTime` [in]

Pointer to a STREAM_TIME value that contains the sample's new start time.

### `pEndTime` [in]

Pointer to a STREAM_TIME value that contains the sample's new end time.

## Return value

Returns S_OK if successful or E_POINTER if one of the parameters is **NULL**.

## Remarks

For streams that have a clock, the times must be relative to the stream's current time. If the stream doesn't have a clock, the times should be relative to the media.

This method applies only to writable streams.

## See also

[IStreamSample Interface](https://learn.microsoft.com/windows/desktop/api/mmstream/nn-mmstream-istreamsample)

[Multimedia Streaming Data Types](https://learn.microsoft.com/windows/desktop/DirectShow/multimedia-streaming-data-types)
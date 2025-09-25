# IMediaPosition::put_StopTime

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `put_StopTime` method sets the time at which the playback will stop, relative to the duration of the stream.

## Parameters

### `llTime` [in]

Stop time, in seconds.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | Invalid argument. |
| **E_NOTIMPL** | Not implemented. |

## Remarks

The stop time ignores the start time and the playback rate. For example, if the start time is 2 seconds, the stop time is 12 seconds, and the playback rate is 2.0, playback will stop after 5 seconds (real time).

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMediaPosition Interface](https://learn.microsoft.com/windows/desktop/api/control/nn-control-imediaposition)
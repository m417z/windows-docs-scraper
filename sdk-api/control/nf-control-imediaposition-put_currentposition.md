# IMediaPosition::put_CurrentPosition

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `put_CurrentPosition` method sets the current position, relative to the total duration of the stream.

## Parameters

### `llTime` [in]

New position, in seconds.

## Return value

Returns an **HRESULT** value. Possible values include the following:

| Return code | Description |
| --- | --- |
| **S_FALSE** | Graph was paused and is in transition back to a running state. |
| **S_OK** | Success. |
| **E_INVALIDARG** | Invalid argument. |
| **E_NOTIMPL** | Not implemented. |

## Remarks

The position specified by the *llTime* parameter is relative to the total duration, ignoring playback rate. For example, if a source file is 10 seconds long, setting the position to 5.0 causes the graph to seek to the middle of the file, regardless of playback rate.

If the filter graph is running, the Filter Graph Manager pauses the graph, issues the seek command, and then runs the graph again. If the method returns while the graph is still transitioning to a running state, the return value is S_FALSE.

If a filter is paused when it receives a seek command, it must flush existing data before it introduces the data from the new position. See [IPin::BeginFlush](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ipin-beginflush) and [IPin::EndFlush](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ipin-endflush).

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMediaPosition Interface](https://learn.microsoft.com/windows/desktop/api/control/nn-control-imediaposition)
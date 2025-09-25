# IPin::EndOfStream

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `EndOfStream` method notifies the pin that no additional data is expected, until a new run command is issued to the filter.

Applications should not call this method. This method is called by other filters to signal the end of the stream.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_UNEXPECTED** | The pin is an output pin. |

## Remarks

Call this method only on input pins. Output pins return E_UNEXPECTED.

This method sends an end-of-stream notification to the pin. The pin delivers the notification downstream. It must serialize end-of-stream notifications with [IMemInputPin::Receive](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imeminputpin-receive) calls. If the pin queues media samples for delivery, it should queue end-of-stream notifications as well. The [IPin::BeginFlush](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ipin-beginflush) method flushes any queued end-of-stream notifications.

## See also

[Data Flow in the Filter Graph](https://learn.microsoft.com/windows/desktop/DirectShow/data-flow-in-the-filter-graph)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IPin Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ipin)
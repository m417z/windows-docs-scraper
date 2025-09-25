# IPin::BeginFlush

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `BeginFlush` method begins a flush operation.

Applications should not call this method. This method is called by other filters, to flush data from the graph.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_UNEXPECTED** | The pin is an output pin. |

## Remarks

Call this method only on input pins. Output pins return E_UNEXPECTED.

In a flush operation, a filter discards whatever data it was processing. It rejects new data until the flush is completed. The flush is completed when the upstream pin calls the [IPin::EndFlush](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ipin-endflush) method. Flushing enables the filter graph to be more responsive when events alter the normal data flow. For example, flushing occurs during a seek.

When `BeginFlush` is called, the filter performs the following steps:

1. Passes the `IPin::BeginFlush` call downstream.
2. Sets an internal flag that causes all data-streaming methods to fail, such as [IMemInputPin::Receive](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imeminputpin-receive).
3. Returns from any blocked calls to the [Receive](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imeminputpin-receive) method.

When the `BeginFlush` notification reaches a renderer filter, the renderer frees any samples that it holds.

After `BeginFlush` is called, the pin rejects all samples from upstream, with a return value of S_FALSE, until the [IPin::EndFlush](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ipin-endflush) method is called.

## See also

[Data Flow in the Filter Graph](https://learn.microsoft.com/windows/desktop/DirectShow/data-flow-in-the-filter-graph)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IPin Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ipin)
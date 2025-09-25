# IAsyncReader::EndFlush

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `EndFlush` method ends a flush operation.

## Return value

Returns S_OK if successful, or S_FALSE otherwise.

## Remarks

While the pin is flushing, the [IAsyncReader::Request](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iasyncreader-request) method fails and the [IAsyncReader::WaitForNext](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iasyncreader-waitfornext) method returns immediately. Call the `EndFlush` method at the end of a flush operation, to reenable the **Request** method.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAsyncReader Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iasyncreader)
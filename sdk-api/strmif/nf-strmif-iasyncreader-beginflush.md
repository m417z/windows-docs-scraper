# IAsyncReader::BeginFlush

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `BeginFlush` method begins a flush operation.

## Return value

Returns S_OK if successful, or S_FALSE otherwise.

## Remarks

This method interrupts all pending read requests. While the pin is flushing, the [IAsyncReader::Request](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iasyncreader-request) method fails and the [IAsyncReader::WaitForNext](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iasyncreader-waitfornext) method returns immediately, possibly with the return code VFW_E_TIMEOUT.

The downstream input pin should call this method whenever the downstream filter flushes the filter graph. After calling this method, call the **WaitForNext** method until it returns **NULL** in the *ppSample* parameter, to clear out the queue of pending samples. Ignore error codes, and release each sample. Then call the [IAsyncReader::EndFlush](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iasyncreader-endflush) method to end the flush operation.

For more information, see [Flushing](https://learn.microsoft.com/windows/desktop/DirectShow/flushing).

#### Examples

The following example shows how a downstream input pin should call this method:

| C++ |
| --- |
| ``` m_pReader->BeginFlush();  while (1) {     IMediaSample *pSample;     DWORD_PTR dwUnused;     m_pReader->WaitForNext(0, &pSample, &dwUnused);     if(pSample) {          pSample->Release();       }      else {  // No more samples.         break;     } } m_pReader->EndFlush(); ``` |

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAsyncReader Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iasyncreader)
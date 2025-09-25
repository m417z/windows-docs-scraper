# IAsyncReader::WaitForNext

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `WaitForNext` method waits for the next pending read request to complete.

## Parameters

### `dwTimeout` [in]

Specifies a time-out in milliseconds. Use the value INFINITE to wait indefinitely

### `ppSample` [out]

Address of a variable that receives an [IMediaSample](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-imediasample) interface pointer.

### `pdwUser` [out]

Pointer to a variable that receives the value of the *dwUser* parameter specified in the [IAsyncReader::Request](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iasyncreader-request) method.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **VFW_E_TIMEOUT** | The time-out expired, or the pin is flushing. |
| **VFW_E_WRONG_STATE** | The pin is flushing. |
| **E_FAIL** | A read error occurred. |
| **S_OK** | Success. |
| **S_FALSE** | Reached the end of the file; retrieved fewer bytes than requested. |

## Remarks

If the method succeeds, the *ppSample* parameter contains a pointer to a media sample, whose buffer holds the requested data. Call the [IMediaSample::GetTime](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imediasample-gettime) method and divide the results by 10,000,000 to determine the start and stop bytes. Samples may be returned out of order. Release the sample when you are finished processing the data.

The method fails if the pin is flushing. However, it may return an empty sample in *ppSample*. If **ppSample* is non-**NULL**, release the sample and discard it. For more information, see [IAsyncReader::BeginFlush](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iasyncreader-beginflush).

If a read error occurs, the source filter sends an error event to the Filter Graph Manager; the caller does not have to signal an error.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAsyncReader Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iasyncreader)
# IMemInputPin::Receive

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `Receive` method receives the next media sample in the stream.

## Parameters

### `pSample` [in]

Pointer to the sample's [IMediaSample](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-imediasample) interface.

## Return value

Returns an **HRESULT** value. Possible values include those shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **S_FALSE** | The sample was rejected. |
| **E_POINTER** | **NULL** pointer argument. |
| **VFW_E_INVALIDMEDIATYPE** | Invalid media type. |
| **VFW_E_RUNTIME_ERROR** | A run-time error occurred. |
| **VFW_E_WRONG_STATE** | The pin is stopped. |

## Remarks

This method is synchronous and possibly blocking. The pin does one of the following:

* Rejects the sample.
* Returns immediately and processes the sample in a worker thread.
* Processes the sample before returning.

In the last case, the method might block indefinitely. If this might happen, the [IMemInputPin::ReceiveCanBlock](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imeminputpin-receivecanblock) method returns S_OK.

If the pin uses a worker thread to process the sample, it holds a reference count on the sample. In any case, the output pin cannot directly re-use this sample. It must call the [IMemAllocator::GetBuffer](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imemallocator-getbuffer) method to obtain a new sample.

If this method returns S_FALSE or an error code, the upstream filter should stop sending samples until the graph stops or completes a flush operation. Typical reasons for an S_FALSE return value include:

* The downstream pin is flushing; that is, it received a **BeginFlush** call and has not yet received an **EndFlush** call.
* The downstream filter detected the end of the stream. (See [End-of-Stream Notifications](https://learn.microsoft.com/windows/desktop/DirectShow/end-of-stream-notifications).)

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMemInputPin Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-imeminputpin)
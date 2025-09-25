# IAsyncReader::Request

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `Request` method queues an asynchronous request for data.

## Parameters

### `pSample`

Pointer to the [IMediaSample](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-imediasample) interface of a media sample provided by the caller.

### `dwUser` [in]

Specifies an arbitrary value that is returned when the request completes.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **VFW_E_BADALIGN** | The buffer is not aligned correctly. |
| **VFW_E_SAMPLE_TIME_NOT_SET** | The sample was not time stamped. |
| **VFW_E_WRONG_STATE** | The pin is flushing. |
| **HRESULT_FROM_WIN32(ERROR_HANDLE_EOF)** | The requested start position is past the end of the file. |
| **E_OUTOFMEMORY** | Insufficient memory. |

## Remarks

Before calling this method, retrieve a media sample from the pin's allocator. Time stamp the sample with the byte offsets you are requesting, first and last inclusive, multiplied by 10,000,000. Byte offsets are relative to the start of the stream.

The start and stop positions should match the alignment that was decided when the pins connected. Otherwise, the method might return VFW_E_BADALIGN. If the agreed alignment is coarser than the actual alignment of the stream, the stop position might exceed the real duration. If so, the method rounds the stop position down to the actual alignment.

Although it is technically a violation of COM rules, the caller must leave an outstanding reference count on the sample. The `Request` method does not call **AddRef** or **Release**, so the reference count is needed to keep the sample active.

The method returns before the request completes. Call the [IAsyncReader::WaitForNext](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iasyncreader-waitfornext) method to wait for the request. Do not reuse the original media sample while the request is pending. The **WaitForNext** method returns a pointer to the original sample. If the request succeeded, the sample contains the requested data. The **WaitForNext** method also returns whatever value is specified in the *dwUser* parameter. The caller can use this value to identify the sample.

#### Examples

The following example shows a possible helper function for an input pin, to queue requests:

| C++ |
| --- |
| ``` CMyPin::QueueSample(long cbFirst, long cbLast, DWORD_PTR dwuser) { IMediaSample* pSample = NULL; HRESULT hr = m_pAlloc->GetBuffer(&pSample, NULL, NULL, 0); if (FAILED(hr)) { return hr; }<br><br> LONGLONG tStart = cbFirst * 10000000, tStop = cbLast * 10000000; hr = pSample->SetTime(&tStart, &tStop); if (SUCCEEDED(hr)) { hr = m_pReader->Request(pSample, dwuser); }<br><br> if (FAILED(hr)) { pSample->Release(); } return hr; } ``` |

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAsyncReader Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iasyncreader)
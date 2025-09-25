# IMemInputPin::ReceiveMultiple

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `ReceiveMultiple` method receives multiple samples in the stream.

## Parameters

### `pSamples` [in]

Address of an array of [IMediaSample](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-imediasample) interface pointers, of size *nSamples*.

### `nSamples` [in]

Number of samples to process.

### `nSamplesProcessed` [out]

Pointer to a variable that receives the number of samples that were processed.

## Return value

Returns an **HRESULT** value. Possible values include those shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **S_FALSE** | Pin is currently flushing; sample was rejected. |
| **E_POINTER** | **NULL** pointer argument. |
| **VFW_E_INVALIDMEDIATYPE** | Invalid media type. |
| **VFW_E_RUNTIME_ERROR** | A run-time error occurred. |
| **VFW_E_WRONG_STATE** | The pin is stopped. |

## Remarks

This method behaves like the [IMemInputPin::Receive](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imeminputpin-receive) method, but receives an array of samples.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMemInputPin Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-imeminputpin)
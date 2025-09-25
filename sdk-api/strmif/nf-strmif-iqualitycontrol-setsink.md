# IQualityControl::SetSink

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetSink` method sets the [IQualityControl](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iqualitycontrol) object that will receive quality messages.

## Parameters

### `piqc`

Pointer to the [IQualityControl](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iqualitycontrol) object to which the notifications should be sent.

## Return value

Returns an **HRESULT** value that depends on the implementation. **HRESULT** can be one of the following standard constants, or other values not listed.

| Return code | Description |
| --- | --- |
| **E_FAIL** | Failure. |
| **E_POINTER** | **NULL** pointer argument. |
| **E_INVALIDARG** | Invalid argument. |
| **E_NOTIMPL** | Method isn't supported. |
| **S_OK or NOERROR** | Success. |

## Remarks

The filter that receives a call to this method should record the *piqc* but should not add a reference count to it. The object pointed to will be a quality manager and will be a part of the filter graph (for example, a plug-in distributor). Adding a reference count to this could cause circular reference problems.

The reference to the object specified in *piqc* is guaranteed to be valid until this method is called with a null value.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IQualityControl Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iqualitycontrol)
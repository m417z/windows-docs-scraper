# IMediaSample2::SetProperties

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetProperties** method sets the properties of a media sample.

## Parameters

### `cbProperties` [in]

Length of property data to set, in bytes.

### `pbProperties` [in]

Pointer to a buffer of size *cbProperties*.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | Invalid argument. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **E_POINTER** | **NULL** pointer argument. |

## Remarks

The data contained in [AM_SAMPLE2_PROPERTIES](https://learn.microsoft.com/windows/win32/api/strmif/ns-strmif-am_sample2_properties) structure. You can specify a subset of the sample properties by setting *cbProperties* to a value less than the size of the **AM_SAMPLE2_PROPERTIES** structure.

The standard implementation of this method does not support updating [AM_SAMPLE2_PROPERTIES](https://learn.microsoft.com/windows/win32/api/strmif/ns-strmif-am_sample2_properties) structure. If these members are not equal to zero, the method returns **E_INVALIDARG**. To modify the data contained in the sample's memory buffer, call [IMediaSample::GetPointer](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imediasample-getpointer).

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMediaSample2 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-imediasample2)
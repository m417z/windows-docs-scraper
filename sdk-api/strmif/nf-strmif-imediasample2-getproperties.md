# IMediaSample2::GetProperties

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetProperties` method retrieves the properties of a media sample.

## Parameters

### `cbProperties` [in]

Length of property data to retrieve, in bytes.

### `pbProperties` [out]

Pointer to a buffer of size *cbProperties*.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | **NULL** pointer argument. |

## Remarks

The retrieved data conforms to the format of the [AM_SAMPLE2_PROPERTIES](https://learn.microsoft.com/windows/win32/api/strmif/ns-strmif-am_sample2_properties) structure. You can retrieve a subset of the sample properties by setting *cbProperties* to a value less than the size of the **AM_SAMPLE2_PROPERTIES** structure.

For efficiency, the **pMediaType** member returned in **AM_SAMPLE2_PROPERTIES** is a pointer to the data stored in the media sample, not a copy of that data. The pointer may become invalid after the sample is passed to another filter, or after the input pin's [IMemInputPin::Receive](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imeminputpin-receive) method has completed. Also, do not free the pointer or delete the media type.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMediaSample2 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-imediasample2)
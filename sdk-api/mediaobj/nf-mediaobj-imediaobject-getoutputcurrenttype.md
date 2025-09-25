# IMediaObject::GetOutputCurrentType

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetOutputCurrentType` method retrieves the media type that was set for an output stream, if any.

## Parameters

### `dwOutputStreamIndex`

Zero-based index of an output stream on the DMO.

### `pmt` [out]

Pointer to a [DMO_MEDIA_TYPE](https://learn.microsoft.com/previous-versions/windows/desktop/api/mediaobj/ns-mediaobj-dmo_media_type) structure allocated by the caller. The method fills the structure with the media type.

## Return value

Returns an **HRESULT** value. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **DMO_E_INVALIDSTREAMINDEX** | Invalid stream index. |
| **DMO_E_TYPE_NOT_SET** | Media type was not set. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **S_OK** | Success. |

## Remarks

The caller must set the media type for the stream before calling this method. To set the media type, call the [IMediaObject::SetOutputType](https://learn.microsoft.com/windows/desktop/api/mediaobj/nf-mediaobj-imediaobject-setoutputtype) method.

If the method succeeds, call [MoFreeMediaType](https://learn.microsoft.com/windows/desktop/api/dmort/nf-dmort-mofreemediatype) to free the format block.

## See also

[IMediaObject Interface](https://learn.microsoft.com/windows/desktop/api/mediaobj/nn-mediaobj-imediaobject)
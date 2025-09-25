# IAMStreamConfig::SetFormat

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetFormat` method sets the output format on the pin.

## Parameters

### `pmt` [in]

Pointer to an [AM_MEDIA_TYPE](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-am_media_type) structure that specifies the new format.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **E_POINTER** | **NULL** pointer value. |
| **VFW_E_INVALIDMEDIATYPE** | This media type is not valid. |
| **VFW_E_NOT_CONNECTED** | The input pin is not connected. |
| **VFW_E_NOT_STOPPED** | Cannot set the type; the filter is not stopped. |
| **VFW_E_WRONG_STATE** | Cannot set the type; the filter is not stopped. |

## Remarks

This method specifies the format for the output pin. If the pin is not connected, it will use this format for its next connection. If the pin is already connected, it will attempt to reconnect with this format. The method might fail if the other pin rejects the new type.

If this method succeeds, subsequent calls to the [IPin::EnumMediaTypes](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ipin-enummediatypes) method will return the new type, and no others.

On most filters, this method fails if the filter is paused or running. On some compression filters, the method fails if the filter's input pin is not connected.

With some filters, you can call this method with the value **NULL** to reset the pin to its default format.

**Filter Developers**: The following remarks describe how to implement this method:

If the output pin is not connected, and the pin supports the specified media type, return S_OK. Store the media type and offer it as format number zero in the [CBasePin::GetMediaType](https://learn.microsoft.com/windows/desktop/DirectShow/cbasepin-getmediatype) method. Do not offer other formats, and reject other formats in the [CBasePin::CheckMediaType](https://learn.microsoft.com/windows/desktop/DirectShow/cbasepin-checkmediatype) method.

If the pin is already connected, and the pin supports the media type, reconnect the pin with that type. If the other pin rejects the new type, return VFW_E_INVALIDMEDIATYPE and restore the original connection.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMStreamConfig Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamstreamconfig)
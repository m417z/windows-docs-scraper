# IAMStreamConfig::GetFormat

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetFormat` method retrieves the current or preferred output format.

## Parameters

### `ppmt` [out]

Address of a pointer to an [AM_MEDIA_TYPE](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-am_media_type) structure.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **E_POINTER** | **NULL** pointer value. |
| **VFW_E_NOT_CONNECTED** | The input pin is not connected. |

## Remarks

If the pin is connected, this method returns the format that the pin is currently using. Otherwise, the method returns the pin's preferred format for the next pin connection. If you have already called the [IAMStreamConfig::SetFormat](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamstreamconfig-setformat) method to set the format, `GetFormat` returns the same format. If not, it returns the first format in the pin's list of preferred formats, as determined by the [IPin::EnumMediaTypes](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ipin-enummediatypes) method.

The method allocates the memory for the **AM_MEDIA_TYPE** structure, fills in the structure, and returns it in the *pmt* parameter. The caller must release the memory, including the format block. You can use the [DeleteMediaType](https://learn.microsoft.com/windows/desktop/DirectShow/deletemediatype) helper function in the base class library.

On some compression filters, the method fails if the filter's input pin is not connected.

#### Examples

| C++ |
| --- |
| ``` IAMStreamConfig *pConfig = NULL; // Query the output pin for IAMStreamConfig (not shown). AM_MEDIA_TYPE *pmt = NULL; hr = pConfig->GetFormat(&pmt); if (SUCCEEDED(hr)) {     /* Examine the media type for any information you need. */     DeleteMediaType(pmt); } pConfig->Release(); ``` |

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMStreamConfig Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamstreamconfig)
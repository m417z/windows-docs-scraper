# IMediaObject::SetOutputType

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetOutputType` method sets the media type on an output stream, or tests whether a media type is acceptable.

## Parameters

### `dwOutputStreamIndex`

Zero-based index of an output stream on the DMO.

### `pmt` [in]

Pointer to a [DMO_MEDIA_TYPE](https://learn.microsoft.com/previous-versions/windows/desktop/api/mediaobj/ns-mediaobj-dmo_media_type) structure that specifies the media type.

### `dwFlags`

Bitwise combination of zero or more flags from the [DMO_SET_TYPE_FLAGS](https://learn.microsoft.com/windows/desktop/api/mediaobj/ne-mediaobj-_dmo_set_type_flags) enumeration.

## Return value

Returns an **HRESULT** value. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **DMO_E_INVALIDSTREAMINDEX** | Invalid stream index |
| **DMO_E_TYPE_NOT_ACCEPTED** | Media type was not accepted |
| **S_FALSE** | Media type is not acceptable |
| **S_OK** | Media type was set successfully, or is acceptable |

## Remarks

Call this method to test, set, or clear the media type on an output stream:

* To test the media type without setting it, use the DMO_SET_TYPEF_TEST_ONLY flag. If the media type is not acceptable, the method returns S_FALSE.
* To set the media type, set *dwFlags* to zero. If the media type is not acceptable, the method returns DMO_E_TYPE_NOT_ACCEPTED.
* To clear the current media type (if any), use the DMO_SET_TYPEF_CLEAR flag and set *pmt* to **NULL**. When the method returns, the stream no longer has a media type. The DMO cannot process samples until the application sets a new media type, unless the stream is optional.

The media types that are currently set on other streams can affect whether the media type is acceptable.

## See also

[IMediaObject Interface](https://learn.microsoft.com/windows/desktop/api/mediaobj/nn-mediaobj-imediaobject)
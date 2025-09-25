# ISBE2MediaTypeProfile::GetStream

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the media type of a stream that appears at a specific index in a media type profile.

## Parameters

### `Index` [in]

The index of the stream. To get the number of the streams in the profile, call the [ISBE2MediaTypeProfile::GetStreamCount](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nf-sbe-isbe2mediatypeprofile-getstreamcount) method.

### `ppMediaType` [out]

Receives a pointer to an [AM_MEDIA_TYPE](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-am_media_type) structure. The caller must not modify this structure or release the memory allocated for it.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| ****S_OK**** | The method succeeded. |
| ****E_INVALIDARG**** | Invalid parameter. |
| ****E_OUTOFMEMORY**** | Not enough memory for media type pointer. |
| ****E_POINTER**** | Null media type pointer. |

## See also

[ISBE2MediaTypeProfile](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-isbe2mediatypeprofile)
# IMFVideoMediaType::GetVideoFormat

## Description

[**GetVideoFormat** is no longer available for use as of Windows 7. Instead, use the media type attributes to get the properties of the video format.]

Returns a pointer to an [MFVIDEOFORMAT](https://learn.microsoft.com/windows/desktop/api/mfobjects/ns-mfobjects-mfvideoformat) structure that describes the video format.

## Return value

This method returns a pointer to an [MFVIDEOFORMAT](https://learn.microsoft.com/windows/desktop/api/mfobjects/ns-mfobjects-mfvideoformat) structure.

## Remarks

If you need to convert the media type into an [MFVIDEOFORMAT](https://learn.microsoft.com/windows/desktop/api/mfobjects/ns-mfobjects-mfvideoformat) structure, call [MFCreateMFVideoFormatFromMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfcreatemfvideoformatfrommfmediatype).

There are no guarantees about how long the returned pointer is valid.

## See also

[IMFVideoMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfvideomediatype)

[Media Types](https://learn.microsoft.com/windows/desktop/medfound/media-types)
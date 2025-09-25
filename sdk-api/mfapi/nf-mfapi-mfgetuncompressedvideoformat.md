# MFGetUncompressedVideoFormat function

## Description

[This API is not supported and may be altered or unavailable in the future. Applications should avoid using the [MFVIDEOFORMAT](https://learn.microsoft.com/windows/desktop/api/mfobjects/ns-mfobjects-mfvideoformat) structure, and use media type attributes instead. For more information, see [Video Media Types](https://learn.microsoft.com/windows/desktop/medfound/video-media-types).]

Returns the FOURCC or **D3DFORMAT** value for an uncompressed video format.

## Parameters

### `pVideoFormat` [in]

Pointer to an [MFVIDEOFORMAT](https://learn.microsoft.com/windows/desktop/api/mfobjects/ns-mfobjects-mfvideoformat) structure.

## Return value

Returns a FOURCC or **D3DFORMAT** value that identifies the video format. If the video format is compressed or not recognized, the return value is D3DFMT_UNKNOWN.

## Remarks

**Note** Prior to Windows 7, this function was exported from evr.dll. Starting in Windows 7, this function is exported from mfplat.dll, and evr.dll exports a stub function that calls into mfplat.dll. For more information, see [Library Changes in Windows 7](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-headers-and-libraries).

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Media Types](https://learn.microsoft.com/windows/desktop/medfound/media-types)

[Video Media Types](https://learn.microsoft.com/windows/desktop/medfound/video-media-types)
# MFInitVideoFormat_RGB function

## Description

[This API is not supported and may be altered or unavailable in the future. Applications should avoid using the [MFVIDEOFORMAT](https://learn.microsoft.com/windows/desktop/api/mfobjects/ns-mfobjects-mfvideoformat) structure, and use media type attributes instead. For more information, see [Video Media Types](https://learn.microsoft.com/windows/desktop/medfound/video-media-types).]

Initializes an [MFVIDEOFORMAT](https://learn.microsoft.com/windows/desktop/api/mfobjects/ns-mfobjects-mfvideoformat) structure for an uncompressed RGB video format.

## Parameters

### `pVideoFormat` [in]

A pointer to an [MFVIDEOFORMAT](https://learn.microsoft.com/windows/desktop/api/mfobjects/ns-mfobjects-mfvideoformat) structure. The functions fills in the structure members with the format information.

### `dwWidth` [in]

The width of the video, in pixels.

### `dwHeight` [in]

The height of the video, in pixels.

### `D3Dfmt` [in]

A **D3DFORMAT** value that specifies the RGB format.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function fills in some reasonable default values for the specified RGB format.

Developers are encouraged to use media type attributes instead of using the [MFVIDEOFORMAT](https://learn.microsoft.com/windows/desktop/api/mfobjects/ns-mfobjects-mfvideoformat) structure. See [Media Type Attributes](https://learn.microsoft.com/windows/desktop/medfound/media-type-attributes).

In general, you should avoid calling this function. If you know all of the format details, you can fill in the [MFVIDEOFORMAT](https://learn.microsoft.com/windows/desktop/api/mfobjects/ns-mfobjects-mfvideoformat) structure without this function. If you do not know all of the format details, attributes are preferable to using the **MFVIDEOFORMAT** structure.

**Note** Prior to Windows 7, this function was exported from evr.dll. Starting in Windows 7, this function is exported from mfplat.dll, and evr.dll exports a stub function that calls into mfplat.dll. For more information, see [Library Changes in Windows 7](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-headers-and-libraries).

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Media Types](https://learn.microsoft.com/windows/desktop/medfound/media-types)

[Uncompressed Video Media Types](https://learn.microsoft.com/windows/desktop/medfound/uncompressed-video-media-types)

[Video Media Types](https://learn.microsoft.com/windows/desktop/medfound/video-media-types)
# MFCreateVideoMediaTypeFromVideoInfoHeader function

## Description

Creates a media type from a **KS_VIDEOINFOHEADER** structure.

## Parameters

### `pVideoInfoHeader`

Pointer to the **KS_VIDEOINFOHEADER** structure to convert. (This structure is identical to the DirectShow **VIDEOINFOHEADER** structure.)

### `cbVideoInfoHeader`

Size of the **KS_VIDEOINFOHEADER** structure in bytes.

### `dwPixelAspectRatioX`

The X dimension of the pixel aspect ratio. The pixel aspect ratio is *dwPixelAspectRatioX*:*dwPixelAspectRatioY*.

### `dwPixelAspectRatioY`

The Y dimension of the pixel aspect ratio.

### `InterlaceMode`

Member of the [MFVideoInterlaceMode](https://learn.microsoft.com/windows/desktop/api/mfobjects/ne-mfobjects-mfvideointerlacemode) enumeration that specifies how the video is interlaced.

### `VideoFlags`

Bitwise **OR** of flags from the [MFVideoFlags](https://learn.microsoft.com/windows/desktop/api/mfobjects/ne-mfobjects-mfvideoflags) enumeration.

### `pSubtype`

Pointer to a subtype GUID. This parameter can be **NULL**. If the subtype GUID is specified, the function uses it to set the media subtype. Otherwise, the function attempts to deduce the subtype from the **biCompression** field contained in the **KS_VIDEOINFOHEADER** structure.

### `ppIVideoMediaType`

Receives a pointer to the [IMFVideoMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfvideomediatype) interface. The caller must release the interface.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**Note** Prior to Windows 7, this function was exported from evr.dll. Starting in Windows 7, this function is exported from mfplat.dll, and evr.dll exports a stub function that calls into mfplat.dll. For more information, see [Library Changes in Windows 7](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-headers-and-libraries).

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Media Types](https://learn.microsoft.com/windows/desktop/medfound/media-types)
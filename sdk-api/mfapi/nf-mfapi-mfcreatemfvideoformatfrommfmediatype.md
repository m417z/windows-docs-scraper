# MFCreateMFVideoFormatFromMFMediaType function

## Description

[This API is not supported and may be altered or unavailable in the future. Applications should avoid using the [MFVIDEOFORMAT](https://learn.microsoft.com/windows/desktop/api/mfobjects/ns-mfobjects-mfvideoformat) structure, and use media type attributes instead. For more information, see [Video Media Types](https://learn.microsoft.com/windows/desktop/medfound/video-media-types).]

Creates an [MFVIDEOFORMAT](https://learn.microsoft.com/windows/desktop/api/mfobjects/ns-mfobjects-mfvideoformat) structure from a video media type.

## Parameters

### `pMFType` [in]

Pointer to the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface of a video media type.

### `ppMFVF` [out]

Receives a pointer to an [MFVIDEOFORMAT](https://learn.microsoft.com/windows/desktop/api/mfobjects/ns-mfobjects-mfvideoformat) structure. The caller must release the memory allocated for the structure by calling [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

### `pcbSize` [out]

Receives the size of the [MFVIDEOFORMAT](https://learn.microsoft.com/windows/desktop/api/mfobjects/ns-mfobjects-mfvideoformat) structure.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Media Type Conversions](https://learn.microsoft.com/windows/desktop/medfound/media-type-conversions)

[Media Types](https://learn.microsoft.com/windows/desktop/medfound/media-types)

[Video Media Types](https://learn.microsoft.com/windows/desktop/medfound/video-media-types)
# MFConvertColorInfoFromDXVA function

## Description

[This API is not supported and may be altered or unavailable in the future. Applications should avoid using the [MFVIDEOFORMAT](https://learn.microsoft.com/windows/desktop/api/mfobjects/ns-mfobjects-mfvideoformat) structure, and use media type attributes instead. For more information, see [Extended Color Information](https://learn.microsoft.com/windows/desktop/medfound/extended-color-information).]

Sets the extended color information in a [MFVIDEOFORMAT](https://learn.microsoft.com/windows/desktop/api/mfobjects/ns-mfobjects-mfvideoformat) structure.

## Parameters

### `pToFormat` [in, out]

Pointer to an [MFVIDEOFORMAT](https://learn.microsoft.com/windows/desktop/api/mfobjects/ns-mfobjects-mfvideoformat) structure. The function fills in the structure members that correspond to the DXVA color information in the *dwFromDXVA* parameter. The function does not modify the other structure members.

### `dwFromDXVA` [in]

**DWORD** that contains extended color information. The bitfields in the **DWORD** are defined in the [DXVA2_ExtendedFormat](https://learn.microsoft.com/windows/desktop/api/dxva2api/ns-dxva2api-dxva2_extendedformat) structure.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function sets the following fields in the [MFVIDEOFORMAT](https://learn.microsoft.com/windows/desktop/api/mfobjects/ns-mfobjects-mfvideoformat) structure.

* **videoInfo.MFNominalRange**
* **videoInfo.MFVideoLighting**
* **videoInfo.MFVideoPrimaries**
* **videoInfo.MFVideoTransferFunction**
* **videoInfo.MFVideoTransferMatrix**
* **videoInfo.SourceChromaSubsampling**

**Note** Prior to Windows 7, this function was exported from evr.dll. Starting in Windows 7, this function is exported from mfplat.dll, and evr.dll exports a stub function that calls into mfplat.dll. For more information, see [Library Changes in Windows 7](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-headers-and-libraries).

## See also

[Extended Color Information](https://learn.microsoft.com/windows/desktop/medfound/extended-color-information)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Media Types](https://learn.microsoft.com/windows/desktop/medfound/media-types)
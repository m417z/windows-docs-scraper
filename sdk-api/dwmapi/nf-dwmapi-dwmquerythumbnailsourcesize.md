# DwmQueryThumbnailSourceSize function

## Description

Retrieves the source size of the Desktop Window Manager (DWM) thumbnail.

## Parameters

### `hThumbnail` [in]

A handle to the thumbnail to retrieve the source window size from.

### `pSize` [out]

A pointer to a [SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size) structure that, when this function returns successfully, receives the size of the source thumbnail.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[DWM Thumbnail Overview](https://learn.microsoft.com/windows/desktop/dwm/thumbnail-ovw)

[Desktop Window Manager Overview](https://learn.microsoft.com/windows/desktop/dwm/dwm-overview)

[DwmUpdateThumbnailProperties](https://learn.microsoft.com/windows/desktop/api/dwmapi/nf-dwmapi-dwmupdatethumbnailproperties)
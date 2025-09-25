# DwmUnregisterThumbnail function

## Description

Removes a Desktop Window Manager (DWM) thumbnail relationship created by the [DwmRegisterThumbnail](https://learn.microsoft.com/windows/desktop/api/dwmapi/nf-dwmapi-dwmregisterthumbnail) function.

## Parameters

### `hThumbnailId` [in]

The handle to the thumbnail relationship to be removed. Null or non-existent handles will result in a return value of E_INVALIDARG.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Unregistering DWM thumbnail relationships must be done within the process that registered the relationships.

## See also

[DWM Thumbnail Overview](https://learn.microsoft.com/windows/desktop/dwm/thumbnail-ovw)

[Desktop Window Manager Overview](https://learn.microsoft.com/windows/desktop/dwm/dwm-overview)

[DwmQueryThumbnailSourceSize](https://learn.microsoft.com/windows/desktop/api/dwmapi/nf-dwmapi-dwmquerythumbnailsourcesize)

[DwmUpdateThumbnailProperties](https://learn.microsoft.com/windows/desktop/api/dwmapi/nf-dwmapi-dwmupdatethumbnailproperties)
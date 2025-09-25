# DXGKDDI_VIDPN_RELEASESOURCEMODESET callback function

## Description

The **pfnReleaseSourceModeSet** function releases a handle to a source mode set object.

## Parameters

### `hVidPn` [in]

A handle to the VidPN object that contains the source mode set object. The VidPN manager previously provided this handle to the display miniport driver by calling [DxgkDdiEnumVidPnCofuncModality](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_enumvidpncofuncmodality), [DxgkDdiIsSupportedVidPn](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_issupportedvidpn), or [DxgkDdiRecommendFunctionalVidPn](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_recommendfunctionalvidpn).

### `hVidPnSourceModeSet` [in]

The handle to be released.

## Return value

The **pfnReleaseSourceModeSet** function returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The function succeeded.|
|STATUS_GRAPHICS_INVALID_VIDPN|The handle supplied in hVidPn was invalid.|
|STATUS_GRAPHICS_INVALID_VIDPN_SOURCEMODESET|The handle supplied in hVidPnSourceModeSet was invalid.|
|STATUS_GRAPHICS_RESOURCES_NOT_RELATED|The VidPN identified by hVidPn does not contain the source mode set identified by hVidPnSourceModeSet.|

## Remarks

When you have finished using a handle that you obtained by calling [pfnAcquireSourceModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_acquiresourcemodeset), you must release the handle by calling **pfnReleaseSourceModeSet**.

If you obtain a handle by calling [pfnCreateNewSourceModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_createnewsourcemodeset) and then pass that handle to [pfnAssignSourceModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_assignsourcemodeset), you do not need to release the handle.

If you obtain a handle by calling **pfnCreateNewSourceModeSet** and then you decide not to assign the new source mode set to a source, you must release the newly obtained handle by calling **pfnReleaseSourceModeSet**.

The D3DKMDT_HVIDPN and D3DKMDT_HVIDPNSOURCEMODESET data types are defined in *D3dkmdt.h*.

## See also

[pfnAcquireSourceModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_acquiresourcemodeset)

[pfnCreateNewSourceModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_createnewsourcemodeset)
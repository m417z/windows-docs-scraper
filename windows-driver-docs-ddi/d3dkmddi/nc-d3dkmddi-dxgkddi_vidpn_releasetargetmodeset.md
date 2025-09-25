# DXGKDDI_VIDPN_RELEASETARGETMODESET callback function

## Description

The **pfnReleaseTargetModeSet** function releases a handle to a target mode set object.

## Parameters

### `hVidPn` [in]

A handle to a VidPN object that contains the target mode set object. The VidPN manager previously provided this handle to the display miniport driver by calling [DxgkDdiEnumVidPnCofuncModality](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_enumvidpncofuncmodality), [DxgkDdiIsSupportedVidPn](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_issupportedvidpn), or [DxgkDdiRecommendFunctionalVidPn](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_recommendfunctionalvidpn).

### `hVidPnTargetModeSet` [in]

The handle to be released.

## Return value

The **pfnReleaseTargetModeSet** function returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The function succeeded.|
|STATUS_GRAPHICS_INVALID_VIDPN|The handle supplied in hVidPn was invalid.|
|STATUS_GRAPHICS_INVALID_VIDPN_TARGETMODESET|The handle supplied in hVidPnTargetModeSet was invalid.|
|STATUS_GRAPHICS_RESOURCES_NOT_RELATED|The VidPN identified by hVidPn does not contain the target mode set identified by hVidPnTargetModeSet.|

## Remarks

When you have finished using a handle that you obtained by calling [pfnAcquireTargetModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_acquiretargetmodeset), you must release the handle by calling **pfnReleaseTargetModeSet**.

If you obtain a handle by calling [pfnCreateNewTargetModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_createnewtargetmodeset) and then pass that handle to [pfnAssignTargetModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_assigntargetmodeset), you do not need to release the handle.

If you obtain a handle by calling **pfnCreateNewTargetModeSet** and then you decide not to assign the new source mode set to a source, you must release the newly obtained handle by calling **pfnReleaseTargetModeSet**.

The D3DKMDT_HVIDPN and D3DKMDT_HVIDPNTARGETMODESET data types are defined in *D3dkmdt.h*.

## See also

[pfnAcquireTargetModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_acquiretargetmodeset)

[pfnCreateNewTargetModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_createnewtargetmodeset)
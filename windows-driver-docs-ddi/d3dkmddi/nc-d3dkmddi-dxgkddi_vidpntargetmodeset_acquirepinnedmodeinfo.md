# DXGKDDI_VIDPNTARGETMODESET_ACQUIREPINNEDMODEINFO callback function

## Description

The **pfnAcquirePinnedModeInfo** function returns a descriptor of the pinned mode in a specified VidPN target mode set.

## Parameters

### `hVidPnTargetModeSet` [in]

A handle to a VidPN target mode set object. The display miniport driver previously obtained this handle by calling the [pfnAcquireTargetModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_acquiretargetmodeset) function of the [DXGK_VIDPN_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_vidpn_interface) interface.

### `ppPinnedVidPnTargetModeInfo` [out]

A pointer to a variable that receives a pointer to a [D3DKMDT_VIDPN_TARGET_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_target_mode) structure. The structure contains a variety of information about the pinned mode, including its ID and video signal characteristics. If the target mode set identified by *hVidPnTargetModeSet* has no pinned mode, then this variable receives a **NULL** pointer.

## Return value

The **pfnAcquirePinnedModeInfo** function returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The function succeeded by doing one of the following:<br>1. Setting ppPinnedVidPnTargetModeInfo to the address of D3DKMDT_VIDPN_TARGET_MODE structure that describes the pinned mode.<br>2. Setting ppPinnedVidPnTargetModeInfo to NULL to indicate that the target mode set has no pinned mode.|
|STATUS_GRAPHICS_INVALID_VIDPN_TARGETMODESET|The handle supplied in hVidPnTargetModeSet was invalid.|

## Remarks

When you have finished using the [D3DKMDT_VIDPN_TARGET_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_target_mode) structure, you must release the structure by calling [pfnReleaseModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntargetmodeset_releasemodeinfo).

The D3DKMDT_HVIDPNTARGETMODESET data type is defined in *D3dkmdt.h*.

## See also

[D3DKMDT_VIDPN_TARGET_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_target_mode)

[pfnPinMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntargetmodeset_pinmode)

[pfnReleaseModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntargetmodeset_releasemodeinfo)
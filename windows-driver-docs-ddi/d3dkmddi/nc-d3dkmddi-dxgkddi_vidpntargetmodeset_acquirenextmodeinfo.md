# DXGKDDI_VIDPNTARGETMODESET_ACQUIRENEXTMODEINFO callback function

## Description

The **pfnAcquireNextModeInfo** function returns a descriptor of the next mode in a specified VidPN target mode set, given the current mode.

## Parameters

### `hVidPnTargetModeSet` [in]

A handle to a VidPN target mode set object. The display miniport driver previously obtained this handle by calling the [pfnAcquireTargetModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_acquiretargetmodeset) function of the [DXGK_VIDPN_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_vidpn_interface) interface.

### `pVidPnTargetModeInfo` [in]

A pointer to a [D3DKMDT_VIDPN_TARGET_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_target_mode) structure that describes the current mode. The display miniport driver previously obtained this pointer by calling [pfnAcquireFirstModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntargetmodeset_acquirefirstmodeinfo) or **pfnAcquireNextModeInfo**.

### `ppNextVidPnTargetModeInfo` [out]

A pointer to a variable that receives a pointer to a D3DKMDT_VIDPN_TARGET_MODE structure that describes the next mode.

## Return value

The **pfnAcquireNextModeInfo** function returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The function succeeded.|
|STATUS_GRAPHICS_INVALID_VIDPN_TARGETMODESET|The handle supplied in hVidPnTargetModeSet was invalid.|

## Remarks

When you have finished using the [D3DKMDT_VIDPN_TARGET_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_target_mode) structure, you must release the structure by calling [pfnReleaseModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntargetmodeset_releasemodeinfo).

You can enumerate all the modes that belong to a particular target mode set object by calling [pfnAcquireFirstModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntargetmodeset_acquirefirstmodeinfo) and then making a sequence of calls to **pfnAcquireNextModeInfo**.

The D3DKMDT_HVIDPNTARGETMODESET data type is defined in *D3dkmdt.h*.

## See also

[D3DKMDT_VIDPN_TARGET_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_target_mode)

[pfnAcquireFirstModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntargetmodeset_acquirefirstmodeinfo)

[pfnReleaseModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntargetmodeset_releasemodeinfo)
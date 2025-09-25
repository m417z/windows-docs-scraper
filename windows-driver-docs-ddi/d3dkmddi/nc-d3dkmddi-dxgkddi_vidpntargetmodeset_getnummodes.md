# DXGKDDI_VIDPNTARGETMODESET_GETNUMMODES callback function

## Description

The **pfnGetNumModes** function returns the number of target modes in a specified VidPN target mode set.

## Parameters

### `hVidPnTargetModeSet`

A handle to a VidPN target mode set object. The display miniport driver previously obtained this handle by calling the [pfnAcquireTargetModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_acquiretargetmodeset) function of the [DXGK_VIDPN_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_vidpn_interface) interface.

### `pNumTargetModes`

A pointer to a SIZE_T-typed variable that receives the number of target modes in the set.

## Return value

The **pfnGetNumModes** function returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The function succeeded.|
|STATUS_GRAPHICS_INVALID_VIDPN_TARGETMODESET|The handle supplied in hVidPnTargetModeSet was invalid.|

## Remarks

The D3DKMDT_HVIDPNTARGETMODESET data type is defined in *D3dkmdt.h*.

## See also

[pfnAcquireFirstModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntargetmodeset_acquirefirstmodeinfo)

[pfnAcquireNextModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntargetmodeset_acquirenextmodeinfo)
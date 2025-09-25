# DXGKDDI_VIDPNTARGETMODESET_ADDMODE callback function

## Description

The **pfnAddMode** function adds a VidPN target mode to a specified VidPN target mode set object.

## Parameters

### `hVidPnTargetModeSet` [in]

A handle to a VidPN target mode set object. The display miniport driver previously obtained this handle by calling the [pfnAcquireTargetModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_acquiretargetmodeset) function of the [DXGK_VIDPN_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_vidpn_interface) interface.

### `pVidPnTargetModeInfo` [in]

A pointer to a [D3DKMDT_VIDPN_TARGET_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_target_mode) structure that describes the target mode. The display miniport driver previously obtained this structure by calling [pfnCreateNewModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntargetmodeset_createnewmodeinfo).

## Return value

The **pfnAddMode** function returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The function succeeded.|
|STATUS_GRAPHICS_INVALID_VIDPN_TARGETMODESET|The handle supplied in hVidPnTargetModeSet was invalid.|

## Remarks

To add a mode to a target mode set, the display miniport driver performs the following steps.

1. Call [pfnCreateNewModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntargetmodeset_createnewmodeinfo) to obtain a pointer to a [D3DKMDT_VIDPN_TARGET_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_target_mode) structure. The **pnfCreateNewModeInfo** function allocates the structure and fills in the **Id** member with a newly generated target mode identifier.
2. The **Info** member of the D3DKMDT_VIDPN_TARGET_MODE structure is a [D3DKMDT_VIDEO_SIGNAL_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_video_signal_info) structure. Populate that structure with information about the mode.
3. Call **pfnAddMode** to add the mode to a target mode set.

The VidPN manager allocates a D3DKMDT_VIDPN_TARGET_MODE structure when you call **pfnCreateNewModeInfo**. If you add the mode described by that structure to a target mode set, you do not need to explicitly release the structure; **pfnAddMode** releases it.

If you obtain a D3DKMDT_VIDPN_TARGET_MODE structure by calling **pfnCreateNewModeInfo** and then decide not to add that mode to a target mode set, you must explicitly release the structure by calling [pfnReleaseModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntargetmodeset_releasemodeinfo).

The D3DKMDT_HVIDPNTARGETMODESET data type is defined in *D3dkmdt.h*.

## See also

[D3DKMDT_VIDPN_TARGET_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_target_mode)

[pfnCreateNewModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntargetmodeset_createnewmodeinfo)

[pfnReleaseModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntargetmodeset_releasemodeinfo)
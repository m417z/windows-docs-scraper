# DXGKDDI_VIDPNTARGETMODESET_CREATENEWMODEINFO callback function

## Description

The **pfnCreateNewModeInfo** function returns a pointer to a [D3DKMDT_VIDPN_TARGET_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_target_mode) structure that the display miniport driver populates before calling [pfnAddMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntargetmodeset_addmode).

## Parameters

### `hVidPnTargetModeSet` [in]

A handle to a VidPN target mode set object. The display miniport driver previously obtained this handle by calling the [pfnAcquireTargetModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_acquiretargetmodeset) function of the [DXGK_VIDPN_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_vidpn_interface) interface.

### `ppNewVidPnTargetModeInfo` [out]

A pointer to a variable that receives a pointer to a D3DKMDT_VIDPN_TARGET_MODE structure allocated by the VidPN manager.

## Return value

The **pfnCreateNewModeInfo** function returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The function succeeded.|
|STATUS_GRAPHICS_INVALID_VIDPN_TARGETMODESET|The handle supplied in hVidPnTargetModeSet was invalid.|

## Remarks

The **pfnCreateNewModeInfo** function allocates a [D3DKMDT_VIDPN_TARGET_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_target_mode) structure and sets its **Id** member to a newly generated identifier.

After you call **pfnCreateNewModeInfo** to obtain a D3DKMDT_VIDPN_TARGET_MODE structure, you must do one, but not both, of the following:

* Populate the **Info** member of the structure and pass the structure to [pfnAddMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntargetmodeset_addmode).
* Release the structure by calling [pfnReleaseModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntargetmodeset_releasemodeinfo).

When you populate a D3DKMDT_VIDPN_TARGET_MODE structure, you have the option of overwriting the **Id** member that was generated and set by **pfnCreateNewModeInfo**. However, if you overwrite the **Id** member of any D3DKMDT_VIDPN_TARGET_MODE structure, you must overwrite the **Id** members of all the D3DKMDT_VIDPN_TARGET_MODE structures you obtain from **pfnCreateNewModeInfo**. Unless you have a specific reason for overwriting the **Id** members (for example, tracking target modes with your own numbering scheme), you should leave them as set by **pfnCreateNewModeInfo**.

The D3DKMDT_HVIDPNTARGETMODESET data type is defined in *D3dkmdt.h*.

## See also

[D3DKMDT_VIDPN_TARGET_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_target_mode)

[pfnAddMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntargetmodeset_addmode)

[pfnReleaseModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntargetmodeset_releasemodeinfo)
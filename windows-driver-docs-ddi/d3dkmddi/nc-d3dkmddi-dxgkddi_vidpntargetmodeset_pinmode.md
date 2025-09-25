# DXGKDDI_VIDPNTARGETMODESET_PINMODE callback function

## Description

The **pfnPinMode** function pins a specified mode in a VidPN target mode set.

## Parameters

### `hVidPnTargetModeSet` [in]

A handle to a VidPN target mode set object. The display miniport driver previously obtained this handle by calling the [pfnAcquireTargetModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_acquiretargetmodeset) function of the [DXGK_VIDPN_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_vidpn_interface) interface.

### `VidPnTargetModeId` [in]

An integer that identifies the mode to be pinned.

## Return value

The **pfnPinMode** function returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The function succeeded.|
|STATUS_GRAPHICS_INVALID_VIDPN_TARGETMODESET|The handle supplied in hVidPnTargetModeSet was invalid.|
|STATUS_GRAPHICS_INVALID_VIDEO_PRESENT_TARGET_MODE|The mode identified by VidPnTargetModeId does not belong to the source mode set represented by hVidPnTargetModeSet.|

## Remarks

VidPN target mode identifiers are assigned by the operating system. The [pfnCreateNewModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntargetmodeset_createnewmodeinfo) function generates a mode identifier, assigns the identifier to the **Id** member of a [D3DKMDT_VIDPN_TARGET_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_target_mode) structure, and returns the structure to the display miniport driver.

The D3DKMDT_HVIDPNTARGETMODESET data type is defined in *D3dkmdt.h*.
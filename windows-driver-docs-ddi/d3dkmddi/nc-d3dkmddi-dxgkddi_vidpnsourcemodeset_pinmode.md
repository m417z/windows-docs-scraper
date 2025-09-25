# DXGKDDI_VIDPNSOURCEMODESET_PINMODE callback function

## Description

The **pfnPinMode** function pins a specified mode in a VidPN source mode set.

## Parameters

### `hVidPnSourceModeSet` [in]

A handle to a VidPN source mode set object. The display miniport driver previously obtained this handle by calling the [pfnAcquireSourceModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_acquiresourcemodeset) function of the [DXGK_VIDPN_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_vidpn_interface) interface.

### `VidPnSourceModeId` [in]

An integer that identifies the mode to be pinned.

## Return value

The **pfnPinMode** function returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The function succeeded.|
|STATUS_GRAPHICS_INVALID_VIDPN_SOURCEMODESET|The handle supplied in hVidPnSourceModeSet was invalid.|
|STATUS_GRAPHICS_INVALID_VIDEO_PRESENT_SOURCE_MODE|The mode identified by VidPnSourceModeId does not belong to the source mode set represented by hVidPnSourceModeSet.|

## Remarks

VidPN source mode identifiers are assigned by the operating system. The [pfnCreateNewModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpnsourcemodeset_createnewmodeinfo) function generates a mode identifier, assigns the identifier to the **Id** member of a [D3DKMDT_VIDPN_SOURCE_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_source_mode) structure, and returns the structure to the display miniport driver.

The D3DKMDT_HVIDPNSOURCEMODESET data type is defined in *D3dkmdt.h*.

## See also

[D3DKMDT_VIDPN_SOURCE_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_source_mode)

[pfnAcquirePinnedModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpnsourcemodeset_acquirepinnedmodeinfo)
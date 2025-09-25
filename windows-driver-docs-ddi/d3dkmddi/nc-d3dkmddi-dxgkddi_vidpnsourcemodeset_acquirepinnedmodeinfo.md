# DXGKDDI_VIDPNSOURCEMODESET_ACQUIREPINNEDMODEINFO callback function

## Description

The **pfnAcquirePinnedModeInfo** function returns a descriptor of the pinned mode in a specified VidPN source mode set.

## Parameters

### `hVidPnSourceModeSet` [in]

A handle to a VidPN source mode set object. The display miniport driver previously obtained this handle by calling the [pfnAcquireSourceModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_acquiresourcemodeset) function of the [DXGK_VIDPN_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_vidpn_interface) interface.

### `ppPinnedVidPnSourceModeInfo` [out]

A pointer to a variable that receives a pointer to a [D3DKMDT_VIDPN_SOURCE_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_source_mode) structure. The structure contains a variety of information about the pinned mode, including its ID, type, and rendering format. If the source mode set identified by *hVidPnSourceModeSet* has no pinned mode, then this variable receives a **NULL** pointer.

## Return value

The **pfnAcquirePinnedModeInfo** function returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The function succeeded by doing one of the following:<br>1. Setting ppPinnedVidPnSourceModeInfo to the address of D3DKMDT_VIDPN_SOURCE_MODE structure that describes the pinned mode.<br>2. Setting ppPinnedVidPnSourceModeInfo to NULL to indicate that the source mode set has no pinned mode.|
|STATUS_GRAPHICS_INVALID_VIDPN_SOURCEMODESET|The handle supplied in hVidPnSourceModeSet was invalid.|

## Remarks

When you have finished using the D3DKMDT_VIDPN_SOURCE_MODE structure, you must release the structure by calling [pfnReleaseModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpnsourcemodeset_releasemodeinfo).

The D3DKMDT_HVIDPNSOURCEMODESET data type is defined in *D3dkmdt.h*.

## See also

[D3DKMDT_VIDPN_SOURCE_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_source_mode)

[pfnPinMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpnsourcemodeset_pinmode)

[pfnReleaseModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpnsourcemodeset_releasemodeinfo)
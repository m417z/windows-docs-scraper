# DXGKDDI_VIDPNSOURCEMODESET_ACQUIRENEXTMODEINFO callback function

## Description

The **pfnAcquireNextModeInfo** function returns a descriptor of the next mode in a specified VidPN source mode set, given the current mode.

## Parameters

### `hVidPnSourceModeSet` [in]

A handle to a VidPN source mode set object. The display miniport driver previously obtained this handle by calling the [pfnAcquireSourceModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_acquiresourcemodeset) function of the [DXGK_VIDPN_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_vidpn_interface) interface.

### `pVidPnSourceModeInfo` [in]

A pointer to a [D3DKMDT_VIDPN_SOURCE_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_source_mode) structure that describes the current mode. The display miniport driver previously obtained this pointer by calling [pfnAcquireFirstModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpnsourcemodeset_acquirefirstmodeinfo) or **pfnAcquireNextModeInfo**.

### `ppNextVidPnSourceModeInfo` [out]

A pointer to a variable that receives a pointer to a D3DKMDT_VIDPN_SOURCE_MODE structure that describes the next mode.

## Return value

The **pfnAcquireNextModeInfo** function returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The function succeeded.|
|STATUS_GRAPHICS_INVALID_VIDPN_SOURCEMODESET|The handle supplied in hVidPnSourceModeSet was invalid.|

## Remarks

When you have finished using the [D3DKMDT_VIDPN_SOURCE_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_source_mode) structure, you must release the structure by calling [pfnReleaseModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpnsourcemodeset_releasemodeinfo).

You can enumerate all the modes that belong to a VidPN source mode set object by calling [pfnAcquireFirstModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpnsourcemodeset_acquirefirstmodeinfo) and then making a sequence of calls to **pfnAcquireNextModeInfo**.

The D3DKMDT_HVIDPNSOURCEMODESET data type is defined in *D3dkmdt.h*.

## See also

[D3DKMDT_VIDPN_SOURCE_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_source_mode)

[pfnAcquireFirstModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpnsourcemodeset_acquirefirstmodeinfo)

[pfnReleaseModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpnsourcemodeset_releasemodeinfo)
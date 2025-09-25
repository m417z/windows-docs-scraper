# DXGKDDI_VIDPNSOURCEMODESET_ACQUIREFIRSTMODEINFO callback function

## Description

The **pfnAcquireFirstModeInfo** function returns a descriptor of the first mode in a specified VidPN source mode set.

## Parameters

### `hVidPnSourceModeSet` [in]

A handle to a VidPN source mode set object. The display miniport driver previously obtained this handle by calling the [pfnAcquireSourceModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_acquiresourcemodeset) function of the [DXGK_VIDPN_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_vidpn_interface) interface.

### `ppFirstVidPnSourceModeInfo` [out]

A pointer to a variable that receives a pointer to a [D3DKMDT_VIDPN_SOURCE_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_source_mode) structure. The structure contains a variety of information about the mode, including its ID, type, and rendering format.

## Return value

The **pfnAcquireFirstModeInfo** function returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The function succeeded.|
|STATUS_GRAPHICS_INVALID_VIDPN_SOURCEMODESET|The handle supplied in hVidPnSourceModeSet was invalid.|

## Remarks

When you have finished using the D3DKMDT_VIDPN_SOURCE_MODE structure, you must release the structure by calling [pfnReleaseModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpnsourcemodeset_releasemodeinfo).

You can enumerate all the modes that belong to a VidPN source mode set object by calling **pfnAcquireFirstModeInfo** and then making a sequence of calls to [pfnAcquireNextModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpnsourcemodeset_acquirenextmodeinfo).

The D3DKMDT_HVIDPNSOURCEMODESET data type is defined in *D3dkmdt.h*.

## See also

[D3DKMDT_VIDPN_SOURCE_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_source_mode)

[pfnAcquireNextModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpnsourcemodeset_acquirenextmodeinfo)

[pfnReleaseModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpnsourcemodeset_releasemodeinfo)
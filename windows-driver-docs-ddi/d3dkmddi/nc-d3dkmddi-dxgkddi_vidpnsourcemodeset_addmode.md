# DXGKDDI_VIDPNSOURCEMODESET_ADDMODE callback function

## Description

The **pfnAddMode** function adds a VidPN source mode to a specified VidPN source mode set object.

## Parameters

### `hVidPnSourceModeSet` [in]

A handle to a VidPN source mode set object. The display miniport driver previously obtained this handle by calling the [pfnAcquireSourceModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_acquiresourcemodeset) function of the [DXGK_VIDPN_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_vidpn_interface) interface.

### `pVidPnSourceModeInfo` [in]

A pointer to a [D3DKMDT_VIDPN_SOURCE_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_source_mode) structure that describes the source mode. The display miniport driver previously obtained this structure by calling [pfnCreateNewModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpnsourcemodeset_createnewmodeinfo).

## Return value

The **pfnAddMode** function returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The function succeeded.|
|STATUS_GRAPHICS_INVALID_VIDPN_SOURCEMODESET|The handle supplied in hVidPnSourceModeSet was invalid.|

## Remarks

To add a mode to a source mode set, the display miniport driver performs the following steps.

Call [pfnCreateNewModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpnsourcemodeset_createnewmodeinfo) to obtain a pointer to a [D3DKMDT_VIDPN_SOURCE_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_source_mode) structure. The **pnfCreateNewModeInfo** function allocates the structure, fills in the **Id** member with a newly generated source mode identifier, and sets the **Type** member to **D3DKMDT_RMT_UNINITIALIZED**.

Populate the D3DKMDT_VIDPN_SOURCE_MODE structure (except for the **Id** member) with information about the mode, including the mode's type and format.

Call **pfnAddMode** to add the mode to a source mode set.

The VidPN manager allocates a D3DKMDT_VIDPN_SOURCE_MODE structure when you call **pfnCreateNewModeInfo**. If you add the mode described by that structure to a source mode set, you do not need to explicitly release the structure; **pfnAddMode** releases it.

If you obtain a D3DKMDT_VIDPN_SOURCE_MODE structure by calling **pfnCreateNewModeInfo** and then decide not to add that mode to a source mode set, you must explicitly release the structure by calling [pfnReleaseModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpnsourcemodeset_releasemodeinfo).

The D3DKMDT_HVIDPNSOURCEMODESET data type is defined in *D3dkmdt.h*.

## See also

[D3DKMDT_VIDPN_SOURCE_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_source_mode)

[pfnCreateNewModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpnsourcemodeset_createnewmodeinfo)

[pfnReleaseModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpnsourcemodeset_releasemodeinfo)
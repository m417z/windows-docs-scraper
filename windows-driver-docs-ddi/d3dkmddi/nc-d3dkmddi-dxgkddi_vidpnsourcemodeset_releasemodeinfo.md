# DXGKDDI_VIDPNSOURCEMODESET_RELEASEMODEINFO callback function

## Description

The **pfnReleaseModeInfo** function releases a [D3DKMDT_VIDPN_SOURCE_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_source_mode) structure that the VidPN manager previously provided to the display miniport driver.

## Parameters

### `hVidPnSourceModeSet` [in]

A handle to a VidPN source mode set object. The display miniport driver previously obtained this handle by calling the [pfnAcquireSourceModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_acquiresourcemodeset) function of the [DXGK_VIDPN_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_vidpn_interface) interface.

### `pVidPnSourceModeInfo` [in]

A pointer to the D3DKMDT_VIDPN_SOURCE_MODE structure that is to be released.

## Return value

The **pfnReleaseModeInfo** function returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The function succeeded.|
|STATUS_GRAPHICS_INVALID_VIDPN_SOURCEMODESET|The handle supplied in hVidPnSourceModeSet was invalid.|
|STATUS_GRAPHICS_INVALID_VIDEO_PRESENT_SOURCE_MODE|The pointer supplied in pVidPnSourceModeInfo was invalid.|

## Remarks

When you have finished using a D3DKMDT_VIDPN_SOURCE_MODE structure that you obtained by calling any of the following functions, you must release the structure by calling **pfnReleaseModeInfo**.

* [pfnAcquireFirstModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpnsourcemodeset_acquirefirstmodeinfo)
* [pfnAcquireNextModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpnsourcemodeset_acquirenextmodeinfo)
* [pfnAcquirePinnedModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpnsourcemodeset_acquirepinnedmodeinfo)

If you obtain a D3DKMDT_VIDPN_SOURCE_MODE structure by calling [pfnCreateNewModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpnsourcemodeset_createnewmodeinfo) and then pass that structure to [pfnAddMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpnsourcemodeset_addmode), you do not need to release the structure.

If you obtain a handle by calling **pfnCreateNewModeInfo** and then you decide not to add the new mode to a source mode set, you must release the newly created structure by calling **pfnReleaseModeInfo**.

The D3DKMDT_HVIDPNSOURCEMODESET data type is defined in *D3dkmdt.h*.

## See also

[D3DKMDT_VIDPN_SOURCE_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_source_mode)

[pfnAcquireFirstModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpnsourcemodeset_acquirefirstmodeinfo)

[pfnAcquireNextModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpnsourcemodeset_acquirenextmodeinfo)

[pfnAcquirePinnedModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpnsourcemodeset_acquirepinnedmodeinfo)
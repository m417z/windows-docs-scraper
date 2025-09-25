# _DXGK_VIDPNSOURCEMODESET_INTERFACE structure

## Description

The DXGK_VIDPNSOURCEMODESET_INTERFACE structure contains pointers to functions that belong to the VidPn Source mode set interface in [VidPN Objects and Interfaces](https://learn.microsoft.com/windows-hardware/drivers/display/vidpn-objects-and-interfaces), which is implemented by the video present network (VidPN) manager.

## Members

### `pfnGetNumModes`

A pointer to the [pfnGetNumModes](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpnsourcemodeset_getnummodes) function.

### `pfnAcquireFirstModeInfo`

A pointer to the [pfnAcquireFirstModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpnsourcemodeset_acquirefirstmodeinfo) function.

### `pfnAcquireNextModeInfo`

A pointer to the [pfnAcquireNextModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpnsourcemodeset_acquirenextmodeinfo) function.

### `pfnAcquirePinnedModeInfo`

A pointer to the [pfnAcquirePinnedModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpnsourcemodeset_acquirepinnedmodeinfo) function.

### `pfnReleaseModeInfo`

A pointer to the [pfnReleaseModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpnsourcemodeset_releasemodeinfo) function.

### `pfnCreateNewModeInfo`

A pointer to the [pfnCreateNewModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpnsourcemodeset_createnewmodeinfo) function.

### `pfnAddMode`

A pointer to the [pfnAddMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpnsourcemodeset_addmode) function.

### `pfnPinMode`

A pointer to the [pfnPinMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpnsourcemodeset_pinmode) function.

## Remarks

The display miniport driver calls the [pfnAcquireSourceModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_acquiresourcemodeset) function of the [VidPn interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/) to obtain a handle to a VidPN source mode set object and a pointer to a DXGK_VIDPNSOURCEMODESET_INTERFACE structure. The structure contains pointers to functions that the display miniport driver can call to inspect and alter the VidPN source mode set object.

## See also

[D3DKMDT_VIDPN_SOURCE_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_source_mode)

[DXGK_MONITORSOURCEMODESET_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_monitorsourcemodeset_interface)

[DXGK_VIDPNTARGETMODESET_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_vidpntargetmodeset_interface)

[pfnAcquireSourceModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_acquiresourcemodeset)
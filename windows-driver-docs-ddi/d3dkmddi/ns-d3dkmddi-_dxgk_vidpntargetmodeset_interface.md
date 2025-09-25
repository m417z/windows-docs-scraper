# _DXGK_VIDPNTARGETMODESET_INTERFACE structure

## Description

The DXGK_VIDPNTARGETMODESET_INTERFACE structure contains pointers to functions that belong to the [VidPn Target Mode Set interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/), which is implemented by the VidPN manager.

## Members

### `pfnGetNumModes`

A pointer to the [pfnGetNumModes](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntargetmodeset_getnummodes) function.

### `pfnAcquireFirstModeInfo`

A pointer to the [pfnAcquireFirstModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntargetmodeset_acquirefirstmodeinfo) function.

### `pfnAcquireNextModeInfo`

A pointer to the [pfnAcquireNextModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntargetmodeset_acquirenextmodeinfo) function.

### `pfnAcquirePinnedModeInfo`

A pointer to the [pfnAcquirePinnedModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntargetmodeset_acquirepinnedmodeinfo) function.

### `pfnReleaseModeInfo`

A pointer to the [pfnReleaseModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntargetmodeset_releasemodeinfo) function.

### `pfnCreateNewModeInfo`

A pointer to the [pfnCreateNewModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntargetmodeset_createnewmodeinfo) function.

### `pfnAddMode`

A pointer to the [pfnAddMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntargetmodeset_addmode) function.

### `pfnPinMode`

A pointer to the [pfnPinMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntargetmodeset_pinmode) function.

## Remarks

The display miniport driver calls the [pfnAcquireTargetModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_acquiretargetmodeset) function of the [VidPn interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/) to obtain a handle to a VidPN target mode set object and a pointer to a DXGK_VIDPNTARGETMODESET_INTERFACE structure. The structure contains pointers to functions that the display miniport driver can call to inspect and alter the VidPN target mode set object.

## See also

[D3DKMDT_VIDPN_TARGET_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_target_mode)

[DXGK_MONITORSOURCEMODESET_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_monitorsourcemodeset_interface)

[DXGK_VIDPNSOURCEMODESET_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_vidpnsourcemodeset_interface)

[pfnAcquireTargetModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_acquiretargetmodeset)
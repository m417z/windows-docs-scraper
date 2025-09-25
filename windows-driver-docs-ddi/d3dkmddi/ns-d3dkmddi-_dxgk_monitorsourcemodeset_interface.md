# _DXGK_MONITORSOURCEMODESET_INTERFACE structure

## Description

The DXGK_MONITORSOURCEMODESET_INTERFACE structure contains pointers to functions that belong to the [Monitor Source Mode Set interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/), which is implemented by the video present network (VidPN) manager.

## Members

### `pfnGetNumModes`

A pointer to the [pfnGetNumModes](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitorsourcemodeset_getnummodes) function.

### `pfnAcquirePreferredModeInfo`

A pointer to the [pfnAcquirePreferredModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitorsourcemodeset_acquirepreferredmodeinfo) function.

### `pfnAcquireFirstModeInfo`

A pointer to the [pfnAcquireFirstModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitorsourcemodeset_acquirefirstmodeinfo) function.

### `pfnAcquireNextModeInfo`

A pointer to the [pfnAcquireNextModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitorsourcemodeset_acquirenextmodeinfo) function.

### `pfnCreateNewModeInfo`

A pointer to the [pfnCreateNewModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitorsourcemodeset_createnewmodeinfo) function.

### `pfnAddMode`

A pointer to the [pfnAddMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitorsourcemodeset_addmode) function.

### `pfnReleaseModeInfo`

A pointer to the [pfnReleaseModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitorsourcemodeset_releasemodeinfo) function.

## Remarks

The display miniport driver calls the [pfnAcquireMonitorSourceModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitor_acquiremonitorsourcemodeset) function of the [Monitor interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/) to obtain a handle to a monitor source mode set object and a pointer to a DXGK_MONITORSOURCEMODESET_INTERFACE structure. The structure contains pointers to functions that the display miniport driver can call to inspect and alter the monitor source mode set object.

## See also

[D3DKMDT_MONITOR_SOURCE_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_monitor_source_mode)

[DXGK_VIDPNSOURCEMODESET_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_vidpnsourcemodeset_interface)

[DXGK_VIDPNTARGETMODESET_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_vidpntargetmodeset_interface)

[pfnAcquireMonitorSourceModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitor_acquiremonitorsourcemodeset)
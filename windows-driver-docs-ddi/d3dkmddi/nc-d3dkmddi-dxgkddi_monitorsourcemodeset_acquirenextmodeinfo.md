# DXGKDDI_MONITORSOURCEMODESET_ACQUIRENEXTMODEINFO callback function

## Description

The **pfnAcquireNextModeInfo** function returns a descriptor of the next mode in a specified monitor source mode set, given the current mode.

## Parameters

### `hMonitorSourceModeSet` [in]

A handle to a monitor source mode set object. The display miniport driver previously obtained this handle by calling the [pfnAcquireMonitorSourceModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitor_acquiremonitorsourcemodeset) function of the [Monitor interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/).

### `pMonitorSourceModeInfo` [in]

A pointer to a [D3DKMDT_MONITOR_SOURCE_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_monitor_source_mode) structure that describes the current mode. The display miniport driver previously obtained this pointer by calling [pfnAcquireFirstModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitorsourcemodeset_acquirefirstmodeinfo) or **pfnAcquireNextModeInfo**.

### `ppNextMonitorSourceModeInfo` [out]

A pointer to a variable that receives a pointer to a D3DKMDT_MONITOR_SOURCE_MODE structure that describes the next mode.

## Return value

The **pfnAcquireNextModeInfo** function returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The function succeeded.|
|STATUS_GRAPHICS_INVALID_MONITOR_SOURCEMODESET|The handle supplied in *hMonitorSourceModeSet* was invalid.|

## Remarks

When you have finished using the [D3DKMDT_MONITOR_SOURCE_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_monitor_source_mode) structure, you must release the structure by calling [pfnReleaseModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitorsourcemodeset_releasemodeinfo).

You can enumerate all the modes that belong to a particular monitor source mode set object by calling [pfnAcquireFirstModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitorsourcemodeset_acquirefirstmodeinfo) and then making a sequence of calls to **pfnAcquireNextModeInfo**.

The D3DKMDT_HMONITORSOURCEMODESET data type is defined in *D3dkmdt.h*.

## See also

[D3DKMDT_MONITOR_SOURCE_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_monitor_source_mode)

[pfnAcquireFirstModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitorsourcemodeset_acquirefirstmodeinfo)

[pfnReleaseModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitorsourcemodeset_releasemodeinfo)
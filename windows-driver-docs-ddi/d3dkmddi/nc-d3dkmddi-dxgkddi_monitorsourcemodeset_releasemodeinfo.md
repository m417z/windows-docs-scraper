# DXGKDDI_MONITORSOURCEMODESET_RELEASEMODEINFO callback function

## Description

The **pfnReleaseModeInfo** function releases a [D3DKMDT_MONITOR_SOURCE_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_monitor_source_mode) structure that the VidPN manager previously provided to the display miniport driver.

## Parameters

### `hMonitorSourceModeSet` [in]

A handle to a monitor source mode set object. The display miniport driver previously obtained this handle by calling the [pfnAcquireMonitorSourceModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitor_acquiremonitorsourcemodeset) function of the [Monitor interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/).

### `pMonitorSourceModeInfo` [in]

A pointer to the D3DKMDT_MONITOR_SOURCE_MODE structure that is to be released.

## Return value

The **pfnReleaseModeInfo** function returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The function succeeded.|
|STATUS_GRAPHICS_INVALID_MONITOR_SOURCEMODESET|The handle supplied in hMonitorSourceModeSet was invalid.|
|STATUS_GRAPHICS_INVALID_VIDEO_PRESENT_TARGET_MODE|The pointer supplied in pMonitorSourceModeInfo was invalid.|

## Remarks

When you have finished using a [D3DKMDT_MONITOR_SOURCE_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_monitor_source_mode) structure that you obtained by calling [pfnAcquireFirstModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitorsourcemodeset_acquirefirstmodeinfo) or [pfnAcquireNextModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitorsourcemodeset_acquirenextmodeinfo), you must release the structure by calling **pfnReleaseModeInfo**.

The D3DKMDT_HMONITORSOURCEMODESET data type is defined in *D3dkmdt.h*.

## See also

[D3DKMDT_MONITOR_SOURCE_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_monitor_source_mode)

[pfnAcquireFirstModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitorsourcemodeset_acquirefirstmodeinfo)

[pfnAcquireNextModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitorsourcemodeset_acquirenextmodeinfo)
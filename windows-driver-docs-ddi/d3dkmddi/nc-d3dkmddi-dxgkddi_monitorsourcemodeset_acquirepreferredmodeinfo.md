# DXGKDDI_MONITORSOURCEMODESET_ACQUIREPREFERREDMODEINFO callback function

## Description

The **pfnAcquirePreferredModeInfo** returns a descriptor of the preferred mode in a specified monitor source mode set object.

## Parameters

### `hMonitorSourceModeSet` [in]

A handle to a monitor source mode set object. The display miniport driver previously obtained this handle by calling the [pfnAcquireMonitorSourceModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitor_acquiremonitorsourcemodeset) function of the [Monitor interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/).

### `ppFirstMonitorSourceModeInfo` [out]

A pointer to a variable that receives a pointer to a [D3DKMDT_MONITOR_SOURCE_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_monitor_source_mode) structure. The structure contains a variety of information about the preferred monitor source mode, including its ID and video signal.

## Return value

The **pfnAcquirePreferredModeInfo** function returns one of the following values.

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The function successfully returned a descriptor of the preferred mode.|
|STATIS_GRAPHICS_NO_PREFERRED_MODE|The function succeeded, but the specified monitor source mode set does not have a preferred mode.|
|STATUS_GRAPHICS_INVALID_MONITOR_SOURCEMODESET|The handle supplied in hMonitorSourceModeSet was invalid.|

## Remarks

When you have finished using the [D3DKMDT_MONITOR_SOURCE_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_monitor_source_mode) structure, you must release the structure by calling [pfnReleaseModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitorsourcemodeset_releasemodeinfo).

The D3DKMDT_HMONITORSOURCEMODESET data type is defined in *D3dkmdt.h*.
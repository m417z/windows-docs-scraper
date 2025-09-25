# DXGKDDI_MONITORSOURCEMODESET_GETNUMMODES callback function

## Description

The **pfnGetNumModes** function returns the number modes in a specified monitor source mode set.

## Parameters

### `hMonitorSourceModeSet`

A handle to a monitor source mode set object. The display miniport driver previously obtained this handle by calling the [pfnAcquireMonitorSourceModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitor_acquiremonitorsourcemodeset) function of the [Monitor interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/).

### `pNumMonitorSourceModes`

A pointer to a SIZE_T-typed variable that receives the number of monitor source modes in the set.

## Return value

The **pfnGetNumModes** function returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The function succeeded.|
|STATUS_GRAPHICS_INVALID_MONITOR_SOURCEMODESET|The handle supplied in hMonitorSourceModeSet was invalid.|

## Remarks

The D3DKMDT_HMONITORSOURCEMODESET data type is defined in *D3dkmdt.h*.

## See also

[pfnAcquireFirstModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitorsourcemodeset_acquirefirstmodeinfo)

[pfnAcquireNextModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitorsourcemodeset_acquirenextmodeinfo)
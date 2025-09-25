# DXGKDDI_MONITORSOURCEMODESET_ADDMODE callback function

## Description

The **pfnAddMode** function adds a monitor source mode to a specified monitor source mode set object.

## Parameters

### `hMonitorSourceModeSet` [in]

A handle to a monitor source mode set object. The display miniport driver previously obtained this handle by calling the [pfnAcquireMonitorSourceModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitor_acquiremonitorsourcemodeset) function of the [Monitor interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/).

### `pMonitorSourceModeInfo` [in]

A pointer to a [D3DKMDT_MONITOR_SOURCE_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_monitor_source_mode) structure that describes the monitor source mode. The display miniport driver previously obtained this structure by calling [pfnCreateNewModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitorsourcemodeset_createnewmodeinfo).

## Return value

The **pfnAddMode** function returns one of the following values.

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The function succeeded.|
|STATUS_NO_MEMORY|The function failed because it could not allocate enough memory.|
|STATUS_GRAPHICS_INVALID_MONITOR_SOURCE_MODE|The information supplied in pMonitorSourceModeInfo was invalid.|
|STATUS_GRAPHICS_INVALID_MONITOR_SOURCEMODESET|The handle supplied in hMonitorSourceModeSet was invalid.|
|STATUS_GRAPHICS_INVALID_FREQUENCY|The frequency information supplied in pMonitorSourceModeInfo was invalid.|
|STATUS_GRAPHICS_INVALID_ACTIVE_REGION|The active region supplied in pMonitorSourceModeInfo was invalid.|
|STATUS_GRAPHICS_INVALID_TOTAL_REGION|The total region supplied in pMonitorSourceModeInfo was invalid.|
|STATUS_GRAPHICS_MODE_ALREADY_IN_MODE_SET|The mode set already contains a mode that is identical to the mode supplied in pMonitorSourceModeInfo.|
|STATUS_GRAPHICS_MODE_ID_MUST_BE_UNIQUE|The identifier supplied in pMonitorSourceModeInfo->Id is already being used for another mode in the mode set.|
|STATUS_GRAPHICS_RESOURCES_NOT_RELATED|The structure pointed to by pMonitorSourceModeInfo was not created for addition to the mode set specified by hMonitorSourceModeSet.|

## Remarks

If *pMonitorSourceModeInfo*->**Preference** is equal to D3DKMDT_MP_PREFERRED, the newly added mode becomes the preferred mode of the mode set.

## See also

[pfnCreateNewModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitorsourcemodeset_createnewmodeinfo)
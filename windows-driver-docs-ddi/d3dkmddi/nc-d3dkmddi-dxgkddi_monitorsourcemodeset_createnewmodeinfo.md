# DXGKDDI_MONITORSOURCEMODESET_CREATENEWMODEINFO callback function

## Description

The **pfnCreateNewModeInfo** function returns a pointer to a [D3DKMDT_MONITOR_SOURCE_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_monitor_source_mode) structure that the display miniport driver populates before calling [pfnAddMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitorsourcemodeset_addmode).

## Parameters

### `hMonitorSourceModeSet` [in]

A handle to a monitor source mode set object. The display miniport driver previously obtained this handle by calling the [pfnAcquireMonitorSourceModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitor_acquiremonitorsourcemodeset) function of the [Monitor interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/).

### `ppNewMonitorSourceModeInfo` [out]

A pointer to a variable that receives a pointer to a newly created D3DKMDT_MONITOR_SOURCE_MODE structure allocated by the VidPN manager.

## Return value

The **pfnCreateNewModeInfo** function returns one of the following values.

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The function succeeded.|
|STATUS_NO_MEMORY|The function failed because it was unable to allocate enough memory.|

## Remarks

After you call **pfnCreateNewModeInfo** to obtain a D3DKMDT_MONITOR SOURCE_MODE structure, you must do one, but not both, of the following:

* Populate the structure and pass it to [pfnAddMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitorsourcemodeset_addmode).
* Release the structure by calling [pfnReleaseModeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitorsourcemodeset_releasemodeinfo).
# DXGKDDI_MONITOR_RELEASEMONITORSOURCEMODESET callback function

## Description

The **pfnReleaseMonitorSourceModeSet** function releases a handle to a monitor source mode set object.

## Parameters

### `hAdapter` [in]

A handle that identifies a display adapter. The Microsoft DirectX graphics kernel subsystem previously provided this handle to the display miniport driver in the *DxgkInterface* parameter of the [DxgkDdiStartDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device) function.

### `hMonitorSourceModeSet` [in]

The handle to be released.

## Return value

The **pfnReleaseMonitorSourceModeSet** function returns one of the following values.

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The function succeeded.|
|STATUS_GRAPHICS_INVALID_DISPLAY_ADAPTER|The handle supplied in *hAdapter* was invalid.|
|STATUS_INVALID_MONITOR_SOURCEMODESET|The handle supplied in *hMonitorSourceModeSet* was invalid.|

This function might also return other error codes that are defined in *Ntstatus.h*.

## Remarks

When you have finished using a handle that you obtained by calling [pfnAcquireMonitorSourceModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitor_acquiremonitorsourcemodeset), you must release the handle by calling **pfnReleaseMonitorSourceModeSet**.

This function is also available in the [DXGK_MONITOR_INTERFACE_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_monitor_interface_v2) interface beginning with Windows 7.

## See also

[DXGK_MONITOR_INTERFACE_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_monitor_interface_v2)
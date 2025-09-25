# DXGKDDI_MONITOR_RELEASEADDITIONALMONITORMODESET callback function

## Description

The **pfnReleaseAdditionalMonitorModeSet** function releases a handle to an additional monitor source mode set object that is associated with a specified monitor. It is available in the [**DXGK_MONITOR_INTERFACE_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_monitor_interface_v2) interface, starting in Windows 7.

## Parameters

### `hAdapter` [in]

A handle that identifies a display adapter. The Microsoft DirectX graphics kernel subsystem previously provided this handle to the display miniport driver in the **DxgkInterface** parameter of the [**DxgkDdiStartDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device) function.

### `VideoPresentTargetId` [in]

An integer that identifies one of the video present targets on the display adapter. The additional modes set object **ppAdditionalModesSet** returned in a call to the [**pfnGetAdditionalMonitorModeSet**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitor_getadditionalmonitormodeset) function describes the additional monitor source mode sets that are available on the monitor that is connected to this video present target.

### `pAdditionalModesSet` [in]

A pointer to a variable that receives a [**DXGK_TARGETMODE_DETAIL_TIMING**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgk_targetmode_detail_timing) structure that describes a video present target's additional timing modes that are compatible with the display device. This structure was initially obtained in a call to [**pfnGetAdditionalMonitorModeSet**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitor_getadditionalmonitormodeset).

## Return value

The **pfnReleaseAdditionalMonitorModeSet** function returns one of the following values.

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The function succeeded.|
|STATUS_GRAPHICS_INVALID_DISPLAY_ADAPTER|The handle supplied in hAdapter was invalid.|
|STATUS_INVALID_MONITOR_SOURCEMODESET|The handle supplied in ppAdditionalModesSet was invalid.|

## Remarks

This function is available beginning with Windows 7.

## See also

[**DXGK_MONITOR_INTERFACE_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_monitor_interface_v2)

[**DXGK_MONITOR_INTERFACE_V2::pfnGetAdditionalMonitorModeSet**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitor_getadditionalmonitormodeset)

[**DxgkDdiStartDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device)
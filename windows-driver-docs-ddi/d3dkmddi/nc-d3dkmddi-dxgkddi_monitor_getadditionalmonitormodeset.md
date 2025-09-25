# DXGKDDI_MONITOR_GETADDITIONALMONITORMODESET callback function

## Description

The **pfnGetAdditionalMonitorModeSet** function returns a handle to an additional monitor source mode set object that is associated with a specified monitor. It is available in the [**DXGK_MONITOR_INTERFACE_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_monitor_interface_v2) interface, starting in Windows 7.

## Parameters

### `hAdapter` [in]

A handle that identifies a display adapter. The Microsoft DirectX graphics kernel subsystem previously provided this handle to the display miniport driver in the **DxgkInterface** parameter of the [**DxgkDdiStartDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device) function.

### `VideoPresentTargetId` [in]

An integer that identifies one of the video present targets on the display adapter. The returned **ppAdditionalModesSet** additional modes set object describes the additional monitor source mode sets that are available on the monitor that is connected to this video present target.

### `pNumberModes` [out]

A pointer to a variable that contains the number of additional timing modes of the video present target specified by **VideoPresentTargetId**.

### `ppAdditionalModesSet` [out]

A pointer to a variable that receives a pointer to a [**DXGK_TARGETMODE_DETAIL_TIMING**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgk_targetmode_detail_timing) structure. The structure describes a video present target's additional timing modes that are compatible with the display device.

## Return value

The [**pfnAcquireMonitorSourceModeSet**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitor_acquiremonitorsourcemodeset) function returns one of the following values.

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The function succeeded.|
|STATUS_GRAPHICS_INVALID_DISPLAY_ADAPTER|The handle supplied in hAdapter was invalid.|
|STATUS_GRAPHICS_INVALID_VIDEO_PRESENT_TARGET|The identifier supplied in VideoPresentTargetId was invalid.|
|STATUS_GRAPHICS_MONITOR_NOT_CONNECTED|There is no monitor connected to the video present target identified by VideoPresentTargetId.|
|STATUS_NOT_FOUND|The video present target identified by VideoPresentTargetId could not be found.|

## Remarks

VidPN target identifiers are assigned by the display miniport driver. The [**DxgkDdiQueryChildRelations**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_child_relations) function, implemented by the display miniport driver, returns an array of [**DXGK_CHILD_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_child_descriptor) structures, each of which contains an identifier.

This function is available beginning with Windows 7.

## See also

[**DXGK_CHILD_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_child_descriptor)

[**DXGK_MONITOR_INTERFACE_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_monitor_interface_v2)

[**DXGK_MONITOR_INTERFACE_V2::pfnReleaseAdditionalMonitorModeSet**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitor_releaseadditionalmonitormodeset)

[**DXGK_TARGETMODE_DETAIL_TIMING**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgk_targetmode_detail_timing)

[**DxgkDdiQueryChildRelations**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_child_relations)

[**DxgkDdiStartDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device)
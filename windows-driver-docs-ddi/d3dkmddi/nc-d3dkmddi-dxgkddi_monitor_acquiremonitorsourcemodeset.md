# DXGKDDI_MONITOR_ACQUIREMONITORSOURCEMODESET callback function

## Description

The **pfnAcquireMonitorSourceModeSet** function returns a handle to the monitor source mode set object that is associated with a specified monitor.

## Parameters

### `hAdapter` [in]

A handle that identifies a display adapter. The Microsoft DirectX graphics kernel subsystem previously provided this handle to the display miniport driver in the *DxgkInterface* parameter of the [DxgkDdiStartDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device) function.

### `VideoPresentTargetId` [in]

An integer that identifies one of the video present targets on the display adapter. The returned source mode set object describes the modes available on the monitor that is connected to this video present target.

### `phMonitorSourceModeSet` [out]

A pointer to a variable that receives a handle to a monitor source mode set object.

### `ppMonitorSourceModeSetInterface` [out]

A pointer to a variable that receives a pointer to a [DXGK_MONITORSOURCEMODESET_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_monitorsourcemodeset_interface) structure. The structure contains pointers to functions that the display miniport driver can call to inspect and alter the monitor source mode set object.

## Return value

The **pfnAcquireMonitorSourceModeSet** function returns one of the following values.

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The function succeeded.|
|STATUS_GRAPHICS_INVALID_DISPLAY_ADAPTER|The handle supplied in hAdapter was invalid.|
|STATUS_GRAPHICS_INVALID_VIDEO_PRESENT_TARGET|The identifier supplied in VideoPresentTargetId was invalid.|
|STATUS_GRAPHICS_MONITOR_NOT_CONNECTED|There is no monitor connected to the video present target identified by VideoPresentTargetId.|

This function might also return other error codes that are defined in *Ntstatus.h*.

## Remarks

VidPN target identifiers are assigned by the display miniport driver. The [DxgkDdiQueryChildRelations](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_child_relations) function, implemented by the display miniport driver, returns an array of [DXGK_CHILD_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_child_descriptor) structures, each of which contains an identifier.

When you have finished using the monitor source mode set object handle, you must release the handle by calling [pfnReleaseMonitorSourceModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitor_releasemonitorsourcemodeset). Target mode set objects are reference counted, so if you acquire a handle several times, you must release it that same number of times.

This function is also available in the [DXGK_MONITOR_INTERFACE_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_monitor_interface_v2) interface beginning with Windows 7.

## See also

[DXGK_MONITOR_INTERFACE_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_monitor_interface_v2)

[DxgkDdiEnumVidPnCofuncModality](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_enumvidpncofuncmodality)
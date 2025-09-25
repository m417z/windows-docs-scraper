# DXGKDDI_MONITOR_GETMONITORDESCRIPTORSET callback function

## Description

The **pfnGetMonitorDescriptorSet** function returns a handle to a monitor descriptor set object that is associated with a specified monitor.

## Parameters

### `hAdapter` [in]

A handle that identifies a display adapter. The Microsoft DirectX graphics kernel subsystem previously provided this handle to the display miniport driver in the *DxgkInterface* parameter of the [DxgkDdiStartDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device) function.

### `VideoPresentTargetId` [in]

An integer that identifies one of the video present targets on the display adapter. The returned monitor descriptor set object contains descriptors for the monitor that is connected to this video present target.

### `phMonitorDescriptorSet` [out]

A pointer to a variable that receives a handle to a monitor descriptor set object.

### `ppMonitorDescriptorSetInterface` [out]

A pointer to a variable that receives a pointer to a [DXGK_MONITORDESCRIPTORSET_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_monitordescriptorset_interface) structure. The structure contains pointers to functions that the display miniport driver can call to inspect and alter the monitor descriptor set object.

## Return value

The **pfnGetMonitorDescriptorSet** function returns one of the following values.

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The function succeeded.|
|STATUS_INVALID_PARAMETER|An invalid parameter was supplied.|
|STATUS_GRAPHICS_INVALID_DISPLAY_ADAPTER|The handle supplied in hAdapter was invalid.|
|STATUS_GRAPHICS_INVALID_VIDEO_PRESENT_TARGET|The identifier supplied in VideoPresentTargetId was invalid.|
|STATUS_GRAPHICS_MONITOR_NOT_CONNECTED|There is no monitor connected to the video present target identified by VideoPresentTargetId.|

## Remarks

VidPN target identifiers are assigned by the display miniport driver. The [DxgkDdiQueryChildRelations](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_child_relations) function, implemented by the display miniport driver, returns an array of [DXGK_CHILD_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_child_descriptor) structures, each of which contains an identifier.

You do not need to release the handle returned in *phMonitorDescriptorSet*.

This function is also available in the [DXGK_MONITOR_INTERFACE_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_monitor_interface_v2) interface beginning with Windows 7.

## See also

[DXGK_MONITOR_INTERFACE_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_monitor_interface_v2)

[DxgkDdiEnumVidPnCofuncModality](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_enumvidpncofuncmodality)
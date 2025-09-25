# DXGKDDI_QUERY_CHILD_STATUS callback function

## Description

The *DxgkDdiQueryChildStatus* function returns the status of an individual child device of a display adapter.

## Parameters

### `MiniportDeviceContext` [in]

A handle to a context block associated with a display adapter. The display miniport driver's [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function previously provided this handle to the DirectX graphics kernel subsystem.

### `ChildStatus` [in, out]

A pointer to a [DXGK_CHILD_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_child_status) structure. The caller supplies ChildStatus->Type and ChildStatus->ChildUid. On return, the remaining structure member (a union) receives the requested status.

### `NonDestructiveOnly` [in]

A BOOLEAN value that specifies whether the display miniport driver is permitted to determine the requested status in a way that causes visual artifacts. If the caller sets this parameter to **TRUE**, then the display miniport driver is not permitted to cause artifacts. If the caller sets this parameter to **FALSE**, then the display miniport driver is permitted to cause artifacts.

## Return value

*DxgkDdiQueryChildStatus* returns STATUS_SUCCESS if it succeeds; otherwise, it returns one of the error codes defined in *Ntstatus.h*.

## Remarks

During initialization, the display port driver calls [DxgkDdiQueryChildRelations](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_child_relations) to get a list of devices that are children of the display adapter represented by *MiniportDeviceContext*. Then for each child that has an HPD awareness value of **HpdAwarenessPolled** or **HpdAwarenessInterruptible**, the display port driver calls *DxgkDdiQueryChildStatus* to determine whether the child currently has hardware (for example a monitor) connected to it.

*DxgkDdiQueryChildStatus* must perform the following actions:

* If ChildStatus->Type is equal to **StatusConnection**, return a Boolean value in ChildStatus->HotPlug.Connected. Return **TRUE** if the child device identified by ChildStatus->ChildUid has external hardware connected to it; otherwise return **FALSE**.
* If ChildStatus->Type is equal to **StatusRotation**, return (in ChildStatus->Rotation.Angle) the angle of rotation for the display connected to the child device identified by ChildStatus->ChildUid.

*DxgkDdiQueryChildStatus* should be made pageable.

## See also

[DXGK_CHILD_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_child_status)

[DXGK_CHILD_STATUS_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ne-dispmprt-_dxgk_child_status_type)

[DxgkDdiQueryChildRelations](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_child_relations)
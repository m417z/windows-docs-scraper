# DXGKDDI_QUERY_CHILD_RELATIONS callback function

## Description

The *DxgkDdiQueryChildRelations* function enumerates the child devices of a display adapter.

## Parameters

### `MiniportDeviceContext` [in]

A handle to a context block associated with a display adapter. The display miniport driver's [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function previously provided this handle to the DirectX graphics kernel subsystem.

### `ChildRelations` [in, out]

A pointer to an array of [DXGK_CHILD_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_child_descriptor) structures allocated and zeroed by the caller. The number of elements in the array is one greater than the value returned by [DxgkDdiStartDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device) in the *NumberOfChildren* parameter. *DxgkDdiQueryChildRelations* must fill in all but the last structure in the array with information that describes the child devices of the display adapter. The last structure in the array must remain zeroed.

### `ChildRelationsSize` [in]

The total size, in bytes, of the *ChildRelations* array including the zeroed structure at the end.

## Return value

*DxgkDdiQueryChildRelations* returns STATUS_SUCCESS if it succeeds; otherwise, it returns one of the error codes defined in *Ntstatus.h*.

## Remarks

All child devices of the display adapter are onboard; monitors and other external devices that connect to the display adapter are not considered child devices.

The display miniport driver must fill in an array of DXGK_CHILD_DESCRIPTOR structures, one for each of the display adapter's children. The array must contain DXGK_CHILD_DESCRIPTOR structures for all current child devices and all potential child devices. For example, if docking a portable computer will result in new video outputs becoming available, those video outputs must have descriptors in the array, even if they are not currently available.

The *DxgkDdiQueryChildRelations* function should be made pageable.

## See also

[DXGK_CHILD_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_child_descriptor)

[DXGK_CHILD_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_child_status)

[DxgkDdiQueryChildStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_child_status)

[DxgkDdiQueryDeviceDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_device_descriptor)
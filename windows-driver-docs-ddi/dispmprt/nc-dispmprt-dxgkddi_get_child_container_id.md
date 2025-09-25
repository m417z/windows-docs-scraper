# DXGKDDI_GET_CHILD_CONTAINER_ID callback function

## Description

 Queries the container ID for the specified target. Implemented by Windows Display Driver Model (WDDM) 1.2 and later display miniport drivers.

## Parameters

### `MiniportDeviceContext` [in]

A handle to a context block that is associated with a display adapter. The display miniport driver's [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function previously provided this handle to the Microsoft DirectX graphics kernel subsystem.

### `ChildUid` [in]

A ULONG value that uniquely identifies the child device. The display miniport driver previously provided this identifier when its [DxgkDdiQueryChildRelations](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_child_relations) function was called.

### `ContainerId` [in, out]

A pointer to a [DXGK_CHILD_CONTAINER_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_child_container_id) structure. For more information, see the Remarks section.

## Return value

Returns one of the following error codes.

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The driver has updated the structure pointed to by the ContainerId parameter with container ID information obtained from the display hardware.|
|STATUS_MONITOR_NODESCRIPTOR|The driver has accepted the default container ID information provided in the structure pointed to by ContainerId. **Note:** If the driver returns this status code, it should not modify the structure.|

Otherwise the function returns one of the status codes defined in Ntstatus.h.

## Remarks

The operating system calls the display miniport driver's [DxgkDdiQueryChildRelations](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_child_relations) function to enumerate the child devices of the display adapter. The operating system then calls the display miniport driver's [DxgkDdiQueryDeviceDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_device_descriptor) function for each child device to obtain the Extended Display Information Data (EDID) for the device. For more information on this procedure, see [Enumerating Child Devices of a Display Adapter](https://learn.microsoft.com/windows-hardware/drivers/display/enumerating-child-devices-of-a-display-adapter).

Based on the device's EDID data, the operating system generates a default container ID for the child device. Then, the operating system calls the display miniport driver's *DxgkDdiGetChildContainerId* function and passes a pointer to a [DXGK_CHILD_CONTAINER_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_child_container_id) structure through the *ContainerId* parameter. The **ContainerId** member of this structure contains the default container ID for the child display device.

The display miniport driver can either accept the default container ID or set the **ContainerId** member to a unique identifier for the device before it returns from the call to *DxgkDdiGetChildContainerId*.

For more information about Container IDs, see [Container IDs](https://learn.microsoft.com/windows/desktop/com/com-error-codes-4).

## See also

[DXGK_CHILD_CONTAINER_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_child_container_id)

[DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)

[DxgkDdiQueryChildRelations](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_child_relations)

[DxgkDdiQueryDeviceDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_device_descriptor)
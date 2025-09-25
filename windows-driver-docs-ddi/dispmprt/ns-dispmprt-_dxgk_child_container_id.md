# _DXGK_CHILD_CONTAINER_ID structure

## Description

Contains the container ID for a child device that is connected to a display adapter.

## Members

### `ContainerId`

The container ID for the child device. For more information, see the Remarks section.

### `EldInfo`

This structure contains the information that the operating system used to generate the container ID for the child device.

### `EldInfo.PortId`

A ULONG64 value that contains the port ID for the child device. The operating system created this ID based on the name of the child device.

### `EldInfo.ManufacturerName`

A USHORT value that contains the manufacturer's name. The operating system obtains this data from the child device's descriptor.

### `EldInfo.ProductCode`

A USHORT value that contains the manufacturer's product code for the child device. The operating system obtains this data from the child device's descriptor.

## Remarks

The operating system calls the display miniport driver's [DxgkDdiQueryChildRelations](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_child_relations) function to enumerate the child devices of the display adapter. The operating system then calls the display miniport driver's [DxgkDdiQueryDeviceDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_device_descriptor) function for each child device to obtain the Extended Display Information Data (EDID) for the device. For more information on this procedure, see [Enumerating Child Devices of a Display Adapter](https://learn.microsoft.com/windows-hardware/drivers/display/enumerating-child-devices-of-a-display-adapter).

Based on the device's EDID data, the operating system generates a default container ID for the child device. Then, the operating system calls the display miniport driver's [DxgkDdiGetChildContainerId](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_get_child_container_id) function and passes a pointer to a **DXGK_CHILD_CONTAINER_ID** structure through the *ContainerId* parameter. The **ContainerId** member of this structure contains the default container ID for the child display device.

The display miniport driver can either accept the default container ID because the display hardware has no container ID coded into the firmware, or it can set the **ContainerId** member to a unique identifier obtained from the display hardware device before it returns from the call to [DxgkDdiGetChildContainerId](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_get_child_container_id).

For more information about Container IDs, see [Container IDs](https://learn.microsoft.com/windows/desktop/com/com-error-codes-4).

## See also

[DxgkDdiGetChildContainerId](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_get_child_container_id)

[DxgkDdiQueryChildRelations](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_child_relations)

[DxgkDdiQueryDeviceDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_device_descriptor)
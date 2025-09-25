# DXGKDDI_QUERY_DEVICE_DESCRIPTOR callback function

## Description

The *DxgkDdiQueryDeviceDescriptor* function returns a descriptor for a child device of a display adapter or for an external device (typically a monitor) connected to a child device of a display adapter.

## Parameters

### `MiniportDeviceContext` [in]

A handle to a context block associated with a display adapter. The display miniport driver's [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function previously provided this handle to the DirectX graphics kernel subsystem.

### `ChildUid` [in]

An integer that uniquely identifies the child device. The display miniport driver's [DxgkDdiQueryChildRelations](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_child_relations) function previously provided this identifier to the display port driver.

### `DeviceDescriptor` [in, out]

A pointer to a [DXGK_DEVICE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_device_descriptor) structure. The caller initializes the **DescriptorLength** and **DescriptorBuffer** members. If the child device has a type of **TypeVideoOutput**, the caller also initializes the **DescriptorOffset** member. On return, the caller-allocated buffer pointed to by the **DescriptorBuffer** member receives the descriptor.

## Return value

*DxgkDdiQueryDeviceDescriptor* returns one of the following values:

| **Return code** | **Description** |
|:--|:--|
| **STATUS_SUCCESS** | The function successfully returned the device descriptor. |
| **STATUS_GRAPHICS_CHILD_DESCRIPTOR_NOT_SUPPORTED** | The (onboard) child device identified by ChildUid does not support a descriptor. |
| **STATUS_MONITOR_NO_DESCRIPTOR** | The child device identified by ChildUid is connected to a monitor that does not support an EDID descriptor. |
| **STATUS_MONITOR_NO_MORE_DESCRIPTOR_DATA** | The child device identified by ChildUid is connected to a monitor that does support an EDID descriptor, but the descriptor does not have the EDID extension block specified by the DescriptorOffset and DescriptorLengthmembers of DeviceDescriptor. |

## Remarks

*DxgkDdiQueryDeviceDescriptor* must never write more than the number of bytes specified by *DeviceDescriptor*->**DescriptorLength**.

If the child device identified by *ChildUid* has a type of **TypeVideoOutput**, *DxgkDdiQueryDeviceDescriptor* returns a portion of the Extended Display Identification Data (EDID) for the monitor connected to the output. *DeviceDescriptor*->**DescriptorOffset** specifies the byte-offset into the EDID of the start of the data to be returned.

If the child device identified by *ChildUid* is not a video output, *DxgkDdiQueryDeviceDescriptor* returns a generic device descriptor; that is, it fills in the members of a [DXGK_GENERIC_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_generic_descriptor) structure.

The *DxgkDdiQueryDeviceDescriptor* function can be called several times for one child device. For a child device that has a connected monitor, the display port driver calls *DxgkDdiQueryDeviceDescriptor* during initialization to obtain the first 128-byte block of a monitor's EDID. Later the monitor class function driver (Monitor.sys) calls *DxgkDdiQueryDeviceDescriptor* to obtain selected portions (including the first 128-byte block) of that same monitor's EDID.

*DxgkDdiQueryDeviceDescriptor* should be made pageable.

## See also

[DXGK_CHILD_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_child_descriptor)

[DXGK_DEVICE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_device_descriptor)

[DxgkDdiQueryChildRelations](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_child_relations)

[DxgkDdiQueryChildStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_child_status)
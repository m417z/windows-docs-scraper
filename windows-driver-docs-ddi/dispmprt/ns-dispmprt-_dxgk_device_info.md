# _DXGK_DEVICE_INFO structure

## Description

The DXGK_DEVICE_INFO structure holds information that describes a display adapter.

## Members

### `MiniportDeviceContext`

A handle to a context block (created and maintained by the display miniport driver) associated with a display adapter.

### `PhysicalDeviceObject`

A pointer to the physical device object (PDO) that represents the display adapter.

### `DeviceRegistryPath`

A Unicode string that holds the registry path of the software key for the display adapter. Registry data should be written only to this path.

### `TranslatedResourceList`

A pointer to a [CM_RESOURCE_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_resource_list) structure that holds the translated resources assigned to the display adapter.

### `SystemMemorySize`

The size, in bytes, of system memory.

### `HighestPhysicalAddress`

The highest physical address of system memory (RAM).

### `AgpApertureBase`

The base physical address of the AGP aperture. If 0, the display adapter is not an AGP adapter, or AGP resources were not found.

### `AgpApertureSize`

The size, in bytes, of the AGP aperture. If 0, the display adapter is not an AGP adapter, or AGP resources were not found.

### `DockingState`

The state of a portable computer that can be attached to a docking station.

## Remarks

The display miniport driver's [DxgkDdiStartDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device) function allocates a DXGK_DEVICE_INFO structure and calls [DxgkCbGetDeviceInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_get_device_information) to get that structure filled in with information about a display adapter. Five of the structure members (**Version**, **SystemMemorySize**, **HighestPhysicalAddress**, **AgpApertureBase**, and **AgpApertureSize**) hold general information and are not associated with a particular display adapter. Those members are included in the DXGK_DEVICE_INFO structure because they provide information that *DxgkDdiStartDevice* requires to initialize the driver and display adapter hardware.

## See also

[CM_RESOURCE_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_resource_list)

[DxgkCbGetDeviceInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_get_device_information)

[DxgkDdiStartDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device)
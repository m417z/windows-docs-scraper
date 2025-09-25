# NdisMGetDeviceProperty function

## Description

The
**NdisMGetDeviceProperty** function retrieves device objects required to set up communication with a
miniport driver through a bus driver.

## Parameters

### `MiniportAdapterHandle` [in]

The NDIS handle that identifies the miniport adapter. This handle was originally passed to the
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function.

### `PhysicalDeviceObject` [out, optional]

A pointer to a caller-allocated buffer. The buffer receives a pointer to a
[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure that represents the
physical device for the miniport adapter. This pointer is optional.

### `FunctionalDeviceObject` [out, optional]

A pointer to a caller-allocated buffer. The buffer receives a pointer to a
[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure.
**DEVICE_OBJECT** represents the functional device object that NDIS creates for the physical device.
This pointer is optional.

### `NextDeviceObject` [out, optional]

A pointer to a caller-allocated buffer. The buffer receives a pointer to a
[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure that represents the next device object. This next device object is
preceded in the chain by the functional device object that belongs to the miniport driver. NDIS creates
this functional device object for the physical device. For example, the next device object could be the
object that is associated with a bus driver or HAL This pointer is optional.

### `AllocatedResources` [out, optional]

A pointer to a caller-allocated buffer that receives a pointer to a
CM_RESOURCE_LIST structure.
CM_RESOURCE_LIST describes a list of hardware resources that the PnP manager assigns to the
physical device. This list contains the resources in raw form, that is, not translated by HAL. This
pointer is optional.

### `AllocatedResourcesTranslated` [out, optional]

A pointer to a caller-allocated buffer that receives a pointer to a
CM_RESOURCE_LIST structure.
CM_RESOURCE_LIST describes a list of hardware resources that the PnP manager assigns to the
physical device. This list contains the resources in translated form, that is, translated by HAL. This
pointer is optional.

## Remarks

Miniport drivers must retrieve specific information to set up their communications. Miniport drivers
for miniport instances that communicate through bus drivers use
**NdisMGetDeviceProperty** to retrieve this information. For example, miniport driver instances that
attach to Universal Serial Bus (USB) or IEEE 1394 buses require miniport drivers that expose a standard
NDIS miniport driver interface at their upper edge, and use the class interface for the particular bus at
their lower edge. To use the USB or 1394 class interface, a miniport driver creates and submits I/O
Request Packets (IRPs). The miniport driver uses the physical and next-device objects that
**NdisMGetDeviceProperty** retrieves to submit IRPs to the class interface for a particular bus. To
locate more information about creating and submitting IRPs to bus drivers, see
[Handling IRPs](https://learn.microsoft.com/windows-hardware/drivers/kernel/handling-irps).

Pointers to
[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) for the physical, functional, and next device objects that
**NdisMGetDeviceProperty** retrieves are simply handles that are opaque to the miniport driver.

Miniport drivers can call
**NdisMGetDeviceProperty** to retrieve pointers to "raw" or "translated" resources. Raw resources have
not been translated by HAL; translated resources have been. To locate more information about raw and
translated resources, see
[Plug and Play](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff562374(v=vs.85)).

## See also

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)
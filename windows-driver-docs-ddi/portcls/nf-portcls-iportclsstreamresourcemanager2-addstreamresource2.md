# IPortClsStreamResourceManager2::AddStreamResource2

## Description

AddStreamResource2 adds a stream resource.
Two type of stream resources are supported: interrupts and driver-owned threads. The AddStreamResource2 method can only be used by audio waveRT miniport drivers.

## Parameters

### `PhysicalDeviceObject` [in]

Pointer to the device object. The device object is a system structure of type [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object).

### `ResourceSet` [in]

PVOID - Reserved for future use, set to NULL. Only device-scoped resources are supported at this time.

### `ResourceDescriptor` [in]

PPCSTREAMRESOURCE_DESCRIPTOR - The resource to add. For more information see, [PCSTREAMRESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-_pcstreamresource_descriptor).

### `ResourceHandle` [out]

PCSTREAMRESOURCE* - The location that will hold the resource handle. For more information, see [RemoveStreamResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportclsstreamresourcemanager-removestreamresource).

## Return value

STATUS_SUCCESS – The driver was able to register the resource of the specified PDO.

STATUS_INVALID_PARAMETER – The driver returns this error if it finds any other parameter invalid, aside from the specific cases for other error status instances.

Additional standard status codes may be returned.

## See also

[IPortClsStreamResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iportclsstreamresourcemanager)

[IPortClsStreamResourceManager2](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iportclsstreamresourcemanager2)

[PCSTREAMRESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-_pcstreamresource_descriptor)

[RemoveStreamResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportclsstreamresourcemanager-removestreamresource)
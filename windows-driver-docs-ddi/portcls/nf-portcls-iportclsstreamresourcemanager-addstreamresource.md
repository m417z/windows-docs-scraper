# IPortClsStreamResourceManager::AddStreamResource

## Description

AddStreamResource adds a stream resource. Two type of stream resources are supported: interrupts and driver-owned threads. The AddStreamResource method can only be used by audio WaveRT miniport drivers.

## Parameters

### `ResourceSet`

PVOID - Reserved for future use, set to NULL. Only device-scoped resources are supported at this time.

### `ResourceDescriptor`

PPCSTREAMRESOURCE_DESCRIPTOR - The resource to add. For more information see, [_PCSTREAMRESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-_pcstreamresource_descriptor).

### `ResourceHandle`

PCSTREAMRESOURCE* - The location that will hold the resource handle. For more information, see [PcRemoveStreamResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcremovestreamresource).

## Return value

This method returns NTSTATUS which contains:

- STATUS_SUCCESS – The driver was able to register the resource of the specified PDO.
- STATUS_INVALID_PARAMETER – The driver returns this error if it finds any other parameter invalid, aside from the specific cases for other error status instances.

Additional standard status codes may be returned.

## Remarks

## See also

[IPortClsStreamResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iportclsstreamresourcemanager)
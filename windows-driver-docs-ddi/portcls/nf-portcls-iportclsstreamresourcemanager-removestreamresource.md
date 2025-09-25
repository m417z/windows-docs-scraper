# IPortClsStreamResourceManager::RemoveStreamResource

## Description

RemoveStreamResource removes an existing stream resource. The RemoveStreamResource method can only be used by audio waveRT miniport drivers.

## Parameters

### `ResourceHandle`

PCSTREAMRESOURCE– Resource handle returned by PcAddStreamResource. For more information, see [PcAddStreamResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcaddstreamresource).

## Return value

This method returns NTSTATUS which contains:

- STATUS_SUCCESS – The driver was able to register the resource of the specified PDO.
- STATUS_INVALID_PARAMETER – The driver returns this error if it finds any other parameter invalid, aside from the specific cases for other error status instances.

Additional standard status codes may be returned.

## Remarks

To help ensure glitch-free operation, audio drivers must register their streaming resources with portcls. This allows the OS to manage resources to avoid interference between audio streaming and other subsystems. Stream resources are any resources used by the audio driver to process audio streams or ensure audio data flow.

Audio drivers must remove a previously registered resource. Drivers may unregister a resource as a result of the following system activities:

- Device re-balance when I/O resources change.
- Device power transitions (D0<- ->Dx) when resources are destroyed or created. For example interrupts may be disconnected when going in Dx and reconnected with moving back to D0.
- When processing stop, surprise-remove, remove plug and play events.
- When associated audio endpoints go away. For example if a thread is created to handle the data stream of an endpoint and the endpoint is removed. In this case, the driver should remove the thread stream resource.

The audio driver must make sure the resource is valid when making this call.

## See also

[IPortClsStreamResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iportclsstreamresourcemanager)
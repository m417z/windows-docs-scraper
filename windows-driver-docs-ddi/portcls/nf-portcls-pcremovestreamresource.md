# PcRemoveStreamResource function

## Description

PcRemoveStreamResource removes an existing stream resource. PcRemoveStreamResource can be called by any driver, including non-audio WaveRT miniport drivers, that has interrupts/threads associated with an audio stream. It can also be called by audio WaveRT miniport drivers.

## Parameters

### `ResourceHandle` [in]

PCSTREAMRESOURCE– Resource handle returned by PcAddStreamResource.
For more information, see [PcAddStreamResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcaddstreamresource) and [PCSTREAMRESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-_pcstreamresource_descriptor).

## Return value

STATUS_SUCCESS – The driver was able to register the resource of the specified PDO.

STATUS_INVALID_PARAMETER – The driver returns this error if it finds any other parameter invalid, aside from the specific cases for other error status instances.

Additional standard status codes may be returned.

## Remarks

To help ensure glitch-free operation, audio drivers must register their streaming resources with portcls. This allows the OS to manage resources to avoid interference between audio streaming and other subsystems.

Stream resources are any resources used by the audio driver to process audio streams or ensure audio data flow.

Audio drivers must remove a previously registered resource. Drivers may unregister a resource as a result of the following system activities:

* Device re-balance when I/O resources change.
* Device power transitions (D0<- ->Dx) when resources are destroyed or created. For example interrupts may be disconnected when going in Dx and reconnected with moving back to D0.
* When processing stop, surprise-remove, remove plug and play events.
* When associated audio endpoints go away. For example if a thread is created to handle the data stream of an endpoint and the endpoint is removed. In this case, the driver should remove the thread stream resource.

The audio driver must make sure the resource is valid when making this call.

Audio drivers that only run in Windows 10 can use [PcAddStreamResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcaddstreamresource) and **PcRemoveStreamResource**. For Audio waveRT miniport drivers that need to also run under previous versions of Windows, use [AddStreamResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportclsstreamresourcemanager-addstreamresource) and [RemoveStreamResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportclsstreamresourcemanager-removestreamresource).

## See also

[PCSTREAMRESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-_pcstreamresource_descriptor)

[PcAddStreamResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcaddstreamresource)

[PcStreamResourceType](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ne-portcls-_pcstreamresourcetype)
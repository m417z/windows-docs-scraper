# PcAddStreamResource function

## Description

PcAddStreamResource adds a stream resource.
Two type of stream resources are supported: interrupts and driver-owned threads. PcAddStreamResource can be called by any non-audio WaveRT miniport driver that has interrupts/threads associated with an audio stream. It can also be called by audio WaveRT miniport drivers.

## Parameters

### `PhysicalDeviceObject` [in]

PDEVICE_OBJECT - The PDO of the device stack using this resource.

### `ResourceSet` [in]

PVOID - Reserved for future use, set to NULL. Only device-scoped resources are supported at this time.

### `ResourceDescriptor` [in]

PPCSTREAMRESOURCE_DESCRIPTOR - The resource to add. For more information, see [PCSTREAMRESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-_pcstreamresource_descriptor).

### `ResourceHandle` [out]

PCSTREAMRESOURCE* - The location that will hold the resource handle. For more information, see [PcRemoveStreamResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcremovestreamresource).

## Return value

STATUS_SUCCESS – The driver was able to register the resource of the specified PDO.

STATUS_INVALID_PARAMETER – The driver returns this error if it finds any other parameter invalid, aside from the specific cases for other error status instances.

Additional standard status codes may be returned.

## Remarks

To help ensure glitch-free operation, audio drivers must register their streaming resources with portcls. This allows the OS to manage resources to avoid interference between audio streaming and other subsystems.

Stream resources are any resources used by the audio driver to process audio streams or ensure audio data flow.

All audio drivers must register their stream resources with the audio class driver. Driver registers the following resource types: interrupts, driver-owned threads and dependencies on other audio stack’s resources (example: parallel audio driver stacks). See the definition of [PCSTREAMRESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-_pcstreamresource_descriptor) for more information.

Audio driver must make sure the resource is valid when making this call.

Audio drivers that only run in Windows 10 can use **PcAddStreamResource** and [PcRemoveStreamResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcremovestreamresource). For Audio waveRT miniport drivers that need to also run under previous versions of Windows, use [AddStreamResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportclsstreamresourcemanager-addstreamresource) and [RemoveStreamResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportclsstreamresourcemanager-removestreamresource).

## See also

[PCSTREAMRESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-_pcstreamresource_descriptor)

[PcRemoveStreamResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcremovestreamresource)
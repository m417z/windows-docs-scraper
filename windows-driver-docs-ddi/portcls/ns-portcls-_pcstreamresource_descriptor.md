# _PCSTREAMRESOURCE_DESCRIPTOR structure

## Description

PCSTREAMRESOURCE_DESCRIPTOR defines the stream resource. Use PCSTREAMRESOURCE_DESCRIPTOR_INIT to correctly initialize this structure.

## Members

### `Size`

 This field is init to the size of the struct.

### `Flags`

Reserved for future use. Set to zero.

### `Pdo`

The physical device object of the stack that created this resource.

### `Type`

The union of the different stream resource types.

### `Resource`

### `Resource.Interrupt`

### `Resource.Interrupt.Version`

### `Resource.Interrupt.Generic`

### `Resource.Thread`

Thread.

### `Resource.ResourceSet`

Reserved for future use, set to NULL. Only device-scoped resources are supported at this time.

## Remarks

Stream resources are any resources used by the audio driver to process audio streams or ensure audio data flow. Two type of stream resources are supported: interrupts and driver-owned threads. Audio drivers should register a resource after creating the resource, and unregister the resource before deleted it.

## See also

[PcStreamResourceType](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ne-portcls-_pcstreamresourcetype)
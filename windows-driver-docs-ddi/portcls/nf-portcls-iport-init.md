# IPort::Init

## Description

The Init method initializes the port driver.

## Parameters

### `DeviceObject`

Pointer to the device object that was passed as an argument to the adapter driver's device-startup routine. The device object is a system structure of type DEVICE_OBJECT.

### `Irp`

Pointer to the IRP that was passed as an argument to the adapter driver's device-startup routine.

### `UnknownMiniport`

Pointer to the IUnknown interface of the uninitialized miniport object. This interface is queried for the specific miniport interface supported by the port driver, and the initialization function on that interface is called.

### `UnknownAdapter`

Pointer to the IUnknown interface of the adapter object whose port driver is being initialized. This pointer is optional and can be specified as NULL. For more information, see the following Remarks section.

### `ResourceList`

Pointer to the IResourceList object that was passed as an argument to the adapter driver's device-startup routine. After passing this reference to the miniport driver, the port driver is free to examine the contents of the resource list but will not modify the contents of this list.

## Return value

This method returns NTSTATUS which contains STATUS_SUCCESS if the call was successful. Otherwise, the method returns an appropriate error code.

## Remarks

The miniport object specified by UnknownMiniport must support the miniport interface that the port driver requires or the Init call will fail.

During the IPort::Init call, the port driver calls the miniport driver's initialization method (for example, see [IMiniportWavePci::Init](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiportwavepci-init)).

Parameter UnknownAdapter points to the COM interface of an adapter object. The adapter driver typically creates this object within its device-startup routine, which is the routine that the operating system calls to start the device (see Startup Sequence). For an example of an interface for an adapter object, see the `CMiniportWaveRT::Init` definition and implementation in the sysvad audio driver sample.

The UnknownMiniport, UnknownAdapter, and ResourceList parameters follow the standard reference-counting conventions for COM objects.

## See also

[IPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iport)

[IMiniportWavePci::Init](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiportwavepci-init)
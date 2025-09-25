# IMiniportMidi::Init

## Description

The `Init` method initializes the MIDI miniport object.

## Parameters

### `UnknownAdapter` [in]

Pointer to the **IUnknown** interface of the adapter object whose miniport object is being initialized. This parameter is optional and can be specified as **NULL**. For more information, see the following Remarks section.

### `ResourceList` [in]

Pointer to [IResourceList](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iresourcelist) interface of the resource list object that is to be supplied to the miniport driver during initialization. After passing this reference to the miniport driver, the port driver is free to examine the contents of the resource list but will not modify the contents of this list. For more information, see the following Remarks section.

### `Port` [in]

Pointer to the [IPortMidi](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iportmidi) object that is bound to this miniport object. The caller specifies a valid, non-**NULL** pointer value for this parameter.

### `ServiceGroup` [out]

Output pointer for the service group. This parameter points to a caller-allocated pointer variable into which the method writes a pointer to the [IServiceGroup](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iservicegroup) interface of the miniport driver's service group object. This is the service group that is being registered for interrupt notification. The caller specifies a valid, non-**NULL** pointer value for this parameter.

## Return value

`Init` returns STATUS_SUCCESS if the call was successful. Otherwise, the method returns an appropriate error code.

## Remarks

The *UnknownAdapter* parameter is optional:

* If *UnknownAdapter* is non-**NULL**, the `Init` method queries the *UnknownAdapter* object for its [IInterruptSync](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iinterruptsync) interface.
* If *UnknownAdapter* is **NULL**, the `Init` method calls [PcNewInterruptSync](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcnewinterruptsync) to create a new **IInterruptSync** object. In this case, the resource list that *ResourceList* points to supplies the interrupt resource that the new **IInterruptSync** object uses.

In either case, the `Init` method and calls the **RegisterServiceRoutine** method on the **IInterruptSync** object in order to add the miniport driver's interrupt service routine (ISR) to the list of interrupt sync routines. When the adapter driver later frees the port object, the port driver releases its reference to the **IInterruptSync** object.

The *UnknownAdapter* and *ResourceList* parameters are the same pointer values that the adapter driver earlier passed as parameters to the **IPortMidi** object's **Init** method (see [IPort::Init](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iport-init)).

The *UnknownAdapter*, *ResourceList*, *Port*, and *ServiceGroup* parameters follow the [reference-counting conventions for COM objects](https://learn.microsoft.com/windows-hardware/drivers/audio/reference-counting-conventions-for-com-objects).

## See also

[IInterruptSync](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iinterruptsync)

[IMiniportMidi](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportmidi)

[IPort::Init](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iport-init)

[IPortMidi](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iportmidi)

[IResourceList](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iresourcelist)

[IServiceGroup](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iservicegroup)

[PcNewInterruptSync](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcnewinterruptsync)
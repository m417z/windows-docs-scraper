# IMiniportDMus::Init

## Description

The `Init` method initializes the DMus miniport object.

## Parameters

### `UnknownAdapter` [in, optional]

Pointer to the **IUnknown** interface of the adapter object whose miniport object is being initialized. This parameter is optional and can be specified as **NULL**. For more information, see the following Remarks section.

### `ResourceList` [in]

Pointer to an [IResourceList](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iresourcelist) object that contains the adapter's resource list. After passing this reference to the miniport driver, the port driver is free to examine the contents of the resource list but will not modify the contents of this list.

### `Port` [in]

Pointer to an [IPortDMus](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nn-dmusicks-iportdmus) object that provides the port driver's callback interface.

### `ServiceGroup` [out]

Output pointer for the service group. This parameter points to a caller-allocated pointer variable into which the method writes a pointer to the [IServiceGroup](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iservicegroup) interface of the miniport driver's service group object. This is the service group that this miniport driver wants to have used for calls to [IPortDMus::Notify](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nf-dmusicks-iportdmus-notify).

## Return value

`Init` returns S_OK if the call was successful. Otherwise, the method returns an appropriate error code.

## Remarks

The *pUnknownAdapter* parameter is optional:

* If *pUnknownAdapter* is non-**NULL**, the `Init` method queries the *pUnknownAdapter* object for its [IInterruptSync](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iinterruptsync) interface.
* If *pUnknownAdapter* is **NULL**, the `Init` method calls [PcNewInterruptSync](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcnewinterruptsync) to create a new **IInterruptSync** object. In this case, the resource list that *pResourceList* points to supplies the interrupt resource that the new **IInterruptSync** object uses.

In either case, the `Init` method and calls the **RegisterServiceRoutine** method on the **IInterruptSync** object in order to add the miniport driver's interrupt service routine (ISR) to the list of ISRs. When the adapter driver later frees the port object, the port driver releases its reference to the **IInterruptSync** object.

The *pUnknownAdapter* and *pResourceList* parameters are the same pointer values that the adapter driver earlier passed as parameters to the **IPortDMus** object's `Init` method (see [IPort::Init](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iport-init)).

The *pUnknownAdapter*, *pResourceList*, *pPort*, and *ppServiceGroup* parameters follow the [reference-counting conventions for COM objects](https://learn.microsoft.com/windows-hardware/drivers/audio/reference-counting-conventions-for-com-objects).

## See also

[IInterruptSync](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iinterruptsync)

[IMiniportDMus](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nn-dmusicks-iminiportdmus)

[IPort::Init](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iport-init)

[IPortDMus](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nn-dmusicks-iportdmus)

[IPortDMus::Notify](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nf-dmusicks-iportdmus-notify)

[IResourceList](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iresourcelist)

[IServiceGroup](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iservicegroup)

[PcNewInterruptSync](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcnewinterruptsync)
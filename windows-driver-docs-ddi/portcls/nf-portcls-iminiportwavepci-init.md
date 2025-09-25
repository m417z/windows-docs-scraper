# IMiniportWavePci::Init

## Description

The `Init` method initializes the WavePci miniport object. Initialization includes verification of the hardware using the resources specified in the resource list.

## Parameters

### `UnknownAdapter` [in]

Pointer to the **IUnknown** interface of the adapter object whose miniport object is being initialized. For more information, see the following Remarks section.

### `ResourceList` [in]

Pointer to [IResourceList](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iresourcelist) interface of resource list object that is to be supplied to the miniport driver during initialization. After passing this reference to the miniport driver, the port driver is free to examine the contents of the resource list but will not modify the contents of this list. For more information, see the following Remarks section.

### `Port` [in]

Pointer to the port driver's [IPortWavePci](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iportwavepci) interface object. The caller specifies a valid, non-NULL pointer value for this parameter.

### `ServiceGroup` [out]

Output pointer for the service group. This parameter points to a caller-allocated pointer variable into which the method writes a pointer to the [IServiceGroup](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iservicegroup) interface of the miniport driver's service group object. This is the service group that is being registered for interrupt notification. The caller specifies a valid, non-NULL pointer value for this parameter.

## Return value

`Init` returns STATUS_SUCCESS if the call was successful. Otherwise, the method returns an appropriate error code.

## Remarks

The *UnknownAdapter* and *ResourceList* parameters are the same pointer values that the adapter driver earlier passed as parameters to the **IPortWavePci** object's **Init** method (see [IPort::Init](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iport-init)).

The *UnknownAdapter*, *ResourceList*, *Port*, and *ServiceGroup* parameters follow the [reference-counting conventions for COM objects](https://learn.microsoft.com/windows-hardware/drivers/audio/reference-counting-conventions-for-com-objects).

## See also

[IMiniportWavePci](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportwavepci)

[IPort::Init](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iport-init)

[IPortWavePci](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iportwavepci)

[IResourceList](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iresourcelist)

[IServiceGroup](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iservicegroup)
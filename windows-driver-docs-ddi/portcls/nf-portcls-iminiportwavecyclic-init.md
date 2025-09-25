# IMiniportWaveCyclic::Init method

## Description

The `Init` method initializes the WaveCyclic miniport object. Initialization includes verification of the hardware using the resources specified in the resource list.

## Parameters

### `UnknownAdapter` [in]

Pointer to the **IUnknown** interface of the adapter object whose miniport object is being initialized. For more information, see the following Remarks section.

### `ResourceList` [in]

Pointer to [IResourceList](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iresourcelist) interface of the resource list object that is to be supplied to the miniport driver during initialization. After passing this reference to the miniport driver, the port driver is free to examine the contents of the resource list but will not modify the contents of this list. For more information, see the following Remarks section.

### `Port` [in]

Pointer to the [IPortWaveCyclic](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iportwavecyclic) object that is bound to this miniport driver. The caller specifies a valid, non-NULL pointer for this parameter.

## Return value

`Init` returns STATUS_SUCCESS if the call was successful. Otherwise, the method returns an appropriate error code.

## Remarks

The *UnknownAdapter* and *ResourceList* parameters are the same pointer values that the adapter driver earlier passed as parameters to the **IPortWaveCyclic** object's `Init` method (see [IPort::Init](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iport-init)).

The *UnknownAdapter*, *ResourceList*, and *Port* parameters follow the [reference-counting conventions for COM objects](https://learn.microsoft.com/windows-hardware/drivers/audio/reference-counting-conventions-for-com-objects).

## See also

[IMiniportWavweCyclic](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportwavecyclic)

[IPort::Init](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iport-init)

[IPortWaveCyclic](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iportwavecyclic)

[IResourceList](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iresourcelist)
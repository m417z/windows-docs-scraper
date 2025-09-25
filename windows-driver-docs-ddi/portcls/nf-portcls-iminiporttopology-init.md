# IMiniportTopology::Init

## Description

The `Init` method initializes the topology miniport object.

## Parameters

### `UnknownAdapter` [in]

Pointer to the **IUnknown** interface of the adapter object whose miniport object is being initialized. This parameter is optional and can be specified as **NULL**. For more information, see the following Remarks section.

### `ResourceList` [in]

Pointer to the [IResourceList](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iresourcelist) interface of the resource list object that is to be supplied to the miniport driver during initialization. After passing this reference to the miniport driver, the port driver is free to examine the contents of the resource list but will not modify the contents of this list. For more information, see the following Remarks section.

### `Port` [in]

Pointer to the [IPortTopology](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iporttopology) object that is bound to this miniport object. The caller specifies a valid, non-**NULL** pointer value for this parameter.

## Return value

`Init` returns STATUS_SUCCESS if the call was successful. Otherwise, the method returns an appropriate error code.

## Remarks

The *UnknownAdapter* and *ResourceList* parameters are the same pointer values that the adapter driver earlier passed as parameters to the **IPortTopology** object's **Init** method (see [IPort::Init](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iport-init)).

The *UnknownAdapter*, *ResourceList*, and *Port* parameters follow the [reference-counting conventions for COM objects](https://learn.microsoft.com/windows-hardware/drivers/audio/reference-counting-conventions-for-com-objects).

## See also

[IMiniportTopology](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiporttopology)

[IPort::Init](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iport-init)

[IPortTopology](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iporttopology)

[IResourceList](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iresourcelist)
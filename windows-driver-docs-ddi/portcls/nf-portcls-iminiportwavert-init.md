# IMiniportWaveRT::Init

## Description

The `Init` method initializes the [WaveRT miniport driver](https://learn.microsoft.com/windows-hardware/drivers/audio/wavert-miniport-driver) object.

## Parameters

### `UnknownAdapter` [in]

Pointer to the **IUnknown** interface of the adapter driver object whose miniport driver object is being initialized.

### `ResourceList` [in]

Pointer to the [IResourceList](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iresourcelist) interface of a resource-list object. This object specifies the list of hardware resources that the adapter driver has allocated to the miniport driver. The WaveRT port driver can examine the contents of the resource list, but it does not modify the list.

### `Port` [in]

Pointer to the [IPortWaveRT](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iportwavert) interface of the WaveRT port driver. The caller specifies a valid, non-NULL pointer value for this parameter.

## Return value

`Init` returns STATUS_SUCCESS if the call was successful. Otherwise, the method returns an appropriate error status code.

## Remarks

For more information about the *ResourceList* parameter, see the [IPort::Init](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iport-init)  topic. The *ResourceList* and *Port* parameters follow the reference-counting conventions for COM objects.

## See also

[IMiniportWaveRT](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportwavert)

[IPortWaveRT](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iportwavert)
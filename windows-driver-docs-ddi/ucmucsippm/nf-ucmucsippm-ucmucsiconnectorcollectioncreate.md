# UcmUcsiConnectorCollectionCreate function

## Description

Creates a connector collection object with UcmUcsiCx.

## Parameters

### `WdfDevice` [in]

A handle to a framework device object that the client driver received in the previous call to [**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

### `Attributes` [in]

A pointer to a caller-supplied [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that contains attributes for the new connector collection object. This parameter is optional and can be WDF_NO_OBJECT_ATTRIBUTES.

### `ConnectorCollection` [out]

A pointer to a location that receives a handle to the new connector collection object.

## Return value

Returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method can return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) value.

## Remarks

The collection object is required for creating a Platform Policy Manager (PPM) object. The client driver creates the object by calling [**UcmUcsiPpmCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmucsippm/nf-ucmucsippm-ucmucsippmcreate). The driver must not call [**UcmUcsiConnectorCollectionCreate**] after **UcmUcsiPpmCreate** because it would have no effect on the already existing PPM object.

The connector collection object is parented to the WDFOBJECT even when UcmUcsiConnectorCollectionCreate is called by passing WDF_NO_ATTRIBUTES. The lifetime of the object is manager by the framework.

## See also

[**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate)

[WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)

[**UcmUcsiPpmCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmucsippm/nf-ucmucsippm-ucmucsippmcreate)

[**UcmUcsiConnectorCollectionAddConnector**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmucsippm/nf-ucmucsippm-ucmucsiconnectorcollectionaddconnector)
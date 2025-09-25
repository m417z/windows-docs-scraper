# UcmUcsiPpmCreate function

## Description

Creates a Platform Policy Manager (PPM) object.

## Parameters

### `WdfDevice` [in]

A handle to a framework device object that the client driver received in the previous call to [**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

### `Config` [in]

A pointer to a caller-supplied [**UCMUCSI_PPM_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmucsippm/ns-ucmucsippm-_ucmucsi_ppm_config) structure that is initialized by calling [**UCMUCSI_PPM_CONFIG_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmucsippm/nf-ucmucsippm-ucmucsi_ppm_config_init). The **ConnectorCollectionHandle** member must be set to the handle retrieved in a previous call to [**UcmUcsiConnectorCollectionCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmucsippm/nf-ucmucsippm-ucmucsiconnectorcollectioncreate).

### `Attributes` [in]

A pointer to a caller-supplied [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that contains attributes for the new connector collection object. This parameter is optional and can be WDF_NO_OBJECT_ATTRIBUTES.

### `PPMObject` [out]

A pointer to a location that receives a handle to the new PPM object.

## Return value

Returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method can return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) value.

## Remarks

The client driver is expected to call **UcmUcsiPpmCreate** from the [EVT_WDF_DEVICE_PREPARE_HARDWARE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware) callback function.

The structure passed in _Config_ contains Type-C connector information that is necessary for creating connectors with USB Type-C connector class extension (UcmCx) by using [**UcmConnectorCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nf-ucmmanager-ucmconnectorcreate) and are not obtainable from PPM through UCSI commands such as GetCapability or GetConnectorCapability.

The _Config_ structure also contains connector IDs, which are required for one-to-one mapping between USB Type-C connectors and USB ports.

The PPM object is also a WDFOBJECT and creates a one-to-one association with the WDFDEVICE handle provided by the client driver.

The PPM object is parented to the WDFOBJECT even when UcmUcsiPpmCreate is called by passing WDF_NO_ATTRIBUTES. The lifetime of the object is manager by the framework.

## See also
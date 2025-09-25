# IUnregisterPhysicalConnection::UnregisterPhysicalConnection

## Description

The `UnregisterPhysicalConnection` method deletes the registration of a physical connection that was registered by a previous call to [PcRegisterPhysicalConnection](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcregisterphysicalconnection).

## Parameters

### `DeviceObject` [in]

Pointer to the device object for the adapter device. This parameter must point to a system structure of type [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object).

### `FromUnknown` [in]

Pointer to the [IPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iport) interface of a port driver object. The port driver object that is associated with *FromUnknown* is bound to the subdevice that supplies the connection's data source pin.

### `FromPin` [in]

Specifies a pin ID. This parameter identifies the data source (output) pin on the filter that is associated with the *FromUnknown* interface.

### `ToUnknown` [in]

Pointer to the **IPort** interface of a port driver object. The port driver object that is associated with *ToUnknown* is bound to the subdevice that supplies the connection's data sink pin.

### `ToPin` [in]

Specifies a pin ID. This parameter identifies the data sink (input) pin on the filter that is associated with the *ToUnknown* interface.

## Return value

`UnregisterPhysicalConnection` returns STATUS_SUCCESS if the call was successful. Otherwise, it returns an appropriate error code.

## Remarks

For more information, see [Dynamic Audio Subdevices](https://learn.microsoft.com/windows-hardware/drivers/audio/dynamic-audio-subdevices).

## See also

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[IPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iport)

[IUnregisterPhysicalConnection](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iunregisterphysicalconnection)

[PcRegisterPhysicalConnection](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcregisterphysicalconnection)
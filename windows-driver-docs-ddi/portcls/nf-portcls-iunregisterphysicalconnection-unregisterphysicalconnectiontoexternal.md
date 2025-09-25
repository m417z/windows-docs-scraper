# IUnregisterPhysicalConnection::UnregisterPhysicalConnectionToExternal

## Description

The `UnregisterPhysicalConnectionToExternal` method deletes the registration of a physical connection that was registered by a previous call to [PcRegisterPhysicalConnectionToExternal](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcregisterphysicalconnectiontoexternal).

## Parameters

### `DeviceObject` [in]

Pointer to the device object for the adapter device. This parameter must point to a system structure of type [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object).

### `FromUnknown` [in]

Pointer to the [IPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iport) interface of a port driver object. The port driver object that is associated with *FromUnknown* is bound to the subdevice that supplies the connection's data source pin.

### `FromPin` [in]

Specifies a pin ID. This parameter identifies the data source (output) pin on the filter that is associated with the *FromUnknown* interface.

### `ToString` [in]

Pointer to a null-terminated Unicode string that contains the name of the external filter that supplies the connection's data sink pin.

### `ToPin` [in]

Specifies a pin ID. This parameter identifies the data sink (input) pin on the external filter that is named by the *ToString* parameter.

## Return value

**UnregisterPhysicalConnectionToExternal** returns STATUS_SUCCESS if the call was successful. Otherwise, it returns an appropriate error code.

## Remarks

For more information, see [Dynamic Audio Subdevices](https://learn.microsoft.com/windows-hardware/drivers/audio/dynamic-audio-subdevices).

## See also

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[IPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iport)

[IUnregisterPhysicalConnection](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iunregisterphysicalconnection)

[PcRegisterPhysicalConnectionToExternal](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcregisterphysicalconnectiontoexternal)
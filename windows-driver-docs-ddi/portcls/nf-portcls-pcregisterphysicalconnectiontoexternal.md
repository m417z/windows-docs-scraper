# PcRegisterPhysicalConnectionToExternal function

## Description

The **PcRegisterPhysicalConnectionToExternal** function registers a physical connection from an audio adapter filter to an external audio adapter filter.

## Parameters

### `DeviceObject` [in]

Pointer to the device object for the device. This is a system structure of type [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object).

### `FromUnknown` [in]

Pointer to the [IPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iport) interface of a port driver object. The port driver object that is associated with *FromUnknown* is bound to the subdevice that supplies the connection's data source (output) pin.

### `FromPin` [in]

Specifies a pin ID. This parameter identifies the source (output) pin on the filter that is associated with the *FromUnknown* interface.

### `ToString` [in]

Pointer to a null-terminated Unicode string containing the symbolic link name of the external filter that supplies the sink pin for the connection.

### `ToPin` [in]

Specifies a pin ID. This parameter identifies the sink (input) pin on the external filter named by *ToString*.

## Return value

**PcRegisterPhysicalConnectionToExternal** returns STATUS_SUCCESS if the call was successful. Otherwise, it returns an appropriate error code.

## Remarks

An adapter driver calls **PcRegisterPhysicalConnectionToExternal** to register a physical connection with the PortCls system driver. PortCls stores this information so that the port driver can subsequently use the information to respond to [KSPROPERTY_PIN_PHYSICALCONNECTION](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-pin-physicalconnection) property requests.

This function is useful for specifying a topology link between two audio adapters that are controlled by different adapter drivers. The function registers a physical connection between a filter object representing a subdevice in the local audio adapter and a filter object representing a subdevice in an external adapter.

The *ToString* parameter is a symbolic link to the subdevice that is exposed by the external adapter driver.

The information that is required to register an external physical connection must be supplied to the two drivers. This can be done either during an initial coordinated install of the two devices, or dynamically by a user-mode configuration program that coordinates changes to the configuration of both devices.

An adapter driver can call the [IUnregisterPhysicalConnection::UnregisterPhysicalConnectionToExternal](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iunregisterphysicalconnection-unregisterphysicalconnectiontoexternal) method to delete the registration of a physical connection that was registered by a previous call to **PcRegisterPhysicalConnectionToExternal**. For more information, see [Dynamic Audio Subdevices](https://learn.microsoft.com/windows-hardware/drivers/audio/dynamic-audio-subdevices).

## See also

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[IPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iport)

[IUnregisterPhysicalConnection::UnregisterPhysicalConnectionToExternal](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iunregisterphysicalconnection-unregisterphysicalconnectiontoexternal)

[KSPROPERTY_PIN_PHYSICALCONNECTION](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-pin-physicalconnection)

[PcRegisterPhysicalConnection](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcregisterphysicalconnection)

[PcRegisterPhysicalConnectionFromExternal](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcregisterphysicalconnectionfromexternal)
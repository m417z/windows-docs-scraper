# PcRegisterPhysicalConnectionFromExternal function

## Description

The **PcRegisterPhysicalConnectionFromExternal** function registers a physical connection to an audio adapter filter from an external audio adapter filter.

## Parameters

### `DeviceObject` [in]

Pointer to the device object for the device. This is a system structure of type [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object).

### `FromString` [in]

Pointer to a null-terminated Unicode string containing the symbolic link name of the external filter that supplies the connection's source pin.

### `FromPin` [in]

Specifies a pin ID. This parameter identifies the source (output) pin on the external filter named by *FromString*.

### `ToUnknown` [in]

Pointer to the [IPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iport) interface of a port driver object. The port driver object that is associated with *ToUnknown* is bound to the subdevice that supplies the connection's data sink (input) pin.

### `ToPin` [in]

Specifies a pin ID. This parameter identifies the sink (input) pin on the filter that is associated with the *ToUnknown* interface.

## Return value

**PcRegisterPhysicalConnectionFromExternal** returns STATUS_SUCCESS if the call was successful. Otherwise, it returns an appropriate error code.

## Remarks

An adapter driver calls **PcRegisterPhysicalConnectionFromExternal** to register a physical connection with the PortCls system driver. PortCls stores this information so that the port driver can subsequently use the information to respond to [KSPROPERTY_PIN_PHYSICALCONNECTION](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-pin-physicalconnection) property requests.

This function is useful for specifying a topology link between two audio adapters that are controlled by different adapter drivers. The function registers a physical connection between a filter object representing a subdevice in the local audio adapter and a filter object representing a subdevice in an external adapter.

The *FromString* parameter is a symbolic link to the subdevice that is exposed by the external adapter driver.

The information that is required to register an external physical connection must be supplied to the two drivers. This can be done during an initial coordinated install of the two devices, or it can be done dynamically by a user-mode configuration program that coordinates changes to the configurations of both devices.

An adapter driver can call the [IUnregisterPhysicalConnection::UnregisterPhysicalConnectionFromExternal](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iunregisterphysicalconnection-unregisterphysicalconnectionfromexternal) method to delete the registration of a physical connection that was registered by a previous call to **PcRegisterPhysicalConnectionFromExternal**. For more information, see [Dynamic Audio Subdevices](https://learn.microsoft.com/windows-hardware/drivers/audio/dynamic-audio-subdevices).

## See also

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[IPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iport)

[IUnregisterPhysicalConnection::UnregisterPhysicalConnectionFromExternal](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iunregisterphysicalconnection-unregisterphysicalconnectionfromexternal)

[KSPROPERTY_PIN_PHYSICALCONNECTION](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-pin-physicalconnection)

[PcRegisterPhysicalConnection](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcregisterphysicalconnection)

[PcRegisterPhysicalConnectionToExternal](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcregisterphysicalconnectiontoexternal)
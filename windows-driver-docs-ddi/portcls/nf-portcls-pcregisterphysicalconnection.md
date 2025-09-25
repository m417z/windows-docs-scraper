# PcRegisterPhysicalConnection function

## Description

The **PcRegisterPhysicalConnection** function registers a physical connection between two audio adapter filters that are instantiated by the same adapter driver.

## Parameters

### `DeviceObject` [in]

Pointer to the device object for the adapter device. This parameter must point to a system structure of type [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object).

### `FromUnknown` [in]

Pointer to the [IPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iport) interface of a port driver object. The port driver object that is associated with *FromUnknown* is bound to the subdevice that supplies the connection's data source (output) pin.

### `FromPin` [in]

Specifies a pin ID. This parameter identifies the source (output) pin on the filter that is associated with the *FromUnknown* interface.

### `ToUnknown` [in]

Pointer to the [IPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iport) interface of a port driver object. The port driver object that is associated with *ToUnknown* is bound to the subdevice that supplies the connection's data sink (input) pin.

### `ToPin` [in]

Specifies a pin ID. This parameter identifies the sink (input) pin on the filter that is associated with the *ToUnknown* interface.

## Return value

**PcRegisterPhysicalConnection** returns STATUS_SUCCESS if the call was successful. Otherwise, it returns an appropriate error code.

## Remarks

An adapter driver calls **PcRegisterPhysicalConnection** to register a physical connection with the PortCls system driver. PortCls stores this information so that the port driver can subsequently use the information to respond to [KSPROPERTY_PIN_PHYSICALCONNECTION](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-pin-physicalconnection) property requests.

The parameters that the caller provides to the **PcRegisterPhysicalConnection** function describe a physical connection between two subdevices (represented as individual filters) on the same adapter card.

Unlike a logical connection between two pins, which can be configured under software control, a physical connection is hardwired. For example, a typical adapter card might have a physical connection that carries the analog signal from the output pin of its wave-output filter to the input pin of its [topology filter](https://learn.microsoft.com/windows-hardware/drivers/audio/topology-filters).

For an example of an adapter driver's device-startup routine (see [Startup Sequence](https://learn.microsoft.com/windows-hardware/drivers/audio/startup-sequence)) that uses the **PcRegisterPhysicalConnection** call to register an adapter's physical connections, see the source code for the SB16 sample audio driver in the Microsoft Windows Driver Kit (WDK).

An adapter driver can call the [IUnregisterPhysicalConnection::UnregisterPhysicalConnection](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iunregisterphysicalconnection-unregisterphysicalconnection) method to delete the registration of a physical connection that was registered by a previous call to **PcRegisterPhysicalConnection**. For more information, see [Dynamic Audio Subdevices](https://learn.microsoft.com/windows-hardware/drivers/audio/dynamic-audio-subdevices).

## See also

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[IPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iport)

[IUnregisterPhysicalConnection::UnregisterPhysicalConnection](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iunregisterphysicalconnection-unregisterphysicalconnection)

[KSPROPERTY_PIN_PHYSICALCONNECTION](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-pin-physicalconnection)

[PcRegisterPhysicalConnectionFromExternal](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcregisterphysicalconnectionfromexternal)

[PcRegisterPhysicalConnectionToExternal](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcregisterphysicalconnectiontoexternal)
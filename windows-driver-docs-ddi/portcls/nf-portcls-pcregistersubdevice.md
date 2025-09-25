# PcRegisterSubdevice function

## Description

The **PcRegisterSubdevice** function registers a subdevice to make it available for use by clients.

## Parameters

### `DeviceObject` [in]

Pointer to the adapter driver's device object. This is a system structure of type [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object).

### `Name` [in]

Pointer to a null-terminated Unicode string that specifies the name of the subdevice. The string buffer that the *Name* parameter points to must remain valid for the lifetime of the device object. The string contains a short name that distinguishes the subdevice from any other subdevices registered on the same device. Each of the device's subdevices must have a unique name.

### `Unknown` [in]

Pointer to the [IPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iport) interface of the port driver object that is bound to the subdevice.

## Return value

**PcRegisterSubdevice** returns STATUS_SUCCESS if the call was successful. Otherwise, it returns an appropriate error code.

## Remarks

The function registers the device interface instance for a filter object that represents a subdevice on an audio adapter. The I/O manager appends the string specified by the *Name* parameter to the reference string that it uses to identify the instance. The modified reference string is useful for distinguishing among the subdevices in the audio adapter. For more information about reference strings, see [IoRegisterDeviceInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregisterdeviceinterface).

For more information about the role of the **PcRegisterSubdevice** function in registering a subdevice, see [Subdevice Creation](https://learn.microsoft.com/windows-hardware/drivers/audio/subdevice-creation).

An adapter driver can call the [IUnregisterSubdevice::UnregisterSubdevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iunregistersubdevice-unregistersubdevice) method to delete the registration of a physical connection that was registered by a previous call to **PcRegisterSubdevice**. For more information, see [Dynamic Audio Subdevices](https://learn.microsoft.com/windows-hardware/drivers/audio/dynamic-audio-subdevices).

## See also

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[IPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iport)

[IUnregisterSubdevice::UnregisterSubdevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iunregistersubdevice-unregistersubdevice)

[IoRegisterDeviceInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregisterdeviceinterface)
# IUnregisterSubdevice::UnregisterSubdevice

## Description

The **UnregisterSubdevice** method deletes the registration of a subdevice that was previously registered by a call to [PcRegisterSubdevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcregistersubdevice).

## Parameters

### `DeviceObject` [in]

Pointer to the device object for the adapter device. This parameter must point to a system structure of type [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object).

### `Unknown` [in]

Pointer to the [IPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iport) interface of the port driver object that is bound to the subdevice.

## Return value

**UnregisterSubdevice** returns STATUS_SUCCESS if the call was successful. Otherwise, it returns an appropriate error code.

## Remarks

For more information, see [Dynamic Audio Subdevices](https://learn.microsoft.com/windows-hardware/drivers/audio/dynamic-audio-subdevices).

## See also

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[IPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iport)

[IUnregisterSubdevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iunregistersubdevice)

[PcRegisterSubdevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcregistersubdevice)
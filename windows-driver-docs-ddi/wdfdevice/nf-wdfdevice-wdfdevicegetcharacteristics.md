# WdfDeviceGetCharacteristics function

## Description

[Applies to KMDF only]

The **WdfDeviceGetCharacteristics** method returns device characteristics for a specified device.

## Parameters

### `Device` [in]

A handle to a framework device object.

## Return value

A bitwise OR of system-defined constants that represent device characteristics. For more information, see the **Characteristics** member of the [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure.

A bug check occurs if the driver supplies an invalid object handle.

## See also

[WdfDeviceInitSetCharacteristics](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetcharacteristics)

[WdfDeviceSetCharacteristics](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicesetcharacteristics)
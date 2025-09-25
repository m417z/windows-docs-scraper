# WdfDeviceInitSetCharacteristics function

## Description

[Applies to KMDF only]

The **WdfDeviceInitSetCharacteristics** method sets device characteristics for a specified device.

## Parameters

### `DeviceInit` [in]

A pointer to a [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure.

### `DeviceCharacteristics` [in]

A value that consists of ORed system-defined constants that represent device characteristics. For more information, see the **Characteristics** member of the [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure.

### `OrInValues` [in]

A Boolean value. If this value is **TRUE**, the *DeviceCharacteristics* value is ORed with existing device characteristics. If the value is **FALSE**, the *DeviceCharacteristics* value replaces existing device characteristics.

## Remarks

To set device characteristics, call the **WdfDeviceInitSetCharacteristics** method in your [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function before calling [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate). If your driver cannot determine a device's characteristics until after the *EvtDriverDeviceAdd* callback function returns, call [WdfDeviceSetCharacteristics](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicesetcharacteristics).

For more information about calling [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate), see [Creating a Framework Device Object](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-a-framework-device-object).

The framework always sets the FILE_DEVICE_SECURE_OPEN characteristic, so your driver does not have to set this characteristic.

Each call to **WdfDeviceInitSetCharacteristics** overwrites the settings of any previous call.

#### Examples

The following code example indicates that a device is a floppy disk.

```cpp
WdfDeviceInitSetCharacteristics(
                                DeviceInit,
                                FILE_FLOPPY_DISKETTE,
                                FALSE
                                );
```

## See also

[WdfDeviceSetCharacteristics](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicesetcharacteristics)
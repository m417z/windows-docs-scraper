# WdfDeviceSetCharacteristics function

## Description

[Applies to KMDF only]

The **WdfDeviceSetCharacteristics** method sets device characteristics for a specified device.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `DeviceCharacteristics` [in]

A value that consists of ORed system-defined constants that represent device characteristics. For more information, see the **Characteristics** member of the [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

You should set device characteristics by calling the [WdfDeviceInitSetCharacteristics](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetcharacteristics) method in your [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function before calling [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate). If your driver cannot determine a device's characteristics until after the *EvtDriverDeviceAdd* callback function returns, the driver typically should call **WdfDeviceSetCharacteristics** in its [EvtDevicePrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware) callback function.

Each call to **WdfDeviceSetCharacteristics** overwrites the settings of any previous call.

#### Examples

The following code example sets the FILE_REMOVABLE_MEDIA characteristic for a specified device.

```cpp
WdfDeviceSetCharacteristics(
                            Device,
                            FILE_REMOVABLE_MEDIA
                            );
```

## See also

[WdfDeviceGetCharacteristics](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicegetcharacteristics)

[WdfDeviceInitSetCharacteristics](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetcharacteristics)
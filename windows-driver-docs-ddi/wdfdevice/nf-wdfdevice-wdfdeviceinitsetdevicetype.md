# WdfDeviceInitSetDeviceType function

## Description

[Applies to KMDF only]

The **WdfDeviceInitSetDeviceType** method sets the device type for a specified device.

## Parameters

### `DeviceInit` [in]

A pointer to a [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure.

### `DeviceType` [in]

A FILE_DEVICE_XXXX value that identifies the device type. For more information about FILE_DEVICE_XXXX values, see [Specifying Device Types](https://learn.microsoft.com/windows-hardware/drivers/kernel/specifying-device-types).

## Remarks

If a driver calls **WdfDeviceInitSetDeviceType**, it must do so before it calls [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

For more information about calling [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate), see [Creating a Framework Device Object](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-a-framework-device-object).

The device type that a driver specifies determines the default priority boost value that the framework uses when the driver completes an I/O request. For more information about priority boost values, see [Specifying Priority Boosts When Completing I/O Requests](https://learn.microsoft.com/windows-hardware/drivers/wdf/specifying-priority-boosts-when-completing-i-o-requests).

If you are writing a UMDF driver, you must modify your driver's INF file or make registry changes to specify a device type. For more information about using the registry, see [Setting Device Object Registry Properties During Installation](https://learn.microsoft.com/windows-hardware/drivers/kernel/setting-device-object-registry-properties-during-installation).

#### Examples

The following code example indicates that a device is a serial device.

```cpp
WdfDeviceInitSetDeviceType(
                           DeviceInit,
                           FILE_DEVICE_SERIAL_PORT
                           );
```
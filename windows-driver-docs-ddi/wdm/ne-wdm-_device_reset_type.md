# _DEVICE_RESET_TYPE enumeration

## Description

The **DEVICE_RESET_TYPE** enumeration specifies the type of device reset that is being requested by a call to the [DeviceReset](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-device_reset_handler) routine of the GUID_DEVICE_RESET_INTERFACE_STANDARD interface.

For more information see [Working with the GUID_DEVICE_RESET_INTERFACE_STANDARD](https://learn.microsoft.com/windows-hardware/drivers/kernel/working-with-guid-device-reset-interface-standard).

## Constants

### `FunctionLevelDeviceReset`

A function-level device reset, which is restricted to a specific device.

### `PlatformLevelDeviceReset`

A platform-level device reset, which affects a specific device and all other devices that are connected to it via the same power rail or reset line.

## See also

[DEVICE_RESET_INTERFACE_STANDARD](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_reset_interface_standard)

[DeviceReset](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-device_reset_handler)

[Working with the GUID_DEVICE_RESET_INTERFACE_STANDARD](https://learn.microsoft.com/windows-hardware/drivers/kernel/working-with-guid-device-reset-interface-standard)
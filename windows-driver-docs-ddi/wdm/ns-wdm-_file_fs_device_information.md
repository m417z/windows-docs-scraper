# _FILE_FS_DEVICE_INFORMATION structure

## Description

The **FILE_FS_DEVICE_INFORMATION** structure provides file system device information about the type of device object associated with a file object.

## Members

### `DeviceType`

Set when a driver calls **IoCreateDevice** as appropriate for the type of underlying device. For more information, see [Specifying Device Types](https://learn.microsoft.com/windows-hardware/drivers/kernel/specifying-device-types).

### `Characteristics`

The device characteristics. For a description of relevant values, see [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object).

## See also

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)
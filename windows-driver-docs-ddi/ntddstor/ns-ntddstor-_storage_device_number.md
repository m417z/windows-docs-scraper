# _STORAGE_DEVICE_NUMBER structure

## Description

The STORAGE_DEVICE_NUMBER structure is used in conjunction with the [IOCTL_STORAGE_GET_DEVICE_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_get_device_number) request to retrieve the FILE_DEVICE_*XXX* device type, the device number, and, for a device that can be partitioned, the partition number assigned to a device by the driver when the device is started.

## Members

### `DeviceType`

Specifies one of the system-defined FILE_DEVICE_*XXX* constants indicating the type of device (such as FILE_DEVICE_DISK, FILE_DEVICE_KEYBOARD, and so forth) or a vendor-defined value for a new type of device. For more information, see [Specifying Device Types](https://learn.microsoft.com/windows-hardware/drivers/kernel/specifying-device-types).

### `DeviceNumber`

Indicates the number of this device. This value is set to 0xFFFFFFFF (-1) for the disks that represent the physical paths of an MPIO disk.

### `PartitionNumber`

Indicates the partition number of the device is returned in this member, if the device can be partitioned. Otherwise, -1 is returned.

## Remarks

The [IOCTL_STORAGE_GET_DEVICE_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_get_device_number) request is usually issued by a fault-tolerant disk driver.

The values in the STORAGE_DEVICE_NUMBER structure are guaranteed to remain unchanged until the system is rebooted. They are not guaranteed to be persistent across boots.

## See also

[IOCTL_STORAGE_GET_DEVICE_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_get_device_number)
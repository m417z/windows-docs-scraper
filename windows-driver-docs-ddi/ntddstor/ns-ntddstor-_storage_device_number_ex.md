# STORAGE_DEVICE_NUMBER_EX structure

## Description

The STORAGE_DEVICE_NUMBER_EX structure is used in conjunction with the [IOCTL_STORAGE_GET_DEVICE_NUMBER_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_get_device_number_ex) request to retrieve the FILE_DEVICE_*XXX* device type, the device number, device GUID, and, for a device that can be partitioned, the partition number assigned to a device by the driver when the device is started.

## Members

### `Version`

The version of this structure. Will be set to **sizeof**(STORAGE_DEVICE_NUMBER_EX).

### `Size`

Total size of this structure, including any additional data. Currently, this will always be set to **sizeof**(STORAGE_DEVICE_NUMBER_EX).

### `Flags`

Can be a combination of STORAGE_DEVICE_FLAGS_XXX flags that provide more information about the members of this structure. See **Remarks** for details.

### `DeviceType`

Specifies one of the system-defined FILE_DEVICE_*XXX* constants indicating the type of device (such as FILE_DEVICE_DISK) or a vendor-defined value for a new type of device. This IOCTL is only supported for disk devices. For more information, see [Specifying Device Types](https://learn.microsoft.com/windows-hardware/drivers/kernel/specifying-device-types).

### `DeviceNumber`

Indicates the number of this device. This value is set to 0xFFFFFFFF (-1) for the disks that represent the physical paths of an MPIO disk.

### `DeviceGuid`

A globally-unique identification number for this device. A GUID of {0} indicates that a GUID could not be generated. The GUID is based on hardware information that doesn't change with firmware updates; for instance, the serial number can be used to form the GUID, but not the firmware revision.

### `PartitionNumber`

Indicates the partition number of the device is returned in this member, if the device can be partitioned. Otherwise, -1 is returned.

## Remarks

The [IOCTL_STORAGE_GET_DEVICE_NUMBER_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_get_device_number_ex) request is usually issued by a fault-tolerant disk driver.

In general, if a device exposes a globally unique identifier, the storage driver will use that identifier to form the GUID. Otherwise, the storage driver will combine the device's vendor ID, product ID and serial number to create the GUID.

If a storage driver detects two devices with the same hardware information (which is an indication of a problem with the device), the driver will generate a random GUID for one of the two devices. When handling IOCTL_STORAGE_GET_DEVICE_NUMBER_EX for the device with the random GUID, the driver will add STORAGE_DEVICE_FLAGS_RANDOM_DEVICEGUID_REASON_CONFLICT to the **Flags** member of this structure.

If a storage device does not provide any identifying information, the driver will generate a random GUID and add STORAGE_DEVICE_FLAGS_RANDOM_DEVICEGUID_REASON_NOHWID to the **Flags** member of this structure.

If the STORAGE_DEVICE_FLAGS_PAGE_83_DEVICEGUID flag is set, the deviceguid was created from the SCSI page83 data. If this flag is not set, this implies it was created from the serial number or was randomly generated.

The values in the STORAGE_DEVICE_NUMBER_EX structure are guaranteed to remain unchanged until the system is rebooted. They are not guaranteed to be persistent across boots. A device GUID remains the same across reboots. A random GUID is not persisted and will not be the same after a reboot.

## See also

[IOCTL_STORAGE_GET_DEVICE_NUMBER_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_get_device_number_ex)
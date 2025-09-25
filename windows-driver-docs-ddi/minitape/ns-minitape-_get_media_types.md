# _GET_MEDIA_TYPES structure (minitape.h)

## Description

The GET_MEDIA_TYPES structure is used in conjunction with the [IOCTL_STORAGE_GET_MEDIA_TYPES_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_get_media_types_ex) request to retrieve information about the types of media supported by a device.

## Members

### `DeviceType`

Specifies one of the system-defined FILE_DEVICE_*XXX* constants indicating the type of device (such as FILE_DEVICE_DISK, FILE_DEVICE_KEYBOARD, and so forth) or a vendor-defined value for a new type of device. For more information, see [Specifying Device Types](https://learn.microsoft.com/windows-hardware/drivers/kernel/specifying-device-types).

### `MediaInfoCount`

Contains the number of [DEVICE_MEDIA_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_media_info) structures in the array starting at **MediaInfo**.

### `MediaInfo`

Contains an array whose first element holds the first DEVICE_MEDIA_INFO structure in the array.

## Remarks

A storage class driver must handle the [IOCTL_STORAGE_GET_MEDIA_TYPES_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_get_media_types_ex) request to support any device that the Removable Storage Manager (RSM) accesses, whether the device is a stand-alone device or a data transfer element (drive) in a media library or changer.

## See also

[DEVICE_MEDIA_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_media_info)

[IOCTL_STORAGE_GET_MEDIA_TYPES_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_get_media_types_ex)
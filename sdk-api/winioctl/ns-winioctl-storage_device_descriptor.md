# STORAGE_DEVICE_DESCRIPTOR structure

## Description

Used in conjunction with the
[IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_query_property) control code
to retrieve the storage device descriptor data for a device.

## Members

### `Version`

Contains the size of this structure, in bytes. The value of this member will change as members are added to
the structure.

### `Size`

Specifies the total size of the descriptor, in bytes, which may include vendor ID, product ID, product
revision, device serial number strings and bus-specific data which are appended to the structure.

### `DeviceType`

Specifies the device type as defined by the Small Computer Systems Interface (SCSI) specification.

### `DeviceTypeModifier`

Specifies the device type modifier, if any, as defined by the SCSI specification. If no device type
modifier exists, this member is zero.

### `RemovableMedia`

Indicates when **TRUE** that the device's media (if any) is removable. If the device
has no media, this member should be ignored. When **FALSE** the device's media is not
removable.

### `CommandQueueing`

Indicates when **TRUE** that the device supports multiple outstanding commands (SCSI
tagged queuing or equivalent). When **FALSE**, the device does not support SCSI-tagged
queuing or the equivalent.

### `VendorIdOffset`

Specifies the byte offset from the beginning of the structure to a null-terminated ASCII string that
contains the device's vendor ID. If the device has no vendor ID, this member is zero.

### `ProductIdOffset`

Specifies the byte offset from the beginning of the structure to a null-terminated ASCII string that
contains the device's product ID. If the device has no product ID, this member is zero.

### `ProductRevisionOffset`

Specifies the byte offset from the beginning of the structure to a null-terminated ASCII string that
contains the device's product revision string. If the device has no product revision string, this member is
zero.

### `SerialNumberOffset`

Specifies the byte offset from the beginning of the structure to a null-terminated ASCII string that
contains the device's serial number. If the device has no serial number, this member is zero.

### `BusType`

Specifies an enumerator value of type
[STORAGE_BUS_TYPE](https://learn.microsoft.com/windows/desktop/api/winioctl/ne-winioctl-storage_bus_type) that indicates the type of bus to
which the device is connected. This should be used to interpret the raw device properties at the end of this
structure (if any).

### `RawPropertiesLength`

Indicates the number of bytes of bus-specific data that have been appended to this descriptor.

### `RawDeviceProperties`

Contains an array of length one that serves as a place holder for the first byte of the bus specific
property data.

## Remarks

An application can determine the required buffer size by issuing a
[IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_query_property) control code
passing a [STORAGE_DESCRIPTOR_HEADER](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-storage_descriptor_header) structure
for the output buffer, and then using the returned **Size** member of the
**STORAGE_DESCRIPTOR_HEADER** structure to allocate
a buffer of the proper size.

## See also

[Disk Management Structures](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-structures)

[IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_query_property)

[STORAGE_ADAPTER_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-storage_adapter_descriptor)

[STORAGE_DESCRIPTOR_HEADER](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-storage_descriptor_header)

[STORAGE_DEVICE_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-storage_device_descriptor)

[STORAGE_DEVICE_ID_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-storage_device_id_descriptor)
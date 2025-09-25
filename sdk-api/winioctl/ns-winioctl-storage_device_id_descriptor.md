# STORAGE_DEVICE_ID_DESCRIPTOR structure

## Description

Used with the
[IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_query_property) control code
request to retrieve the device ID descriptor data for a device.

## Members

### `Version`

Contains the size of this structure, in bytes. The value of this member will change as members are added to
the structure.

### `Size`

Specifies the total size of the data returned, in bytes. This may include data that follows this
structure.

### `NumberOfIdentifiers`

Contains the number of identifiers reported by the device in the **Identifiers** array.

### `Identifiers`

Contains a variable-length array of identification descriptors.

## Remarks

The device ID descriptor consists of an array of device IDs taken from the SCSI-3 vital product data (VPD)
page 0x83 that was retrieved during discovery.

## See also

[Disk Management Structures](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-structures)

[IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_query_property)

[STORAGE_ADAPTER_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-storage_adapter_descriptor)

[STORAGE_DESCRIPTOR_HEADER](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-storage_descriptor_header)

[STORAGE_DEVICE_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-storage_device_descriptor)
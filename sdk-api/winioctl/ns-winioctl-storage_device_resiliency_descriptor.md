# STORAGE_DEVICE_RESILIENCY_DESCRIPTOR structure

## Description

Reserved for system use.

## Members

### `Version`

Contains the size of this structure, in bytes. The value of this member will change as members are added to
the structure. Set to
`sizeof(STORAGE_DEVICE_RESILIENCY_DESCRIPTOR)`.

### `Size`

Specifies the total size of the data returned, in bytes. This may include data that follows this
structure.

### `NameOffset`

Byte offset to the null-terminated ASCII string containing the resiliency properties Name. For devices with
no Name property, this will be zero.

### `NumberOfLogicalCopies`

Number of logical copies of data that are available.

### `NumberOfPhysicalCopies`

Number of complete copies of data that are stored.

### `PhysicalDiskRedundancy`

Number of disks that can fail without leading to data loss.

### `NumberOfColumns`

Number of columns in the storage device.

### `Interleave`

Size of a stripe unit of the storage device, in bytes. This is also referred to as the stripe width or
interleave of the storage device.

## See also

[Disk Management Structures](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-structures)

[IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_query_property)

[STORAGE_PROPERTY_QUERY](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-storage_property_query)
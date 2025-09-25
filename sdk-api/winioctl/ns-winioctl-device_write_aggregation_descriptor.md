# DEVICE_WRITE_AGGREGATION_DESCRIPTOR structure

## Description

Reserved for system use.

## Members

### `Version`

Contains the size, in bytes, of this structure. The value of this member will change as members are added
to the structure.

### `Size`

Specifies the total size of the descriptor, in bytes.

### `BenefitsFromWriteAggregation`

**TRUE** if the device benefits from write aggregation.

## See also

[Disk Management Structures](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-structures)

[IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_query_property)
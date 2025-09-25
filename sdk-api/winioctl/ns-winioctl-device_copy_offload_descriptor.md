# DEVICE_COPY_OFFLOAD_DESCRIPTOR structure

## Description

The
**DEVICE_COPY_OFFLOAD_DESCRIPTOR**
structure is one of the query result structures returned from an
[IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_query_property) request. This
structure contains the copy offload capabilities for a storage device.

## Members

### `Version`

Contains the size of this structure, in bytes. The value of this member will change as members are added to
the structure.

### `Size`

Specifies the total size of the data returned, in bytes. This may include data that follows this
structure.

### `MaximumTokenLifetime`

The maximum lifetime of the token, in seconds.

### `DefaultTokenLifetime`

The default lifetime of the token, in seconds.

### `MaximumTransferSize`

The maximum transfer size, in bytes.

### `OptimalTransferCount`

The optimal transfer size, in bytes.

### `MaximumDataDescriptors`

The maximum number of data descriptors.

### `MaximumTransferLengthPerDescriptor`

The maximum transfer length, in blocks, per descriptor.

### `OptimalTransferLengthPerDescriptor`

The optimal transfer length per descriptor.

### `OptimalTransferLengthGranularity`

The granularity of the optimal transfer length, in blocks. Transfer lengths that are not an even multiple
of this length may be delayed.

### `Reserved`

Reserved.

## Remarks

This structure is returned from a
[IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_query_property) request when the
**PropertyId** member of
[STORAGE_PROPERTY_QUERY](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-storage_property_query) is set to
**StorageDeviceCopyOffloadProperty**.

## See also

[Disk Management Structures](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-structures)

[IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_query_property)

[STORAGE_PROPERTY_QUERY](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-storage_property_query)
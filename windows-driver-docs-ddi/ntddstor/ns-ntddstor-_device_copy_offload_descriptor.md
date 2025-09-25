# _DEVICE_COPY_OFFLOAD_DESCRIPTOR structure

## Description

Used in conjunction with the
[IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property) request to describe the copy offload capabilities of a storage device.

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

The optimal transfer length, in blocks, per descriptor.

### `OptimalTransferLengthGranularity`

The granularity of the optimal transfer length, in blocks. Transfer lengths that are not an even multiple
of this length may be delayed.

### `Reserved`

Reserved for future use.

## See also

[IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property)
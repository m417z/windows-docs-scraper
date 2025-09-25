# STORAGE_PROPERTY_QUERY structure

## Description

Indicates the properties of a storage device or adapter to retrieve as the input buffer passed to the
[IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_query_property) control code.

## Members

### `PropertyId`

Indicates whether the caller is requesting a device descriptor, an adapter descriptor, a write cache
property, a device unique ID (DUID), or the device identifiers provided in the device's SCSI vital product data
(VPD) page. For a list of the property IDs that can be assigned to this member, see
[STORAGE_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/winioctl/ne-winioctl-storage_property_id).

### `QueryType`

Contains flags indicating the type of query to be performed as enumerated by the
[STORAGE_QUERY_TYPE](https://learn.microsoft.com/windows/desktop/api/winioctl/ne-winioctl-storage_query_type) enumeration.

| Value | Meaning |
| --- | --- |
| **PropertyStandardQuery**<br><br>0 | Instructs the port driver to report a device descriptor, an adapter descriptor or a unique hardware device ID (DUID). |
| **PropertyExistsQuery**<br><br>1 | Instructs the port driver to report whether the descriptor is supported. |

### `AdditionalParameters`

Contains an array of bytes that can be used to retrieve additional parameters for specific queries.

## Remarks

The optional output buffer returned through the *lpOutBuffer* parameter of the
[IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_query_property) control code can
be one of several structures depending on the value of the **PropertyId** member. If the
**QueryType** member is set to **PropertyExistsQuery**, then no
structure is returned.

## See also

[Disk Management Structures](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-structures)

[IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_query_property)

[STORAGE_ADAPTER_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-storage_adapter_descriptor)

[STORAGE_DESCRIPTOR_HEADER](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-storage_descriptor_header)

[STORAGE_DEVICE_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-storage_device_descriptor)

[STORAGE_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/winioctl/ne-winioctl-storage_property_id)

[STORAGE_QUERY_TYPE](https://learn.microsoft.com/windows/desktop/api/winioctl/ne-winioctl-storage_query_type)
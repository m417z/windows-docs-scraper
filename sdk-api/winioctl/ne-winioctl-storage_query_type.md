# STORAGE_QUERY_TYPE enumeration

## Description

Used by the [STORAGE_PROPERTY_QUERY](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_property_query) structure passed to the [IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_storage_query_property) control code to indicate what information is returned about a property of a storage device or adapter.

## Constants

### `PropertyStandardQuery:0`

Instructs the driver to return an appropriate descriptor.

### `PropertyExistsQuery`

Instructs the driver to report whether the descriptor is supported.

### `PropertyMaskQuery`

Not currently supported. Do not use.

### `PropertyQueryMaxDefined`

Specifies the upper limit of the list of query types. This is used to validate the query type.

## See also

* [Disk Management Enumeration Types](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-enumeration-types)
* [IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_storage_query_property)
* [STORAGE_PROPERTY_ID](https://learn.microsoft.com/windows/win32/api/winioctl/ne-winioctl-storage_property_id)
* [STORAGE_PROPERTY_QUERY](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_property_query)
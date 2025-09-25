# _STORAGE_QUERY_TYPE enumeration

## Description

The STORAGE_QUERY_TYPE enumeration is used in conjunction with the [IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property) request to retrieve the properties of a storage device or adapter.

## Constants

### `PropertyStandardQuery`

Instructs the port driver to report a device descriptor, an adapter descriptor or a unique hardware device ID (DUID).

### `PropertyExistsQuery`

Instructs the port driver to report whether the descriptor is supported.

### `PropertyMaskQuery`

Not currently supported. Do not use.

### `PropertyQueryMaxDefined`

Specifies the upper limit of the list of query types. This is used to validate the query type.

## Remarks

Caller specifies the type of query by choosing one of the enumeration values.

Caller defines the exact nature of an [IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property) request by specifying the query type together with the property ID. See [STORAGE_PROPERTY_QUERY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_property_query) for an explanation of how these two values are combined to define the query.

## See also

[IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property)

[STORAGE_PROPERTY_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-storage_property_id)

[STORAGE_PROPERTY_QUERY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_property_query)
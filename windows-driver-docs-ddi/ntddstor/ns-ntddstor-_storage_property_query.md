# STORAGE_PROPERTY_QUERY structure

## Description

This structure is used in conjunction with [**IOCTL_STORAGE_QUERY_PROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property) to retrieve the properties of a storage device or adapter.

## Members

### `PropertyId`

Indicates whether the caller is requesting a device descriptor, an adapter descriptor, a write cache property, a device unique ID (DUID), or the device identifiers provided in the device's SCSI vital product data (VPD) page. For a list of the property IDs that can be assigned to this member, see [**STORAGE_PROPERTY_ID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-storage_property_id).

### `QueryType`

Contains flags indicating the type of query to be performed. For a list of the various query types that can be assigned to this member, see [**STORAGE_QUERY_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-_storage_query_type).

### `AdditionalParameters`

Contains an array of bytes with additional input parameters that are needed for the **PropertyId** query. Not all **PropertyId** values require additional input parameters.

## Remarks

The results of the query can be one of several structures depending on the value of the **PropertyId** member. These values are enumerated by the [**STORAGE_PROPERTY_ID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-storage_property_id) enumeration.

If the **QueryType** member is set to **PropertyExistsQuery**, then no structure is returned. For more info, see [**STORAGE_QUERY_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-_storage_query_type).

## See also

[**IOCTL_STORAGE_QUERY_PROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property)

[**STORAGE_ADAPTER_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_adapter_descriptor)

[**STORAGE_DESCRIPTOR_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_descriptor_header)

[**STORAGE_DEVICE_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_device_descriptor)

[**STORAGE_PROPERTY_ID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-storage_property_id)

[**STORAGE_QUERY_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-_storage_query_type)
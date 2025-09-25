# _STORAGE_DESCRIPTOR_HEADER structure

## Description

The STORAGE_DESCRIPTOR_HEADER structure is used in conjunction with the [IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property) request to retrieve the properties of a storage device or adapter.

## Members

### `Version`

Contains the version of the data reported.

### `Size`

Indicates the quantity of data reported, in bytes.

## Remarks

The data retrieved by IOCTL_STORAGE_QUERY_PROPERTY is reported in the buffer immediately following this structure.

The IOCTL_STORAGE_QUERY_PROPERTY request reports one of three types of properties: a device descriptor, an adapter descriptor, or a set of device IDs taken from the device's SCSI vital product data pages. Device descriptors are reported in a structure of type [STORAGE_DEVICE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_device_descriptor). Adapter descriptors are reported in a structure of type [STORAGE_ADAPTER_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_adapter_descriptor). Vital product page device IDs are reported in a structure of type [STORAGE_DEVICE_ID_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_device_id_descriptor).

## See also

[IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property)

[STORAGE_PROPERTY_QUERY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_property_query)
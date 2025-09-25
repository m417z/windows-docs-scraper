# _STORAGE_DEVICE_ID_DESCRIPTOR structure

## Description

The **STORAGE_DEVICE_ID_DESCRIPTOR** structure is used in conjunction with the [IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property) request to retrieve the device ID descriptor data for a device.

## Members

### `Version`

Indicates the version of the descriptor.

### `Size`

Indicates the size in bytes of the descriptor.

### `NumberOfIdentifiers`

Contains the number of identifiers reported by the device in the **Identifiers** array.

### `Identifiers`

Contains a variable-length array of identification descriptors.

## Remarks

The device descriptor consists of an array of device IDs taken from the SCSI-3 vital product page data that was retrieved during discovery.

## See also

[IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property)

[STORAGE_ADAPTER_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_adapter_descriptor)

[STORAGE_DESCRIPTOR_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_descriptor_header)

[STORAGE_DEVICE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_device_descriptor)
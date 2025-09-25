# STORAGE_PROTOCOL_DATA_DESCRIPTOR_EXT structure

## Description

This structure is used in conjunction with [IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property) and [IOCTL_STORAGE_SET_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_set_property) to respectively return and set protocol-specific data from a storage device or adapter.

## Members

### `Version`

Version of this structure. Set this to be **sizeof**(STORAGE_PROTOCOL_DATA_DESCRIPTOR_EXT).

### `Size`

Size, in bytes, of the buffer containing the descriptor, including the space for all protocol data. Must be >= **sizeof**(STORAGE_PROTOCOL_DATA_DESCRIPTOR_EXT).

### `ProtocolSpecificData`

[STORAGE_PROTOCOL_SPECIFIC_DATA_EXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-storage_protocol_specific_data_ext) structure that contains the protocol-specific data.

## Remarks

## See also

[IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property)

[IOCTL_STORAGE_SET_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_set_property)

[STORAGE_PROTOCOL_SPECIFIC_DATA_EXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-storage_protocol_specific_data_ext)
# STORAGE_PROTOCOL_UFS_DATA_TYPE enumeration

## Description

The UFS (Universal Flash Storage) data type. Describes the type of UFS-specific data that is to be queried during an [**IOCTL_STORAGE_QUERY_PROPERTY*](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property) request.

## Constants

### `UfsDataTypeUnknown:0`

Unknown data type.

### `UfsDataTypeQueryDescriptor`

Query the UFS descriptor data. Retrieved by the QUERY UPIU command.

### `UfsDataTypeQueryAttribute`

Query the UFS attributes. Retrieved by the QUERY UPIU command.

### `UfsDataTypeQueryFlag`

Query the UFS flag. Retrieved by the QUERY UPIU command.

### `UfsDataTypeQueryDmeAttribute`

Query the UFS device management entity (DME) attribute. Retrieved by the QUERY UPIU command.

### `UfsDataTypeQueryDmePeerAttribute`

Query the UFS DME peer attribute. Retrieved by the QUERY UPIU command.

### `UfsDataTypeMax`

Max size of data type.

## See also

[**STORAGE_PROTOCOL_DATA_DESCRIPTOR*](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_protocol_data_descriptor)
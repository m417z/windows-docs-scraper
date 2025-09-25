# STORAGE_PROTOCOL_SPECIFIC_DATA_EXT structure

## Description

The STORAGE_PROTOCOL_SPECIFIC_DATA_EXT structure describes the protocol-specific device data for [IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property) and [IOCTL_STORAGE_SET_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_set_property) requests.

## Members

### `ProtocolType`

The protocol type. Values for this member are defined in the [STORAGE_PROTOCOL_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-_storage_protocol_type) enumeration.

### `DataType`

The protocol data type. Data types are defined in the [STORAGE_PROTOCOL_NVME_DATA_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-_storage_protocol_nvme_data_type) and [STORAGE_PROTOCOL_ATA_DATA_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-_storage_protocol_ata_data_type) enumerations.

### `ProtocolDataValue`

The protocol data value.

### `ProtocolDataSubValue`

Sub-value of the protocol data value.

### `ProtocolDataOffset`

The offset of the data buffer from the beginning of this structure. The typical value is **sizeof**(STORAGE_PROTOCOL_SPECIFIC_DATA_EXT).

### `ProtocolDataLength`

The length of the protocol data. **ProtocolDataLength** must be >= 512 bytes.

### `FixedProtocolReturnData`

The returned data.

### `ProtocolDataSubValue2`

First additional data sub-value.

### `ProtocolDataSubValue3`

Second additional data sub-value.

### `ProtocolDataSubValue4`

Third additional data sub-value.

### `ProtocolDataSubValue5`

Fourth additional data sub-value.

### `ProtocolDataSubValue6`

Fifth additional data sub-value.

### `Reserved[4]`

Reserved for future use; do not use.

## See also

- [IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property)
- [IOCTL_STORAGE_SET_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_set_property)
- [STORAGE_PROTOCOL_SPECIFIC_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_protocol_specific_data)
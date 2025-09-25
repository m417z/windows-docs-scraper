## Description

**STORAGE_PROTOCOL_DATA_SUBVALUE_GET_LOG_PAGE** is used to provide additional information to be specified when getting an NVMe log page.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.RetainAsynEvent`

Indicates whether to retain (1) or clear (0) an asynchronous event.

### `DUMMYSTRUCTNAME.LogSpecificField`

Used for certain log page queries. See the log page-related sections of the NVMe specification for details.

### `DUMMYSTRUCTNAME.Reserved0`

Reserved.

### `DUMMYSTRUCTNAME.UUIDIndex`

Used internally to iterate through an array of UUID values.

### `DUMMYSTRUCTNAME.Reserved`

Reserved.

### `AsUlong`

Can be used to reference the entire bit field.

## Remarks

**STORAGE_PROTOCOL_DATA_SUBVALUE_GET_LOG_PAGE** is the value of **ProtocolDataRequestSubValue4** of the **[STORAGE_PROTOCOL_SPECIFIC_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_protocol_specific_data)** structure when **[STORAGE_PROTOCOL_NVME_DATA_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-_storage_protocol_nvme_data_type)** is **NVMeDataTypeLogPage**.

## See also

- **[IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property)**
- **[STORAGE_PROTOCOL_NVME_DATA_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-_storage_protocol_nvme_data_type)**
- **[STORAGE_PROTOCOL_SPECIFIC_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_protocol_specific_data)**
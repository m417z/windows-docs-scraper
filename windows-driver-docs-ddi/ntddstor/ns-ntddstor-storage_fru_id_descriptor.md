## Description

**STORAGE_FRU_ID_DESCRIPTOR** is the structure used when a caller sends [**IOCTL_STORAGE_QUERY_PROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property) to query for the ID of a fault replacement unit (FRU).

## Members

### `Version`

Version of this structure. Set to ```sizeof(STORAGE_FRU_ID_DESCRIPTOR)```.

### `Size`

Size of this structure, in bytes. Must be >= ```sizeof(STORAGE_FRU_ID_DESCRIPTOR)```.

### `IdentifierSize`

Size of the array in **Identifier**, in bytes.

### `Identifier`

Array in which to write the FRU's identifier. The size of this array is **IdentifierSize** bytes.

## Remarks

**STORAGE_FRU_ID_DESCRIPTOR** is used as the output buffer in which to return the result when a caller sends [**IOCTL_STORAGE_QUERY_PROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property) with a [**STORAGE_PROPERTY_ID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-storage_property_id) value of **StorageFruIdProperty**.

## See also

[**IOCTL_STORAGE_QUERY_PROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property)

[**STORAGE_PROPERTY_ID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-storage_property_id)

[**STORAGE_PROPERTY_QUERY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_property_query)

[**STORAGE_QUERY_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-_storage_query_type)
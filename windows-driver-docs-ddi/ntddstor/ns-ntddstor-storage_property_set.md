# STORAGE_PROPERTY_SET structure

## Description

The STORAGE_PROPERTY_SET structure describes the details of the property set associated with [IOCTL_STORAGE_SET_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_set_property).

## Members

### `PropertyId`

A [STORAGE_PROPERTY_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-storage_property_id) enum value that specifies which property is being set. Currently, should be set to **StorageAdapterProtocolSpecificProperty**.

### `SetType`

A [STORAGE_SET_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-storage_set_type) enum value that describes the type of set operation being performed.

### `AdditionalParameters`

Space for additional parameters if necessary, depending on **PropertyId**.

## Remarks

## See also

[IOCTL_STORAGE_SET_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_set_property)

[STORAGE_PROPERTY_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-storage_property_id)

[STORAGE_SET_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-storage_set_type)
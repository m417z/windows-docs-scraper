## Description

**STORAGE_DEVICE_SELF_ENCRYPTION_PROPERTY** is the structure used when a caller sends [**IOCTL_STORAGE_QUERY_PROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property) to query whether a device supports self encryption.

## Members

### `Version`

Version of this structure. Set to ```sizeof(STORAGE_DEVICE_SELF_ENCRYPTION_PROPERTY)```.

### `Size`

Size of this structure, in bytes. Must be >= ```sizeof(STORAGE_DEVICE_SELF_ENCRYPTION_PROPERTY)```.

### `SupportsSelfEncryption`

Boolean value. This field is TRUE if the device supports self-encryption; otherwise it is FALSE.

## Remarks

**STORAGE_DEVICE_SELF_ENCRYPTION_PROPERTY** is used as the output buffer in which to return the result when a caller sends [**IOCTL_STORAGE_QUERY_PROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property) with a [**STORAGE_PROPERTY_ID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-storage_property_id) value of **StorageDeviceSelfEncryptionProperty**.

## See also

[**IOCTL_STORAGE_QUERY_PROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property)

[**STORAGE_PROPERTY_ID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-storage_property_id)

[**STORAGE_PROPERTY_QUERY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_property_query)

[**STORAGE_QUERY_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-_storage_query_type)
## Description

The STORAGE_DEVICE_LED_STATE_DESCRIPTOR structure describes the LED state of a device.

## Members

### `Version`

Version of this structure. Set to ```sizeof(STORAGE_DEVICE_LED_STATE_DESCRIPTOR)```.

### `Size`

Size of this structure, in bytes. Must be >= ```sizeof(STORAGE_DEVICE_LED_STATE_DESCRIPTOR)```.

### `State`

Opaque structure that contains the unit's LED state.

## Remarks

The unit's LED state is returned in a **STORAGE_DEVICE_LED_STATE_DESCRIPTOR** structure during an [**IOCTL_STORAGE_QUERY_PROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property) request with a **PropertyId** of **StorageDeviceLedStateProperty**.

## See also

[**IOCTL_STORAGE_QUERY_PROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property)

[**STORAGE_PROPERTY_ID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-storage_property_id)

[**STORAGE_PROPERTY_QUERY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_property_query)
# _STATE_LOCATION_TYPE enumeration

## Description

Defines values for persisted state locations for device and driver files. This enumeration is used by [**RtlGetPersistedStateLocation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlgetpersistedstatelocation).

## Constants

### `LocationTypeRegistry`

The device and driver files are stored in the registry.

### `LocationTypeFileSystem`

The device and driver files are stored in the file system.

### `LocationTypeMaximum`

Reserved.

## Remarks

## See also

[**RtlGetPersistedStateLocation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlgetpersistedstatelocation)
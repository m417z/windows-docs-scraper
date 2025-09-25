# _STORAGE_DEVICE_IO_CAPABILITY_DESCRIPTOR structure

## Description

The output buffer for the StorageDeviceIoCapabilityProperty as defined in [STORAGE_PROPERTY_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-storage_property_id).

## Members

### `Version`

The version of this structure. The Size serves as the version.

### `Size`

The size of this structure.

### `LunMaxIoCount`

The logical unit number (LUN) max outstanding I/O count.

### `AdapterMaxIoCount`

The adapter max outstanding I/O count.
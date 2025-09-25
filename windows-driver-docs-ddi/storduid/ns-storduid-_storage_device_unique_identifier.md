# _STORAGE_DEVICE_UNIQUE_IDENTIFIER structure

## Description

The STORAGE_DEVICE_UNIQUE_IDENTIFIER structure defines a device unique identifier (DUID).

## Members

### `Version`

The version of the DUID.

### `Size`

The size, in bytes, of the identifier header and the identifiers (IDs) that follow the header.

### `StorageDeviceIdOffset`

The offset, in bytes, from the beginning of the header to the device ID descriptor ([STORAGE_DEVICE_ID_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_device_id_descriptor)). The device ID descriptor contains the IDs that are extracted from page 0x83 of the device's vital product data (VPD).

### `StorageDeviceOffset`

The offset, in bytes, from the beginning of the header to the device descriptor ([STORAGE_DEVICE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_device_descriptor)). The device descriptor contains IDs that are extracted from non-VPD inquiry data.

### `DriveLayoutSignatureOffset`

The offset, in bytes, to the drive layout signature ([STORAGE_DEVICE_LAYOUT_SIGNATURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/storduid/ns-storduid-_storage_device_layout_signature)).

## See also

[STORAGE_DEVICE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_device_descriptor)

[STORAGE_DEVICE_ID_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_device_id_descriptor)
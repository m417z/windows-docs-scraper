# _STORAGE_DEVICE_LAYOUT_SIGNATURE structure

## Description

The STORAGE_DEVICE_LAYOUT_SIGNATURE structure defines a device layout structure.

## Members

### `Version`

The version of the DUID.

### `Size`

The size, in bytes, of this STORAGE_DEVICE_LAYOUT_SIGNATURE structure.

### `Mbr`

A Boolean value that indicates whether the partition table of the disk is formatted with a master boot record (MBR). If **TRUE**, the partition table of the disk is formatted with a master boot record (MBR). If **FALSE**, the disk has a GUID partition table (GPT).

### `DeviceSpecific`

### `DeviceSpecific.MbrSignature`

The signature value, which uniquely identifies the disk.

### `DeviceSpecific.GptDiskId`

The GUID that uniquely identifies the disk.

## Remarks

The device layout signature contributes to the definition of a device unique identifier (DUID). For more information about DUIDs, see the description of the [STORAGE_DEVICE_UNIQUE_IDENTIFIER](https://learn.microsoft.com/windows-hardware/drivers/ddi/storduid/ns-storduid-_storage_device_unique_identifier) structure.

## See also

[STORAGE_DEVICE_UNIQUE_IDENTIFIER](https://learn.microsoft.com/windows-hardware/drivers/ddi/storduid/ns-storduid-_storage_device_unique_identifier)
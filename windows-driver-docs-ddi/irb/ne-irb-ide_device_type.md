# IDE_DEVICE_TYPE enumeration

## Description

The IDE_DEVICE_TYPE enumeration type indicates the device type.

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Constants

### `DeviceUnknown`

Indicates that the device does not communicate by means of a known protocol.

### `DeviceIsAta`

Indicates an ATA device.

### `DeviceIsAtapi`

Indicates an ATAPI device.

### `DeviceNotExist`

Indicates that the device does not exist.
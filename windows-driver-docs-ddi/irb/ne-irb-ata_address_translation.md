# ATA_ADDRESS_TRANSLATION enumeration

## Description

The ATA_ADDRESS_TRANSLATION enumeration type indicates the type of address translation used during data transfers.

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Constants

### `UnknownMode`

### `ChsMode`

Indicates that sectors are to be addressed using cylinder/head/sector (CHS) values.

### `LbaMode`

Indicates that sectors are to be addressed using logical block addressing (LBA) values.

### `Lba48BitMode`

Indicates support for 48-bit LBAs.
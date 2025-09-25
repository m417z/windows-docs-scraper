# _IDE_LBA_RANGE structure

## Description

The IDE_LBA_RANGE structure is used by the port driver to provide the miniport driver with a range of logical blocks.

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Members

### `StartSector`

Contains the starting sector of the LBA range.

### `SectorCount`

Contains the sector count of the LBA range.
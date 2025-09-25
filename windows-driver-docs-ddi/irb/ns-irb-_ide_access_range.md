# _IDE_ACCESS_RANGE structure

## Description

The IDE_ACCESS_RANGE structure contains the address ranges allocated for an IDE controller.

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Members

### `RangeStart`

Contains the logical starting address of the address range.

### `PhysicalRangeStart`

Contains the physical starting address of the address range.

### `RangeLength`

Contains the size, in bytes, of the range.

### `InMemory`

Flag that indicates if this is a memory mapped resource. If cleared, this is an I/O port resource.

### `Bar`

The number of the PCI Base Address Range that this resource was found in.
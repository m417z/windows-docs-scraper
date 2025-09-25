# _IDE_MINIPORT_RESOURCES structure

## Description

The IDE_MINIPORT_RESOURCES structure is used by the port driver to provide the miniport driver with resources.

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Members

### `NumberOfAccessRanges`

Contains the number of access ranges pointed to by **IdeAccessRange**. Each is a range either of memory addresses or I/O port addresses.

### `IdeAccessRange`

Pointer to the first address range in a series of contiguous address ranges defined by a structure of type [IDE_ACCESS_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/ns-irb-_ide_access_range). The value in the **NumberOfAccessRanges** member indicates how many address ranges are provided. The port driver populates each **IDE_ACCESS_RANGE** structure with the address ranges allocated for the controller.

## Remarks

The port driver passes this structure to the miniport driver's [IdeHwControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nc-irb-ide_hw_control) routine.

## See also

[IDE_ACCESS_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/ns-irb-_ide_access_range)

[IdeHwControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nc-irb-ide_hw_control)
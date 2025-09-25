# AtaPortGetPhysicalAddress function

## Description

The **AtaPortGetPhysicalAddress** routine converts the virtual address range to the physical address range.

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `ChannelExtension` [in]

A pointer to the channel extension.

### `Irb` [in, optional]

A pointer to a structure of type [IDE_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/ns-irb-_ide_request_block) that defines the IDE request block (IRB) for which the address range is converted.

### `VirtualAddress` [in, optional]

A pointer to the base virtual address to convert.

### `Length` [out, optional]

Returns the number of mapped bytes starting at the returned physical address.

## Return value

**AtaPortGetPhysicalAddress** returns the corresponding physical address for the virtual address. If the virtual address cannot be converted, it returns **NULL**.

## See also

[IDE_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/ns-irb-_ide_request_block)
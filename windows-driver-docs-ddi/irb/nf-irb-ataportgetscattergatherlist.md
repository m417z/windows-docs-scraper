# AtaPortGetScatterGatherList function

## Description

The **AtaPortGetScatterGatherList** routine retrieves the scatter/gather list that is associated with this request.

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `ChannelExtension` [in]

A pointer to the channel extension.

### `Irb` [in]

A pointer to a structure of type [IDE_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/ns-irb-_ide_request_block) that defines the IDE request block (IRB) for which a scatter/gather list is constructed.

## Return value

If the IRB_FLAGS_USE_DMA flag is set in the **IrbFlags** member of IRB, the **AtaPortGetScatterGatherList** routine returns a pointer to the scatter/gather list that is associated with the IRB. Otherwise, **AtaPortGetScatterGatherList** returns **NULL**.

## Remarks

Every IRB with IRB_FLAGS_USE_DMA set in the **IrbFlags** member has a scatter/gather list associated with it.

The miniport driver must not modify the scatter/gather list.

## See also

[IDE_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/ns-irb-_ide_request_block)
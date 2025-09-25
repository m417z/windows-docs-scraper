# AtaPortCompleteRequest function

## Description

The **AtaPortCompleteRequest** routine completes the indicated IRB.

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `ChannelExtension` [in]

A pointer to the channel extension.

### `Irb` [in]

A pointer to a structure of type [IDE_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/ns-irb-_ide_request_block) that defines the IDE request block (IRB) to be completed.

## Remarks

The miniport driver uses this routine to indicate to the port driver that the IRB has completed. The miniport driver must not touch the IRB after this call. It is an error to complete an IRB with status IRB_STATUS_PENDING.

## See also

[IDE_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/ns-irb-_ide_request_block)
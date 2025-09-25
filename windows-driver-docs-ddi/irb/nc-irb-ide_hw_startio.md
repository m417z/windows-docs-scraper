# IDE_HW_STARTIO callback function

## Description

The ***IdeHwStartIo*** miniport driver routine processes the synchronized aspects of an I/O request.

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `ChannelExtension` [in]

A pointer to the miniport driver per channel device extension.

### `Irb` [in]

A pointer to a structure of type [IDE_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/ns-irb-_ide_request_block) that defines the IDE request block (IRB) to process.

## Return value

***IdeHwStartIo*** returns **TRUE** to acknowledge the receipt of an IRB. The port driver ignores a return value of **FALSE**.

## Remarks

Miniport drivers must provide an ***IdeHwStartIo*** routine to process the aspects of an I/O request that must be handled synchronously. For information about how the miniport driver processes the unsynchronized aspects of an I/O request, see [IdeHwBuildIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nc-irb-ide_hw_buildio).

After the miniport driver receives the ***IdeHwStartIo*** call, it owns the request and must complete it.

After this routine returns, the miniport driver should be prepared to receive the next request from the port driver immediately.

## See also

[IDE_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/ns-irb-_ide_request_block)

[IdeHwBuildIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nc-irb-ide_hw_buildio)
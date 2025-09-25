# IDE_HW_RESET callback function

## Description

The ***IdeHwReset*** miniport driver routine resets the channel.

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `ChannelExtension` [in]

A pointer to the channel extension.

## Return value

***IdeHwReset*** returns **TRUE** if the reset operation succeeded. Otherwise, it returns **FALSE**.

## Remarks

The ***IdeHwReset*** routine should complete all pending requests and reset the indicated channel.

***IdeHwReset*** can be called even if the miniport driver is not ready for another request.
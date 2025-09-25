# ATA_CHANNEL_STATE enumeration

## Description

The ATA_CHANNEL_STATE enumeration type indicates the state of the channel.

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Constants

### `ChannelStateDisabled`

Indicates that the channel is disabled.

### `ChannelStateEnabled`

Indicates that the channel is enabled.

### `ChannelStateUnKnown`

Indicates that the state of the channel is unknown.

## Remarks

The ATA_CHANNEL_STATE enumeration type is used in conjunction with the [AtaControllerChannelEnabled](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nc-irb-ide_channel_enabled) routine to determine whether the channel is enabled.

## See also

[AtaControllerChannelEnabled](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nc-irb-ide_channel_enabled)
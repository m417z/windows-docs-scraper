# AtaPortRequestPowerStateChange function

## Description

The **AtaPortRequestPowerStateChange** routine requests a power state transition for the indicated device.

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `ChannelExtension`

A pointer to the channel extension.

### `TargetId`

Specifies the target identifier of the device.

### `Lun`

Specifies the logical unit number (LUN).

### `DesiredPowerState`

Contains an enumerator value of type [IDE_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/ne-irb-ide_power_state) that indicates the power state to which the indicated device should be changed.

## Remarks

The **AtaPortRequestPowerStateChange** routine is used when a miniport driver might have to initiate a power state change, such as when a hot-plug operation occurs.

**Note** The practice of doing idle detection from an ATA miniport driver is discouraged.

## See also

[IDE_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/ne-irb-ide_power_state)
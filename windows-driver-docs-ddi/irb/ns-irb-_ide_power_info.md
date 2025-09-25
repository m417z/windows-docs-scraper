# _IDE_POWER_INFO structure

## Description

The POWER_CHANGE_INFO structure is used in conjunction with the [IDE_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/ns-irb-_ide_request_block) to request a power state change.

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Members

### `CurrentPowerState`

Contains an enumeration value of type [IDE_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/ne-irb-ide_power_state) that indicates the current power state of the device.

### `DesiredPowerState`

Contains an enumeration value of type IDE_POWER_STATE that indicates the power state to which the device will be changed.

## See also

[IDE_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/ne-irb-ide_power_state)

[IDE_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/ns-irb-_ide_request_block)
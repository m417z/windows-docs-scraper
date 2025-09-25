# IDE_POWER_STATE enumeration

## Description

The IDE_POWER_STATE enumeration type indicates that power state of the device.

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Constants

### `IdePowerUnSpecified`

Indicates that the power level is unspecified.

### `IdePowerD0`

Indicates a device power level of 0.

### `IdePowerD3`

Indicates a device power level of 3.

## Remarks

The IDE_POWER_STATE enumeration type is used in conjunction with the [AtaPortRequestPowerStateChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportrequestpowerstatechange) routine to request a power state transition for a device.

## See also

[AtaPortRequestPowerStateChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportrequestpowerstatechange)
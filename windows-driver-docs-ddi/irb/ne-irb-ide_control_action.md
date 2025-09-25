# IDE_CONTROL_ACTION enumeration

## Description

The IDE_CONTROL_ACTION enumeration type indicates the control action to be performed by an [IdeHwControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nc-irb-ide_hw_control) routine.

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Constants

### `IdeStart`

Indicates that the miniport driver should start the channel.

### `IdeStop`

Indicates that the miniport driver should stop the channel.

### `IdePowerUp`

Indicates that the miniport driver should power up the channel.

### `IdePowerDown`

 Indicates that the miniport driver should power down the channel.

### `IdeVendorDefined`

Indicates that the miniport driver should perform a vendor-defined control action.

## See also

[IdeHwControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nc-irb-ide_hw_control)
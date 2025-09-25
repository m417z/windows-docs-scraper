# IDE_TRANSFER_MODE_SELECT callback function

## Description

The **AtaControllerTransferModeSelect** miniport driver routine selects the transfer mode for all devices on the indicated ATA channel and programs the controller for the selected transfer mode.

> [!NOTE]
> The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `ControllerExtension`

[in] A pointer to the controller extension.

### `TransferModeSelect`

[in, out] A pointer to a structure of type [**IDE_TRANSFER_MODE_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/ns-irb-_ide_transfer_mode_parameters) that indicates to the miniport driver the channel on which to set the transfer modes and which transfer modes are available.

## Return value

**AtaControllerTransferModeSelect** returns TRUE to acknowledge the receipt of the transfer mode parameters. The miniport driver ignores a return value of FALSE.

## Remarks

The **AtaControllerTransferModeSelect** miniport driver routine must select the appropriate timing modes and program the controller for the selected modes. The miniport driver must select at least one programmed input/output (PIO) mode for the indicated channel, and preferably at least one direct memory access (DMA) timing mode also. To communicate to the caller the transfer modes that it selected, the miniport driver sets the appropriate bits in the **TransferModeSelected** member of the IDE_TRANSFER_MODE_PARAMETERS structure.

**AtaControllerTransferModeSelect** is an optional routine.

## See also

[**IDE_TRANSFER_MODE_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/ns-irb-_ide_transfer_mode_parameters)
# PHW_RESET_BUS callback

## Description

The PHW_RESET_BUS prototype declares a routine that resets the indicated SCSI bus.

## Parameters

### `DeviceExtension` [in]

Pointer to the miniport driver's per-HBA storage area.

### `PathId` [in]

Contains a number that identifies the SCSI bus to be reset.

## Return value

The routine that this prototype declares returns **TRUE** if the bus is successfully reset. The routine returns **FALSE** if the bus is not successfully reset.

## Remarks

The initialization routine for both SCSI and StorPort miniport drivers are declared using this prototype.

For more information about the SCSI miniport driver's bus reset routine see [HwScsiResetBus](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557318(v=vs.85)).

For more information about the bus reset routine that is used with the StorPort driver's miniport driver routine, see [HwStorResetBus](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_reset_bus).

## See also

[HwScsiResetBus](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557318(v=vs.85))

[HwStorResetBus](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_reset_bus)
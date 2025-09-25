# PHW_INTERRUPT callback (srb.h)

## Description

The PHW_INTERRUPT routine prototype declares the miniport driver's interrupt handler routine.

## Parameters

### `DeviceExtension` [in]

Pointer to the miniport driver's per-HBA storage area.

## Return value

If the interrupt handler routine determines that its HBA generated the interrupt, it returns **TRUE**. If the interrupt handler determines that its HBA did not generate the interrupt, it should return **FALSE** as soon as possible.

## Remarks

The interrupt handler routine for both SCSI and StorPort miniport drivers are declared using this prototype.

For more information about the SCSI miniport driver's interrupt handler routine see [HwScsiInterrupt](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557312(v=vs.85)).

For more information about the miniport driver's interrupt handler routine that is used with the StorPort driver see [HwStorInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_interrupt).

## See also

[HwScsiInterrupt](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557312(v=vs.85))

[HwStorInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_interrupt)
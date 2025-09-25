# PHW_TIMER callback

## Description

The PHW_TIMER routine prototype declares a SCSI miniport driver's timer routine.

## Parameters

### `DeviceExtension` [in]

Pointer to the miniport driver's per-HBA storage area.

## Remarks

The SCSI miniport driver's timer routine, [HwScsiTimer](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557327(v=vs.85)), is called after the interval specified when the miniport driver called **ScsiPortNotification** with the **RequestTimerCall***NotificationType* value.

Miniport drivers that work with the StorPort driver do not use this timer routine.

## See also

[HwScsiTimer](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557327(v=vs.85))
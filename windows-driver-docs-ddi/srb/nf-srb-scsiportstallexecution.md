# ScsiPortStallExecution function

## Description

The **ScsiPortStallExecution** routine stalls in the miniport driver.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `Delay` [in]

Specifies the delay interval in microseconds. The given value must be less than a full millisecond.

## Return value

None

## Remarks

**ScsiPortStallExecution** should be called as seldom as possible and the total stall time in a miniport driver routine must be less than one millisecond. This call ties up a processor, doing no useful work while stalling in the driver.

In general, a miniport driver should call **ScsiPortStallExecution** only if the driver must wait for a state change on the HBA that cannot cause an interrupt, or if the driver must delay for a very short interval between accesses to the HBA.

If a miniport driver's [HwScsiInterrupt](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557312(v=vs.85)) routine must stall between accesses to the HBA and the total delay time in the ISR might be more than one millisecond, *HwScsiInterrupt* should call **ScsiPortNotification** with the *NotificationType***CallEnableInterrupts** instead of calling **ScsiPortStallExecution**. Such a miniport driver has a pair of *HwScsi..InterruptsCallback* routines to manage its interrupt-driven I/O processing without tying up a processor and degrading the I/O performance of other HBAs that miniport driver might support in the same machine.

A miniport driver-supplied [HwScsiTimer](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557327(v=vs.85)) routine also can be passed in calls to **ScsiPortNotification** with a specified interval that is not limited to one millisecond.

## See also

[HwScsiDisableInterruptsCallback](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557288(v=vs.85))

[HwScsiEnableInterruptsCallback](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557295(v=vs.85))

[HwScsiInterrupt](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557312(v=vs.85))

[HwScsiTimer](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557327(v=vs.85))

[ScsiPortNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportnotification)
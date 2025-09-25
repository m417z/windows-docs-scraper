# UPSStop function

## Description

The **UPSStop** function causes a UPS minidriver to stop monitoring its UPS unit.

## Remarks

The **UPSStop** function must:

* Cancel all waiting calls to [UPSWaitForStateChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/upssvc/nf-upssvc-upswaitforstatechange).
* Stop monitoring the UPS unit.
* Close and release the UPS unit's COM port.

After **UPSStop** returns, the only function the UPS service can call is [UPSInit](https://learn.microsoft.com/windows-hardware/drivers/ddi/upssvc/nf-upssvc-upsinit).

## See also

[UPSInit](https://learn.microsoft.com/windows-hardware/drivers/ddi/upssvc/nf-upssvc-upsinit)
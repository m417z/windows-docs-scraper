# PsGetProcessExitTime function

## Description

The **PsGetProcessExitTime** routine returns the exit time for the current process.

## Return value

**PsGetProcessExitTime** returns the exit time for the current process, in system time format.

## Remarks

System time is a count of 100-nanosecond intervals since January 1, 1601. System time is typically updated approximately every ten milliseconds. This value is computed for the GMT time zone. To adjust this value for the local time zone, use **ExSystemTimeToLocalTime**.

For more information about converting time values, see [Data Conversions](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#data-conversions).

## See also

[ExSystemTimeToLocalTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exsystemtimetolocaltime)

[KeQuerySystemTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequerysystemtime)

[PsIsThreadTerminating](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-psisthreadterminating)
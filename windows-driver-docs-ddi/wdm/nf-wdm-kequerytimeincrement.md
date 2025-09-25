# KeQueryTimeIncrement function

## Description

The **KeQueryTimeIncrement** routine returns the number of 100-nanosecond units that are added to the system time each time the interval clock interrupts.

## Return value

**KeQueryTimeIncrement** returns a ULONG value indicating the number of 100-nanosecond units that are added to the system time each time the interval clock interrupts.

## Remarks

At startup time, the operating system determines the time increment to use for the system time. This time increment remains constant until the computer restarts. During this time, calls to **KeQueryTimeIncrement** always return the same time increment value. The time increment does not change while the computer is running, and it does not change as the result of a suspend-resume cycle.

## See also

[KeQueryPerformanceCounter](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-kequeryperformancecounter)

[KeQuerySystemTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequerysystemtime)

[KeQueryTickCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kequerytickcount)
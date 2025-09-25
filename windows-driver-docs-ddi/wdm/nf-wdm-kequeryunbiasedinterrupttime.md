# KeQueryUnbiasedInterruptTime function

## Description

The **KeQueryUnbiasedInterruptTime** routine returns the current value of the system [interrupt time](https://learn.microsoft.com/windows/win32/sysinfo/interrupt-time) count.

## Return value

**KeQueryUnbiasedInterruptTime** returns the current interrupt time count in 100-nanosecond units. The count begins at zero when the computer starts. Updates to this count are suspended when the computer enters a sleep state and are resumed when the computer awakens.

## Remarks

Kernel-mode drivers can call this routine to measure relatively fine-grained durations.

This routine returns the system interrupt time, which is the amount of time since the operating system was last started. The interrupt-time count begins at zero when the operating system starts and is incremented at each clock interrupt by the length of a clock tick. For various reasons, such as hardware differences, the length of a system clock tick can vary between computers. Call the [KeQueryTimeIncrement](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequerytimeincrement) routine to determine the size of a system clock tick.

The **KeQueryUnbiasedInterruptTime** and [KeQueryInterruptTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequeryinterrupttime) routines are similar, but they differ in the way in which they account for periods in which the operating system suspends updates of the interrupt time count. For example, these updates are suspended while the computer is in a system sleep state. To compensate for periods in which updates of the count are suspended, **KeQueryInterruptTime** returns a biased count value that it calculates by adding a bias count to the raw interrupt time count. The bias count is the estimated sum of all of the updates to the interrupt time count that the operating system missed while counting was suspended. In contrast, **KeQueryUnbiasedInterruptTime** returns the raw, unbiased count.

Unlike the [KeQuerySystemTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequerysystemtime) routine, **KeQueryUnbiasedInterruptTime** returns a count value that is not affected by operations that set or reset the system time. In addition, the system time that is reported by **KeQuerySystemTime** is typically updated approximately every ten milliseconds. In contrast, the count that is returned by **KeQueryUnbiasedInterruptTime** is updated at least once per system clock tick.

In Windows 2000 and later versions of the Windows operating system, the [KeQueryPerformanceCounter](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-kequeryperformancecounter) routine provides the finest grained running count that is available from the operating system.

## See also

[KeQueryInterruptTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequeryinterrupttime)

[KeQueryInterruptTimePrecise](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequeryinterrupttimeprecise)

[KeQueryPerformanceCounter](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-kequeryperformancecounter)

[KeQuerySystemTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequerysystemtime)

[KeQueryTimeIncrement](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequerytimeincrement)
# KeQueryInterruptTime function

## Description

The **KeQueryInterruptTime** routine returns the current value of the system [interrupt time](https://learn.microsoft.com/windows/win32/sysinfo/interrupt-time) count, with accuracy to within system clock tick.

## Return value

**KeQueryInterruptTime** returns the current interrupt-time count in 100-nanosecond units. The update to this return value generally occurs at least once per system clock tick.

## Remarks

This routine returns the system interrupt time, which is the amount of time since the operating system was last started. The interrupt-time count begins at zero when the operating system starts and is incremented at each clock interrupt by the length of a clock tick. For various reasons, such as hardware differences, the length of a system clock tick can vary between computers. Call the [KeQueryTimeIncrement](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequerytimeincrement) routine to determine the size of a system clock tick.

**KeQueryInterruptTime** can be used for performance tuning. This routine returns a finer grained measurement than the [KeQueryTickCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kequerytickcount) routine. A call to **KeQueryInterruptTime** has considerably less overhead than a call to the [KeQueryPerformanceCounter](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-kequeryperformancecounter) routine, as well.

Consequently, interrupt time can be used to measure very fine-grained durations while the system is running because operations that set or reset the system time have no effect on the system interrupt time count.

However, power-management state changes do affect the system interrupt time count. Maintenance of the interrupt time count is suspended during system sleep states. When a subsequent wake state transition occurs, the system adds a "bias" value to the interrupt time count to compensate for the estimated duration of such a sleep state. The interrupt time count that is returned by **KeQueryInterruptTime** includes this bias value. To obtain an unbiased interrupt time count, use the [KeQueryUnbiasedInterruptTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequeryunbiasedinterrupttime) routine instead of **KeQueryInterruptTime**.

## See also

[Acquiring high-resolution time stamps](https://learn.microsoft.com/windows/win32/sysinfo/acquiring-high-resolution-time-stamps)

**KeQueryInterruptTimePrecise**

[KeQueryPerformanceCounter](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-kequeryperformancecounter)

[KeQueryTickCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kequerytickcount)

[KeQueryTimeIncrement](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequerytimeincrement)

[KeQueryUnbiasedInterruptTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequeryunbiasedinterrupttime)
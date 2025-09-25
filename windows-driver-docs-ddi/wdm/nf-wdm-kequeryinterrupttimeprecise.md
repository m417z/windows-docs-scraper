# KeQueryInterruptTimePrecise function

## Description

The **KeQueryInterruptTimePrecise** routine returns the current value of the system [interrupt time](https://learn.microsoft.com/windows/win32/sysinfo/interrupt-time) count, with accuracy to within a microsecond.

## Parameters

### `QpcTimeStamp` [out]

A pointer to a ULONG64 variable into which the routine writes the performance counter value used to interpolate the return value.

## Return value

The current interrupt-time count in 100-nanosecond units.

## Remarks

**KeQueryInterruptTimePrecise** returns the system's current interrupt time, which is the amount of time since the operating system was last started. **KeQueryInterruptTimePrecise** is similar to the [KeQueryInterruptTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequeryinterrupttime) routine, but is more precise.

The interrupt time reported by [KeQueryInterruptTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequeryinterrupttime) is based on the latest tick of the system clock timer. The clock timer is the hardware timer that periodically generates interrupts for the system clock. The uniform period between clock timer interrupts is referred to as a system clock tick, and is typically in the range of 500 microseconds to 15.625 milliseconds, depending on the hardware platform. The interrupt time value retrieved by **KeQueryInterruptTime** is accurate within a system clock tick.

To provide an interrupt time value that is more precise than that of [KeQueryInterruptTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequeryinterrupttime), **KeQueryInterruptTimePrecise** uses the system performance counter to measure the time elapsed since the last clock timer interrupt, and adds this time to the interrupt time associated with the latest clock time. The interrupt time reported by **KeQueryInterruptTimePrecise** is accurate to within a microsecond.

On some hardware platforms, a **KeQueryInterruptTimePrecise** call might be slower than a [KeQueryInterruptTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequeryinterrupttime) call. The reason is that **KeQueryInterruptTimePrecise** reads the performance counter, which can introduce an additional delay. For more information, see [KeQueryPerformanceCounter](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-kequeryperformancecounter).

Call the [KeQueryTimeIncrement](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequerytimeincrement) routine to determine the size of a system clock tick.

Precise interrupt time can be used to measure very fine-grained durations while the system is running because operations that set or reset the system time have no effect on the system interrupt time count.

However, power-management state changes do affect the system interrupt time count. Maintenance of the interrupt time count is suspended during system sleep states. When a subsequent wake state transition occurs, the system adds a "bias" value to the interrupt time count to compensate for the estimated duration of such a sleep state. The interrupt time count that is returned by **KeQueryInterruptTimePrecise** includes this bias value. To obtain an unbiased interrupt time count, use the [KeQueryUnbiasedInterruptTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequeryunbiasedinterrupttime). A precise version of the unbiased interrupt time count is not currently available.

## See also

[Acquiring high-resolution time stamps](https://learn.microsoft.com/windows/win32/sysinfo/acquiring-high-resolution-time-stamps)

[KeQueryInterruptTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequeryinterrupttime)

[KeQueryTimeIncrement](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequerytimeincrement)

[KeQueryUnbiasedInterruptTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequeryunbiasedinterrupttime)
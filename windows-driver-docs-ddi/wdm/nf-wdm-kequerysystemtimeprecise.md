# KeQuerySystemTimePrecise function

## Description

The **KeQuerySystemTimePrecise** routine retrieves the current [system time](https://learn.microsoft.com/windows/desktop/SysInfo/system-time), and is more precise than the [KeQuerySystemTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequerysystemtime-r1) routine.

## Parameters

### `CurrentTime` [out]

A pointer to a LARGE_INTEGER variable into which the routine writes the current system time.

## Remarks

System time is a count of 100-nanosecond intervals since January 1, 1601. This value is computed for the GMT time zone. To adjust this value for the local time zone, call the [ExSystemTimeToLocalTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exsystemtimetolocaltime) routine.

**KeQuerySystemTimePrecise** is similar to the **KeQuerySystemTime** routine, but is more precise. The system time reported by **KeQuerySystemTime** is based on the latest tick of the system clock timer. The clock timer is the hardware timer that periodically generates interrupts for the system clock. The uniform period between clock timer interrupts is referred to as a system clock tick, and is typically in the range of 500 microseconds to 15.625 milliseconds, depending on the hardware platform. The system time value retrieved by **KeQuerySystemTime** is accurate within a system clock tick.

To provide a system time value that is more accurate than that of **KeQuerySystemTime**, **KeQuerySystemTimePrecise** uses the system performance counter to measure the time elapsed since the last clock timer interrupt, and adds this time to the system clock time that it calculates from the clock timer count. The system time reported by **KeQuerySystemTimePrecise** is accurate to within a microsecond.

On some hardware platforms, a **KeQuerySystemTimePrecise** call might be slower than a **KeQuerySystemTime** call. The reason is that **KeQuerySystemTimePrecise** reads the performance counter, which can introduce an additional delay. For more information, see [KeQueryPerformanceCounter](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-kequeryperformancecounter).

Call the [KeQueryTimeIncrement](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequerytimeincrement) routine to determine the duration of a system clock tick.

## See also

[ExSystemTimeToLocalTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exsystemtimetolocaltime)

[KeQueryPerformanceCounter](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-kequeryperformancecounter)

[KeQuerySystemTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequerysystemtime~r1)

[KeQueryTickCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kequerytickcount)

[KeQueryTimeIncrement](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequerytimeincrement)
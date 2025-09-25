# KeQuerySystemTime function

## Description

The **KeQuerySystemTime** routine obtains the current system time.

## Parameters

### `CurrentTime` [out]

Pointer to LARGE_INTEGER variable that receives the current time.

## Remarks

System time is a count of 100-nanosecond intervals since January 1, 1601. System time is typically updated approximately every ten milliseconds. This value is computed for the GMT time zone. To adjust this value for the local time zone use [ExSystemTimeToLocalTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exsystemtimetolocaltime).

## See also

[ExSystemTimeToLocalTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exsystemtimetolocaltime)

[KeQueryPerformanceCounter](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-kequeryperformancecounter)

[KeQueryTickCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kequerytickcount)

[KeQueryTimeIncrement](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequerytimeincrement)
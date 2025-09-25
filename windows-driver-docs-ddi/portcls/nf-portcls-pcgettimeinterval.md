# PcGetTimeInterval function

## Description

The **PcGetTimeInterval** function returns the time elapsed since a specified time. Time is measured in 100-nanosecond units.

## Parameters

### `Since` [in]

Specifies the time from which to measure the interval. Typically, this function is called once with a "since" of zero to get the current time, and is called subsequently with a "since" of the recorded current time to get time intervals from that time.

## Return value

**PcGetTimeInterval** returns the current time minus *Since*.

## Remarks

The value that is specified in parameter *Since* is measured in 100-nanosecond units. If *Since* is zero, the time returned is the number of 100-nanosecond ticks since January 1, 1601. The time units are the same as those used to specify the system time in the [KeQuerySystemTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequerysystemtime~r1) function.

The following macros from portcls.h are useful for converting seconds, milliseconds, and microseconds to 100-millisecond units:

GTI_SECONDS

GTI_MILLISECONDS

GTI_MICROSECONDS

This function can be used for timing purposes by first saving the current time,

```
  ULONGLONG ullTime = PcGetTimeInterval(0);
```

and then checking to see whether the required interval has passed

```
  if (PcGetTimeInterval(ullTime) >= GTI_MILLISECONDS(5))
```

## See also

[KeQuerySystemTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequerysystemtime~r1)
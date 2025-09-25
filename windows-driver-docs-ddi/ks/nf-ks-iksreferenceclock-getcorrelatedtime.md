# IKsReferenceClock::GetCorrelatedTime

## Description

The **IKsReferenceClock::GetCorrelatedTime** method queries the associated reference clock for current stream time and acquires the correlated system time.

## Parameters

### `SystemTime` [out]

A pointer to a LONGLONG-typed variable that receives the current system time in 100 nanosecond units.

## Return value

The **IKsReferenceClock::GetCorrelatedTime** method returns the stream time, specified by default in 100-nanosecond units. The correlated system time is returned in *SystemTime*.

## Remarks

Use this method to determine the difference between stream time and system time. **IKsReferenceClock::GetCorrelatedTime** returns the times that both clocks show at the same moment.

For the most accurate results, call this method only when the stream is in a running state (KSSTATE_RUN) and not during a state transition.

You should use this method when obtaining a time stamp to put in the **PresentationTime** member of [KSSTREAM_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksstream_header).

For more information, see [AVStream Clocks](https://learn.microsoft.com/windows-hardware/drivers/stream/avstream-clocks).

AVStream uses the [KSPROPERTY_CLOCK_CORRELATEDTIME](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-clock-correlatedtime) property to retrieve the correlated time.

## See also

[KsPinGetReferenceClockInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspingetreferenceclockinterface)
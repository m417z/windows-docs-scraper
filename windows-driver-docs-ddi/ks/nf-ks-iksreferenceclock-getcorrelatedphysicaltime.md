# IKsReferenceClock::GetCorrelatedPhysicalTime

## Description

The **IKsReferenceClock::GetCorrelatedPhysicalTime** method queries the associated reference clock for the current physical time and retrieves the correlated system time.

## Parameters

### `SystemTime` [out]

Specifies the current system time in 100 nanosecond units.

## Return value

The **IKsReferenceClock::GetCorrelatedPhysicalTime** method returns the current physical clock time, specified by default in 100-nanosecond units. The correlated system time is returned in *SystemTime*.

## Remarks

Use this method to determine the difference between physical time and system time. **IKsReferenceClock::GetCorrelatedPhysicalTime** returns the times that both clocks show at the same moment.

For more information, see [AVStream Clocks](https://learn.microsoft.com/windows-hardware/drivers/stream/avstream-clocks).

AVStream uses the [KSPROPERTY_CLOCK_CORRELATEDPHYSICALTIME](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-clock-correlatedphysicaltime) property to retrieve the correlated physical time.

## See also

[KsPinGetReferenceClockInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspingetreferenceclockinterface)
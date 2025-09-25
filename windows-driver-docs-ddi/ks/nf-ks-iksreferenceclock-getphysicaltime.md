# IKsReferenceClock::GetPhysicalTime

## Description

The **IKsReferenceClock::GetPhysicalTime** method queries the associated reference clock for the current physical time.

## Return value

The **IKsReferenceClock::GetPhysicalTime** method returns the current physical time for the associated pin, specified by default in 100-nanosecond units.

## Remarks

Physical time is tied to a physical clock, either the system clock or an on-board hardware clock.

The physical clock time progresses continuously. Unlike the presentation time, it is not reversible.

Clocks are not required to support a 100-nanosecond resolution. To determine the clock resolution, clients can use the [KSPROPERTY_CLOCK_RESOLUTION](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-clock-resolution) request.

For more information, see [AVStream Clocks](https://learn.microsoft.com/windows-hardware/drivers/stream/avstream-clocks).

AVStream uses the [KSPROPERTY_CLOCK_PHYSICALTIME](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-clock-physicaltime) property to retrieve the physical time.

## See also

[KsPinGetReferenceClockInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspingetreferenceclockinterface)
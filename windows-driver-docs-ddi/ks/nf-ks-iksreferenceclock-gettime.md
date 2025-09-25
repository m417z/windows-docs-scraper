# IKsReferenceClock::GetTime

## Description

The **IKsReferenceClock::GetTime** method queries the associated reference clock for the current time.

## Return value

The **IKsReferenceClock::GetTime** method returns the current stream time for the associated pin, specified by default in 100-nanosecond units.

## Remarks

Do not call this method when obtaining a time stamp for the **PresentationTime** member of [KSSTREAM_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksstream_header). Instead, call [IKsReferenceClock::GetCorrelatedTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-iksreferenceclock-getcorrelatedtime) in this situation.

For more information, see [AVStream Clocks](https://learn.microsoft.com/windows-hardware/drivers/stream/avstream-clocks).

AVStream uses the [KSPROPERTY_CLOCK_TIME](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-clock-time) property to retrieve the current clock time.

## See also

[KsPinGetReferenceClockInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspingetreferenceclockinterface)
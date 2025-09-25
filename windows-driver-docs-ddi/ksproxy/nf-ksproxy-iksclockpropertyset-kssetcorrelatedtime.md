# IKsClockPropertySet::KsSetCorrelatedTime

## Description

The **KsSetCorrelatedTime** method sets the current time with the correlated system time on the underlying clock.

## Parameters

### `CorrelatedTime` [in]

Pointer to a [KSCORRELATED_TIME](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kscorrelated_time) structure that contains the current clock time along with the correlated system time to which to set the underlying clock.

## Return value

Returns NOERROR if successful; otherwise, returns an error code.

## Remarks

The proxy uses the [KSPROPERTY_CLOCK_CORRELATEDTIME](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-clock-correlatedtime) property to set the correlated time.

## See also

[IKsClockPropertySet::KsGetCorrelatedTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-iksclockpropertyset-ksgetcorrelatedtime)

[KSCORRELATED_TIME](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kscorrelated_time)

[KSPROPERTY_CLOCK_CORRELATEDTIME](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-clock-correlatedtime)
# IKsClockPropertySet::KsGetCorrelatedTime

## Description

The **KsGetCorrelatedTime** method retrieves the current time and the correlated system time from the underlying clock.

## Parameters

### `CorrelatedTime` [out]

Pointer to a variable that receives a [KSCORRELATED_TIME](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kscorrelated_time) structure that contains the current clock time along with the correlated system time.

## Return value

Returns NOERROR if successful; otherwise, returns an error code.

## Remarks

The **KsGetCorrelatedTime** method retrieves the current time and the correlated system in an atomic operation.

The proxy uses the [KSPROPERTY_CLOCK_CORRELATEDTIME](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-clock-correlatedtime) property to retrieve the correlated time.

## See also

[IKsClockPropertySet::KsSetCorrelatedTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-iksclockpropertyset-kssetcorrelatedtime)

[KSCORRELATED_TIME](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kscorrelated_time)

[KSPROPERTY_CLOCK_CORRELATEDTIME](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-clock-correlatedtime)
# IKsClockPropertySet::KsSetCorrelatedPhysicalTime

## Description

The **KsSetCorrelatedPhysicalTime** method sets the physical time with the correlated system time on the underlying clock.

## Parameters

### `CorrelatedTime` [in]

Pointer to a [KSCORRELATED_TIME](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kscorrelated_time) structure that contains the physical clock time along with the correlated system time to which to set the underlying clock.

## Return value

Returns NOERROR if successful; otherwise, returns an error code.

## Remarks

The proxy uses the [KSPROPERTY_CLOCK_CORRELATEDPHYSICALTIME](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-clock-correlatedphysicaltime) property to set the correlated time.

## See also

[IKsClockPropertySet::KsGetCorrelatedPhysicalTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-iksclockpropertyset-ksgetcorrelatedphysicaltime)

[KSCORRELATED_TIME](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kscorrelated_time)

[KSPROPERTY_CLOCK_CORRELATEDPHYSICALTIME](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-clock-correlatedphysicaltime)
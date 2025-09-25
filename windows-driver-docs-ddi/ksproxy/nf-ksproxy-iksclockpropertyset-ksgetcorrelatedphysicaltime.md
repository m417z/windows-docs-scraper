# IKsClockPropertySet::KsGetCorrelatedPhysicalTime

## Description

The **KsGetCorrelatedPhysicalTime** method retrieves the physical time and the correlated system time from the underlying clock.

## Parameters

### `CorrelatedTime` [out]

Pointer to a variable that receives a [KSCORRELATED_TIME](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kscorrelated_time) structure that contains the physical clock time along with the correlated system time.

## Return value

Returns NOERROR if successful; otherwise, returns an error code.

## Remarks

The proxy uses the [KSPROPERTY_CLOCK_CORRELATEDPHYSICALTIME](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-clock-correlatedphysicaltime) property to retrieve the correlated time.

## See also

[IKsClockPropertySet::KsSetCorrelatedPhysicalTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-iksclockpropertyset-kssetcorrelatedphysicaltime)

[KSCORRELATED_TIME](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kscorrelated_time)

[KSPROPERTY_CLOCK_CORRELATEDPHYSICALTIME](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-clock-correlatedphysicaltime)
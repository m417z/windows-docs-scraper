# IKsClockPropertySet::KsSetPhysicalTime

## Description

The **KsSetPhysicalTime** method sets the physical time on the underlying clock.

## Parameters

### `Time` [in]

Physical time to which to set the underlying clock.

## Return value

Returns NOERROR if successful; otherwise, returns an error code.

## Remarks

The physical time is based on some underlying physical clock that always progresses, even if the physical type of clock must be changed on the fly. Other physical clocks use an underlying clock's physical time for rate matching.

The proxy uses the [KSPROPERTY_CLOCK_PHYSICALTIME](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-clock-physicaltime) property to set the physical time.

## See also

[IKsClockPropertySet::KsGetPhysicalTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-iksclockpropertyset-ksgetphysicaltime)

[KSPROPERTY_CLOCK_PHYSICALTIME](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-clock-physicaltime)
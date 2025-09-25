# IKsClockPropertySet::KsGetPhysicalTime

## Description

The **KsGetPhysicalTime** method retrieves the physical time from the underlying clock.

## Parameters

### `Time` [out]

Pointer to a variable that receives the current physical time.

## Return value

Returns NOERROR if successful; otherwise, returns an error code.

## Remarks

The physical time is based on some underlying physical clock that always progresses, even if the physical type of clock must be changed in real time. Other physical clocks use an underlying clock's physical time for rate matching.

The proxy uses the [KSPROPERTY_CLOCK_PHYSICALTIME](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-clock-physicaltime) property to retrieve the physical time.

## See also

[IKsClockPropertySet::KsSetPhysicalTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-iksclockpropertyset-kssetphysicaltime)

[KSPROPERTY_CLOCK_PHYSICALTIME](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-clock-physicaltime)
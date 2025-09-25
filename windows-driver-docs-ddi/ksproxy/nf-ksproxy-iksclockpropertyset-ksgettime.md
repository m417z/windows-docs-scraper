# IKsClockPropertySet::KsGetTime

## Description

The **KsGetTime** method retrieves the time of the underlying clock.

## Parameters

### `Time` [out]

Pointer to a variable that receives the current clock time.

## Return value

Returns NOERROR if successful; otherwise, returns an error code.

## Remarks

The proxy uses the [KSPROPERTY_CLOCK_TIME](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-clock-time) property to retrieve the current clock time.

## See also

[IKsClockPropertySet::KsSetTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-iksclockpropertyset-kssettime)

[KSPROPERTY_CLOCK_TIME](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-clock-time)
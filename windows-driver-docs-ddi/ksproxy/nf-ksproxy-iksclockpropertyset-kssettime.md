# IKsClockPropertySet::KsSetTime

## Description

The **KsSetTime** method sets the current time on the underlying clock.

## Parameters

### `Time` [in]

Time to which to set the underlying clock.

## Return value

Returns NOERROR if successful; otherwise, returns an error code.

## Remarks

The proxy uses the [KSPROPERTY_CLOCK_TIME](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-clock-time) property to set the current clock time.

## See also

[IKsClockPropertySet::KsGetTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-iksclockpropertyset-ksgettime)

[KSPROPERTY_CLOCK_TIME](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-clock-time)
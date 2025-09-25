# IKsClockPropertySet::KsGetResolution

## Description

The **KsGetResolution** method retrieves the clock resolution from the underlying clock.

## Parameters

### `Resolution` [out]

Pointer to a variable that receives a [KSRESOLUTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksresolution) structure that contains the granularity and error of the underlying clock.

## Return value

Returns NOERROR if successful; otherwise, returns an error code.

## Remarks

The **KsGetResolution** method retrieves the underlying clock's resolution property, which specifies the underlying clock's increment granularity and notification error in terms of 100-nanosecond units. The best granularity would be one 100-nanosecond unit; less granular increments would contain larger numbers. The least amount of notification error above and beyond the clock granularity would be reported as zero 100-nanosecond units, and less accurate clocks would use larger numbers to indicate +/− error. The proxy can use this resolution property to determine maximum error and resolution in event notification and synchronization.

The proxy uses the [KSPROPERTY_CLOCK_RESOLUTION](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-clock-resolution) property to retrieve the clock resolution.

## See also

[KSPROPERTY_CLOCK_RESOLUTION](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-clock-resolution)

[KSRESOLUTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksresolution)
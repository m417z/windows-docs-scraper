# IKsReferenceClock::GetResolution

## Description

The **IKsReferenceClock::GetResolution** method queries the associated reference clock for its resolution.

## Parameters

### `Resolution` [out]

Specifies granularity and notification error of the clock in a [KSRESOLUTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksresolution) structure.

## Return value

The **IKsReferenceClock::GetResolution** method returns STATUS_SUCCESS or the error code that the relevant clock returned from its **GetResolution** property. See [KSPROPERTY_CLOCK_RESOLUTION](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-clock-resolution). May return STATUS_DEVICE_NOT_READY if no clock is assigned.

## Remarks

This method retrieves the underlying clock's resolution property, which specifies the clock's increment granularity and notification error in 100-nanosecond units. The finest granularity is one unit; less granular increments contain larger numbers.

The least amount of notification error greater than the clock granularity is zero units; less accurate clocks use larger numbers to indicate error. The proxy can use this resolution property to determine maximum error and resolution in event notification and synchronization.

For more information, see [AVStream Clocks](https://learn.microsoft.com/windows-hardware/drivers/stream/avstream-clocks).

AVStream uses the [KSPROPERTY_CLOCK_RESOLUTION](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-clock-resolution) property to retrieve the clock resolution.

## See also

[KsPinGetReferenceClockInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspingetreferenceclockinterface)
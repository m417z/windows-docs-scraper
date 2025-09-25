# IKsReferenceClock::GetState

## Description

The **IKsReferenceClock::GetState** method queries the associated reference clock for its current streaming state.

## Parameters

### `State` [out]

Points to a [KSSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ne-ks-ksstate) structure that indicates the streaming state of the underlying clock.

## Return value

The **IKsReferenceClock::GetState** method returns STATUS_SUCCESS or the error code that the relevant clock returned from its **GetState** property. See [KSPROPERTY_CLOCK_STATE](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-clock-state). May return STATUS_DEVICE_NOT_READY if no clock is assigned.

## Remarks

For more information, see [AVStream Clocks](https://learn.microsoft.com/windows-hardware/drivers/stream/avstream-clocks).

AVStream uses the [KSPROPERTY_CLOCK_STATE](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-clock-state) property to retrieve the correlated time.

## See also

[KSSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ne-ks-ksstate)

[KsPinGetReferenceClockInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspingetreferenceclockinterface)
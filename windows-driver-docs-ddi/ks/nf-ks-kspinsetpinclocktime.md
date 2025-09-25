# KsPinSetPinClockTime function

## Description

The **KsPinSetPinClockTime** function sets the current time on the clock exposed by *Pin*.

## Parameters

### `Pin` [in]

A pointer to a [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin) structure representing the AVStream pin object for which the exposed clock is set to the time specified by *Time*.

### `Time` [in]

This parameter specifies the time that is set on the clock exposed by *Pin*. To determine time measurement units, use [IKsReferenceClock::GetResolution](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-iksreferenceclock-getresolution).

## Return value

None

## Remarks

**KsPinSetPinClockTime** modifies the current time returned by the clock. If an external clock is used, this function can still be used to force a resetting of the current timer when the external timer is not being used. In this case, the time provided is ignored and must be set to zero.

## See also

[IKsControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nn-ksproxy-ikscontrol)

[IKsReferenceClock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nn-ks-iksreferenceclock)

[KsFilterGetOuterUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfiltergetouterunknown)

[KsGetOuterUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetouterunknown)

[KsPinGetConnectedFilterInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspingetconnectedfilterinterface)

[KsPinGetConnectedPinInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspingetconnectedpininterface)

[KsPinGetReferenceClockInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspingetreferenceclockinterface)

[KsRegisterAggregatedClientUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksregisteraggregatedclientunknown)
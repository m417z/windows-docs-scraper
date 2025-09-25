# KsPinGetOuterUnknown function

## Description

The **KsPinGetOuterUnknown** function returns the outer **IUnknown** of the pin specified by *Pin*.

## Parameters

### `Pin` [in]

A pointer to the [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin) structure for which to return the outer **IUnknown**.

## Return value

**KsPinGetOuterUnknown** returns a pointer to the outer **IUnknown** interface of *Pin*. This can subsequently be used to query for other interfaces.

## Remarks

**KsPinGetOuterUnknown** is an inline function call to [KsGetOuterUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetouterunknown).

## See also

[AVStream Overview](https://learn.microsoft.com/windows-hardware/drivers/stream/avstream-overview)

[IKsControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nn-ksproxy-ikscontrol)

[KsDeviceGetOuterUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksdevicegetouterunknown)

[KsFilterFactoryGetOuterUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfilterfactorygetouterunknown)

[KsFilterGetOuterUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfiltergetouterunknown)

[KsGetOuterUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetouterunknown)

[KsRegisterAggregatedClientUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksregisteraggregatedclientunknown)
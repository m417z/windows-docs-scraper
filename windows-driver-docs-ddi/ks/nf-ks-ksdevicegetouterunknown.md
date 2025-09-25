# KsDeviceGetOuterUnknown function

## Description

The **KsDeviceGetOuterUnknown** function returns the outer **IUnknown** of the AVStream device specified by *Device*.

## Parameters

### `Device` [in]

A pointer to a [KSDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice) structure for which to get the outer unknown interface.

## Return value

Returns a pointer to an outer **IUnknown** of *Device*. This interface can then be used to query for other interfaces.

## Remarks

This call is an inline function call to [KsGetOuterUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetouterunknown).

## See also

[IKsControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nn-ksproxy-ikscontrol)

[KsFilterFactoryGetOuterUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfilterfactorygetouterunknown)

[KsFilterGetOuterUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfiltergetouterunknown)

[KsGetOuterUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetouterunknown)

[KsPinGetOuterUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspingetouterunknown)

[KsRegisterAggregatedClientUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksregisteraggregatedclientunknown)
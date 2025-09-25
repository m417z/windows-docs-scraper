# KsFilterFactoryGetOuterUnknown function

## Description

The **KsFilterFactoryGetOuterUnknown** function returns the outer **IUnknown** of the specified filter factory.

## Parameters

### `FilterFactory` [in]

A pointer to a [KSFILTERFACTORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilterfactory) for which to return the outer unknown interface.

## Return value

**KsFilterFactoryGetOuterUnknown** returns the outer **IUnknown** of *FilterFactory*. The minidriver can then use it to query for other interfaces.

## Remarks

This call is an inline function call to [KsGetOuterUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetouterunknown).

For more information, see [AVStream Overview](https://learn.microsoft.com/windows-hardware/drivers/stream/avstream-overview)

## See also

[IKsControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nn-ksproxy-ikscontrol)

[KsFilterGetOuterUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfiltergetouterunknown)

[KsFilterRegisterAggregatedClientUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfilterregisteraggregatedclientunknown)

[KsGetOuterUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetouterunknown)

[KsPinGetOuterUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspingetouterunknown)

[KsRegisterAggregatedClientUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksregisteraggregatedclientunknown)
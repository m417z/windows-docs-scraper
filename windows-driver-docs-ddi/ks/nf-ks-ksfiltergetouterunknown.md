# KsFilterGetOuterUnknown function

## Description

The **KsFilterGetOuterUnknown** function returns the outer **IUnknown** interface of the filter specified by *Filter*.

## Parameters

### `Filter` [in]

A pointer to the [KSFILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter) structure for which to return the outer **IUnknown**.

## Return value

**KsFilterGetOuterUnknown** returns a pointer to the outer **IUknown** interface of *Filter*. The interface can then be used to query for other interfaces, or it can be used in conjunction with a **Ks***Xxx***RegisterAggregatedClientUnknown** call to cause *Filter* to aggregate a minidriver supplied COM object.

## Remarks

This call is an inline function call to [KsGetOuterUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetouterunknown).

## See also

[AVStream Overview](https://learn.microsoft.com/windows-hardware/drivers/stream/avstream-overview)

[IKsControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nn-ksproxy-ikscontrol)

[KsFilterRegisterAggregatedClientUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfilterregisteraggregatedclientunknown)

[KsGetOuterUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetouterunknown)

[KsPinGetOuterUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspingetouterunknown)

[KsPinRegisterAggregatedClientUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinregisteraggregatedclientunknown)

**KsRegisterAggregatedClientUnknown**
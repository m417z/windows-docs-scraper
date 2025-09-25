# KsFilterRegisterAggregatedClientUnknown function

## Description

This inline function is a wrapper for [KsRegisterAggregatedClientUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksregisteraggregatedclientunknown).

## Parameters

### `Filter` [in]

A pointer to the specified AVStream [KSFILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter) structure.

### `ClientUnknown` [in]

The client **IUnknown** interface object.

## Return value

**KsFilterRegisterAggregatedClientUnknown** returns a pointer to an **IUnknown** interface representing the newly created aggregate object.

## Remarks

Note that this inline function only performs a typecast and then calls [KsRegisterAggregatedClientUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksregisteraggregatedclientunknown).

## See also

[KsRegisterAggregatedClientUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksregisteraggregatedclientunknown)
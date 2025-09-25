# KsFilterFactoryRegisterAggregatedClientUnknown function

## Description

This inline function is a wrapper for [KsRegisterAggregatedClientUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksregisteraggregatedclientunknown).

## Parameters

### `FilterFactory` [in]

A pointer to the [KSFILTERFACTORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilterfactory) structure that represents the specified AVStream filter factory.

### `ClientUnknown` [in]

A pointer to the client **IUnknown** interface.

## Return value

**KsFilterFactoryRegisterAggregatedClientUnknown** returns a pointer to the **IUnknown** interface of the newly created aggregate object.

## Remarks

Note that this inline function only performs a typecast and then calls **KsRegisterAggregatedClientUnknown**.

## See also

[KsRegisterAggregatedClientUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksregisteraggregatedclientunknown)
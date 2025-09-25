# KsRegisterAggregatedClientUnknown function

## Description

In a manner very similar to COM, the **KsRegisterAggregatedClientUnknown** function aggregates two objects: the specified AVStream object and a client unknown object.

## Parameters

### `Object` [in]

A pointer to the AVStream object to become the outer unknown interface.

### `ClientUnknown` [in]

A pointer to an **IUnknown** interface.

## Return value

Returns the newly created aggregate object.

## Remarks

The client unknown becomes the inner part of the aggregate object, and the AVStream object becomes the outer unknown. When an interface is queried that AVStream does not handle, AVStream passes the query is to the inner aggregate.

If a client unknown is already aggregated on the AVStream object, AVStream releases the previously registered aggregate and uses the unknown passed to **KsRegisterAggregatedClientUnknown** as the new inner unknown.

There are four wrappers to **KsRegisterAggregatedClientUnknown** that perform typecasts.

Minidrivers do not need to be running in a C++ environment to use this function.

## See also

[KsDeviceRegisterAggregatedClientUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksdeviceregisteraggregatedclientunknown)

[KsFilterFactoryRegisterAggregatedClientUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfilterfactoryregisteraggregatedclientunknown)

[KsFilterRegisterAggregatedClientUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfilterregisteraggregatedclientunknown)

[KsGetOuterUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetouterunknown)

[KsPinRegisterAggregatedClientUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinregisteraggregatedclientunknown)
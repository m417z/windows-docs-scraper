# KsDeviceRegisterAggregatedClientUnknown function

## Description

This inline function is a wrapper for [KsRegisterAggregatedClientUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksregisteraggregatedclientunknown).

## Parameters

### `Device` [in]

A pointer to a [KSDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice) structure representing the specified AVStream device.

### `ClientUnknown` [in]

A pointer to the client's undelegated **IUnknown** interface.

## Return value

Returns the newly created aggregate object.

## Remarks

This inline function performs a typecast and then calls [KsRegisterAggregatedClientUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksregisteraggregatedclientunknown).

## See also

[KsRegisterAggregatedClientUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksregisteraggregatedclientunknown)
# KsPinRegisterAggregatedClientUnknown function

## Description

This inline function is a wrapper for [KsRegisterAggregatedClientUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksregisteraggregatedclientunknown).

## Parameters

### `Pin` [in]

A pointer to a [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin) structure.

### `ClientUnknown` [in]

A pointer to an **IUnknown** interface.

## Return value

**KsPinRegisterAggregatedClientUnknown** returns the newly created aggregate object.

## Remarks

This inline function only performs a typecast and then calls [KsRegisterAggregatedClientUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksregisteraggregatedclientunknown).

## See also

[KsRegisterAggregatedClientUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksregisteraggregatedclientunknown)
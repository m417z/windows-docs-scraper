# KsPinGetReferenceClockInterface function

## Description

The **KsPinGetReferenceClockInterface** function returns a COM style interface to the reference clock associated with *Pin*. This interface pointer will be an **IKsReferenceClock** interface.

## Parameters

### `Pin` [in]

A pointer to the [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin) structure for which to return the reference clock interface.

### `Interface` [out]

A pointer to a memory location that receives the address of an [IKsReferenceClock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nn-ks-iksreferenceclock) interface. This is a COM style interface with an associated reference count. Minidrivers must release the interface when finished with it.

## Return value

**KsPinGetReferenceClockInterface** returns STATUS_SUCCESS and deposits the address of the [IKsReferenceClock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nn-ks-iksreferenceclock) interface into *Interface* if the pin implements the clock or has received notification of the master clock through the [KSPROPERTY_STREAM_MASTERCLOCK](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-stream-masterclock) property. Returns STATUS_DEVICE_NOT_READY if the pin has not yet received notification of the master clock.

## Remarks

The most common time to call **KsPinGetReferenceClockInterface** is in a state transition to KSSTATE_ACQUIRE.

See [AVStream Clocks](https://learn.microsoft.com/windows-hardware/drivers/stream/avstream-clocks) for more information about using the [IKsReferenceClock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nn-ks-iksreferenceclock) interface that this routine returns.

## See also

[IKsControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nn-ksproxy-ikscontrol)

[IKsReferenceClock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nn-ks-iksreferenceclock)

[KsFilterGetOuterUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfiltergetouterunknown)

[KsGetOuterUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetouterunknown)

[KsPinGetConnectedFilterInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspingetconnectedfilterinterface)

[KsPinGetConnectedPinInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspingetconnectedpininterface)

[KsPinSetPinClockTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinsetpinclocktime)

[KsRegisterAggregatedClientUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksregisteraggregatedclientunknown)
# KsPinGetConnectedPinInterface function

## Description

The **KsPinGetConnectedPinInterface** function queries the pin to which *Pin* is connected for a COM style interface.

## Parameters

### `Pin` [in]

A pointer to a [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin) structure. AVStream queries the pin connected to *Pin* for the requested interface.

### `InterfaceId` [in]

A pointer to the GUID specifying the interface type to be obtained. A **QueryInterface** call is automatically performed for this interface.

### `Interface` [out]

A pointer to a pointer that AVStream sets to the location of the COM interface.

## Return value

**KsPinGetConnectedPinInterface** returns STATUS_SUCCESS or STATUS_NOINTERFACE. See details below.

## Remarks

*Interface* has a corresponding reference count and **must** be released by the caller as in COM.

This routine returns STATUS_SUCCESS if the interface exists on the connected pin or in the AVStream thunk. If STATUS_SUCCESS is returned, AVStream deposits the interface pointer into **Interface*. Otherwise, the routine returns STATUS_NOINTERFACE. This corresponds to the COM HRESULT E_NOINTERFACE.

By default, objects support the **IUnknown** interface and the [IKsControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nn-ksproxy-ikscontrol) interface. If the connected pin is an AVStream pin, the query and the returned interface pointer are direct calls to the other driver. If, on the other hand, the connected pin does not belong to an AVStream driver, a thunk is created that provides *IKsControl* support through synchronous calls to the driver containing the connected pin, using [IoCallDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver).

The most common usage of **KsPinGetConnectedPinInterface** is to acquire the control interface for the connected pin. This control interface can be used for property, method, or event calls down to the connected pin or can query for interfaces that have been aggregated onto the connected pin. If the connected pin is an AVStream pin; AVStream only provides thunking for **IKsControl** and **IUnknown** for non-AVStream pins.

The thunk is only created if *Pin* is a source pin; thus, the calls only work if one or more of the following is true:

* The connection is intra-AVStream (*Pin*'s connected pin is an AVStream pin).
* *Pin* is a source pin.

Otherwise, STATUS_UNSUCCESSFUL is returned.

## See also

[IKsControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nn-ksproxy-ikscontrol)

[IKsReferenceClock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nn-ks-iksreferenceclock)

[KsFilterGetOuterUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfiltergetouterunknown)

[KsGetOuterUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetouterunknown)

[KsPinGetConnectedFilterInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspingetconnectedfilterinterface)

[KsPinGetReferenceClockInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspingetreferenceclockinterface)

[KsRegisterAggregatedClientUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksregisteraggregatedclientunknown)
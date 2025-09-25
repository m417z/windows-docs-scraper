# KsPinGetConnectedFilterInterface function

## Description

The **KsPinGetConnectedFilterInterface** function queries the filter to which *Pin* is connected in order to obtain a pointer to a COM interface.

## Parameters

### `Pin` [in]

A pointer to a [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin) structure. The filter to which this pin is attached is queried for the requested interface.

### `InterfaceId` [in]

A pointer to a GUID representing the interface ID for the interface to obtain. A **QueryInterface** call is automatically performed for this interface.

### `Interface` [out]

A pointer to a PVOID. As in COM, the resulting interface pointer is deposited into **Interface*. This interface has a corresponding reference count and *must* be released by the caller as in COM.

## Return value

**KsPinGetConnectedFilterInterface** returns STATUS_SUCCESS if the interface exists on the connected filter or in the AVStream thunk. If STATUS_SUCCESS is returned, the interface pointer is deposited into **Interface*. Otherwise, it returns STATUS_NOINTERFACE. Note that this corresponds to the COM HRESULT E_NOINTERFACE.

## Remarks

By default, objects support the **IUnknown** interface and the [IKsControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nn-ksproxy-ikscontrol) interface. If the filter and connected pin are AVStream objects, the query and the returned interface pointer are direct calls to the other driver. However, if the connected pin and filter do not belong to an AVStream driver, a thunk is created that provides IKsControl support through synchronous calls to the driver containing the filter, using [IoCallDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver).

The most common usage of **KsPinGetConnectedFilterInterface** is to acquire the control interface for the filter to which *Pin* attaches. This control interface can then be used for property, method, or event calls down to the connected pin, or can query for interfaces that have been aggregated onto the connected filter. (If the connected filter is an AVStream filter; AVStream provides thunking only for [IKsControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nn-ksproxy-ikscontrol) and **IUnknown** for non-AVStream filters).

The thunk is created only if *Pin* is a source pin; thus, the calls only work if one or more of the following is true:

* The connection is intra-AVStream (*Pin*'s connected pin is an AVStream pin).
* *Pin* is a source pin.

Otherwise, STATUS_UNSUCCESSFUL is returned.

## See also

[IKsControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nn-ksproxy-ikscontrol)

[IKsReferenceClock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nn-ks-iksreferenceclock)

[KsFilterGetOuterUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfiltergetouterunknown)

[KsGetOuterUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetouterunknown)

[KsPinGetConnectedPinInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspingetconnectedpininterface)

[KsPinGetReferenceClockInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspingetreferenceclockinterface)

[KsRegisterAggregatedClientUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksregisteraggregatedclientunknown)
# KsGetOuterUnknown function

## Description

The **KsGetOuterUnknown** function returns the outer **IUnknown** of a given AVStream object.

## Parameters

### `Object` [in]

A pointer to an AVStream object for which to return the outer **IUnknown** interface.

## Return value

**KsGetOuterUnknown** returns a pointer to the outer **IUnknown** interface of *Object*. The client can then call the **QueryInterface** method to determine whether the component supports a given interface.

## Remarks

Minidrivers should not call this function directly. Instead, use one of the inline versions that perform automatic typecasting: [KsDeviceGetOuterUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksdevicegetouterunknown), [KsFilterFactoryGetOuterUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfilterfactorygetouterunknown), [KsFilterGetOuterUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfiltergetouterunknown), [KsPinGetOuterUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspingetouterunknown).

Minidrivers using this function must include *kcom.h* and use a C++ compiler.

## See also

[IKsControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nn-ksproxy-ikscontrol)

[KsDeviceGetOuterUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksdevicegetouterunknown)

[KsFilterFactoryGetOuterUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfilterfactorygetouterunknown)

[KsFilterGetOuterUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfiltergetouterunknown)

[KsPinGetOuterUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspingetouterunknown)

[KsRegisterAggregatedClientUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksregisteraggregatedclientunknown)
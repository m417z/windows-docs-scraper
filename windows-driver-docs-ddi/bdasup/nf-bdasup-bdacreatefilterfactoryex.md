# BdaCreateFilterFactoryEx function

## Description

The **BdaCreateFilterFactoryEx** function adds the specified filter descriptor as a filter factory to the specified device and associates the filter factory with the specified BDA template topology.

## Parameters

### `pKSDevice` [in]

Points to the BDA device to which to add the filter factory with associated BDA template topology.

### `pFilterDescriptor` [in]

Points to a [KSFILTER_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter_descriptor) structure that describes a filter for the BDA device. Note that not all of the template pin and node types may be exposed as pin and node factories when the filter is first initialized.

### `pBdaFilterTemplate` [in]

Points to a [BDA_FILTER_TEMPLATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bdasup/ns-bdasup-_bda_filter_template) structure that describes a BDA template topology.

### `ppKSFilterFactory` [out, optional]

Points to a buffer that receives a pointer to a [KSFILTERFACTORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilterfactory) structure for the newly created filter factory.

## Return value

Returns STATUS_SUCCESS or an appropriate error code.

## Remarks

A BDA minidriver calls the **BdaCreateFilterFactoryEx** function to add a filter factory with an associated BDA template topology to a device and to register all of the topology's static template structures with the BDA support library (*BdaSup.sys*). The BDA support library can then handle the following method and property calls:

* [KSMETHODSETID_BdaChangeSync](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethodsetid-bdachangesync)
* [KSMETHODSETID_BdaDeviceConfiguration](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethodsetid-bdadeviceconfiguration)
* [KSPROPSETID_BdaTopology](https://learn.microsoft.com/windows-hardware/drivers/stream/kspropsetid-bdatopology)

A BDA minidriver calls **BdaCreateFilterFactoryEx** rather than the [BdaCreateFilterFactory](https://learn.microsoft.com/windows-hardware/drivers/ddi/bdasup/nf-bdasup-bdacreatefilterfactory) function whenever it requires a pointer to the newly created KSFILTERFACTORY. The **BdaCreateFilterFactory** function also creates a filter factory but doesn't return it to the caller. The BDA minidriver requires a pointer to the newly created KSFILTERFACTORY if the minidriver must call the [_KsEdit](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-_ksedit) function to edit KSFILTERFACTORY.

## See also

[BDA_FILTER_TEMPLATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bdasup/ns-bdasup-_bda_filter_template)

[BdaCreateFilterFactory](https://learn.microsoft.com/windows-hardware/drivers/ddi/bdasup/nf-bdasup-bdacreatefilterfactory)

[KSDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice)

[KSFILTERFACTORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilterfactory)

[KSFILTER_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter_descriptor)

[KSMETHODSETID_BdaChangeSync](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethodsetid-bdachangesync)

[KSMETHODSETID_BdaDeviceConfiguration](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethodsetid-bdadeviceconfiguration)

[KSPROPSETID_BdaTopology](https://learn.microsoft.com/windows-hardware/drivers/stream/kspropsetid-bdatopology)

[_KsEdit](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-_ksedit)
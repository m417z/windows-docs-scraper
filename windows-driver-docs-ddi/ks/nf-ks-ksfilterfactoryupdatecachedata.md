## Description

The KsFilterFactoryUpdateCacheData function updates the FilterData registry key and the Medium cache (a set of registry keys) for a given filter factory.

## Parameters

### `FilterFactory` [in]

The [**KSFILTERFACTORY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilterfactory) for which to update FilterData and Medium cache in the registry.

### `FilterDescriptor` [in, optional]

An optional [**KSFILTER_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter_descriptor) for which the FilterData key and Medium cache will be updated. If **NULL**, *FilterFactory*'s descriptor is used instead. Provide if the filter factory uses dynamic pins and needs to update information for pins that have not yet been instantiated.

## Return value

**KsFilterFactoryUpdateCacheData** returns STATUS_SUCCESS or a failure code, indicating whether the relevant registry information was successfully updated. It returns STATUS_INVALID_PARAMETER if no device interface is found that corresponds to the categories passed in the filter descriptor.

## Remarks

This function updates the FilterData key and Medium cache for all categories specified in *FilterDescriptor*. If *FilterDescriptor* is **NULL**, the FilterData and Medium cache are updated for all categories specified in *FilterFactory*'s [**KSFILTER_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter_descriptor) member.

[KsRegisterFilterWithNoKSPins](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksregisterfilterwithnokspins) provides similar functionality, but should not be used if two instances of [**KSFILTER_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter_descriptor) under the same [**KSDEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice) are registered in the same category, and differ only in reference GUID. In this case, **KsRegisterFilterWithNoKSPins** updates data only for the first, even though the second may have been specified.

Do not use this routine in place of **KsRegisterFilterWithNoKSPins** for filters with no KS pins, such as analog style crossbars. Use this routine only for a specific filter for which the minidriver is passing the corresponding filter factory.

In addition, **KsRegisterFilterWithNoKSPins** only allows one medium per registered pin. This may not be sufficient for a BDA minidriver.

For more information, see [AVStream Object Hierarchy](https://learn.microsoft.com/windows-hardware/drivers/stream/avstream-object-hierarchy).

The KsFilterFactoryUpdateCacheData function can only be called in PASSIVE_LEVEL.

## See also

[**KSFILTERFACTORY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilterfactory)

[**KSFILTER_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter_descriptor)

[KsRegisterFilterWithNoKSPins](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksregisterfilterwithnokspins)
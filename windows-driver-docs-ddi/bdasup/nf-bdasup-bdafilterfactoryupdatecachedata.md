## Description

The **BdaFilterFactoryUpdateCacheData** function updates the pin data cache for an instance of a filter.

## Parameters

### `pFilterFactory` [in]

Points to the [KSFILTERFACTORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilterfactory) for which to update the pin data cache.

### `pFilterDescriptor` [in, optional]

Points to an optional [KSFILTER_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter_descriptor) for which the pin data cache will be updated. If **NULL**, *pFilterFactory*'s descriptor is used instead. This parameter enables dynamic pin creation, that is, pin creation that occurs after a filter's create dispatch routine completes.

## Return value

Returns STATUS_SUCCESS or an appropriate error code. Returns STATUS_INVALID_PARAMETER if no device interface is found that corresponds to the categories passed in the filter descriptor.

## Remarks

A BDA minidriver calls the **BdaFilterFactoryUpdateCacheData** function to update the pin data cache for all pins specified at *pFilterDescriptor*. In this call, the BDA minidriver typically passes the **pFilterDescriptor** member of a [BDA_FILTER_TEMPLATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bdasup/ns-bdasup-_bda_filter_template) structure that describes the template topology for the BDA filter to *pFilterDescriptor*. If *pFilterDescriptor* is **NULL**, the cached information will be updated for all pin factories specified at *pFilterFactory*'s KSFILTER_DESCRIPTOR member. For information about the pin data cache, see [Caching Pin Information for DirectShow](https://learn.microsoft.com/windows-hardware/drivers/stream/caching-pin-information-for-directshow).

The [KsRegisterFilterWithNoKSPins](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksregisterfilterwithnokspins) function provides similar functionality but only allows one medium per registered pin. This may not be sufficient for a BDA minidriver.

## See also

[BDA_FILTER_TEMPLATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bdasup/ns-bdasup-_bda_filter_template)

[KSFILTERFACTORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilterfactory)

[KSFILTER_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter_descriptor)

[KsRegisterFilterWithNoKSPins](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksregisterfilterwithnokspins)
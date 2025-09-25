# IDVBTLocator::get_OtherFrequencyInUse

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_OtherFrequencyInUse** method indicates whether the frequency is being used by another DVB-T broadcaster.

## Parameters

### `OtherFrequencyInUseVal` [out]

Receives that value VARIANT_TRUE if the frequency is being used by another DVB-T broadcaster, or VARIANT_FALSE otherwise.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## See also

[IDVBTLocator Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-idvbtlocator)
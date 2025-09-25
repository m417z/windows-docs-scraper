# ITuningSpace::get_FrequencyMapping

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_FrequencyMapping** method retrieves the frequency mapping previously created by the network provider by a call to **put_FrequencyMapping**.

## Parameters

### `pMapping` [out]

Pointer to a variable that receives the frequency mappings created by the Network Provider filter.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## Remarks

The returned **BSTR** is treated as a binary blob. It is expected to contain embedded **NULL** values, and it may be formatted internally by the [BDA Network Provider](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/bda-network-provider-filter).

The caller must release the returned **BSTR** by calling **SysFreeString**.

## See also

[ITuningSpace Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ituningspace)
# ITuningSpace::put_FrequencyMapping

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_FrequencyMapping** method creates a frequency/channel map, frequency/transponder map, or whatever other mapping from carrier frequencies to frequency identifiers is appropriate for the tuning space.

## Parameters

### `Mapping` [in]

**BSTR** that contains the frequency mappings.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## Remarks

This method is used by the network provider to store a string that contains the frequency mappings.

## See also

[ITuningSpace Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ituningspace)
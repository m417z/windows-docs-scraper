# IAnalogTVTuningSpace::put_CountryCode

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_CountryCode** method sets the country/region code of the tuning space (based on TAPI country/region codes).

## Parameters

### `NewCountryCodeVal` [in]

The country/region code.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## Remarks

The tuner can use the country/region code to locate a likely channel for frequency mapping.

## See also

[IAnalogTVTuningSpace Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ianalogtvtuningspace)
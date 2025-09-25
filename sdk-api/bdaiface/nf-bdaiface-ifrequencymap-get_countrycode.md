# IFrequencyMap::get_CountryCode

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_CountryCode** method returns the country/region code the Network Provider is currently using. The country/region code determines which frequency table the Network Provider loads.

## Parameters

### `pulCountryCode` [out]

Pointer to a variable that receives the country/region code.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

For a list of country/region codes, see [Country/Region Assignments](https://learn.microsoft.com/windows/desktop/DirectShow/country-region-assignments).

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IFrequencyMap Interface](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ifrequencymap)
# IFrequencyMap::get_CountryCodeList

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_CountryCodeList** method returns a list of all the country/region codes for which the Network Provider has a frequency table.

## Parameters

### `pulCount` [out]

Pointer to a variable that receives the number of country/region codes.

### `ppulList` [out]

Pointer to a variable that receives the address of an array of size *pulCount*, allocated by the method. The array contains a list of the country/region codes. The caller must free the array by calling **CoTaskMemFree**.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

For a list of country/region codes, see [Country/Region Assignments](https://learn.microsoft.com/windows/desktop/DirectShow/country-region-assignments).

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IFrequencyMap Interface](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ifrequencymap)
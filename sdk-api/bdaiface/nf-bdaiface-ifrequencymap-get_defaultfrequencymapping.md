# IFrequencyMap::get_DefaultFrequencyMapping

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_DefaultFrequencyMapping** method returns the default frequency table for a given country/region code. This method returns the frequency table, but does not set the country/region code on Network Provider. The Network Provider continues to use the same frequency table it was using before the method was called.

## Parameters

### `ulCountryCode` [in]

Specifies the country/region code.

### `pulCount` [out]

Pointer to a variable that receives the size of the frequency table.

### `ppulList` [out]

Pointer to a variable that receives the address of the frequency table. The frequency table is an array of size *pulCount*, allocated by the method. The caller must free the array by calling **CoTaskMemFree**.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

Each entry in the frequency table is a tuning frequency, in kilohertz (kHz).

For a list of country/region codes, see [Country/Region Assignments](https://learn.microsoft.com/windows/desktop/DirectShow/country-region-assignments).

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IFrequencyMap Interface](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ifrequencymap)
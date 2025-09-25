# IFrequencyMap::put_CountryCode

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_CountryCode** method sets the country/region code on the Network Provider filter.

## Parameters

### `ulCountryCode` [in]

Specifies the country/region code.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

If the method succeeds, the Network Provider loads the frequency table for the specified country/region code. It uses this table in all subsequent calls to [IScanningTuner](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-iscanningtuner) methods.

If the country/region code does not match an existing frequency table, the method fails and the Network Provider continues to use the previous table. However, it stores the new country/region code, and the application can create a new frequency table by calling the **put_FrequencyMapping** method. This behavior enables an application to define new country/region codes with new frequency tables.

For a list of existing country/region codes, see [Country/Region Assignments](https://learn.microsoft.com/windows/desktop/DirectShow/country-region-assignments).

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IFrequencyMap Interface](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ifrequencymap)
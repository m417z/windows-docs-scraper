# IMSVidAnalogTuner::get_CountryCode

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_CountryCode** method retrieves the tuner's country/region code.

## Parameters

### `lcc` [out]

Pointer to a variable that receives the country/region code.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

Do not confuse the international country/region code with the LCID. The country/region code establishes the mapping between channel numbers and frequencies.

## See also

[IAMTuner::get_CountryCode](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamtuner-get_countrycode)

[IMSVidAnalogTuner Interface](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsvidanalogtuner)

[IMSVidAnalogTuner::put_CountryCode](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidanalogtuner-put_countrycode)

[International Analog TV Tuning](https://learn.microsoft.com/windows/desktop/DirectShow/international-analog-tv-tuning)
# IMSVidAnalogTuner::put_CountryCode

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_CountryCode** method specifies the tuner's country/region code.

## Parameters

### `lcc` [in]

Specifies the international country/region code.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

Do not confuse the international country/region code with the LCID. The country/region code establishes the mapping between channel numbers and frequencies.

## See also

[IAMTuner::put_CountryCode](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamtuner-put_countrycode)

[IMSVidAnalogTuner Interface](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsvidanalogtuner)

[IMSVidAnalogTuner::get_CountryCode](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidanalogtuner-get_countrycode)

[International Analog TV Tuning](https://learn.microsoft.com/windows/desktop/DirectShow/international-analog-tv-tuning)
# IBDA_FrequencyFilter::put_Frequency

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_Frequency** method specifies the frequency.

## Parameters

### `ulFrequency` [in]

Specifies the frequency. The units are 1 Hz x the frequency multiplier, where the *frequency multiplier* is the value returned by the [IBDA_FrequencyFilter::get_FrequencyMultiplier](https://learn.microsoft.com/windows/desktop/api/bdaiface/nf-bdaiface-ibda_frequencyfilter-get_frequencymultiplier) method. The default frequency multiplier is 1000, so the default units are kilohertz (kHz).

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

Frequencies for DVB-S, DVB-T, and ATSC should all be expressed in kilohertz and therefore the default frequency multiplier should not be changed.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IBDA_FrequencyFilter Interface](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_frequencyfilter)

[IBDA_FrequencyFilter::get_Frequency](https://learn.microsoft.com/windows/desktop/api/bdaiface/nf-bdaiface-ibda_frequencyfilter-get_frequency)

[IBDA_FrequencyFilter::put_FrequencyMultiplier](https://learn.microsoft.com/windows/desktop/api/bdaiface/nf-bdaiface-ibda_frequencyfilter-put_frequencymultiplier)
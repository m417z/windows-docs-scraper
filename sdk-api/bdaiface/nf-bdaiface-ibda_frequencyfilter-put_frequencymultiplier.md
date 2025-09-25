# IBDA_FrequencyFilter::put_FrequencyMultiplier

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_FrequencyMultiplier** method specifies the frequency multiplier. The frequency multiplier determines the frequency units for the methods on this interface. The default value is 1000, meaning that frequencies are expressed in kilohertz (kHz).

## Parameters

### `ulMultiplier` [in]

Specifies the multiplier.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

Since frequencies for DVB-S, DVB-T, and ATSC should all be expressed in kilohertz, the default frequency multiplier should never be changed.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IBDA_FrequencyFilter Interface](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_frequencyfilter)

[IBDA_FrequencyFilter::get_FrequencyMultiplier](https://learn.microsoft.com/windows/desktop/api/bdaiface/nf-bdaiface-ibda_frequencyfilter-get_frequencymultiplier)

[IBDA_FrequencyFilter::put_Frequency](https://learn.microsoft.com/windows/desktop/api/bdaiface/nf-bdaiface-ibda_frequencyfilter-put_frequency)
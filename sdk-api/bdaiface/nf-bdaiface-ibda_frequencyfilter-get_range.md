# IBDA_FrequencyFilter::get_Range

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The get_Range method retrieves the tuner range. The *tuner range* is the frequency domain on which to find a particular carrier frequency

## Parameters

### `pulRange` [out]

Pointer that receives the tuner range. The units are 1 Hz x the frequency multiplier, where the *frequency multiplier* is the value returned by the [IBDA_FrequencyFilter::get_FrequencyMultiplier](https://learn.microsoft.com/windows/desktop/api/bdaiface/nf-bdaiface-ibda_frequencyfilter-get_frequencymultiplier) method. The default frequency multiplier is 1000, so the default units are kilohertz (kHz). A value of -1 for this parameter indicates that the tuner range is not set. A value of 0 for this parameter indicates that the tuner range is undefined.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IBDA_FrequencyFilter Interface](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_frequencyfilter)

[IBDA_FrequencyFilter::get_FrequencyMultiplier](https://learn.microsoft.com/windows/desktop/api/bdaiface/nf-bdaiface-ibda_frequencyfilter-get_frequencymultiplier)

[IBDA_FrequencyFilter::put_Range](https://learn.microsoft.com/windows/desktop/api/bdaiface/nf-bdaiface-ibda_frequencyfilter-put_range)
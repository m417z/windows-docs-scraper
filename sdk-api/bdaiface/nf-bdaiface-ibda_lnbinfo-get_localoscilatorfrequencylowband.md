# IBDA_LNBInfo::get_LocalOscilatorFrequencyLowBand

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_LocalOscilatorFrequencyLowBand** method retrieves the low band of the local oscillator frequency.

## Parameters

### `pulLOFLow` [out]

Pointer that receives the low band of the frequency. The units are 1 Hz x the frequency multiplier, where the *frequency multiplier* is the value returned by the [IBDA_FrequencyFilter::get_FrequencyMultiplier](https://learn.microsoft.com/windows/desktop/api/bdaiface/nf-bdaiface-ibda_frequencyfilter-get_frequencymultiplier) method. The default frequency multiplier is 1000, so the default units are kilohertz (kHz).

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IBDA_LNBInfo Interface](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_lnbinfo)

[IBDA_LNBInfo::put_LocalOscilatorFrequencyLowBand](https://learn.microsoft.com/windows/desktop/api/bdaiface/nf-bdaiface-ibda_lnbinfo-put_localoscilatorfrequencylowband)
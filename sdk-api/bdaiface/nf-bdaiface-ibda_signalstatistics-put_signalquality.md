# IBDA_SignalStatistics::put_SignalQuality

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_SignalQuality** method specifies the quality of the signal.

## Parameters

### `lPercentQuality` [in]

Long integer that specifies the quality of the signal as a percentage. 100 indicates best quality and 0 indicates worst quality.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IBDA_SignalStatistics Interface](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_signalstatistics)

[IBDA_SignalStatistics::get_SignalQuality](https://learn.microsoft.com/windows/desktop/api/bdaiface/nf-bdaiface-ibda_signalstatistics-get_signalquality)
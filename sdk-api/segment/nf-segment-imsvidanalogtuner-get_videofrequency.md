# IMSVidAnalogTuner::get_VideoFrequency

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_VideoFrequency** method retrieves the tuner's video frequency for testing purposes.

## Parameters

### `lcc` [out]

Pointer to a variable that receives the video frequency, in hertz (Hz).

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

This method is intended for diagnostic and testing purposes.

## See also

[IAMTVTuner::get_VideoFrequency](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamtvtuner-get_videofrequency)

[IMSVidAnalogTuner Interface](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsvidanalogtuner)
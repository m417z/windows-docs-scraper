# IBDA_AutoDemodulateEx::get_SupportedVideoFormats

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_SupportedVideoFormats** method retrieves the video formats that are supported by the demodulator.

## Parameters

### `pulAMTunerModeType` [out]

Pointer to a variable that receives a mask that indicates the frequency ranges that are supported by the BDA device filter. For a list of valid mask bits, see [AMTunerModeType Enumeration](https://learn.microsoft.com/previous-versions/ms778981(v=vs.85)).

### `pulAnalogVideoStandard` [out]

Pointer to a variable that receives a mask that indicates the analog television signal formats that are supported by the BDA device filter. For a list of valid mask bits, see [AnalogVideoStandard Enumeration](https://learn.microsoft.com/windows/win32/api/strmif/ne-strmif-analogvideostandard).

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## See also

[IBDA_AutoDemodulateEx Interface](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_autodemodulateex)
# ITunerCap::get_SupportedVideoFormats

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005.

The **get_SupportedVideoFormats** method retrieves the video formats that are supported by the TV tuner.

## Parameters

### `pulAMTunerModeType` [out]

Receives a bitmask that indicates the frequency ranges that are supported by the BDA device filter. For a list of valid mask bits, see [AMTunerModeType Enumeration](https://learn.microsoft.com/previous-versions/ms778981(v=vs.85)).

### `pulAnalogVideoStandard` [out]

Receives a bitmask that indicates the analog television signal formats that are supported by the BDA device filter. For a list of valid mask bits, see [AnalogVideoStandard Enumeration](https://learn.microsoft.com/windows/win32/api/strmif/ne-strmif-analogvideostandard).

## Return value

When the method succeeds, it returns S_OK. Otherwise it returns an **HRESULT** error code.

## See also

[ITunerCap Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-itunercap)
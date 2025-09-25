# MP_PARAMINFO structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `MP_PARAMINFO` structure contains information about a parameter.

## Members

### `mpType`

Member of the [MP_TYPE](https://learn.microsoft.com/previous-versions/windows/desktop/api/medparam/ne-medparam-mp_type) enumeration that specifies the valid data type for this parameter.

### `mopCaps`

Bitwise combination of one or more [Parameter Capabilities Flags](https://learn.microsoft.com/windows/desktop/DirectShow/parameter-capabilities-flags) that specify which envelope curves are supported. For Boolean and enumeration parameters, only MP_CAPS_CURVE_JUMP is valid.

### `mpdMinValue`

Minimum value of the parameter. Used only for parameters with numeric values.

### `mpdMaxValue`

Maximum value of the parameter. Used only for parameters with numeric values.

### `mpdNeutralValue`

Default or "neutral" value of the parameter.

### `szUnitText`

NULL-terminated wide-character string that contains the name of the units for the parameter.

### `szLabel`

NULL-terminated wide-character string that contains the name of the parameter.

## Remarks

The **szUnitText** and **szLabel** members always contain English-language strings. For international support, use the [IMediaParamInfo::GetParamText](https://learn.microsoft.com/windows/desktop/api/medparam/nf-medparam-imediaparaminfo-getparamtext) method.

## See also

[DMO Structures](https://learn.microsoft.com/windows/desktop/DirectShow/dmo-structures)
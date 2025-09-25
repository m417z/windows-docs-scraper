# MP_TYPE enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `MP_TYPE` enumeration specifies the data type for a parameter.

## Constants

### `MPT_INT:0`

Value is a signed 32-bit integer.

### `MPT_FLOAT`

Value is a 32-bit IEEE floating-point value.

### `MPT_BOOL`

Value is Boolean. Use the following constants for Boolean parameters:

### `MPT_ENUM`

Value is taken from a set of consecutive integers.

### `MPT_MAX`

Reserved.

## Remarks

To reduce type conversions at run time, all parameters have 32-bit float values, defined as type **MP_DATA**. The members of this enumeration specify how a given parameter should be interpreted.

## See also

[DMO Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/dmo-enumerated-types)

[MP_PARAMINFO](https://learn.microsoft.com/previous-versions/windows/desktop/api/medparam/ns-medparam-mp_paraminfo)
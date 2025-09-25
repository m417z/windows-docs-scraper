# MP_CURVE_TYPE enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `MP_CURVE_TYPE` enumeration defines the curve that a media parameter follows within an envelope segment.

## Constants

### `MP_CURVE_JUMP:0x1`

No interpolation. Jump to the next point.

### `MP_CURVE_LINEAR:0x2`

Linear interpolation.

### `MP_CURVE_SQUARE:0x4`

Parabolic curve.

### `MP_CURVE_INVSQUARE:0x8`

Inverse square curve.

### `MP_CURVE_SINE:0x10`

Sine curve.

## Remarks

The following table lists the defined curves and their mathematical equivalents.

| Value | Curve to Fit | Range |
| --- | --- | --- |
| MP_CURVE_LINEAR | *y* = *x* | 0.0 – 1.0 |
| MP_CURVE_SQUARE | *y* = *x*^2 | 0.0 – 1.0 |
| MP_CURVE_INVSQUARE | *y* = 1 –*x*^2 | 0.0 – 1.0 |
| MP_CURVE_SINE | *y* = sin(*x*) | –π/2 – π/2 |

For Boolean and enumeration parameters, only MP_CURVE_JUMP is valid.

## See also

[DMO Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/dmo-enumerated-types)

[MP_ENVELOPE_SEGMENT](https://learn.microsoft.com/previous-versions/windows/desktop/api/medparam/ns-medparam-mp_envelope_segment)
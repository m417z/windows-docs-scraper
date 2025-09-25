# MP_ENVELOPE_SEGMENT structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `MP_ENVELOPE_SEGMENT` structure defines an envelope segment used by an envelope-following parameter.

## Members

### `rtStart`

Start time of the segment, relative to the time stamp on the first buffer, in 100-nanosecond units.

### `rtEnd`

Stop time of the segment, relative to the time stamp on the first buffer, in 100-nanosecond units.

### `valStart`

Initial value of the parameter, at the start of the segment.

### `valEnd`

Final value of the parameter, at the end of the segment.

### `iCurve`

Member of the **MP_CURVE_TYPE** enumerated type that specifies the curve followed by the parameter.

### `flags`

Specifies one of the following flags.

| Value | Meaning |
| --- | --- |
| **MPF_ENVLP_STANDARD**<br><br>0x0000 | Use all the information provided with the envelope segment. |
| **MPF_ENVLP_BEGIN_CURRENTVAL**<br><br>0x0001 | Ignore the specified start value. Start from the current value. |
| **MPF_ENVLP_BEGIN_NEUTRALVAL**<br><br>0x0002 | Ignore the specified start value. Start from the neutral value. (See [MP_PARAMINFO](https://learn.microsoft.com/previous-versions/windows/desktop/api/medparam/ns-medparam-mp_paraminfo).) |

## See also

[DMO Structures](https://learn.microsoft.com/windows/desktop/DirectShow/dmo-structures)
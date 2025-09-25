# AMTunerModeType enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Specifies the frequency of a TV tuner (cable or antenna).

## Constants

### `AMTUNER_MODE_DEFAULT:0`

Indicates default tuner mode.

### `AMTUNER_MODE_TV:0x1`

Indicates TV tuner mode.

### `AMTUNER_MODE_FM_RADIO:0x2`

Indicates FM radio tuner mode.

### `AMTUNER_MODE_AM_RADIO:0x4`

Indicates AM radio tuner mode.

### `AMTUNER_MODE_DSS:0x8`

Indicates Digital Satellite Service (DSS) tuner mode.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)
# eAVAudioChannelConfig enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Specifies the speaker configuration for the audio channels in the audio bit stream. This enumeration is used with the [AVAudioChannelConfig](https://learn.microsoft.com/windows/desktop/DirectShow/avaudiochannelconfig-property) property.

## Constants

### `eAVAudioChannelConfig_FRONT_LEFT:0x1`

Front left

### `eAVAudioChannelConfig_FRONT_RIGHT:0x2`

Front right

### `eAVAudioChannelConfig_FRONT_CENTER:0x4`

Front center

### `eAVAudioChannelConfig_LOW_FREQUENCY:0x8`

Low frequency effect (LFE)

### `eAVAudioChannelConfig_BACK_LEFT:0x10`

Back left

### `eAVAudioChannelConfig_BACK_RIGHT:0x20`

Back right

### `eAVAudioChannelConfig_FRONT_LEFT_OF_CENTER:0x40`

Front, left of center

### `eAVAudioChannelConfig_FRONT_RIGHT_OF_CENTER:0x80`

Front, right of center

### `eAVAudioChannelConfig_BACK_CENTER:0x100`

Back center

### `eAVAudioChannelConfig_SIDE_LEFT:0x200`

Side left

### `eAVAudioChannelConfig_SIDE_RIGHT:0x400`

Side right

### `eAVAudioChannelConfig_TOP_CENTER:0x800`

Top center

### `eAVAudioChannelConfig_TOP_FRONT_LEFT:0x1000`

Top, front left

### `eAVAudioChannelConfig_TOP_FRONT_CENTER:0x2000`

Top, front center

### `eAVAudioChannelConfig_TOP_FRONT_RIGHT:0x4000`

Top, front right

### `eAVAudioChannelConfig_TOP_BACK_LEFT:0x8000`

Top, back left

### `eAVAudioChannelConfig_TOP_BACK_CENTER:0x10000`

Top, back center

### `eAVAudioChannelConfig_TOP_BACK_RIGHT:0x20000`

Top, back right

## Remarks

These values correspond to the flags used for the **dwChannelMask** member of the [WAVEFORMATEXTENSIBLE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd390971(v=vs.85)) structure.

## See also

[Codec API Enumerations](https://learn.microsoft.com/windows/desktop/DirectShow/codec-api-enumerations)

[ICodecAPI Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icodecapi)
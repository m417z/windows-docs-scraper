# eAVDSPLoudnessEqualization enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Specifies whether loudness equalization is enabled in an audio decoder or digital signal processor (DSP). This enumeration is used with the [AVDSPLoudnessEqualization](https://learn.microsoft.com/windows/desktop/DirectShow/avdsploudnessequalization-property) property.

## Constants

### `eAVDSPLoudnessEqualization_OFF:0`

Loudness equalization is disabled.

### `eAVDSPLoudnessEqualization_ON:1`

Loudness equalization is enabled.

### `eAVDSPLoudnessEqualization_AUTO:2`

The decoder or DSP automatically selects the equalization mode.

## Remarks

Loudness equalization is a DSP process that maintains a consistent volume level when the audio stream changes.

## See also

[Codec API Enumerations](https://learn.microsoft.com/windows/desktop/DirectShow/codec-api-enumerations)

[ICodecAPI Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icodecapi)
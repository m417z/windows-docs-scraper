# eAVDecAudioDualMonoReproMode enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Specifies how the decoder reproduces dual mono audio. This enumeration is used with the [AVDecAudioDualMonoReproMode](https://learn.microsoft.com/windows/desktop/DirectShow/avdecaudiodualmonorepromode-property) property.

## Constants

### `eAVDecAudioDualMonoReproMode_STEREO:0`

Output channel 1 (Ch1) to the left speaker and channel 2 (Ch2) to the right speaker.

### `eAVDecAudioDualMonoReproMode_LEFT_MONO:1`

Output Ch1 to the left and right speakers.

### `eAVDecAudioDualMonoReproMode_RIGHT_MONO:2`

Output Ch2 to the left and right speakers.

### `eAVDecAudioDualMonoReproMode_MIX_MONO:3`

Mix Ch1 and Ch2 and output the mix to the left and right speakers.

## See also

[Codec API Enumerations](https://learn.microsoft.com/windows/desktop/DirectShow/codec-api-enumerations)

[ICodecAPI Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icodecapi)
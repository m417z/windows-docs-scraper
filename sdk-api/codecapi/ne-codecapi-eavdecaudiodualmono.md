# eAVDecAudioDualMono enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Specifies whether the input audio stream is stereo or dual mono. This enumeration is used with the [AVDecAudioDualMono](https://learn.microsoft.com/windows/desktop/DirectShow/avdecaudiodualmono-property) property.

## Constants

### `eAVDecAudioDualMono_IsNotDualMono:0`

The input bit stream is not dual mono.

### `eAVDecAudioDualMono_IsDualMono:1`

The input bit stream is dual mono.

### `eAVDecAudioDualMono_UnSpecified:2`

There is no indication in the bit stream whether the audio is dual mono.

## Remarks

In dual mono encoding, each channel is encoded separately. In stereo encoding, both channels are encoded together.

## See also

[Codec API Enumerations](https://learn.microsoft.com/windows/desktop/DirectShow/codec-api-enumerations)

[ICodecAPI Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icodecapi)
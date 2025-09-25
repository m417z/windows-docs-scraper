# DVD_MUA_Coeff structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The [DVD_MultichannelAudioAttributes](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-dvd_multichannelaudioattributes) structure contains an array of eight `DVD_MUA_Coeff` structures, one for each channel in the stream.

## Members

### `log2_alpha`

The mixing coefficient for this channel to channel 0.

### `log2_beta`

The mixing coefficient for this channel to channel 1.

## Remarks

The information contained in this structure reflects the mixing coefficients as authored on the digital video disc (DVD). An application cannot modify these values or otherwise use them unless it is also decoding the audio. In the typical DVD filter graph, the [DVD Navigator](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-navigator-filter) filter does not send this information to the decoder.

The alpha coefficient is used to mix to audio channel 0 and the beta coefficient is used to mix to audio channel 1. In general, the following formula calculates the mixing coefficients.

| C++ |
| --- |
| ``` Audio channel 0 = coeff[0].alpha * value[0] + coeff[1].alpha * value[1] + ...  Audio channel 1 = coeff[0].beta * value[0]  + coeff[1].beta * value[1] + ... ``` |

## See also

[DVD_AudioAttributes](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-dvd_audioattributes)

[DVD_MUA_MixingInfo](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-dvd_mua_mixinginfo)

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)
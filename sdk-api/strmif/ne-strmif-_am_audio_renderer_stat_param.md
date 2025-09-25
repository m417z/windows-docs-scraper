# _AM_AUDIO_RENDERER_STAT_PARAM enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **_AM_AUDIO_RENDERER_STAT_PARAM** enumeration specifies which performance information to retrieve from the audio renderer.

This enumeration type is used in the [IAMAudioRendererStats::GetStatParam](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamaudiorendererstats-getstatparam) method. Each enumeration member defines the meaning of the values that are returned in the *pdwParam1* and *pdwParam2* parameters of **GetStatParam**.

> [!NOTE]
> Bias-free Communication
Microsoft supports a diverse and inclusionary environment. Within this document, there are references to the word 'slave.' Microsoft's [Style Guide for Bias-Free Communications](https://learn.microsoft.com/style-guide/bias-free-communication) recognizes this as an exclusionary word. This wording is used as it is currently the wording used within the software. For consistency, this document contains this word. When this word is removed from the software, we will correct this document to be in alignment.

## Constants

### `AM_AUDREND_STAT_PARAM_BREAK_COUNT:1`

*Param1*: The cumulative number of breaks in the audio stream.

*Param2*: Not used.

### `AM_AUDREND_STAT_PARAM_SLAVE_MODE`

*Param1*: Indicates the current rate-matching mode. The value is a bitwise combination of the following:

* 0x00: No rate matching.
* 0x01: Match rates to a live source.
* 0x02: Match rates based on the rate of the incoming audio data.
* 0x04: Match rates with the filter graph's reference clock (when the clock is not provided by the audio renderer).
* 0x10: Match rates based on the time stamps of the audio samples.

*Param2*: Not used.

### `AM_AUDREND_STAT_PARAM_SILENCE_DUR`

*Param1*: The cumulative amount of silence the audio renderer has inserted, due to gaps in the time stamps of the incoming samples. The value is given in milliseconds.

*Param2*: Not used.

### `AM_AUDREND_STAT_PARAM_LAST_BUFFER_DUR`

*Param1*: The duration of the most recent audio buffer, in milliseconds.

*Param2*: Not used.

### `AM_AUDREND_STAT_PARAM_DISCONTINUITIES`

*Param1*: The cumulative number of discontinuities in the audio stream.

*Param2*: Not used.

### `AM_AUDREND_STAT_PARAM_SLAVE_RATE`

*Param1*: The sample rate that the audio renderer is matching, in samples per second.

*Param2*: Not used.

Valid only when the [DirectSound Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/directsound-renderer-filter) is matching rates to another clock or a live source.

### `AM_AUDREND_STAT_PARAM_SLAVE_DROPWRITE_DUR`

*Param1*: The amount of data dropped to stay in sync, in milliseconds.

*Param2*: Not used.

Applies only when the [Audio Renderer (WaveOut)](https://learn.microsoft.com/windows/desktop/DirectShow/audio-renderer--waveout--filter) filter is matching rates to a master clock.

### `AM_AUDREND_STAT_PARAM_SLAVE_HIGHLOWERROR`

*Param1*: The highest difference noted between the audio renderer's clock and the clock it is trying to match.

*Param2*: The lowest difference noted between the audio renderer's clock and the clock it is trying to match.

Valid only when the audio renderer is matching rates to a master clock.

### `AM_AUDREND_STAT_PARAM_SLAVE_LASTHIGHLOWERROR`

*Param1*: The last high error, in milliseconds. A *high error* occurs when the audio renderer falls behind the clock.

*Param2*: The last low error, in milliseconds. A *low error* occurs when the audio renderer runs ahead of the clock.

Valid only when the audio renderer is matching rates to a master clock.

### `AM_AUDREND_STAT_PARAM_SLAVE_ACCUMERROR`

*Param1*: The accumulated difference between the audio renderer and the master clock, including adjustments made by dropping samples or inserting gaps.

*Param2*: Not used.

Valid only when the audio renderer is matching rates to another clock or a live source.

### `AM_AUDREND_STAT_PARAM_BUFFERFULLNESS`

*Param1*: How much audio data is in the audio buffer, as a percentage.

*Param2*: Not used.

### `AM_AUDREND_STAT_PARAM_JITTER`

Not implemented.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)

[IAMAudioRendererStats Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamaudiorendererstats)
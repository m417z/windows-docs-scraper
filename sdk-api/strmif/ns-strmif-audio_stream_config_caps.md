# AUDIO_STREAM_CONFIG_CAPS structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **AUDIO_STREAM_CONFIG_CAPS** structure describes a range of audio formats. Audio compression and capture filters use this structure to describe the formats they can produce.

## Members

### `guid`

Will be set to MEDIATYPE_Audio to indicate an audio sample.

### `MinimumChannels`

Minimum number of channels.

### `MaximumChannels`

Maximum number of channels.

### `ChannelsGranularity`

Granularity of the channels. For example, the filter might specify channels 2 through 4, in steps of 2.

### `MinimumBitsPerSample`

Minimum bits per sample.

### `MaximumBitsPerSample`

Maximum bits per sample.

### `BitsPerSampleGranularity`

Granularity of the bits per sample. For example, the filter might specify 8 bits per sample through 32 bits per sample, in steps of 8.

### `MinimumSampleFrequency`

Minimum sample frequency.

### `MaximumSampleFrequency`

Maximum sample frequency.

### `SampleFrequencyGranularity`

Granularity of the frequency. For example, the filter might specify 11025 Hz to 44100 Hz, in steps of 11025 Hz.

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)

[IAMStreamConfig::GetStreamCaps](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamstreamconfig-getstreamcaps)
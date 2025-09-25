# IAMTuner::get_Channel

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `get_Channel` method retrieves the channel to which the tuner is set.

## Parameters

### `plChannel` [out]

Pointer to a variable that receives the channel. For frequencies, see [International Analog TV Tuning](https://learn.microsoft.com/windows/desktop/DirectShow/international-analog-tv-tuning)

### `plVideoSubChannel` [out]

Pointer to a variable that receives either the video subchannel, or one of the following flags:

| Value | Description |
| --- | --- |
| AMTUNER_SUBCHAN_DEFAULT | Default subchannel |
| AMTUNER_SUBCHAN_NO_TUNE | No subchannel tuning |

### `plAudioSubChannel` [out]

Pointer to a variable that receives either the audio subchannel, or one of the following flags:

| Value | Description |
| --- | --- |
| AMTUNER_SUBCHAN_DEFAULT | Default subchannel |
| AMTUNER_SUBCHAN_NO_TUNE | No subchannel tuning |

## Return value

Returns an **HRESULT** value that depends on the implementation of the interface.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMTuner Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamtuner)
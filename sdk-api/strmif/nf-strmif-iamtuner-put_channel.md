# IAMTuner::put_Channel

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `put_Channel` method sets the TV channel.

## Parameters

### `lChannel` [in]

TV channel number.

### `lVideoSubChannel`

Predefined video subchannel value. Specify AMTUNER_SUBCHAN_NO_TUNE for no tuning or AMTUNER_SUBCHAN_DEFAULT for default subchannel. Meaningful only for satellite broadcasts.

### `lAudioSubChannel`

Predefined audio subchannel value. Specify AMTUNER_SUBCHAN_NO_TUNE for no tuning or AMTUNER_SUBCHAN_DEFAULT for default subchannel. Meaningful only for satellite broadcasts.

## Return value

Returns an **HRESULT** value that depends on the implementation of the interface.

## Remarks

This method handles the channel-to-frequency function call that converts the TV channel to a TV frequency. For a list of frequencies for channels, see [International Analog TV Tuning](https://learn.microsoft.com/windows/desktop/DirectShow/international-analog-tv-tuning).

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMTuner Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamtuner)
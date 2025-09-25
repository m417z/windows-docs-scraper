# IAMTuner::SignalPresent

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SignalPresent` method retrieves the strength of the signal on a given channel.

## Parameters

### `plSignalStrength` [out]

Pointer to a variable that receives a value indicating whether a signal is present on the current channel. Can be one of the following values.

| Value | Description |
| --- | --- |
| AMTUNER_HASNOSIGNALSTRENGTH | -1 |
| AMTUNER_NOSIGNAL | 0 |
| AMTUNER_SIGNALPRESENT | 1 |

A value of AMTUNER_HASNOSIGNALSTRENGTH means the signal strength cannot be determined at this time.

## Return value

Returns an **HRESULT** value.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMTuner Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamtuner)
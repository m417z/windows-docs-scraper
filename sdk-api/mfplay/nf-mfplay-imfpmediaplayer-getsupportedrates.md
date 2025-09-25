# IMFPMediaPlayer::GetSupportedRates

## Description

\[The feature associated with this page, MFPlay, is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** and **IMFMediaEngine** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Gets the range of supported playback rates.

## Parameters

### `fForwardDirection` [in]

Specify **TRUE** to get the playback rates for forward playback. Specify **FALSE** to get the rates for reverse playback.

### `pflSlowestRate` [out]

Receives the slowest supported rate.

### `pflFastestRate` [out]

Receives the fastest supported rate.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| ****S_OK**** | The method succeeded. |
| ****MF_E_UNSUPPORTED_RATE**** | The current media item does not support playback in the requested direction (either forward or reverse). |

## Remarks

Playback rates are expressed as a ratio of the current rate to the normal rate. For example, 1.0 indicates normal playback speed, 0.5 indicates half speed, and 2.0 indicates twice speed. Positive values indicate forward playback, and negative values indicate reverse playback.

## See also

[IMFPMediaPlayer](https://learn.microsoft.com/windows/desktop/api/mfplay/nn-mfplay-imfpmediaplayer)

[Using MFPlay for Audio/Video Playback](https://learn.microsoft.com/windows/desktop/medfound/using-mfplay-for-audio-video-playback)
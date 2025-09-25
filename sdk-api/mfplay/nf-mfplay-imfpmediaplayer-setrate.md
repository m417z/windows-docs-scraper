# IMFPMediaPlayer::SetRate

## Description

\[The feature associated with this page, MFPlay, is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** and **IMFMediaEngine** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Sets the playback rate.

## Parameters

### `flRate` [in]

Playback rate. The playback rate is expressed as a ratio of the current rate to the normal rate. For example, **1.0** indicates normal playback speed, **0.5** indicates half speed, and **2.0** indicates twice speed. Positive values indicate forward playback, and negative values indicate reverse playback.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| ****S_OK**** | The method succeeded. |
| ****MF_E_OUT_OF_RANGE**** | The *flRate* parameter is zero. |
| ****MF_E_SHUTDOWN**** | The object's [Shutdown](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaplayer-shutdown) method was called. |

## Remarks

This method completes asynchronously. When the operation completes, the application's [IMFPMediaPlayerCallback::OnMediaPlayerEvent](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaplayercallback-onmediaplayerevent) callback method is invoked. The event type is **MFP_EVENT_TYPE_RATE_SET**.

The method sets the nearest supported rate, which will depend on the underlying media source. For example, if *flRate* is 50 and the source's maximum rate is 8× normal rate, the method will set the rate to 8.0. The actual rate is indicated in the event data for the **MFP_EVENT_TYPE_RATE_SET** event.

To find the range of supported rates, call [IMFPMediaPlayer::GetSupportedRates](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaplayer-getsupportedrates).

This method does not support playback rates of zero, although Media Foundation defines a meaning for zero rates in some other contexts.

The new rate applies only to the current media item. Setting a new media item resets the playback rate to 1.0.

## See also

[IMFPMediaPlayer](https://learn.microsoft.com/windows/desktop/api/mfplay/nn-mfplay-imfpmediaplayer)

[Using MFPlay for Audio/Video Playback](https://learn.microsoft.com/windows/desktop/medfound/using-mfplay-for-audio-video-playback)
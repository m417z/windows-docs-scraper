# IAMAudioInputMixer::put_Loudness

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `put_Loudness` method enables or disables the loudness control.

## Parameters

### `fLoudness` [in]

Specifies whether loudness is on or off. Use one of the following values.

| Value | Description |
| --- | --- |
| **TRUE** | Sets loudness on. |
| **FALSE** | Sets loudness off. |

## Return value

If the method succeeds, it returns S_OK. Otherwise it returns an **HRESULT** error code.

## Remarks

Loudness boosts the bass of low volume signals before they are recorded, to compensate for the fact that the ear does not hear quiet bass sounds as well as other sounds.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMAudioInputMixer Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamaudioinputmixer)

[IAMAudioInputMixer::get_Loudness](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamaudioinputmixer-get_loudness)
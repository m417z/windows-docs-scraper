# IAMAudioInputMixer::put_Pan

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `put_Pan` method sets the pan level.

## Parameters

### `Pan` [in]

Specifies the pan level. Possible values range from –1.0 to 1.0, as follows.

| Value | Description |
| --- | --- |
| -1 | Full left |
| 0 | Center |
| 1 | Full right |

## Return value

If the method succeeds, it returns S_OK. Otherwise it returns an **HRESULT** error code.

## Remarks

In a stereo recording, setting the pan level to -1.0 or 1.0 sends the entire signal to one channel. The other channel records silence. Panning has no effect for a mono recording.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMAudioInputMixer Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamaudioinputmixer)

[IAMAudioInputMixer::get_Pan](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamaudioinputmixer-get_pan)
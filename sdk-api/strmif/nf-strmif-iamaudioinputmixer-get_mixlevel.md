# IAMAudioInputMixer::get_MixLevel

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `get_MixLevel` method retrieves the recording level.

## Parameters

### `pLevel` [out]

Receives the recording level. The following values are possible.

| Value | Description |
| --- | --- |
| 0.0 to 1.0 | Zero indicates that the recording level is off; the value 1.0 indicates that the recording level is at full volume. Intermediate values are also allowed. |
| AMF_AUTOMATICGAIN | Automatic adjustment of the recording level is enabled. |

## Return value

If the method succeeds, it returns S_OK. Otherwise it returns an **HRESULT** error code.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMAudioInputMixer Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamaudioinputmixer)

[IAMAudioInputMixer::put_MixLevel](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamaudioinputmixer-put_mixlevel)
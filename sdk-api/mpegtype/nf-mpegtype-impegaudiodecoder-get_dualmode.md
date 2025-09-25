# IMpegAudioDecoder::get_DualMode

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Returns which channel is currently being decoded.

## Parameters

### `pIntDecode` [out]

Indicates the channel(s) to be decoded.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The *pIntDecode* parameter can have one of the values in the following table.

| Constant | Description |
| --- | --- |
| **AM_MPEG_AUDIO_DUAL_MERGE** | Both channels are decoded. |
| **AM_MPEG_AUDIO_DUAL_LEFT** | The left channel is decoded. |
| **AM_MPEG_AUDIO_DUAL_RIGHT** | The right channel is decoded. |

## See also

[IMpegAudioDecoder](https://learn.microsoft.com/windows/desktop/api/mpegtype/nn-mpegtype-impegaudiodecoder)
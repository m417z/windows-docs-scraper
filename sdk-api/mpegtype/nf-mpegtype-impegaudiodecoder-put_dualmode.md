# IMpegAudioDecoder::put_DualMode

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Specifies the channel to be decoded.

## Parameters

### `IntDecode` [in]

Specifies the channel(s) to be decoded. See remarks for valid values.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The following table lists the valid values for the *pIntDecode* parameter.

| Constant | Description |
| --- | --- |
| **AM_MPEG_AUDIO_DUAL_MERGE** | Specifies that both channels will be decoded. |
| **AM_MPEG_AUDIO_DUAL_LEFT** | Specifies that the left channel will be decoded. |
| **AM_MPEG_AUDIO_DUAL_RIGHT** | Specifies that the right channel will be decoded. |

This method is useful for karaoke discs in Video CD (VCD) format that have two mono channels in the audio stream.

## See also

[IMpegAudioDecoder](https://learn.microsoft.com/windows/desktop/api/mpegtype/nn-mpegtype-impegaudiodecoder)
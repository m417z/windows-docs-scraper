# IAMExtTransport::GetTransportAudioParameters

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetTransportAudioParameters` method retrieves audio parameter setting for external transport.

This method is not implemented.

## Parameters

### `Param` [in]

Specifies the audio parameter, whose value you want receive, as a **long** integer containing one of the following values.

| Value | Description |
| --- | --- |
| ED_TRANSAUDIO_ENABLE_OUTPUT | Audio output channel(s) |
| ED_TRANSAUDIO_ENABLE_RECORD | Audio recording channel(s) |
| ED_TRANSAUDIO_ENABLE_SELSYNC | Audio selsync recording channel(s) |
| ED_TRANSAUDIO_SET_MONITOR | Monitor output audio channel(s) |
| ED_TRANSAUDIO_SET_SOURCE | Audio source channel(s) |

### `pValue` [out]

Specifies a pointer to a **long** integer to receive the channel or channels set in the [IAMExtTransport::SetTransportAudioParameters](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamexttransport-settransportaudioparameters) method.

## Return value

When this method succeeds, it returns S_OK. Otherwise it returns an **HRESULT** error code.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMExtTransport Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamexttransport)
# IAMExtTransport::SetTransportAudioParameters

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetTransportAudioParameters` assigns audio parameter settings for external transport.

This method is not implemented.

## Parameters

### `Param` [in]

Specifies the audio parameter you want to set as a **long** integer.

| Value | Description |
| --- | --- |
| ED_TRANSAUDIO_ENABLE_OUTPUT | Enable audio channel(s) for output. |
| ED_TRANSAUDIO_ENABLE_RECORD | Enable audio channel(s) for recording. |
| ED_TRANSAUDIO_ENABLE_SELSYNC | Enable audio channel(s) for selsync recording. |
| ED_TRANSAUDIO_SET_MONITOR | Set the monitor output source. |
| ED_TRANSAUDIO_SET_SOURCE | Set the active audio input. |

### `Value` [in]

Specifies which audio channel or channels is assigned the parameter as a **long** integer.

## Return value

When this method succeeds, it returns S_OK. Otherwise it returns an **HRESULT** error code.

## Remarks

Specify an exact channel or channels in *Value* by selecting ED_AUDIO_1 through ED_AUDIO_24 (use a bitwise OR to combine), or all channels by selecting ED_AUDIO_ALL.

### DV Implementation

[MSDV](https://learn.microsoft.com/windows/desktop/DirectShow/msdv-driver) does not support this method. It returns E_NOTIMPL.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMExtTransport Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamexttransport)

[IAMExtTransport::GetTransportAudioParameters](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamexttransport-gettransportaudioparameters)
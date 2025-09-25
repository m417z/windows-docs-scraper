# MFCreateAudioRenderer function

## Description

Creates the [Streaming Audio Renderer](https://learn.microsoft.com/windows/desktop/medfound/streaming-audio-renderer).

## Parameters

### `pAudioAttributes` [in]

A pointer to the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) interface, which is used to configure the audio renderer. This parameter can be **NULL**. See Remarks.

### `ppSink` [out]

Receives a pointer to the audio renderer's [IMFMediaSink](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasink) interface. The caller must release the interface.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To configure the audio renderer, set any of the following attributes on the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) interface specified in the *pAudioAttributes* parameter.

| Attribute | Description |
| --- | --- |
| [MF_AUDIO_RENDERER_ATTRIBUTE_ENDPOINT_ID](https://learn.microsoft.com/windows/desktop/medfound/mf-audio-renderer-attribute-endpoint-id-attribute) | The audio endpoint device identifier. |
| [MF_AUDIO_RENDERER_ATTRIBUTE_ENDPOINT_ROLE](https://learn.microsoft.com/windows/desktop/medfound/mf-audio-renderer-attribute-endpoint-role-attribute) | The audio endpoint role. |
| [MF_AUDIO_RENDERER_ATTRIBUTE_FLAGS](https://learn.microsoft.com/windows/desktop/medfound/mf-audio-renderer-attribute-flags-attribute) | Miscellaneous configuration flags. |
| [MF_AUDIO_RENDERER_ATTRIBUTE_SESSION_ID](https://learn.microsoft.com/windows/desktop/medfound/mf-audio-renderer-attribute-session-id-attribute) | The audio policy class. |
| [MF_AUDIO_RENDERER_ATTRIBUTE_STREAM_CATEGORY](https://learn.microsoft.com/windows/desktop/medfound/mf-audio-renderer-attribute-stream-category) | The audio stream category. |
| [MF_LOW_LATENCY](https://learn.microsoft.com/windows/desktop/medfound/mf-low-latency) | Enables low-latency audio streaming. |

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Streaming Audio Renderer](https://learn.microsoft.com/windows/desktop/medfound/streaming-audio-renderer)
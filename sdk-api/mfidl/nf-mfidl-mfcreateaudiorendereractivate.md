# MFCreateAudioRendererActivate function

## Description

Creates an activation object for the [Streaming Audio Renderer](https://learn.microsoft.com/windows/desktop/medfound/streaming-audio-renderer).

## Parameters

### `ppActivate` [out]

Receives a pointer to the [IMFActivate](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfactivate) interface. Use this interface to create the audio renderer. The caller must release the interface.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To create the audio renderer, call [IMFActivate::ActivateObject](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfactivate-activateobject) on the retrieved [IMFActivate](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfactivate) pointer.

**Note** To avoid a memory leak, call [IMFActivate::ShutdownObject](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfactivate-shutdownobject) before releasing the final reference to the audio renderer or the audio renderer activate object.

To configure the audio renderer, set any of the following attributes on the [IMFActivate](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfactivate) object before calling [ActivateObject](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfactivate-activateobject). (If you are using the Media Session, the Media Session automatically calls **ActivateObject** when you queue the topology.)

| Attribute | Description |
| --- | --- |
| [MF_AUDIO_RENDERER_ATTRIBUTE_ENDPOINT_ID](https://learn.microsoft.com/windows/desktop/medfound/mf-audio-renderer-attribute-endpoint-id-attribute) | The audio endpoint device identifier. |
| [MF_AUDIO_RENDERER_ATTRIBUTE_ENDPOINT_ROLE](https://learn.microsoft.com/windows/desktop/medfound/mf-audio-renderer-attribute-endpoint-role-attribute) | The audio endpoint role. |
| [MF_AUDIO_RENDERER_ATTRIBUTE_FLAGS](https://learn.microsoft.com/windows/desktop/medfound/mf-audio-renderer-attribute-flags-attribute) | Miscellaneous configuration flags. |
| [MF_AUDIO_RENDERER_ATTRIBUTE_SESSION_ID](https://learn.microsoft.com/windows/desktop/medfound/mf-audio-renderer-attribute-session-id-attribute) | The audio policy class. |
| [MF_AUDIO_RENDERER_ATTRIBUTE_STREAM_CATEGORY](https://learn.microsoft.com/windows/desktop/medfound/mf-audio-renderer-attribute-stream-category) | The audio stream category. |
| [MF_LOW_LATENCY](https://learn.microsoft.com/windows/desktop/medfound/mf-low-latency) | Enables low-latency audio streaming. |

## See also

[Activation Objects](https://learn.microsoft.com/windows/desktop/medfound/activation-objects)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Streaming Audio Renderer](https://learn.microsoft.com/windows/desktop/medfound/streaming-audio-renderer)
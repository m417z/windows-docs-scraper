# IMFMediaEngineClassFactory::CreateInstance

## Description

Creates a new instance of the Media Engine.

## Parameters

### `dwFlags` [in]

A bitwise **OR** of zero or more flags from the [MF_MEDIA_ENGINE_CREATEFLAGS](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/ne-mfmediaengine-mf_media_engine_createflags) enumeration.

### `pAttr` [in]

A pointer to the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) interface of an attribute store.

This parameter specifies configuration attributes for the Media Engine. Call [MFCreateAttributes](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfcreateattributes) to create the attribute store. Then, set one or more attributes from the list of [Media Engine Attributes](https://learn.microsoft.com/windows/desktop/medfound/media-engine-attributes). For details, see Remarks.

### `ppPlayer` [out]

Receives a pointer to the [IMFMediaEngine](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengine) interface. The caller must release the interface.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **MF_E_ATTRIBUTENOTFOUND** | A required attribute was missing from *pAttr*, or an invalid combination of attributes was used. |

## Remarks

Before calling this method, call [MFStartup](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfstartup).

The Media Engine supports three distinct modes:

| Mode | Description |
| --- | --- |
| Frame-server mode | In this mode, the Media Engine delivers uncompressed video frames to the application. The application is responsible for displaying each frame, using Microsoft Direct3D or any other rendering technique. <br><br>The Media Engine renders the audio; the application is not responsible for audio rendering.<br><br>Frame-server mode is the default mode. |
| Rendering mode | In this mode, the Media Engine renders both audio and video. The video is rendered to a window or Microsoft DirectComposition visual provided by the application.<br><br>To enable rendering mode, set either the [MF_MEDIA_ENGINE_PLAYBACK_HWND](https://learn.microsoft.com/windows/desktop/medfound/mf-media-engine-playback-hwnd) attribute or the [MF_MEDIA_ENGINE_PLAYBACK_VISUAL](https://learn.microsoft.com/windows/desktop/medfound/mf-media-engine-playback-visual) attribute. |
| Audio mode | In this mode, the Media Engine renders audio only, with no video.<br><br>To enable audio mode, set the **MF_MEDIA_ENGINE_AUDIOONLY** flag in the *dwFlags* parameter. |

### Initialization Attributes

The following attributes are defined for the *pAttr* parameter. Some are required, and some are optional, depending on the mode you want.

| Feature | Attributes | Frame Server Mode | Rendering Mode | Audio Mode |
| --- | --- | --- | --- | --- |
| Event callback | [MF_MEDIA_ENGINE_CALLBACK](https://learn.microsoft.com/windows/desktop/medfound/mf-media-engine-callback) | Required. | Required. | Required. |
| Render target | One of the following:<br><br>[MF_MEDIA_ENGINE_PLAYBACK_HWND](https://learn.microsoft.com/windows/desktop/medfound/mf-media-engine-playback-hwnd)<br><br>[MF_MEDIA_ENGINE_PLAYBACK_VISUAL](https://learn.microsoft.com/windows/desktop/medfound/mf-media-engine-playback-visual)<br><br>These attributes are mutually exclusive. Setting either of these attributes puts the Media Engine into rendering mode. | Do not set. | Required. | Do not set. |
| Direct3D format | [MF_MEDIA_ENGINE_VIDEO_OUTPUT_FORMAT](https://learn.microsoft.com/windows/desktop/medfound/mf-media-engine-video-output-format) | Required. | Optional. | Do not set. |
| Microsoft DirectX Graphics Infrastructure (DXGI) device manager | [MF_MEDIA_ENGINE_DXGI_MANAGER](https://learn.microsoft.com/windows/desktop/medfound/mf-media-engine-dxgi-manager) | Optional. | Optional. | Do not set. |
| Media Engine extensions | [MF_MEDIA_ENGINE_EXTENSION](https://learn.microsoft.com/windows/desktop/medfound/mf-media-engine-extension) | Optional. | Optional. | Optional. |
| Content protection | Any of the following:<br><br>[MF_MEDIA_ENGINE_OPM_HWND](https://learn.microsoft.com/windows/desktop/medfound/mf-media-engine-opm-hwnd)<br><br>[MF_MEDIA_ENGINE_CONTENT_PROTECTION_FLAGS](https://learn.microsoft.com/windows/desktop/medfound/mf-media-engine-content-protection-flags)<br><br>[MF_MEDIA_ENGINE_CONTENT_PROTECTION_MANAGER](https://learn.microsoft.com/windows/desktop/medfound/mf-media-engine-content-protection-manager) | Optional. | Optional. | Optional. |
| Audio playback | Any of the following:<br><br>[MF_MEDIA_ENGINE_AUDIO_CATEGORY](https://learn.microsoft.com/windows/desktop/medfound/mf-media-engine-audio-category)<br><br>[MF_MEDIA_ENGINE_AUDIO_ENDPOINT_ROLE](https://learn.microsoft.com/windows/desktop/medfound/mf-media-engine-audio-endpoint-role) | Optional. | Optional. | Optional. |

### Windows Phone 8

This API is supported.

On the phone, the Media Engine only supports frame-server mode. Attempting to initialize the interface in either rendering mode or audio mode will fail.

## See also

[IMFMediaEngineClassFactory](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengineclassfactory)
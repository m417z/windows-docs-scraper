# MF_MEDIA_ENGINE_CREATEFLAGS enumeration

## Description

Contains flags for the [IMFMediaEngineClassFactory::CreateInstance](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengineclassfactory-createinstance) method.

## Constants

### `MF_MEDIA_ENGINE_AUDIOONLY:0x1`

The Media Engine will play audio only. It will not play video.

### `MF_MEDIA_ENGINE_WAITFORSTABLE_STATE:0x2`

The Media Engine's resource loading algorithm waits for the application to signal the thread that loads the resource. For more information, see the remarks for **MF_MEDIA_ENGINE_EVENT_NOTIFYSTABLESTATE** in the [MF_MEDIA_ENGINE_EVENT](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/ne-mfmediaengine-mf_media_engine_event) enumeration.

### `MF_MEDIA_ENGINE_FORCEMUTE:0x4`

Always mute the audio.

### `MF_MEDIA_ENGINE_REAL_TIME_MODE:0x8`

Enable low-latency mode in the rendering pipeline. This can be changed at a later time by calling [IMFMediaEngineEx::SetRealTimeMode](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengineex-setrealtimemode).

### `MF_MEDIA_ENGINE_DISABLE_LOCAL_PLUGINS:0x10`

Disable locally registered media plugins. If this flag is set, the Media Engine will not load decoders or other media plugins that the application registered for the local process.

### `MF_MEDIA_ENGINE_CREATEFLAGS_MASK:0x1f`

Reserved.

## See also

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)
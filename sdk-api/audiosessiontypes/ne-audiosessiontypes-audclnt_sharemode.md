# AUDCLNT_SHAREMODE enumeration

## Description

The **AUDCLNT_SHAREMODE** enumeration defines constants that indicate whether an audio stream will run in shared mode or in exclusive mode.

## Constants

### `AUDCLNT_SHAREMODE_SHARED`

The audio stream will run in shared mode. For more information, see Remarks.

### `AUDCLNT_SHAREMODE_EXCLUSIVE`

The audio stream will run in exclusive mode. For more information, see Remarks.

## Remarks

The [IAudioClient::Initialize](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-initialize) and [IAudioClient::IsFormatSupported](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-isformatsupported) methods use the constants defined in the **AUDCLNT_SHAREMODE** enumeration.

In shared mode, the client can share the audio endpoint device with clients that run in other user-mode processes. The audio engine always supports formats for client streams that match the engine's mix format. In addition, the audio engine might support another format if the Windows audio service can insert system effects into the client stream to convert the client format to the mix format.

In exclusive mode, the Windows audio service attempts to establish a connection in which the client has exclusive access to the audio endpoint device. In this mode, the audio engine inserts no system effects into the local stream to aid in the creation of the connection point. Either the audio device can handle the specified format directly or the method fails.

For more information about shared-mode and exclusive-mode streams, see [User-Mode Audio Components](https://learn.microsoft.com/windows/desktop/CoreAudio/user-mode-audio-components).

Starting with Xbox May 2021 Update, you can open an audio client in exclusive mode on Xbox.

## See also

[Core Audio Constants](https://learn.microsoft.com/windows/desktop/CoreAudio/core-audio-constants)

[Core Audio Enumerations](https://learn.microsoft.com/windows/desktop/CoreAudio/core-audio-enumerations)

[IAudioClient::Initialize](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-initialize)

[IAudioClient::IsFormatSupported](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-isformatsupported)
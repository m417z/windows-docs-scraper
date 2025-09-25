# DIRECTX_AUDIO_ACTIVATION_PARAMS structure

## Description

The **DIRECTX_AUDIO_ACTIVATION_PARAMS** structure specifies the initialization parameters for a DirectSound stream.

## Members

### `cbDirectXAudioActivationParams`

The size, in bytes, of the **DIRECTX_AUDIO_ACTIVATION_PARAMS** structure. Set this member to sizeof(DIRECTX_AUDIO_ACTIVATION_PARAMS).

### `guidAudioSession`

Session GUID. This member is a GUID value that identifies the audio session that the stream belongs to. If the GUID identifies a session that has been previously opened, the method adds the stream to that session. If the GUID does not identify an existing session, the method opens a new session and adds the stream to that session. The stream remains a member of the same session for its lifetime.

### `dwAudioStreamFlags`

Stream-initialization flags. This member specifies whether the stream belongs to a cross-process session or to a session that is specific to the current process. Set this member to 0 or to the following [AUDCLNT_STREAMFLAGS_XXX](https://learn.microsoft.com/windows/desktop/CoreAudio/audclnt-streamflags-xxx-constants) constant:

AUDCLNT_STREAMFLAGS_CROSSPROCESS

## Remarks

This structure is used by the [IMMDevice::Activate](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nf-mmdeviceapi-immdevice-activate) method. When activating an **IDirectSound**, **IDirectSoundCapture**, or **IBaseFilter** interface on an audio endpoint device, the **DIRECTX_AUDIO_ACTIVATION_PARAMS** structure specifies the session GUID and stream-initialization flags for the audio stream that the DirectSound module creates and encapsulates in the interface instance. During the **Activate** call, DirectSound calls the [IAudioClient::Initialize](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-initialize) method and specifies the session GUID and stream-initialization flags from the **DIRECTX_AUDIO_ACTIVATION_PARAMS** structure as input parameters.

For more information about **IDirectSound**, **IDirectSoundCapture**, and **IBaseFilter**, see the Windows SDK documentation.

For a code example that uses the **DIRECTX_AUDIO_ACTIVATION_PARAMS** structure, see [Device Roles for DirectShow Applications](https://learn.microsoft.com/windows/desktop/CoreAudio/device-roles-for-directshow-applications).

## See also

[Core Audio Structures](https://learn.microsoft.com/windows/desktop/CoreAudio/core-audio-structures)

[IAudioClient::Initialize](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-initialize)

[IMMDevice::Activate](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nf-mmdeviceapi-immdevice-activate)
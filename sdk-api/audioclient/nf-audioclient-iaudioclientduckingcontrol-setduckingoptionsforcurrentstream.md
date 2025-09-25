## Description

Sets the audio ducking options for an audio render stream. Allows an app to specify that the system shouldn't duck the audio of other streams when the app's audio render stream is active.

## Parameters

### `options`

A value from the [AUDIO_DUCKING_OPTIONS](https://learn.microsoft.com/windows/win32/api/audioclient/ne-audioclient-audio_ducking_options) enumeration specifying the requested ducking behavior.

## Return value

On successful completion, returns S_OK.

## Remarks

Get an instance of the [IAudioClientDuckingControl](https://learn.microsoft.com/windows/win32/api/audioclient/nn-audioclient-iaudioclientduckingcontrol) interface by calling [IAudioClient::GetService](https://learn.microsoft.com/windows/win32/api/audioclient/nf-audioclient-iaudioclient-getservice), passing in the interface ID constant **IID_IAudioClientDuckingControl**.

**IAudioClientDuckingControl** only controls the ducking caused by the audio stream (**IAudioClient**) that the interface is obtained from.

Audio from applications could continue to be ducked if there are other concurrent applications with streams that cause ducking.

## See also
## Description

Represents an audio microphone boost APO notification.

## Members

### `endpoint`

An [IMMDevice](https://learn.microsoft.com/windows/win32/api/mmdeviceapi/nn-mmdeviceapi-immdevice) representing the audio endpoint associated with the notification.

### `eventContext`

A GUID representing the context associated with the originator of the event. A client can use this method to keep track of control changes made by other processes and by the hardware. The functions [IAudioVolumeLevel::SetLevel](https://learn.microsoft.com/windows/win32/api/devicetopology/nf-devicetopology-iperchanneldblevel-setlevel) and [IAudioMute::SetMute](https://learn.microsoft.com/windows/win32/api/devicetopology/nf-devicetopology-iaudiomute-setmute) use the context. When this notification is recieved, a client can inspect the context GUID to discover whether it or another client is the source of the notification.

### `microphoneBoostEnabled`

A boolean value indicating the presence of a "Microphone Boost" part (connector or subunit) of an audio capture device topology.

### `levelInDb`

A float value specifying the volume level in decibels.

### `levelMinInDb`

A float value specifying the minimum volume level in decibels.

### `levelMaxInDb`

A float value specifying the maximum volume level in decibels.

### `levelStepInDb`

A float value specifying the stepping value between consecutive volume levels in the range *levelMinInDb* to *levelMaxInDb*.

### `muteSupported`

A boolean value indicating if the IAudioMute interface is supported by the "Microphone Boost" part of the audio capture device topology.

### `mute`

A boolean value indicating the current state (enabled or disabled) of the mute control

## Remarks

For more information on the Windows 11 APIs for the Audio Processing Objects (APOs) that can ship with audio drivers, see [Windows 11 APIs for Audio Processing Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/windows-11-apis-for-audio-processing-objects).

## See also
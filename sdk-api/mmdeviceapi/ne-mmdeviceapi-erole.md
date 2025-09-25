# ERole enumeration

## Description

The **ERole** enumeration defines constants that indicate the role that the system has assigned to an audio endpoint device.

## Constants

### `eConsole:0`

Games, system notification sounds, and voice commands.

### `eMultimedia`

Music, movies, narration, and live music recording.

### `eCommunications`

Voice communications (talking to another person).

### `ERole_enum_count`

The number of members in the [ERole](https://learn.microsoft.com/windows/win32/api/mmdeviceapi/ne-mmdeviceapi-erole) enumeration (not counting the ERole_enum_count member).

## Remarks

The [IMMDeviceEnumerator::GetDefaultAudioEndpoint](https://learn.microsoft.com/windows/win32/api/mmdeviceapi/ne-mmdeviceapi-erole) and [IMMNotificationClient::OnDefaultDeviceChanged](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nf-mmdeviceapi-immnotificationclient-ondefaultdevicechanged) methods use the constants defined in the **ERole** enumeration.

For more information, see [Device Roles](https://learn.microsoft.com/windows/desktop/CoreAudio/device-roles).

## See also

[Core Audio Enumerations](https://learn.microsoft.com/windows/desktop/CoreAudio/core-audio-enumerations)

[IMMDeviceEnumerator::GetDefaultAudioEndpoint](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nf-mmdeviceapi-immdeviceenumerator-getdefaultaudioendpoint)

[IMMNotificationClient::OnDefaultDeviceChanged](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nf-mmdeviceapi-immnotificationclient-ondefaultdevicechanged)
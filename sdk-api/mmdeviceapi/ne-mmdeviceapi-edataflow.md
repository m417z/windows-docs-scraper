# EDataFlow enumeration

## Description

The **EDataFlow** enumeration defines constants that indicate the direction in which audio data flows between an audio endpoint device and an application.

## Constants

### `eRender:0`

Audio rendering stream. Audio data flows from the application to the audio endpoint device, which renders the stream.

### `eCapture`

Audio capture stream. Audio data flows from the audio endpoint device that captures the stream, to the application.

### `eAll`

Audio rendering or capture stream. Audio data can flow either from the application to the audio endpoint device, or from the audio endpoint device to the application.

### `EDataFlow_enum_count`

The number of members in the [EDataFlow](https://learn.microsoft.com/windows/win32/api/mmdeviceapi/ne-mmdeviceapi-edataflow) enumeration (not counting the EDataFlow_enum_count member).

## Remarks

The [IMMDeviceEnumerator::GetDefaultAudioEndpoint](https://learn.microsoft.com/windows/win32/api/mmdeviceapi/ne-mmdeviceapi-edataflow), [IMMDeviceEnumerator::EnumAudioEndpoints](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nf-mmdeviceapi-immdeviceenumerator-enumaudioendpoints), [IMMEndpoint::GetDataFlow](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nf-mmdeviceapi-immendpoint-getdataflow), and [IMMNotificationClient::OnDefaultDeviceChanged](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nf-mmdeviceapi-immnotificationclient-ondefaultdevicechanged) methods use the constants defined in the **EDataFlow** enumeration.

## See also

[Core Audio Enumerations](https://learn.microsoft.com/windows/desktop/CoreAudio/core-audio-enumerations)

[IMMDeviceEnumerator::EnumAudioEndpoints](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nf-mmdeviceapi-immdeviceenumerator-enumaudioendpoints)

[IMMDeviceEnumerator::GetDefaultAudioEndpoint](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nf-mmdeviceapi-immdeviceenumerator-getdefaultaudioendpoint)

[IMMEndpoint::GetDataFlow](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nf-mmdeviceapi-immendpoint-getdataflow)

[IMMNotificationClient::OnDefaultDeviceChanged](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nf-mmdeviceapi-immnotificationclient-ondefaultdevicechanged)
# IAudioDeviceEndpoint::GetRTCaps

## Description

The **GetRTCaps** method queries whether the audio device is real-time (RT)-capable. This method is not used in Remote Desktop Services implementations of [IAudioDeviceEndpoint](https://learn.microsoft.com/windows/desktop/api/audioengineendpoint/nn-audioengineendpoint-iaudiodeviceendpoint).

## Parameters

### `pbIsRTCapable` [out]

Receives **TRUE** if the audio device is RT-capable, or **FALSE** otherwise. Remote Desktop Services implementations should always return **FALSE**.

## Return value

If the method succeeds, it returns **S_OK**.

## Remarks

The Remote Desktop Services AudioEndpoint API is for use in Remote Desktop scenarios; it is not for client applications.

## See also

[IAudioDeviceEndpoint](https://learn.microsoft.com/windows/desktop/api/audioengineendpoint/nn-audioengineendpoint-iaudiodeviceendpoint)
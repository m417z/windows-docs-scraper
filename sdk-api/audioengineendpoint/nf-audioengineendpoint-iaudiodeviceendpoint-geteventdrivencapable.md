# IAudioDeviceEndpoint::GetEventDrivenCapable

## Description

The **GetEventDrivenCapable** method indicates whether the device endpoint is event driven. The device endpoint controls the period of the audio engine by setting events that signal buffer availability.

## Parameters

### `pbisEventCapable` [out]

A value of **TRUE** indicates that the device endpoint is event driven. A value of **FALSE** indicates that it is not event driven. If the endpoint device is event driven, the audio engine can receive events from an audio device endpoint.

## Return value

If the method succeeds, it returns **S_OK**.

## Remarks

Call the **GetEventDrivenCapable** method before calling the [IAudioDeviceEndpoint::SetBuffer](https://learn.microsoft.com/windows/desktop/api/audioengineendpoint/nf-audioengineendpoint-iaudiodeviceendpoint-setbuffer) method, which initializes the device endpoint and creates a buffer. This allows the device endpoint to set up the structures needed for driving events.

If the audio engine requires an event driven device endpoint, it will:

* Create an event and set the event handle on the device endpoint by calling the [IAudioEndpoint::SetEventHandle](https://learn.microsoft.com/windows/desktop/api/audioengineendpoint/nf-audioengineendpoint-iaudioendpoint-seteventhandle) method.
* Specify event driven mode by setting the **AUDCLNT_STREAMFLAGS_EVENTCALLBACK** flag on the device endpoint by calling the [IAudioEndpoint::SetStreamFlags](https://learn.microsoft.com/windows/desktop/api/audioengineendpoint/nf-audioengineendpoint-iaudioendpoint-setstreamflags) method.

The Remote Desktop Services AudioEndpoint API is for use in Remote Desktop scenarios; it is not for client applications.

## See also

[IAudioDeviceEndpoint](https://learn.microsoft.com/windows/desktop/api/audioengineendpoint/nn-audioengineendpoint-iaudiodeviceendpoint)
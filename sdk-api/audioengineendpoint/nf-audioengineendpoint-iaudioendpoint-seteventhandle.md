# IAudioEndpoint::SetEventHandle

## Description

The **SetEventHandle** method sets the handle for the event that the endpoint uses to signal that it has completed processing of a buffer.

## Parameters

### `eventHandle` [in]

The event handle used to invoke a buffer completion
callback.

## Return value

If the method succeeds, it returns **S_OK**. If it fails, possible return codes include, but are not limited to, the following.

## Remarks

The **SetEventHandle** method sets the audio engine event handle on the endpoint. In this implementation, the caller should receive an error response of **AEERR_NOT_INITIALIZED** if the audio endpoint is not initialized or the buffer is not set by the [SetBuffer](https://learn.microsoft.com/windows/desktop/api/audioengineendpoint/nf-audioengineendpoint-iaudiodeviceendpoint-setbuffer) method.

To get event notifications, the audio engine will have set the **AUDCLNT_STREAMFLAGS_EVENTCALLBACK** flag on the endpoint. To set this flag, the audio engine calls the [IAudioEndpoint::SetStreamFlags](https://learn.microsoft.com/windows/desktop/api/audioengineendpoint/nf-audioengineendpoint-iaudioendpoint-setstreamflags) method.

This method must not be called from a real-time processing thread.

The Remote Desktop Services AudioEndpoint API is for use in Remote Desktop scenarios; it is not for client applications.

## See also

[IAudioEndpoint](https://learn.microsoft.com/windows/desktop/api/audioengineendpoint/nn-audioengineendpoint-iaudioendpoint)
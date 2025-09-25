# IAudioOutputEndpointRT::PulseEndpoint

## Description

The **PulseEndpoint** method is reserved.

This method is called by the audio engine at the end of a processing pass. The event handle is set by calling the [IAudioEndpoint::SetEventHandle](https://learn.microsoft.com/windows/desktop/api/audioengineendpoint/nf-audioengineendpoint-iaudioendpoint-seteventhandle) method.

## Remarks

This method can be called from a real-time processing thread. The
implementation of this method must not block, access paged memory, or call any blocking system routines.

The Remote Desktop Services AudioEndpoint API is for use in Remote Desktop scenarios; it is not for client applications.

## See also

[IAudioOutputEndpointRT](https://learn.microsoft.com/windows/desktop/api/audioengineendpoint/nn-audioengineendpoint-iaudiooutputendpointrt)
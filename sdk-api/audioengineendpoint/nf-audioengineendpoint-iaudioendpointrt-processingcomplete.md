# IAudioEndpointRT::ProcessingComplete

## Description

The **ProcessingComplete** method notifies the endpoint that a processing pass has been completed.

## Remarks

This method enables the audio engine to call into the endpoint to set an event that indicates
that a processing pass had been completed and that there is audio data ready to be retrieved or passed to
the endpoint device.

This method can be called from a real-time processing thread. The
implementation of this method must not block, access
paged memory, or call any blocking system routines.

The Remote Desktop Services AudioEndpoint API is for use in Remote Desktop scenarios; it is not for client applications.

## See also

[IAudioEndpointRT](https://learn.microsoft.com/windows/desktop/api/audioengineendpoint/nn-audioengineendpoint-iaudioendpointrt)
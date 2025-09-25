# IAudioEndpointRT::SetPinInactive

## Description

The **SetPinInactive** method notifies the endpoint that it must change the state of the underlying stream resources to an inactive state.

## Return value

If the method succeeds, it returns **S_OK**.

## Remarks

This method enables the audio engine to call into the endpoint to indicate that the endpoint can pause the underlying stream resources. In most cases, this method can simply return **S_OK**.

This method can be called from a real-time processing thread. The
implementation of this method must not block, access
paged memory, or call any blocking system routines.

The Remote Desktop Services AudioEndpoint API is for use in Remote Desktop scenarios; it is not for client applications.

## See also

[IAudioEndpointRT](https://learn.microsoft.com/windows/desktop/api/audioengineendpoint/nn-audioengineendpoint-iaudioendpointrt)
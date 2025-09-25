# IAudioEndpointControl::Reset

## Description

The **Reset** method resets the endpoint stream.

## Return value

If the method succeeds, it returns **S_OK**.

## Remarks

**Reset** discards all data that has not been processed yet.
The implementation of this method may differ depending on the type of device that the endpoint represents.

This method must not be called from a real-time processing thread.

The Remote Desktop Services AudioEndpoint API is for use in Remote Desktop scenarios; it is not for client applications.

## See also

[IAudioEndpointControl](https://learn.microsoft.com/windows/desktop/api/audioengineendpoint/nn-audioengineendpoint-iaudioendpointcontrol)
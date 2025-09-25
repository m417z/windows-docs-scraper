# IAudioEndpointControl::Stop

## Description

The **Stop** method stops the endpoint stream.

## Return value

If the method succeeds, it returns **S_OK**.

## Remarks

The implementation of this method can differ depending on the type of device that the endpoint represents.

This method must not be called from a real-time processing thread.

The Remote Desktop Services AudioEndpoint API is for use in Remote Desktop scenarios; it is not for client applications.

## See also

[IAudioEndpointControl](https://learn.microsoft.com/windows/desktop/api/audioengineendpoint/nn-audioengineendpoint-iaudioendpointcontrol)
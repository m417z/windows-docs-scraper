# IAudioEndpointRT::GetCurrentPadding

## Description

The **GetCurrentPadding** method gets the amount, in 100-nanosecond units, of data that is queued up in the endpoint.

## Parameters

### `pPadding` [out]

Receives the number of frames available in the endpoint buffer.

### `pAeCurrentPosition` [out]

Receives information about the position of the current frame in the endpoint buffer in an [AE_CURRENT_POSITION](https://learn.microsoft.com/windows/desktop/api/audioengineendpoint/ns-audioengineendpoint-ae_current_position) structure specified by the caller.

## Remarks

The audio engine uses this information to calculate the amount of data that requires processing.
This calculation depends on the implementation.
The value of the *pPadding* parameter specifies the number of audio frames that are queued up to play in the endpoint buffer. Before writing to the endpoint buffer, the audio engine can calculate the amount of available space in the buffer by subtracting the padding value from the buffer length. For a CaptureStream endpoint, the padding value reported by the **GetCurrentPadding** method specifies the number of frames of capture data that are available in the next packet in the endpoint buffer and that might be ready for the audio engine to read from the buffer.

This method can be called from a real-time processing thread. The
implementation of this method must not block, access
paged memory, or call any blocking system routines.

The Remote Desktop Services AudioEndpoint API is for use in Remote Desktop scenarios; it is not for client applications.

## See also

[IAudioEndpointRT](https://learn.microsoft.com/windows/desktop/api/audioengineendpoint/nn-audioengineendpoint-iaudioendpointrt)
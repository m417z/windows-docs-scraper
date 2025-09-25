# IAudioEndpoint::GetLatency

## Description

The **GetLatency** method gets the latency of the audio endpoint.

## Parameters

### `pLatency` [out]

A pointer to an **HNSTIME** variable that receives the latency that is added to the stream by the audio endpoint.

## Return value

If the method succeeds, it returns **S_OK**.

## Remarks

There is some latency for an endpoint so that the buffer can stay ahead of the data already committed for input/output (I/O) transfer (playback or capture). For example, if an audio endpoint is using 5-millisecond buffers to stay ahead of the I/O transfer, the latency returned by this method is 5 milliseconds.

This method must not be called from a real-time processing thread.

The Remote Desktop Services AudioEndpoint API is for use in Remote Desktop scenarios; it is not for client applications.

## See also

[IAudioEndpoint](https://learn.microsoft.com/windows/desktop/api/audioengineendpoint/nn-audioengineendpoint-iaudioendpoint)
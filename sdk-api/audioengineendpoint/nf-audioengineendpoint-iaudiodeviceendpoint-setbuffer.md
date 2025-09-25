# IAudioDeviceEndpoint::SetBuffer

## Description

The **SetBuffer** method initializes the endpoint and creates a buffer based on the format of the endpoint into which the audio data is streamed.

## Parameters

### `MaxPeriod` [in]

The processing time, in
100-nanosecond units, of the audio endpoint.

### `u32LatencyCoefficient` [in]

The latency coefficient for the audio device. This value is used to calculate the latency. Latency = *u32LatencyCoefficient* * *MaxPeriod*.

**Note** The device that the endpoint represents has a minimum latency
value. If the value of this parameter is less than the minimum latency of the device or is zero, the
endpoint object applies the minimum latency. The audio engine can obtain the
actual latency of the endpoint by calling the [IAudioEndpoint::GetLatency](https://learn.microsoft.com/windows/desktop/api/audioengineendpoint/nf-audioengineendpoint-iaudioendpoint-getlatency) method.

## Return value

If the method succeeds, it returns **S_OK**.

If it fails, possible return codes include, but are not limited to, the following.

## Remarks

The Remote Desktop Services AudioEndpoint API is for use in Remote Desktop scenarios; it is not for client applications.

## See also

[IAudioDeviceEndpoint](https://learn.microsoft.com/windows/desktop/api/audioengineendpoint/nn-audioengineendpoint-iaudiodeviceendpoint)
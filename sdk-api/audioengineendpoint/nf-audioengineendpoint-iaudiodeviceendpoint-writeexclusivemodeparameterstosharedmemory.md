# IAudioDeviceEndpoint::WriteExclusiveModeParametersToSharedMemory

## Description

The
**WriteExclusiveModeParametersToSharedMemory**
method creates and writes the exclusive-mode parameters to shared memory.

## Parameters

### `hTargetProcess` [in]

The handle of the process for which the handles
will be duplicated.

### `hnsPeriod` [in]

The periodicity, in 100-nanosecond units, of the device. This value must fall within the range of the
minimum and maximum periodicity of the device represented by the endpoint.

### `hnsBufferDuration` [in]

The buffer duration, in 100-nanosecond units, requested by the client.

### `u32LatencyCoefficient` [in]

The latency coefficient of the audio endpoint. A client can obtain the actual latency of the endpoint by
calling the [IAudioEndpoint::GetLatency](https://learn.microsoft.com/windows/desktop/api/audioengineendpoint/nf-audioengineendpoint-iaudioendpoint-getlatency)
method.

### `pu32SharedMemorySize` [out]

Receives the size of the memory area shared by the service and the process.

### `phSharedMemory` [out]

Receives a handle to the memory area shared by the service and the process.

## Return value

If the method succeeds, it returns **S_OK**.

## Remarks

This method is used to provide handles and parameters of the audio service of the endpoint to the client
process for use in exclusive mode. This method fails if the endpoint object is fully initialized through the
[IAudioDeviceEndpoint::SetBuffer](https://learn.microsoft.com/windows/desktop/api/audioengineendpoint/nf-audioengineendpoint-iaudiodeviceendpoint-setbuffer)
method call.

The Remote Desktop Services AudioEndpoint API is for use in Remote Desktop scenarios; it is not for client
applications.

## See also

[IAudioDeviceEndpoint](https://learn.microsoft.com/windows/desktop/api/audioengineendpoint/nn-audioengineendpoint-iaudiodeviceendpoint)
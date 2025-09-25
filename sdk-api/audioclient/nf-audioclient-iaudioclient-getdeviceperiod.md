# IAudioClient::GetDevicePeriod

## Description

The **GetDevicePeriod** method retrieves the length of the periodic interval separating successive processing passes by the audio engine on the data in the endpoint buffer.

## Parameters

### `phnsDefaultDevicePeriod` [out]

Pointer to a [REFERENCE_TIME](https://learn.microsoft.com/windows/desktop/DirectShow/reference-time) variable into which the method writes a time value specifying the default interval between periodic processing passes by the audio engine. The time is expressed in 100-nanosecond units. For information about **REFERENCE_TIME**, see the Windows SDK documentation.

### `phnsMinimumDevicePeriod` [out]

Pointer to a [REFERENCE_TIME](https://learn.microsoft.com/windows/desktop/DirectShow/reference-time) variable into which the method writes a time value specifying the minimum interval between periodic processing passes by the audio endpoint device. The time is expressed in 100-nanosecond units.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **AUDCLNT_E_DEVICE_INVALIDATED** | The audio endpoint device has been unplugged, or the audio hardware or associated hardware resources have been reconfigured, disabled, removed, or otherwise made unavailable for use. |
| **AUDCLNT_E_RESOURCES_INVALIDATED** | The stream's resources have been invalidated. This error may be thrown for the following reasons:\<br>- The stream is suspended.\<br>- An Exclusive or Offload stream is disconnected.\<br>- A packaged application that has an exclusive mode or offload stream is quiesced.\<br>- A "protected output" stream is closed.\ |
| **AUDCLNT_E_SERVICE_NOT_RUNNING** | The Windows audio service is not running. |
| **E_POINTER** | Parameters *phnsDefaultDevicePeriod* and *phnsMinimumDevicePeriod* are both **NULL**. |

## Remarks

The client can call this method before calling the [IAudioClient::Initialize](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-initialize) method.

The *phnsDefaultDevicePeriod* parameter specifies the default scheduling period for a shared-mode stream. The *phnsMinimumDevicePeriod* parameter specifies the minimum scheduling period for an exclusive-mode stream.

At least one of the two parameters, *phnsDefaultDevicePeriod* and *phnsMinimumDevicePeriod*, must be non-**NULL** or the method returns immediately with error code E_POINTER. If both parameters are non-**NULL**, then the method outputs both the default and minimum periods.

For a shared-mode stream, the audio engine periodically processes the data in the endpoint buffer, which the engine shares with the client application. The engine schedules itself to perform these processing passes at regular intervals.

The period between processing passes by the audio engine is fixed for a particular audio endpoint device and represents the smallest processing quantum for the audio engine. This period plus the stream latency between the buffer and endpoint device represents the minimum possible latency that an audio application can achieve.

The client has the option of scheduling its periodic processing thread to run at the same time interval as the audio engine. In this way, the client can achieve the smallest possible latency for a shared-mode stream. However, in an application for which latency is less important, the client can reduce the process-switching overhead on the CPU by scheduling its processing passes to occur less frequently. In this case, the endpoint buffer must be proportionally larger to compensate for the longer period between processing passes.

The client determines the buffer size during its call to the [IAudioClient::Initialize](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-initialize) method. For a shared-mode stream, if the client passes this method an *hnsBufferDuration* parameter value of 0, the method assumes that the periods for the client and audio engine are guaranteed to be equal, and the method will allocate a buffer small enough to achieve the minimum possible latency. (In fact, any *hnsBufferDuration* value between 0 and the sum of the audio engine's period and device latency will have the same result.) Similarly, for an exclusive-mode stream, if the client sets *hnsBufferDuration* to 0, the method assumes that the period of the client is set to the minimum period of the audio endpoint device, and the method will allocate a buffer small enough to achieve the minimum possible latency.

If the client chooses to run its periodic processing thread less often, at the cost of increased latency, it can do so as long as it creates an endpoint buffer during the [IAudioClient::Initialize](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-initialize) call that is sufficiently large.

## See also

[IAudioClient Interface](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudioclient)

[IAudioClient::Initialize](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-initialize)
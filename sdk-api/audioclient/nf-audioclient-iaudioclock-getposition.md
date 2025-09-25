# IAudioClock::GetPosition

## Description

The **GetPosition** method gets the current device position.

## Parameters

### `pu64Position` [out]

Pointer to a **UINT64** variable into which the method writes the device position. The device position is the offset from the start of the stream to the current position in the stream. However, the units in which this offset is expressed are undefined—the device position value has meaning only in relation to the frequency reported by the [IAudioClock::GetFrequency](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclock-getfrequency) method. For more information, see Remarks.

### `pu64QPCPosition` [out]

Pointer to a **UINT64** variable into which the method writes the value of the performance counter at the time that the audio endpoint device read the device position (**pu64Position*) in response to the **GetPosition** call. The method converts the counter value to 100-nanosecond time units before writing it to **pu64QPCPosition*. This parameter can be **NULL** if the client does not require the performance counter value.

## Return value

If the method succeeds and obtains an accurate reading of the position, it returns S_OK. If the method succeeds but the duration of the call is long enough to detract from the accuracy of the position reading, the method returns S_FALSE. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Parameter *pu64Position* is **NULL**. |
| **AUDCLNT_E_DEVICE_INVALIDATED** | The audio endpoint device has been unplugged, or the audio hardware or associated hardware resources have been reconfigured, disabled, removed, or otherwise made unavailable for use. |
| **AUDCLNT_E_SERVICE_NOT_RUNNING** | The Windows audio service is not running. |

## Remarks

Rendering or capture clients that need to expose a clock based on the stream's current playback or record position can use this method to derive that clock.

This method retrieves two correlated stream-position values:

* Device position. The client obtains the device position through output parameter *pu64Position*. This is the stream position of the sample that is currently playing through the speakers (for a rendering stream) or being recorded through the microphone (for a capture stream).
* Performance counter. The client obtains the performance counter through output parameter *pu64QPCPosition*. This is the counter value that the method obtained by calling the **QueryPerformanceCounter** function at the time that the audio endpoint device recorded the stream position (**pu64Position*). Note that **GetPosition** converts the counter value to 100-nanosecond time units.

The device position is meaningless unless it is combined with the device frequency reported by the **IAudioClock::GetFrequency** method. The reason is that the units in which the device positions for different streams are expressed might vary according to factors such as whether the stream was opened in shared mode or exclusive mode. However, the frequency *f* obtained from **GetFrequency** is always expressed in units that are compatible with those of the device position *p*. Thus, the stream-relative offset in seconds can always be calculated as *p*/*f*.

The device position is a stream-relative offset. That is, it is specified as an offset from the start of the stream. The device position can be thought of as an offset into an idealized buffer that contains the entire stream and is contiguous from beginning to end.

Given the device position and the performance counter at the time of the **GetPosition** call, the client can provide a more timely estimate of the device position at a slightly later time by calling **QueryPerformanceCounter** to obtain the current performance counter, and extrapolating the device position based on how far the counter has advanced since the original device position was recorded. The client can call the **QueryPerformanceFrequency** function to determine the frequency of the clock that increments the counter. Before comparing the raw counter value obtained from **QueryPerformanceCounter** to the value written to **pu64QPCPosition* by **GetPosition**, convert the raw counter value to 100-nanosecond time units as follows:

1. Multiply the raw counter value by 10,000,000.
2. Divide the result by the counter frequency obtained from **QueryPerformanceFrequency**.

For more information about **QueryPerformanceCounter** and **QueryPerformanceFrequency**, see the Windows SDK documentation.

Immediately following creation of a new stream, the device position is 0. Following a call to the [IAudioClient::Start](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-start) method, the device position increments at a uniform rate. The [IAudioClient::Stop](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-stop) method freezes the device position, and a subsequent **Start** call causes the device position to resume incrementing from its value at the time of the **Stop** call. A call to [IAudioClient::Reset](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-reset), which should only occur while the stream is stopped, resets the device position to 0.

When a new or reset rendering stream initially begins running, its device position might remain 0 for a few milliseconds until the audio data has had time to propagate from the endpoint buffer to the rendering endpoint device. The device position changes from 0 to a nonzero value when the data begins playing through the device.

Successive device readings are monotonically increasing. Although the device position might not change between two successive readings, the device position never decreases from one reading to the next.

The *pu64Position* parameter must be a valid, non-**NULL** pointer or the method will fail and return error code E_POINTER.

Position measurements might occasionally be delayed by intermittent, high-priority events. These events might be unrelated to audio. In the case of an exclusive-mode stream, the method can return S_FALSE instead of S_OK if the method succeeds but the duration of the call is long enough to detract from the accuracy of the reported position. When this occurs, the caller has the option of calling the method again to attempt to retrieve a more accurate position (as indicated by return value S_OK). However, the caller should avoid performing this test in an infinite loop in the event that the method consistently returns S_FALSE.

## See also

[IAudioClient::Reset](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-reset)

[IAudioClient::Start](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-start)

[IAudioClient::Stop](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-stop)

[IAudioClock Interface](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudioclock)

[IAudioClock::GetFrequency](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclock-getfrequency)
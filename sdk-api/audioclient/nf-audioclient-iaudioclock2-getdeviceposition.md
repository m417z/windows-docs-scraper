# IAudioClock2::GetDevicePosition

## Description

The **GetDevicePosition** method gets the current device position, in frames, directly from the hardware.

## Parameters

### `DevicePosition` [out]

Receives the device position, in frames. The received position is an unprocessed value that the method obtains directly from the hardware. For more information, see Remarks.

### `QPCPosition` [out]

Receives the value of the performance counter at the time that the audio endpoint device read the device position retrieved in the *DevicePosition* parameter in response to the **GetDevicePosition** call.
**GetDevicePosition** converts the counter value to 100-nanosecond time units before writing it to *QPCPosition*.
*QPCPosition* can be **NULL** if the client does not require the performance counter value.
For more information, see Remarks.

## Return value

If the method succeeds, it returns S_OK.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Parameter *DevicePosition* is **NULL**. |
| **AUDCLNT_E_DEVICE_INVALIDATED** | The audio endpoint has been disconnected. |
| **AUDCLNT_S_POSITION_STALLED** | The [IAudioClient::Start](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-start) method has not been called for this stream. |

## Remarks

This method only applies to shared-mode streams.

This method retrieves two correlated stream-position values:

* Device position. The client retrieves the unprocessed device position in *DevicePosition*. This is the stream position of the sample that is currently playing through the speakers (for a rendering stream) or being recorded through the microphone (for a capture stream). The sampling rate of the device endpoint may be different from the sampling rate of the mix format used by the client.
  To retrieve the device position from the client, call [IAudioClock::GetPosition](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclock-getposition).
* Performance counter. The client retrieves the performance counter in *QPCPosition*. **GetDevicePosition** obtains the counter value by calling the **QueryPerformanceCounter** function at the time that the audio endpoint device stores the stream position in the *DevicePosition* parameter of the **GetDevicePosition** method. **GetDevicePosition** converts the counter value to 100-nanosecond time units. For more information about **QueryPerformanceCounter** and **QueryPerformanceFrequency**, see the Windows SDK documentation.

Given the device position and the performance counter at the time of the **GetDevicePosition** call, the client can get a more timely estimate of the device position at a later time by calling **QueryPerformanceCounter** to obtain the current performance counter, and extrapolating the device position based on how far the counter has advanced since the original device position was recorded. The client can call the **QueryPerformanceCounter** function to get the frequency of the clock that increments the counter. Before comparing the raw counter value obtained from **QueryPerformanceCounter** to the value retrieved by **GetDevicePosition**, convert the raw counter value to 100-nanosecond time units as follows:

1. Multiply the raw counter value by 10,000,000.
2. Divide the result by the counter frequency obtained from **QueryPerformanceFrequency**.

## See also

[IAudioClock2](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudioclock2)
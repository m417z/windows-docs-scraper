# IAudioClient::Initialize

## Description

The **Initialize** method initializes the audio stream.

## Parameters

### `ShareMode` [in]

The sharing mode for the connection. Through this parameter, the client tells the audio engine whether it wants to share the audio endpoint device with other clients. The client should set this parameter to one of the following [AUDCLNT_SHAREMODE](https://learn.microsoft.com/windows/win32/api/audiosessiontypes/ne-audiosessiontypes-audclnt_sharemode) enumeration values:

AUDCLNT_SHAREMODE_EXCLUSIVE

AUDCLNT_SHAREMODE_SHARED

### `StreamFlags` [in]

Flags to control creation of the stream. The client should set this parameter to 0 or to the bitwise OR of one or more of the [AUDCLNT_STREAMFLAGS_XXX Constants](https://learn.microsoft.com/windows/desktop/CoreAudio/audclnt-streamflags-xxx-constants) or the [AUDCLNT_SESSIONFLAGS_XXX Constants](https://learn.microsoft.com/windows/desktop/CoreAudio/audclnt-sessionflags-xxx-constants).

### `hnsBufferDuration` [in]

The buffer capacity as a time value. This parameter is of type **REFERENCE_TIME** and is expressed in 100-nanosecond units. This parameter contains the buffer size that the caller requests for the buffer that the audio application will share with the audio engine (in shared mode) or with the endpoint device (in exclusive mode). If the call succeeds, the method allocates a buffer that is a least this large. For more information about **REFERENCE_TIME**, see the Windows SDK documentation. For more information about buffering requirements, see Remarks.

### `hnsPeriodicity` [in]

The device period. This parameter can be nonzero only in exclusive mode. In shared mode, always set this parameter to 0. In exclusive mode, this parameter specifies the requested scheduling period for successive buffer accesses by the audio endpoint device. If the requested device period lies outside the range that is set by the device's minimum period and the system's maximum period, then the method clamps the period to that range. If this parameter is 0, the method sets the device period to its default value. To obtain the default device period, call the [IAudioClient::GetDevicePeriod](https://learn.microsoft.com/windows/win32/api/audioclient/nf-audioclient-iaudioclient-getdeviceperiod) method. If the AUDCLNT_STREAMFLAGS_EVENTCALLBACK stream flag is set and AUDCLNT_SHAREMODE_EXCLUSIVE is set as the ShareMode, then *hnsPeriodicity* must be nonzero and equal to *hnsBufferDuration*.

### `pFormat` [in]

Pointer to a format descriptor. This parameter must point to a valid format descriptor of type **WAVEFORMATEX** (or **WAVEFORMATEXTENSIBLE**). For more information, see Remarks.

### `AudioSessionGuid` [in]

Pointer to a session GUID. This parameter points to a GUID value that identifies the audio session that the stream belongs to. If the GUID identifies a session that has been previously opened, the method adds the stream to that session. If the GUID does not identify an existing session, the method opens a new session and adds the stream to that session. The stream remains a member of the same session for its lifetime. Setting this parameter to **NULL** is equivalent to passing a pointer to a GUID_NULL value.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **AUDCLNT_E_ALREADY_INITIALIZED** | The **IAudioClient** object is already initialized. |
| **AUDCLNT_E_WRONG_ENDPOINT_TYPE** | The AUDCLNT_STREAMFLAGS_LOOPBACK flag is set but the endpoint device is a capture device, not a rendering device. |
| **AUDCLNT_E_BUFFER_SIZE_NOT_ALIGNED** | **Note** Applies to Windows 7 and later.<br><br>The requested buffer size is not aligned. This code can be returned for a render or a capture device if the caller specified AUDCLNT_SHAREMODE_EXCLUSIVE and the AUDCLNT_STREAMFLAGS_EVENTCALLBACK flags. The caller must call [Initialize](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-initialize) again with the aligned buffer size. For more information, see Remarks. |
| **AUDCLNT_E_BUFFER_SIZE_ERROR** | **Note** Applies to Windows 7 and later.<br><br>Indicates that the buffer duration value requested by an exclusive-mode client is out of range. The requested duration value for pull mode must not be greater than 5000 milliseconds; for push mode the duration value must not be greater than 2 seconds. |
| **AUDCLNT_E_CPUUSAGE_EXCEEDED** | Indicates that the process-pass duration exceeded the maximum CPU usage. The audio engine keeps track of CPU usage by maintaining the number of times the process-pass duration exceeds the maximum CPU usage. The maximum CPU usage is calculated as a percent of the engine's periodicity. The percentage value is the system's CPU throttle value (within the range of 10% and 90%). If this value is not found, then the default value of 40% is used to calculate the maximum CPU usage. |
| **AUDCLNT_E_DEVICE_INVALIDATED** | The audio endpoint device has been unplugged, or the audio hardware or associated hardware resources have been reconfigured, disabled, removed, or otherwise made unavailable for use. |
| **AUDCLNT_E_RESOURCES_INVALIDATED** | The stream's resources have been invalidated. This error may be thrown for the following reasons:\<br>- The stream is suspended.\<br>- An Exclusive or Offload stream is disconnected.\<br>- A packaged application that has an exclusive mode or offload stream is quiesced.\<br>- A "protected output" stream is closed.\ |
| **AUDCLNT_E_DEVICE_IN_USE** | The endpoint device is already in use. Either the device is being used in exclusive mode, or the device is being used in shared mode and the caller asked to use the device in exclusive mode. |
| **AUDCLNT_E_ENDPOINT_CREATE_FAILED** | The method failed to create the audio endpoint for the render or the capture device. This can occur if the audio endpoint device has been unplugged, or the audio hardware or associated hardware resources have been reconfigured, disabled, removed, or otherwise made unavailable for use. |
| **AUDCLNT_E_INVALID_DEVICE_PERIOD** | **Note** Applies to Windows 7 and later.<br><br>Indicates that the device period requested by an exclusive-mode client is greater than 5000 milliseconds. |
| **AUDCLNT_E_UNSUPPORTED_FORMAT** | The audio engine (shared mode) or audio endpoint device (exclusive mode) does not support the specified format. |
| **AUDCLNT_E_EXCLUSIVE_MODE_NOT_ALLOWED** | The caller is requesting exclusive-mode use of the endpoint device, but the user has disabled exclusive-mode use of the device. |
| **AUDCLNT_E_BUFDURATION_PERIOD_NOT_EQUAL** | The AUDCLNT_STREAMFLAGS_EVENTCALLBACK flag is set but parameters *hnsBufferDuration* and *hnsPeriodicity* are not equal. |
| **AUDCLNT_E_SERVICE_NOT_RUNNING** | The Windows audio service is not running. |
| **E_POINTER** | Parameter *pFormat* is **NULL**. |
| **E_INVALIDARG** | Parameter *pFormat* points to an invalid format description; or the AUDCLNT_STREAMFLAGS_LOOPBACK flag is set but *ShareMode* is not equal to AUDCLNT_SHAREMODE_SHARED; or the AUDCLNT_STREAMFLAGS_CROSSPROCESS flag is set but *ShareMode* is equal to AUDCLNT_SHAREMODE_EXCLUSIVE.<br><br>A prior call to [SetClientProperties](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient2-setclientproperties) was made with an invalid category for audio/render streams. |
| **E_OUTOFMEMORY** | Out of memory. |

## Remarks

After activating an [IAudioClient](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudioclient) interface on an audio endpoint device, the client must successfully call **Initialize** once and only once to initialize the audio stream between the client and the device. The client can either connect directly to the audio hardware (exclusive mode) or indirectly through the audio engine (shared mode). In the **Initialize** call, the client specifies the audio data format, the buffer size, and audio session for the stream.

**Note** In Windows 8, the first use of [IAudioClient](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudioclient) to access the audio device should be on the STA thread. Calls from an MTA thread may result in undefined behavior.

An attempt to create a shared-mode stream can succeed only if the audio device is already operating in shared mode or the device is currently unused. An attempt to create a shared-mode stream fails if the device is already operating in exclusive mode.

If a stream is initialized to be event driven and in shared mode, *ShareMode* is set to AUDCLNT_SHAREMODE_SHARED and one of the stream flags that are set includes AUDCLNT_STREAMFLAGS_EVENTCALLBACK. For such a stream, the associated application must also obtain a handle by making a call to [IAudioClient::SetEventHandle](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-seteventhandle). When it is time to retire the stream, the audio engine can then use the handle to release the stream objects. Failure to call **IAudioClient::SetEventHandle** before releasing the stream objects can cause a delay of several seconds (a time-out period) while the audio engine waits for an available handle. After the time-out period expires, the audio engine then releases the stream objects.

Whether an attempt to create an exclusive-mode stream succeeds depends on several factors, including the availability of the device and the user-controlled settings that govern exclusive-mode operation of the device. For more information, see [Exclusive-Mode Streams](https://learn.microsoft.com/windows/desktop/CoreAudio/exclusive-mode-streams).

An **IAudioClient** object supports exactly one connection to the audio engine or audio hardware. This connection lasts for the lifetime of the **IAudioClient** object.

The client should call the following methods only *after* calling **Initialize**:

* [IAudioClient::GetBufferSize](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-getbuffersize)
* [IAudioClient::GetCurrentPadding](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-getcurrentpadding)
* [IAudioClient::GetService](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-getservice)
* [IAudioClient::GetStreamLatency](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-getstreamlatency)
* [IAudioClient::Reset](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-reset)
* [IAudioClient::SetEventHandle](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-seteventhandle)
* [IAudioClient::Start](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-start)
* [IAudioClient::Stop](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-stop)

The following methods do not require that **Initialize** be called first:

* [IAudioClient::GetDevicePeriod](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-getdeviceperiod)
* [IAudioClient::GetMixFormat](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-getmixformat)
* [IAudioClient::IsFormatSupported](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-isformatsupported)

These methods can be called any time after activating the **IAudioClient** interface.

Before calling **Initialize** to set up a shared-mode or exclusive-mode connection, the client can call the [IAudioClient::IsFormatSupported](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-isformatsupported) method to discover whether the audio engine or audio endpoint device supports a particular format in that mode. Before opening a shared-mode connection, the client can obtain the audio engine's mix format by calling the [IAudioClient::GetMixFormat](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-getmixformat) method.

The endpoint buffer that is shared between the client and audio engine must be large enough to prevent glitches from occurring in the audio stream between processing passes by the client and audio engine. For a rendering endpoint, the client thread periodically writes data to the buffer, and the audio engine thread periodically reads data from the buffer. For a capture endpoint, the engine thread periodically writes to the buffer, and the client thread periodically reads from the buffer. In either case, if the periods of the client thread and engine thread are not equal, the buffer must be large enough to accommodate the longer of the two periods without allowing glitches to occur.

The client specifies a buffer size through the *hnsBufferDuration* parameter. The client is responsible for requesting a buffer that is large enough to ensure that glitches cannot occur between the periodic processing passes that it performs on the buffer. Similarly, the **Initialize** method ensures that the buffer is never smaller than the minimum buffer size needed to ensure that glitches do not occur between the periodic processing passes that the engine thread performs on the buffer. If the client requests a buffer size that is smaller than the audio engine's minimum required buffer size, the method sets the buffer size to this minimum buffer size rather than to the buffer size requested by the client.

If the client requests a buffer size (through the *hnsBufferDuration* parameter) that is not an integral number of audio frames, the method rounds up the requested buffer size to the next integral number of frames.

Following the **Initialize** call, the client should call the [IAudioClient::GetBufferSize](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-getbuffersize) method to get the precise size of the endpoint buffer. During each processing pass, the client will need the actual buffer size to calculate how much data to transfer to or from the buffer. The client calls the [IAudioClient::GetCurrentPadding](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-getcurrentpadding) method to determine how much of the data in the buffer is currently available for processing.

To achieve the minimum stream latency between the client application and audio endpoint device, the client thread should run at the same period as the audio engine thread. The period of the engine thread is fixed and cannot be controlled by the client. Making the client's period smaller than the engine's period unnecessarily increases the client thread's load on the processor without improving latency or decreasing the buffer size. To determine the period of the engine thread, the client can call the [IAudioClient::GetDevicePeriod](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-getdeviceperiod) method. To set the buffer to the minimum size required by the engine thread, the client should call **Initialize** with the *hnsBufferDuration* parameter set to 0. Following the **Initialize** call, the client can get the size of the resulting buffer by calling **IAudioClient::GetBufferSize**.

A client has the option of requesting a buffer size that is larger than what is strictly necessary to make timing glitches rare or nonexistent. Increasing the buffer size does not necessarily increase the stream latency. For a rendering stream, the latency through the buffer is determined solely by the separation between the client's write pointer and the engine's read pointer. For a capture stream, the latency through the buffer is determined solely by the separation between the engine's write pointer and the client's read pointer.

The loopback flag (AUDCLNT_STREAMFLAGS_LOOPBACK) enables audio loopback. A client can enable audio loopback only on a rendering endpoint with a shared-mode stream. Audio loopback is provided primarily to support acoustic echo cancellation (AEC).

An AEC client requires both a rendering endpoint and the ability to capture the output stream from the audio engine. The engine's output stream is the global mix that the audio device plays through the speakers. If audio loopback is enabled, a client can open a capture buffer for the global audio mix by calling the [IAudioClient::GetService](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-getservice) method to obtain an [IAudioCaptureClient](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudiocaptureclient) interface on the rendering stream object. If audio loopback is not enabled, then an attempt to open a capture buffer on a rendering stream will fail. The loopback data in the capture buffer is in the device format, which the client can obtain by querying the device's [PKEY_AudioEngine_DeviceFormat](https://learn.microsoft.com/windows/desktop/CoreAudio/pkey-audioengine-deviceformat) property.

On Windows versions prior to Windows 10, a pull-mode capture client will not receive any events when a stream is initialized with event-driven buffering (AUDCLNT_STREAMFLAGS_EVENTCALLBACK) and is loopback-enabled (AUDCLNT_STREAMFLAGS_LOOPBACK). If the stream is opened with this configuration, the **Initialize** call succeeds, but relevant events are not raised to notify the capture client each time a buffer becomes ready for processing. To work around this, initialize a render stream in event-driven mode. Each time the client receives an event for the render stream, it must signal the capture client to run the capture thread that reads the next set of samples from the capture endpoint buffer.
As of Windows 10 the relevant event handles are now set for loopback-enabled streams that are active.

Note that all streams must be opened in share mode because exclusive-mode streams cannot operate in loopback mode.
For more information about audio loopback, see [Loopback Recording](https://learn.microsoft.com/windows/desktop/CoreAudio/loopback-recording).

The AUDCLNT_STREAMFLAGS_EVENTCALLBACK flag indicates that processing of the audio buffer by the client will be event driven. WASAPI supports event-driven buffering to enable low-latency processing of both shared-mode and exclusive-mode streams.

The initial release of Windows Vista supports event-driven buffering (that is, the use of the AUDCLNT_STREAMFLAGS_EVENTCALLBACK flag) for rendering streams only.

In the initial release of Windows Vista, for capture streams, the AUDCLNT_STREAMFLAGS_EVENTCALLBACK flag is supported only in shared mode. Setting this flag has no effect for exclusive-mode capture streams. That is, although the application specifies this flag in exclusive mode through the **Initialize** call, the application will not receive any events that are usually required to capture the audio stream. In the Windows Vista Service Pack 1 release, this flag is functional in shared-mode and exclusive mode; an application can set this flag to enable event-buffering for capture streams. For more information about capturing an audio stream, see [Capturing a Stream](https://learn.microsoft.com/windows/desktop/CoreAudio/capturing-a-stream).

To enable event-driven buffering, the client must provide an event handle to the system. Following the **Initialize** call and before calling the [IAudioClient::Start](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-start) method to start the stream, the client must call the [IAudioClient::SetEventHandle](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-seteventhandle) method to set the event handle. While the stream is running, the system periodically signals the event to indicate to the client that audio data is available for processing. Between processing passes, the client thread waits on the event handle by calling a synchronization function such as **WaitForSingleObject**. For more information about synchronization functions, see the Windows SDK documentation.

For a shared-mode stream that uses event-driven buffering, the caller must set both *hnsPeriodicity* and *hnsBufferDuration* to 0. The **Initialize** method determines how large a buffer to allocate based on the scheduling period of the audio engine. Although the client's buffer processing thread is event driven, the basic buffer management process, as described previously, is unaltered. Each time the thread awakens, it should call [IAudioClient::GetCurrentPadding](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-getcurrentpadding) to determine how much data to write to a rendering buffer or read from a capture buffer. In contrast to the two buffers that the **Initialize** method allocates for an exclusive-mode stream that uses event-driven buffering, a shared-mode stream requires a single buffer.

For an exclusive-mode stream that uses event-driven buffering, the caller must specify nonzero values for *hnsPeriodicity* and *hnsBufferDuration*, and the values of these two parameters must be equal. The **Initialize** method allocates two buffers for the stream. Each buffer is equal in duration to the value of the *hnsBufferDuration* parameter. Following the **Initialize** call for a rendering stream, the caller should fill the first of the two buffers before starting the stream. For a capture stream, the buffers are initially empty, and the caller should assume that each buffer remains empty until the event for that buffer is signaled. While the stream is running, the system alternately sends one buffer or the other to the client—this form of double buffering is referred to as "ping-ponging". Each time the client receives a buffer from the system (which the system indicates by signaling the event), the client must process the entire buffer. For example, if the client requests a packet size from the [IAudioRenderClient::GetBuffer](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudiorenderclient-getbuffer) method that does not match the buffer size, the method fails. Calls to the **IAudioClient::GetCurrentPadding** method are unnecessary because the packet size must always equal the buffer size. In contrast to the buffering modes discussed previously, the latency for an event-driven, exclusive-mode stream depends directly on the buffer size.

As explained in [Audio Sessions](https://learn.microsoft.com/windows/desktop/CoreAudio/audio-sessions), the default behavior for a session that contains rendering streams is that its volume and mute settings persist across application restarts. The AUDCLNT_STREAMFLAGS_NOPERSIST flag overrides the default behavior and makes the settings nonpersistent. This flag has no effect on sessions that contain capture streams—the settings for those sessions are never persistent. In addition, the settings for a session that contains a loopback stream (a stream that is initialized with the AUDCLNT_STREAMFLAGS_LOOPBACK flag) are not persistent.

Only a session that connects to a rendering endpoint device can have persistent volume and mute settings. The first stream to be added to the session determines whether the session's settings are persistent. Thus, if the AUDCLNT_STREAMFLAGS_NOPERSIST or AUDCLNT_STREAMFLAGS_LOOPBACK flag is set during initialization of the first stream, the session's settings are not persistent. Otherwise, they are persistent. Their persistence is unaffected by additional streams that might be subsequently added or removed during the lifetime of the session object.

After a call to **Initialize** has successfully initialized an **IAudioClient** interface instance, a subsequent **Initialize** call to initialize the same interface instance will fail and return error code E_ALREADY_INITIALIZED.

If the initial call to **Initialize** fails, subsequent **Initialize** calls might fail and return error code E_ALREADY_INITIALIZED, even though the interface has not been initialized. If this occurs, release the **IAudioClient** interface and obtain a new **IAudioClient** interface from the [MMDevice API](https://learn.microsoft.com/windows/desktop/CoreAudio/mmdevice-api) before calling **Initialize** again.

For code examples that call the **Initialize** method, see the following topics:

* [Rendering a Stream](https://learn.microsoft.com/windows/desktop/CoreAudio/rendering-a-stream)
* [Capturing a Stream](https://learn.microsoft.com/windows/desktop/CoreAudio/capturing-a-stream)
* [Exclusive-Mode Streams](https://learn.microsoft.com/windows/desktop/CoreAudio/exclusive-mode-streams)

Starting with Windows 7, **Initialize** can return AUDCLNT_E_BUFFER_SIZE_NOT_ALIGNED for a render or a capture device. This indicates that the buffer size, specified by the caller in the *hnsBufferDuration* parameter, is not aligned. This error code is returned only if the caller requested an exclusive-mode stream (AUDCLNT_SHAREMODE_EXCLUSIVE) and event-driven buffering (AUDCLNT_STREAMFLAGS_EVENTCALLBACK).

 If **Initialize** returns AUDCLNT_E_BUFFER_SIZE_NOT_ALIGNED, the caller must call **Initialize** again and specify the aligned buffer size. Use the following steps:

1. Call [IAudioClient::GetBufferSize](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-getbuffersize) and receive the next-highest-aligned buffer size (in frames).
2. Call **IAudioClient::Release** to release the audio client used in the previous call that returned AUDCLNT_E_BUFFER_SIZE_NOT_ALIGNED.
3. Calculate the aligned buffer size in 100-nanosecond units (hns). The buffer size is `(REFERENCE_TIME)((10000.0 * 1000 / WAVEFORMATEX.nSamplesPerSecond * nFrames) + 0.5)`. In this formula, `nFrames` is the buffer size retrieved by [GetBufferSize](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-getbuffersize).
4. Call the [IMMDevice::Activate](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nf-mmdeviceapi-immdevice-activate) method with parameter *iid* set to REFIID IID_IAudioClient to create a new audio client.
5. Call **Initialize** again on the created audio client and specify the new buffer size and periodicity.

Starting with Windows 10, hardware-offloaded audio streams must be event driven. This means that if you call [IAudioClient2::SetClientProperties](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient2-setclientproperties) and set the *bIsOffload* parameter of the [AudioClientProperties](https://learn.microsoft.com/windows/win32/api/audioclient/ns-audioclient-audioclientproperties-r1) to TRUE, you must specify the **AUDCLNT_STREAMFLAGS_EVENTCALLBACK** flag in the *StreamFlags* parameter to **IAudioClient::Initialize**.

#### Examples

The following example code shows how to respond to the **AUDCLNT_E_BUFFER_SIZE_NOT_ALIGNED** return code.

```cpp
#define REFTIMES_PER_SEC  10000000

HRESULT CreateAudioClient(IMMDevice* pDevice, IAudioClient** ppAudioClient)
{
    if (!pDevice)
    {
        return E_INVALIDARG;
    }

    if (!ppAudioClient)
    {
        return E_POINTER;
    }

    HRESULT hr = S_OK;

    WAVEFORMATEX *pwfx = NULL;

    REFERENCE_TIME hnsRequestedDuration = REFTIMES_PER_SEC;

    UINT32 nFrames = 0;

    IAudioClient *pAudioClient = NULL;

    // Get the audio client.
    CHECK_HR( hr = pDevice->Activate(
        __uuidof(IAudioClient),
        CLSCTX_ALL,
        NULL,
        (void**)&pAudioClient));

    // Get the device format.
    CHECK_HR( hr = pAudioClient->GetMixFormat(&pwfx));

    // Open the stream and associate it with an audio session.
    hr = pAudioClient->Initialize(
        AUDCLNT_SHAREMODE_EXCLUSIVE,
        AUDCLNT_STREAMFLAGS_EVENTCALLBACK,
        hnsRequestedDuration,
        hnsRequestedDuration,
        pwfx,
        NULL);

    // If the requested buffer size is not aligned...
    if (hr == AUDCLNT_E_BUFFER_SIZE_NOT_ALIGNED)
    {	
        // Get the next aligned frame.
        CHECK_HR( hr = pAudioClient->GetBufferSize(&nFrames));

        hnsRequestedDuration = (REFERENCE_TIME)
        ((10000.0 * 1000 / pwfx->nSamplesPerSec * nFrames) + 0.5);

        // Release the previous allocations.
        SAFE_RELEASE(pAudioClient);
        CoTaskMemFree(pwfx);

        // Create a new audio client.
        CHECK_HR( hr = pDevice->Activate(
            __uuidof(IAudioClient),
            CLSCTX_ALL,
            NULL,
            (void**)&pAudioClient));

        // Get the device format.
        CHECK_HR( hr = pAudioClient->GetMixFormat(&pwfx));

        // Open the stream and associate it with an audio session.
        CHECK_HR( hr = pAudioClient->Initialize(
            AUDCLNT_SHAREMODE_EXCLUSIVE,
            AUDCLNT_STREAMFLAGS_EVENTCALLBACK,
            hnsRequestedDuration,
            hnsRequestedDuration,
            pwfx,
            NULL));
    }
    else
    {
        CHECK_HR (hr);
    }

    // Return to the caller.
    *(ppAudioClient) = pAudioClient;
    (*ppAudioClient)->AddRef();

done:

    // Clean up.
    CoTaskMemFree(pwfx);
    SAFE_RELEASE(pAudioClient);
    return hr;
}

```

## See also

[IAudioCaptureClient Interface](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudiocaptureclient)

[IAudioClient Interface](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudioclient)

[IAudioClient::GetBufferSize](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-getbuffersize)

[IAudioClient::GetCurrentPadding](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-getcurrentpadding)

[IAudioClient::GetDevicePeriod](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-getdeviceperiod)

[IAudioClient::GetMixFormat](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-getmixformat)

[IAudioClient::GetService](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-getservice)

[IAudioClient::SetEventHandle](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-seteventhandle)

[IAudioClient::Start](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-start)

[IAudioRenderClient::GetBuffer](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudiorenderclient-getbuffer)
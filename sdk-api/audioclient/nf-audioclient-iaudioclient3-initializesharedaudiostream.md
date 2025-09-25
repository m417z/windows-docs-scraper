# IAudioClient3::InitializeSharedAudioStream

## Description

Initializes a shared stream with the specified periodicity.

## Parameters

### `StreamFlags` [in]

Type: **DWORD**

Flags to control creation of the stream. The client should set this parameter to 0 or to the bitwise OR of one or more of the supported [AUDCLNT_STREAMFLAGS_XXX Constants](https://learn.microsoft.com/windows/desktop/CoreAudio/audclnt-streamflags-xxx-constants) or [AUDCLNT_SESSIONFLAGS_XXX Constants](https://learn.microsoft.com/windows/desktop/CoreAudio/audclnt-sessionflags-xxx-constants). The supported [AUDCLNT_STREAMFLAGS_XXX Constants](https://learn.microsoft.com/windows/desktop/CoreAudio/audclnt-streamflags-xxx-constants) for this parameter when using this method are:

- AUDCLNT_STREAMFLAGS_EVENTCALLBACK

### `PeriodInFrames` [in]

Type: **UINT32**

Periodicity requested by the client. This value must be an integral multiple of the value returned in the *pFundamentalPeriodInFrames* parameter to [IAudioClient3::GetSharedModeEnginePeriod](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient3-getsharedmodeengineperiod). *PeriodInFrames* must also be greater than or equal to the value returned in *pMinPeriodInFrames* and less than or equal to the value returned in *pMaxPeriodInFrames*.

### `pFormat` [in]

Type: **const [WAVEFORMATEX](https://learn.microsoft.com/previous-versions/dd757713(v=vs.85))***

Pointer to a format descriptor. This parameter must point to a valid format descriptor of type [WAVEFORMATEX](https://learn.microsoft.com/previous-versions/dd757713(v=vs.85)) or [WAVEFORMATEXTENSIBLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ksmedia/ns-ksmedia-waveformatextensible). For more information, see the Remarks section for [IAudioClient::Initialize](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-initialize).

### `AudioSessionGuid` [in, optional]

Type: **LPCGUID**

Pointer to a session GUID. This parameter points to a GUID value that identifies the audio session that the stream belongs to. If the GUID identifies a session that has been previously opened, the method adds the stream to that session. If the GUID does not identify an existing session, the method opens a new session and adds the stream to that session. The stream remains a member of the same session for its lifetime. Setting this parameter to **NULL** is equivalent to passing a pointer to a GUID_NULL value.

## Return value

Type: **HRESULT**

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **AUDCLNT_E_ALREADY_INITIALIZED** | The **IAudioClient** object is already initialized. |
| **AUDCLNT_E_WRONG_ENDPOINT_TYPE** | The AUDCLNT_STREAMFLAGS_LOOPBACK flag is set but the endpoint device is a capture device, not a rendering device. |
| **AUDCLNT_E_CPUUSAGE_EXCEEDED** | Indicates that the process-pass duration exceeded the maximum CPU usage. The audio engine keeps track of CPU usage by maintaining the number of times the process-pass duration exceeds the maximum CPU usage. The maximum CPU usage is calculated as a percent of the engine's periodicity. The percentage value is the system's CPU throttle value (within the range of 10% and 90%). If this value is not found, then the default value of 40% is used to calculate the maximum CPU usage. |
| **AUDCLNT_E_DEVICE_INVALIDATED** | The audio endpoint device has been unplugged, or the audio hardware or associated hardware resources have been reconfigured, disabled, removed, or otherwise made unavailable for use. |
| **AUDCLNT_E_DEVICE_IN_USE** | The endpoint device is already in use. Either the device is being used in exclusive mode, or the device is being used in shared mode and the caller asked to use the device in exclusive mode. |
| **AUDCLNT_E_ENGINE_FORMAT_LOCKED** | The client specified [AUDCLNT_STREAMOPTIONS_MATCH_FORMAT](https://learn.microsoft.com/windows/desktop/api/audioclient/ne-audioclient-audclnt_streamoptions) when calling [IAudioClient2::SetClientProperties](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient2-setclientproperties), but the format of the audio engine has been locked by another client. In this case, you can call **IAudioClient2::SetClientProperties** without specifying the match format option and then use audio engine's current format. |
| **AUDCLNT_E_ENGINE_PERIODICITY_LOCKED** | The client specified [AUDCLNT_STREAMOPTIONS_MATCH_FORMAT](https://learn.microsoft.com/windows/desktop/api/audioclient/ne-audioclient-audclnt_streamoptions) when calling [IAudioClient2::SetClientProperties](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient2-setclientproperties), but the periodicity of the audio engine has been locked by another client. In this case, you can call **IAudioClient2::SetClientProperties** without specifying the match format option and then use audio engine's current periodicity. |
| **AUDCLNT_E_ENDPOINT_CREATE_FAILED** | The method failed to create the audio endpoint for the render or the capture device. This can occur if the audio endpoint device has been unplugged, or the audio hardware or associated hardware resources have been reconfigured, disabled, removed, or otherwise made unavailable for use. |
| **AUDCLNT_E_INVALID_DEVICE_PERIOD** | Indicates that the requested device period specified with the *PeriodInFrames* is not an integral multiple of the fundamental periodicity of the audio engine, is shorter than the engine's minimum period, or is longer than the engine's maximum period. Get the supported periodicity values of the engine by calling [IAudioClient3::GetSharedModeEnginePeriod](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient3-getsharedmodeengineperiod). |
| **AUDCLNT_E_UNSUPPORTED_FORMAT** | The audio engine (shared mode) or audio endpoint device (exclusive mode) does not support the specified format. |
| **AUDCLNT_E_SERVICE_NOT_RUNNING** | The Windows audio service is not running. |
| **E_POINTER** | Parameter *pFormat* is **NULL**. |
| **E_INVALIDARG** | Parameter *pFormat* points to an invalid format description; or the AUDCLNT_STREAMFLAGS_LOOPBACK flag is set but *ShareMode* is not equal to AUDCLNT_SHAREMODE_SHARED; or the AUDCLNT_STREAMFLAGS_CROSSPROCESS flag is set but *ShareMode* is equal to AUDCLNT_SHAREMODE_EXCLUSIVE.<br><br>A prior call to [SetClientProperties](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient2-setclientproperties) was made with an invalid category for audio/render streams. |
| **E_OUTOFMEMORY** | Out of memory. |
| **AUDCLNT_E_RESOURCES_INVALIDATED** | The stream's resources have been invalidated. This error may be thrown for the following reasons:\<br>- The stream is suspended.\<br>- An Exclusive or Offload stream is disconnected.\<br>- A packaged application that has an exclusive mode or offload stream is quiesced.\<br>- A "protected output" stream is closed.\ |

## Remarks

Unlike [IAudioClient::Initialize](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-initialize), this method does not allow you to specify a buffer size. The buffer size is computed based on the periodicity requested with the *PeriodInFrames* parameter. It is the client app's responsibility
to ensure that audio samples are transferred in and out of the buffer in a timely manner.

Audio clients should check for allowed values for the *PeriodInFrames* parameter by calling [IAudioClient3::GetSharedModeEnginePeriod](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient3-getsharedmodeengineperiod). The value of *PeriodInFrames* must be an integral multiple of the value returned in the *pFundamentalPeriodInFrames* parameter. *PeriodInFrames* must also be greater than or equal to the value returned in *pMinPeriodInFrames* and less than or equal to the value of *pMaxPeriodInFrames*.

For example, for a 44100 kHz format, **GetSharedModeEnginePeriod** might return:

* *pDefaultPeriodInFrames* = 448 frames (about 10.16 milliseconds)

* *pFundamentalPeriodInFrames* = 4 frames (about 0.09 milliseconds)

* *pMinPeriodInFrames* = 48 frames (about 1.09 milliseconds)

* *pMaxPeriodInFrames* = 448 frames (same as the default)

Allowed values for the *PeriodInFrames* parameter to **InitializeSharedAudioStream** would include 48 and 448. They would also include things like 96 and 128.

They would NOT include 4 (which is smaller than the minimum allowed value) or 98 (which is not a multiple of the fundamental) or 1000 (which is larger than the maximum allowed value).

## See also

[IAudioClient](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudioclient)

[IAudioClient2](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudioclient2)

[IAudioClient3](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudioclient3)
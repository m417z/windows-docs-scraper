# IAudioClient3::GetSharedModeEnginePeriod

## Description

Returns the range of periodicities supported by the engine for the specified stream format. The periodicity of the engine is the rate at which the engine wakes an event-driven audio client
to transfer audio data to or from the engine.
The values returned depend on the characteristics of the audio client as specified through a previous call to
[IAudioClient2::SetClientProperties](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient2-setclientproperties).

## Parameters

### `pFormat` [in]

Type: **const [WAVEFORMATEX](https://learn.microsoft.com/previous-versions/dd757713(v=vs.85))***

The stream format for which the supported periodicities are queried.

### `pDefaultPeriodInFrames` [out]

Type: **UINT32***

The default period with which the engine will wake the client for
transferring audio samples

### `pFundamentalPeriodInFrames` [out]

Type: **UINT32***

The fundamental period with which the engine will wake the client for
transferring audio samples. When setting the audio engine periodicity, you must use an integral multiple of this value.

### `pMinPeriodInFrames` [out]

Type: **UINT32***

The shortest period, in audio frames, with which the audio engine will wake the client for
transferring audio samples.

### `pMaxPeriodInFrames` [out]

Type: **UINT32***

The longest period, in audio frames, with which the audio engine will wake the client for
transferring audio samples.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns **S_OK** to indicate that it has completed successfully. Otherwise it returns an appropriate error code.

## Remarks

Audio clients request a specific periodicity from the audio engine with the *PeriodInFrames* parameter to [IAudioClient3::InitializeSharedAudioStream](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient3-initializesharedaudiostream). The value of *PeriodInFrames* must be an integral multiple of the value returned in the *pFundamentalPeriodInFrames* parameter. *PeriodInFrames* must also be greater than or equal to the value returned in *pMinPeriodInFrames* and less than or equal to the value of *pMaxPeriodInFrames*.

For example, for a 44100 kHz format, **GetSharedModeEnginePeriod** might return:

* *pDefaultPeriodInFrames* = 448 frames (about 10.16 milliseconds)

* *pFundamentalPeriodInFrames* = 4 frames (about 0.09 milliseconds)

* *pMinPeriodInFrames* = 48 frames (about 1.09 milliseconds)

* *pMaxPeriodInFrames* = 448 frames (same as the default)

Allowed values for the *PeriodInFrames* parameter to **InitializeSharedAudioStream** would include 48 and 448. They would also include things like 96 and 128.

They would NOT include 4 (which is smaller than the minimum allowed value) or 98 (which is not a multiple of the fundamental) or 1000 (which is larger than the maximum allowed value).

## See also

[IAudioClient3](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudioclient3)
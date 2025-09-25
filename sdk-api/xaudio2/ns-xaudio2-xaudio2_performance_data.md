# XAUDIO2_PERFORMANCE_DATA structure

## Description

Contains performance information.

## Members

### `AudioCyclesSinceLastQuery`

CPU cycles spent on audio processing since the last call to the [IXAudio2::StartEngine](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2-startengine) or [IXAudio2::GetPerformanceData](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2-getperformancedata) function.

### `TotalCyclesSinceLastQuery`

Total CPU cycles elapsed since the last call.

**Note** This only counts cycles on the CPU on which XAudio2 is running.

### `MinimumCyclesPerQuantum`

Fewest CPU cycles spent on processing any single audio quantum since the last call.

### `MaximumCyclesPerQuantum`

Most CPU cycles spent on processing any single audio quantum since the last call.

### `MemoryUsageInBytes`

Total memory currently in use.

### `CurrentLatencyInSamples`

Minimum delay that occurs between the time a sample is read from a source buffer and the time it reaches the speakers.

| Windows |
| --- |
| The delay reported is a variable value equal to the rough distance between the last sample submitted to the driver by XAudio2 and the sample currently playing. The following factors can affect the delay: playing multichannel audio on a hardware-accelerated device; the type of audio device (WavePci, WaveCyclic, or WaveRT); and, to a lesser extent, audio hardware implementation. |

| Xbox 360 |
| --- |
| The delay reported is a fixed value, which is normally 1,024 samples (21.333 ms at 48 kHz). If **XOverrideSpeakerConfig** has been called using the **XAUDIOSPEAKERCONFIG_LOW_LATENCY** flag, the delay reported is 512 samples (10.667 ms at 48 kHz). |

### `GlitchesSinceEngineStarted`

Total audio dropouts since the engine started.

### `ActiveSourceVoiceCount`

Number of source voices currently playing.

### `TotalSourceVoiceCount`

Total number of source voices currently in existence.

### `ActiveSubmixVoiceCount`

Number of submix voices currently playing.

### `ActiveResamplerCount`

Number of resampler xAPOs currently active.

### `ActiveMatrixMixCount`

Number of matrix mix xAPOs currently active.

### `ActiveXmaSourceVoices`

| Windows |
| --- |
| Unsupported. |

| Xbox 360 |
| --- |
| Number of source voices decoding XMA data. |

### `ActiveXmaStreams`

| Windows |
| --- |
| Unsupported. |

| Xbox 360 |
| --- |
| A voice can use more than one XMA stream. |

## Remarks

CPU cycles are recorded using . Use to convert these values.

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[IXAudio2::GetPerformanceData](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2-getperformancedata)

[XAudio2 Structures](https://learn.microsoft.com/windows/desktop/xaudio2/structures)
# AecQualityMetrics_Struct structure

## Description

Contains quality metrics for acoustic echo cancellation (AEC). This structure is used with the [MFPKEY_WMAAECMA_RETRIEVE_TS_STATS](https://learn.microsoft.com/windows/desktop/medfound/mfpkey-wmaaecma-retrieve-ts-statsproperty) property.

## Members

### `i64Timestamp`

Time stamp that indicates when the quality metrics were collected.

### `ConvergenceFlag`

AEC convergence flag.

### `MicClippedFlag`

If **TRUE**, the input signal from the audio capture device was clipped.

### `MicSilenceFlag`

If **TRUE**, the input signal from the audio capture device was silent or too quiet.

### `PstvFeadbackFlag`

If **TRUE**, positive feedback is causing a chirping sound.

### `SpkClippedFlag`

If **TRUE**, the input signal from the audio rendering device was clipped.

### `SpkMuteFlag`

If **TRUE**, the input signal from the audio rendering device was silent or too quiet.

### `GlitchFlag`

A glitch occurred in the input data.

### `DoubleTalkFlag`

Double talk flag.

### `uGlitchCount`

Number of glitches.

### `uMicClipCount`

Number of times the audio capture signal was clipped.

### `fDuration`

Running duration of the AEC process.

### `fTSVariance`

Long-term average variance in the time stamps.

### `fTSDriftRate`

Long-term average drift rate in the time stamps.

### `fVoiceLevel`

Near-end voice level after AEC processing.

### `fNoiseLevel`

Noise level of the audio capture signal.

### `fERLE`

Echo return loss enhancement (ERLE).

### `fAvgERLE`

Average ERLE over the entire duration of AEC processing.

### `dwReserved`

Reserved

## See also

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)

[Voice Capture DSP](https://learn.microsoft.com/windows/desktop/medfound/voicecapturedmo)
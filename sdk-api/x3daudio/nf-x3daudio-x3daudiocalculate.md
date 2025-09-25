# X3DAudioCalculate function

## Description

Calculates DSP settings with respect to 3D parameters.

## Parameters

### `Instance` [in]

3D audio instance handle. Call [X3DAudioInitialize](https://learn.microsoft.com/windows/desktop/api/x3daudio/nf-x3daudio-x3daudioinitialize) to get this handle.

### `pListener` [in]

Pointer to an [X3DAUDIO_LISTENER](https://learn.microsoft.com/windows/desktop/api/x3daudio/ns-x3daudio-x3daudio_listener) representing the point of reception.

### `pEmitter` [in]

Pointer to an [X3DAUDIO_EMITTER](https://learn.microsoft.com/windows/desktop/api/x3daudio/ns-x3daudio-x3daudio_emitter) representing the sound source.

### `Flags` [in]

| Value | Description |
| --- | --- |
| X3DAUDIO_CALCULATE_MATRIX | Enables matrix coefficient table calculation. |
| X3DAUDIO_CALCULATE_DELAY | Enables delay time array calculation (stereo only). |
| X3DAUDIO_CALCULATE_LPF_DIRECT | Enables low pass filter (LPF) direct-path coefficient calculation. |
| X3DAUDIO_CALCULATE_LPF_REVERB | Enables LPF reverb-path coefficient calculation. |
| X3DAUDIO_CALCULATE_REVERB | Enables reverb send level calculation. |
| X3DAUDIO_CALCULATE_DOPPLER | Enables Doppler shift factor calculation. |
| X3DAUDIO_CALCULATE_EMITTER_ANGLE | Enables emitter-to-listener interior angle calculation. |
| X3DAUDIO_CALCULATE_ZEROCENTER | Fills the center channel with silence. This flag allows you to keep a 6-channel matrix so you do not have to remap the channels, but the center channel will be silent. This flag is only valid if you also set X3DAUDIO_CALCULATE_MATRIX. |
| X3DAUDIO_CALCULATE_REDIRECT_TO_LFE | Applies an equal mix of all source channels to a low frequency effect (LFE) destination channel. It only applies to matrix calculations with a source that does not have an LFE channel and a destination that does have an LFE channel. This flag is only valid if you also set X3DAUDIO_CALCULATE_MATRIX. |

### `pDSPSettings` [in, out]

Pointer to an [X3DAUDIO_DSP_SETTINGS](https://learn.microsoft.com/windows/desktop/api/x3daudio/ns-x3daudio-x3daudio_dsp_settings) structure that receives the calculation results.

## Return value

This function does not return a value.

## Remarks

You typically call **X3DAudioCalculate** once for each pair of emitting objects and listeners in the scene. After each call, to apply the 3D effects, the app manually applies the calculation results at *pDSPSettings* to the XAUDIO2 graph. For more info, see [How to: Integrate X3DAudio with XAudio2](https://learn.microsoft.com/windows/desktop/xaudio2/how-to--integrate-x3daudio-with-xaudio2).

**Important** The listener and emitter values must be valid. Floating-point specials (NaN, QNaN, +INF, -INF) can cause the entire audio output to go silent if introduced into a running audio graph.

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

**Windows Phone 8.1:** This API is supported.

## See also

[Functions](https://learn.microsoft.com/windows/desktop/xaudio2/functions)
# X3DAUDIO_CONE structure

## Description

Specifies directionality for a single-channel non-LFE emitter by scaling DSP behavior with respect to the emitter's orientation.

## Members

### `InnerAngle`

Inner cone angle in radians. This value must be within 0.0f to X3DAUDIO_2PI.

### `OuterAngle`

Outer cone angle in radians. This value must be within *InnerAngle* to X3DAUDIO_2PI.

### `InnerVolume`

Volume scaler on/within inner cone. This value must be within 0.0f to 2.0f.

### `OuterVolume`

Volume scaler on/beyond outer cone. This value must be within 0.0f to 2.0f.

### `InnerLPF`

LPF direct-path or reverb-path coefficient scaler on/within inner cone. This value is only used for LPF calculations and must be within 0.0f to 1.0f.

### `OuterLPF`

LPF direct-path or reverb-path coefficient scaler on or beyond outer cone. This value is only used for LPF calculations and must be within 0.0f to 1.0f.

### `InnerReverb`

Reverb send level scaler on or within inner cone. This must be within 0.0f to 2.0f.

### `OuterReverb`

Reverb send level scaler on/beyond outer cone. This must be within 0.0f to 2.0f.

## Remarks

For a detailed explanation of sound cones see [Sound Cones](https://learn.microsoft.com/windows/desktop/xaudio2/sound-cones).

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[Structures](https://learn.microsoft.com/windows/desktop/xaudio2/structures)
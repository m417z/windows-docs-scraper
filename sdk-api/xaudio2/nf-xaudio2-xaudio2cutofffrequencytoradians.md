# XAudio2CutoffFrequencyToRadians function

## Description

Inline function that converts from filter cutoff frequencies expressed in hertz to the radian frequency values used in the **Frequency** member of the [XAUDIO2_FILTER_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/xaudio2/ns-xaudio2-xaudio2_filter_parameters) structure.

## Parameters

### `CutoffFrequency` [in]

The cutoff frequency in hertz. Frequencies greater than SampleRate ÷ 6 are clamped to XAUDIO2_MAX_FILTER_FREQUENCY.

### `SampleRate` [in]

The sample rate of the audio data affected by the [XAUDIO2_FILTER_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/xaudio2/ns-xaudio2-xaudio2_filter_parameters) structure.

## Return value

Returns a radian frequency for use in the [XAUDIO2_FILTER_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/xaudio2/ns-xaudio2-xaudio2_filter_parameters) structure.

## Remarks

You must explicitly define XAUDIO2_HELPER_FUNCTIONS in your build for this function to become available.

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[XAudio2 Functions](https://learn.microsoft.com/windows/desktop/xaudio2/functions)
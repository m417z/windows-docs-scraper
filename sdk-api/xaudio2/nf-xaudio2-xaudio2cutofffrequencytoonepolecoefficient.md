# XAudio2CutoffFrequencyToOnePoleCoefficient function

## Description

Inline function that converts from filter cutoff frequencies expressed in hertz to the filter coefficients used with the **Frequency** member of the [XAUDIO2_FILTER_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/xaudio2/ns-xaudio2-xaudio2_filter_parameters) structure.

This function applies to LowPassOnePoleFilter and HighPassOnePole filter types only, use [XAudio2CutoffFrequencyToRadians](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-xaudio2cutofffrequencytoradians) for state-variable filter types.

## Parameters

### `CutoffFrequency`

The cutoff frequency in hertz. Frequencies greater than *SampleRate* are clamped to XAUDIO2_MAX_FILTER_FREQUENCY.

### `SampleRate`

The sample rate of the audio data affected by the [XAUDIO2_FILTER_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/xaudio2/ns-xaudio2-xaudio2_filter_parameters) structure.

## Return value

Returns a filter coefficient for use in the [XAUDIO2_FILTER_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/xaudio2/ns-xaudio2-xaudio2_filter_parameters) structure.

## Remarks

You must explicitly define XAUDIO2_HELPER_FUNCTIONS in your build for this function to become available.

The DirectX SDK versions of XAUDIO2 do not support one-pole filters, so this function is not present in those releases.

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[XAudio::Functions](https://learn.microsoft.com/windows/desktop/xaudio2/functions)
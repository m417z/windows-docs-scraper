# XAudio2RadiansToCutoffFrequency function

## Description

Inline function that converts from the radian frequencies used in [XAUDIO2_FILTER_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/xaudio2/ns-xaudio2-xaudio2_filter_parameters) back to absolute frequencies in hertz.

## Parameters

### `Radians` [in]

Value of the Frequency member of the [XAUDIO2_FILTER_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/xaudio2/ns-xaudio2-xaudio2_filter_parameters) structure.

### `SampleRate` [in]

The sample rate of the audio data affected by the [XAUDIO2_FILTER_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/xaudio2/ns-xaudio2-xaudio2_filter_parameters) structure.

## Return value

Returns a floating-point value that represents the frequency in hertz.

## Remarks

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[XAudio2 Functions](https://learn.microsoft.com/windows/desktop/xaudio2/functions)
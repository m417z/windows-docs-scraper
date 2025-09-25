# XAudio2SemitonesToFrequencyRatio function

## Description

Inline function that converts a semitone value to a frequency ratio value.

## Parameters

### `Semitones`

Floating point value representing the semitone value.

## Return value

Returns a floating point value that represents the frequency ratio.

## Remarks

**XAudio2SemitonesToFrequencyRatio** can be used to calculate the Ratio parameter value passed to the function [IXAudio2SourceVoice::SetFrequencyRatio](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2sourcevoice-setfrequencyratio).

You must explicitly define XAUDIO2_HELPER_FUNCTIONS in your build for this function to become available.

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[XAudio2 Functions](https://learn.microsoft.com/windows/desktop/xaudio2/functions)
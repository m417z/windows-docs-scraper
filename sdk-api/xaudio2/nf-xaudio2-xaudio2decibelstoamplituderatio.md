# XAudio2DecibelsToAmplitudeRatio function

## Description

Inline function that converts a decibel value to an amplitude ratio value.

## Parameters

### `Decibels` [in]

Floating point value representing the decibel level.

## Return value

Returns a floating point value that represents the amplitude ratio.

## Remarks

This function can be used to calculate the Volume parameter value passed to the [IXAudio2Voice::SetVolume](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2voice-setvolume) function.

You must explicitly define XAUDIO2_HELPER_FUNCTIONS in your build for this function to become available.

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[XAudio2 Functions](https://learn.microsoft.com/windows/desktop/xaudio2/functions)
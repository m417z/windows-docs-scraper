# ReverbConvertI3DL2ToNative function

## Description

Inline function that converts I3DL2 (Interactive 3D Audio Rendering Guidelines Level 2.0) parameters to native XAudio2 parameters.

## Parameters

### `pI3DL2` [in]

Pointer to a [XAUDIO2FX_REVERB_I3DL2_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/xaudio2fx/ns-xaudio2fx-xaudio2fx_reverb_i3dl2_parameters) structure containing the I3DL2 parameters to convert. There are many preset values defined for the **XAUDIO2FX_REVERB_I3DL2_PARAMETERS** structure; for more information, see [XAUDIO2FX_I3DL2_PRESET](https://learn.microsoft.com/windows/desktop/xaudio2/xaudio2fx-i3dl2-preset).

### `pNative` [in, out]

Pointer to a [XAUDIO2FX_REVERB_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/xaudio2fx/ns-xaudio2fx-xaudio2fx_reverb_parameters) structure that will receive the native parameters that are equivalent to the I3DL2 parameters.

### `sevenDotOneReverb`

A boolean value indicating whether 7.1 reverb is enabled.

**Note** This parameter is supported beginning with Windows 10.

## Remarks

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[XAUDIO2FX_I3DL2_PRESET](https://learn.microsoft.com/windows/desktop/xaudio2/xaudio2fx-i3dl2-preset)

[XAUDIO2FX_REVERB_I3DL2_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/xaudio2fx/ns-xaudio2fx-xaudio2fx_reverb_i3dl2_parameters)

[XAudio2::Functions](https://learn.microsoft.com/windows/desktop/xaudio2/functions)
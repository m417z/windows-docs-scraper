# IXAudio2::SetDebugConfiguration

## Description

Changes global debug logging options for XAudio2.

## Parameters

### `pDebugConfiguration`

Pointer to a [XAUDIO2_DEBUG_CONFIGURATION](https://learn.microsoft.com/windows/desktop/api/xaudio2/ns-xaudio2-xaudio2_debug_configuration) structure that contains the new debug configuration.

### `X2DEFAULT`

This parameter is reserved and must be NULL.

## Remarks

SetDebugConfiguration sets the debug configuration for the given instance of XAudio2 engine. See [XAUDIO2_DEBUG_CONFIGURATION](https://learn.microsoft.com/windows/desktop/api/xaudio2/ns-xaudio2-xaudio2_debug_configuration) Structure for supported debug options. By default, XAudio2 does not log debug output or break on errors.

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[IXAudio2](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2)

[XAudio2 Functions](https://learn.microsoft.com/windows/desktop/xaudio2/functions)
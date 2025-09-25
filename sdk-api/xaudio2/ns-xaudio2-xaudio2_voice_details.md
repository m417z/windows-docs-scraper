# XAUDIO2_VOICE_DETAILS structure

## Description

Contains information about the creation flags, input channels, and sample rate of a voice.

## Members

### `CreationFlags`

Flags used to create the voice; see the individual voice [interfaces](https://learn.microsoft.com/windows/desktop/xaudio2/interfaces) for more information.

### `ActiveFlags`

Flags that are currently set on the voice.

### `InputChannels`

The number of input channels the voice expects.

### `InputSampleRate`

The input sample rate the voice expects.

## Remarks

Note the DirectX SDK versions of XAUDIO2 do not support the **ActiveFlags** member.

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[Structures](https://learn.microsoft.com/windows/desktop/xaudio2/structures)
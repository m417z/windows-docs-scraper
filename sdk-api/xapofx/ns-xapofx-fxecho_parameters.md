# FXECHO_PARAMETERS structure

## Description

Parameters for use with the [FXECHO XAPOFX](https://learn.microsoft.com/windows/desktop/xaudio2/xapofx-overview).

## Members

### `WetDryMix`

Ratio of wet (processed) signal to dry (original) signal.

### `Feedback`

Amount of output to feed back into input.

### `Delay`

Delay to all channels in milliseconds. This value must be between **FXECHO_MIN_DELAY** and [FXECHO_INITDATA](https://learn.microsoft.com/windows/desktop/api/xapofx/ns-xapofx-fxecho_initdata).**MaxDelay**.

## Remarks

Echo only supports FLOAT32 audio formats.

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[Structures](https://learn.microsoft.com/windows/desktop/xaudio2/structures)
# FXECHO_INITDATA structure

## Description

Initialization parameters for use with the [FXECHO XAPOFX](https://learn.microsoft.com/windows/desktop/xaudio2/xapofx-overview).

## Members

### `MaxDelay`

Maximum delay (all channels) in milliseconds. This must be within **FXECHO_MIN_DELAY** and **FXECHO_MAX_DELAY**.

## Remarks

Use of this structure is optional. The default **MaxDelay** is **FXECHO_DEFAULT_DELAY**.

**Note** The DirectX SDK versions of XAUDIO2 don't support this functionality.

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[Structures](https://learn.microsoft.com/windows/desktop/xaudio2/structures)
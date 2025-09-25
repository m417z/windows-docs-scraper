# FXMASTERINGLIMITER_PARAMETERS structure

## Description

Parameters for use with the [FXMasteringLimiter XAPO](https://learn.microsoft.com/windows/desktop/xaudio2/xapofx-overview).

## Members

### `Release`

Speed, in milliseconds, at which the limiter stops affecting audio after the audio drops below the limiter's threshold, which is specified by the **Loudness** member. This value must be between [FXMASTERINGLIMITER_MIN_RELEASE (1)](https://learn.microsoft.com/windows/desktop/xaudio2/fxmasteringlimit-constants) and [FXMASTERINGLIMITER_MAX_RELEASE (20)](https://learn.microsoft.com/windows/desktop/xaudio2/fxmasteringlimit-constants) and defaults to [FXMASTERINGLIMITER_DEFAULT_RELEASE (6)](https://learn.microsoft.com/windows/desktop/xaudio2/fxmasteringlimit-constants).

### `Loudness`

Loudness metric threshold of the limiter. This value must be between [FXMASTERINGLIMITER_MIN_LOUDNESS (1)](https://learn.microsoft.com/windows/desktop/xaudio2/fxmasteringlimit-constants) and [FXMASTERINGLIMITER_MAX_LOUDNESS (1800)](https://learn.microsoft.com/windows/desktop/xaudio2/fxmasteringlimit-constants) and defaults to [FXMASTERINGLIMITER_DEFAULT_LOUDNESS (1000)](https://learn.microsoft.com/windows/desktop/xaudio2/fxmasteringlimit-constants).

## Remarks

### Platform Requirements

Windows 10 (XAudio2.9);
Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[Structures](https://learn.microsoft.com/windows/desktop/xaudio2/structures)
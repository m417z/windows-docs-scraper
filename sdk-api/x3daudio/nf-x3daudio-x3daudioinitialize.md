# X3DAudioInitialize function

## Description

Sets all global 3D audio constants.

## Parameters

### `SpeakerChannelMask` [in]

Assignment of channels to speaker positions. This value must not be zero. The only permissible value on Xbox 360 is SPEAKER_XBOX.

### `SpeedOfSound` [in]

Speed of sound, in user-defined world units per second. Use this value only for doppler calculations. It must be greater than or equal to FLT_MIN.

### `Instance` [out]

3D audio instance handle. Use this handle when you call [X3DAudioCalculate](https://learn.microsoft.com/windows/desktop/api/x3daudio/nf-x3daudio-x3daudiocalculate).

## Return value

This function does not return a value.

## Remarks

**X3DAUDIO_HANDLE** is an opaque data structure. Because the operating system doesn't allocate any additional storage for the 3D audio instance handle, you don't need to free or close it.

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

**Windows Phone 8.1:** This API is supported.

## See also

[Functions](https://learn.microsoft.com/windows/desktop/xaudio2/functions)
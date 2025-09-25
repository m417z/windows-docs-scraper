# CXAPOBase::ValidateFormatDefault

## Description

Verifies that an audio format falls within the default ranges supported.

## Parameters

### `pFormat`

Audio format to validate.

### `fOverwrite`

If TRUE indicates that *pFormat* should be overwritten with the nearest audio format supported if the format it specified is not supported. The nearest audio format is determined by bit depth, framerate and channel count in that order of importance.

## Return value

Return S_OK if the audio format is supported. Returns XAPO_E_FORMAT_UNSUPPORTED if the audio format is unsupported, *pFormat* will be overwritten with the nearest audio format if *fOverwrite* is TRUE. Returns E_INVALIDARG if the audio format is invalid, in which case *pFormat* will be left untouched.

## Remarks

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[CXAPOBase](https://learn.microsoft.com/windows/desktop/api/xapobase/nl-xapobase-cxapobase)
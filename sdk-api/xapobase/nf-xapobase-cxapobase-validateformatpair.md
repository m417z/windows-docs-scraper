# CXAPOBase::ValidateFormatPair

## Description

Verifies that an input and output format pair configuration is supported by the XAPO.

## Parameters

### `pSupportedFormat`

An audio format known to be supported by the XAPO.

### `pRequestedFormat`

An audio format to examine, must be a pointer to a WAVEFORMATEXTENSIBLE structure if *fOverWrite* is TRUE.

### `fOverwrite`

If TRUE indicates that *pRequestedFormat* should be overwritten with the nearest audio format supported if the requested format is not supported. The nearest audio format is determined by bit depth, framerate and channel count in that order of importance.

## Return value

Returns S_OK if the format pair is supported. Returns XAPO_E_FORMAT_UNSUPPORTED if the format pair is unsupported; *pRequestedFormat* will be overwritten if *fOverWrite* is TRUE. Returns E_INVALIDARG if either audio format was invalid; *pRequestedFormat* will be left untouched.

## Remarks

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[CXAPOBase](https://learn.microsoft.com/windows/desktop/api/xapobase/nl-xapobase-cxapobase)
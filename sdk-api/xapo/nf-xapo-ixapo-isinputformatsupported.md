# IXAPO::IsInputFormatSupported

## Description

Queries if a specific input format is supported for a given output format.

## Parameters

### `pOutputFormat`

Output format.

### `pRequestedInputFormat`

Input format to check for being supported.

### `ppSupportedInputFormat`

If not NULL, and the input format is not supported for the given output format, *ppSupportedInputFormat* returns a pointer to the closest input format that is supported. Use [XAPOFree](https://learn.microsoft.com/windows/desktop/api/xapo/nf-xapo-xapofree) to free the returned structure.

## Return value

Returns S_OK if the format pair is supported. Returns XAPO_E_FORMAT_UNSUPPORTED if the format pair is not supported.

## Remarks

The [IXAPO::IsOutputFormatSupported](https://learn.microsoft.com/windows/desktop/api/xapo/nf-xapo-ixapo-isoutputformatsupported) and **IsInputFormatSupported** methods allow an XAPO to indicate which audio formats it is capable of processing. If a requested format is not supported, the XAPO should return the closest format that it does support. The closest format should be determined based on frame rate, bit depth, and channel count, in that order of importance. The behavior of **IsInputFormatSupported** is allowed to change, based on the internal state of the XAPO, but its behavior should remain constant between calls to the [IXAPO::LockForProcess](https://learn.microsoft.com/windows/desktop/api/xapo/nf-xapo-ixapo-lockforprocess) and [IXAPO::UnlockForProcess](https://learn.microsoft.com/windows/desktop/api/xapo/nf-xapo-ixapo-unlockforprocess) methods.

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[IXAPO](https://learn.microsoft.com/windows/desktop/api/xapo/nn-xapo-ixapo)
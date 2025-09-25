# CreateHrtfApo function

## Description

Creates an instance of the [IXAPO](https://learn.microsoft.com/windows/desktop/api/xapo/nn-xapo-ixapo) interface for head-related transfer function (HRTF) processing.

## Parameters

### `init` [in]

Pointer to an [HrtfApoInit](https://learn.microsoft.com/windows/desktop/api/hrtfapoapi/ns-hrtfapoapi-hrtfapoinit) struct. Specifies parameters for XAPO interface initialization.

### `xApo` [out]

The new instance of the [IXAPO](https://learn.microsoft.com/windows/desktop/api/xapo/nn-xapo-ixapo) interface.

## Return value

This function can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | An instance of the XAPO object was created successfully. |
| **E_NOTIMPL** | HRTF is not supported on the current platform. |

## Remarks

Audio is processed in blocks of 1024 samples.

Format requirements:

* Input: mono, 48 kHz, 32-bit float PCM.
* Output: stereo, 48 kHz, 32-bit float PCM.

The source and environment parameters of the HRTF XAPO are controlled through the [IXAPOHrtfParameters](https://learn.microsoft.com/windows/desktop/api/hrtfapoapi/nn-hrtfapoapi-ixapohrtfparameters) interface.

### Platform Requirements

Windows 10 (XAudio2.9);

## See also

[Functions](https://learn.microsoft.com/windows/desktop/xaudio2/functions)

[IXAPO](https://learn.microsoft.com/windows/desktop/api/xapo/nn-xapo-ixapo)
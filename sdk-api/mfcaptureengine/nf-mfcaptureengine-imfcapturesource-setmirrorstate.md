# IMFCaptureSource::SetMirrorState

## Description

Enables or disables mirroring of the video preview stream.

## Parameters

### `dwStreamIndex` [in]

The zero-based index of the stream.

### `fMirrorState` [in]

If **TRUE**, mirroring is enabled; if **FALSE**, mirroring is disabled.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_NOTIMPL** | The device stream does not have mirroring capability. |
| **MF_E_INVALIDREQUEST** | The source is not initialized. |

## See also

[IMFCaptureSource](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nn-mfcaptureengine-imfcapturesource)
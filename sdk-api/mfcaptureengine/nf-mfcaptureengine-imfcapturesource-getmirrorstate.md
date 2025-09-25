# IMFCaptureSource::GetMirrorState

## Description

Gets the current mirroring state of the video preview stream.

## Parameters

### `dwStreamIndex` [in]

The zero-based index of the stream.

### `pfMirrorState` [out]

Receives the value **TRUE** if mirroring is enabled, or **FALSE** if mirroring is disabled.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFCaptureSource](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nn-mfcaptureengine-imfcapturesource)
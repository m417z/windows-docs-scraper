# IMFCaptureRecordSink::GetRotation

## Description

Gets the rotation that is currently being applied to the recorded video stream.

## Parameters

### `dwStreamIndex` [in]

The zero-based index of the stream. You must specify a video stream.

### `pdwRotationValue` [out]

Receives the image rotation, in degrees.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFCaptureRecordSink](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nn-mfcaptureengine-imfcapturerecordsink)
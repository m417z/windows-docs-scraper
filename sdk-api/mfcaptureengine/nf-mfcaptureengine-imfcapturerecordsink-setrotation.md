# IMFCaptureRecordSink::SetRotation

## Description

Rotates the recorded video stream.

## Parameters

### `dwStreamIndex` [in]

The zero-based index of the stream to rotate. You must specify a video stream.

### `dwRotationValue` [in]

The amount to rotate the video, in degrees. Valid values are 0, 90, 180, and 270. The value zero restores the video to its original orientation.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFCaptureRecordSink](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nn-mfcaptureengine-imfcapturerecordsink)
# IMFCaptureRecordSink::SetCustomSink

## Description

Sets a custom media sink for recording.

## Parameters

### `pMediaSink` [in]

A pointer to the [IMFMediaSink](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasink) interface of the media sink.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method overrides the default selection of the media sink for recording.

## See also

[IMFCaptureRecordSink](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nn-mfcaptureengine-imfcapturerecordsink)
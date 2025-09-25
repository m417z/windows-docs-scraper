# IMFCaptureRecordSink::SetOutputFileName

## Description

Specifies the name of the output file for the recording.

## Parameters

### `fileName` [in]

A null-terminated string that contains the URL of the output file.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The capture engine uses the file name extension to select the container type for the output file. For example, if the file name extension is ."mp4", the capture engine creates an MP4 file.

Calling this method overrides any previous call to [IMFCaptureRecordSink::SetOutputByteStream](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nf-mfcaptureengine-imfcapturerecordsink-setoutputbytestream) or [IMFCaptureRecordSink::SetSampleCallback](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nf-mfcaptureengine-imfcapturerecordsink-setsamplecallback).

## See also

[IMFCaptureRecordSink](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nn-mfcaptureengine-imfcapturerecordsink)
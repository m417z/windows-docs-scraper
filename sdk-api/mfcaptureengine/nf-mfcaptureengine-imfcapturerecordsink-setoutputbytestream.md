# IMFCaptureRecordSink::SetOutputByteStream

## Description

Specifies a byte stream that will receive the data for the recording.

## Parameters

### `pByteStream` [in]

A pointer to the [IMFByteStream](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfbytestream) interface of a byte stream. The byte stream must be writable.

### `guidContainerType` [in]

A GUID that specifies the file container type. Possible values are documented in the [MF_TRANSCODE_CONTAINERTYPE](https://learn.microsoft.com/windows/desktop/medfound/mf-transcode-containertype) attribute.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Calling this method overrides any previous call to [IMFCaptureRecordSink::SetOutputFileName](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nf-mfcaptureengine-imfcapturerecordsink-setoutputfilename) or [IMFCaptureRecordSink::SetSampleCallback](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nf-mfcaptureengine-imfcapturerecordsink-setsamplecallback).

## See also

[IMFCaptureRecordSink](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nn-mfcaptureengine-imfcapturerecordsink)